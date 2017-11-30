#Problem 32 - Fixed Size allocation

Array large enough to hold n T obks

Init:
```
| 1 | 2 | 3 | ... | -1 |
  0   1   2        n-1
````

When the client has a slot: T obj

When we have it:
- node in a linked list
- each slow stores the index of the next slot in the list

##Allocation
From the front

Allocate 1
```
|---| 2 | 3 | ... | -1 |
  0   1   2         n-1
```

Allocate 2
```
|---|---| 3 | ... | -1 |
  0   1   2         n-1
```

##Deallocation
Free item 0:
```
| 2 |---| 3 | ... | -1 |
  0   1   2         n-1
```

Free item 1:
```
| 2 | 0 | 3 | ... | -1 |
  0   1   2         n-1
```

##Implementation
```C++
template<typename T, int n> class fsAlloc {
    union slot {
        int next;
        T data;
        Slot() : next{0} {}
    };
    
    Slot theSlots[n];
    int first = 0;
    
public:

    fsAlloc() {
        for (int i = 0; i < n - 1; ++ ) theSlots[i] = i + 1;
        theSlots[n-1] = -1;
    }
    
    T *allocate() noexcept {
        if (first == -1) return nullptr;
        T *result = &(theSlots[first].data);
        first = theSlots[first].next;
        return result;
    }
    
    void deallocate(void *item) noexcept {
        int index = (static_cast<char *>(item) - reintepret_cast<char *>(theSlots)) / sizeof(slots);
        theSlots[index].next = first; 
        first = index;
    }
}
```

Use in a class:
```C++
class student final { // Subclasses would likely be larger
    int assns, mt, final;
    static fsAlloc<student, SIZE> pool; // size is the number we want
public:
    ...
    static void *operator new(size_t size) {
        if (sizee != sizeof(student)) throw std::bad_alloc;
    }
    
    static void operator delete(void *p) noexcept {
        if (p == nullptr) return;
        pool.deallocate(p);
    }
}

fsAlloc <Student, SIZE> Student::pool;
```

Example:
```C++
int main() {
    Student *s1 = new Student; // Custom allocator
    Student *s2 = new Student; // Custom allocator
    delete s1; // Custom deallocator
    delete s2; // Custom deallocator
```

*Q: Where do s1, s2 reside?*
- static memory (NOT in the heap)
- could arrange for stack/heap memory

Note:
- we used a union to hold both int *T
    - wastes less space
- could have used a struct
    - `| next | T |`
- disadvantages
    - if you access a dangling T pointer, you can corrupt the linked list
    - ```C++
        Stduent * s = new Student;
        delete s;
        s->setAssns(--);
        ```

## Lesson
Following a dangling ptr can be very dangerous

With a struct, 'next' is before the T obj, so you have to work hard to corrupt it. 
```C++
reinterpret_cast<int *>(s)[-1] = ------
```
On the other hand, with a struct, problems if T doesn't have a default ctor
i.e.
```C++
struct Slot {
    int next;
    T data;
}
slot theSlots[n]; // Wont work if T has no def. ctor
```
Cannot do operator new/placement new
```C++
union SlotChar{
    char dummy;
    Slot s;
    SlotChar(): dummy{0} {}
};
```
Also:
1. Why store indices instead of ptrs?
    - Smaller than ptrs on this machine
    - So waste no memory as long as T >= size of an int
    - would waste if T is smaller than an int
    - could use a smaller index type (i.e. short, char, etc, as long as you don't need
     more items)
    - could make the index type a param of the templace
2. Student final
    - fixed-size allocator
    - subclass might be larger
    - options:
        - have no subclasses
        - check size, throw if it isn't the 'right size'
    - derived class can have it's own allocator
    
# Problem 33 - I want a (tiny bit) smaller vector class
Currently: vector/vector_base have an allocator field.

Standard allocator is stateless, it has no fields

What is it's size? 0?

No, C++ does not allow 0 size types, it messes things up

Everything has size >= 1

Practically: the compiler adds a dummy char to the allocator

So having an allocator field makes the vector larger by a byte (probably more, due to 
alignment)

Having an allocator field in vector_base may add another byte (or more)

To save this space, C++ provides the empty base optimization (EBO)

Under EBO, an empty base class does not have to occupy space in an obj

So, we can eliminate the space cost of allocator by making it a base class. At the 
same time, make vector_base a base class of vector
```C++
template<typename T, typename Alloc=allocator<T>>
struct vector_base : private Alloc {
    size_t n, cap;
    T* v;
    using Alloc::allocate;
    using Alloc::deallocate;
    // etc
    vector_base(size_t n) : n{0}, cap{n}, v{allocate(n)} {}
    ~vector_basae() { deallocate(v); }
};

template<typename T, typename Alloc = allocator<T>>
class vector: vector_base<T, Alloc> { // private inheritane because vector is a class
    using vector_base<T, Alloc>::n;
    using vector_base<T, Alloc>::cap;
    using vector_base<T, Alloc>::v;
    using Alloc::allocate;    // or say this->allocate
    using Alloc::deallocate;  // or say this->deallocate
public:
    // can use n, cap, v instead of vb.n, vb.cap, vb.v
};
```

uninitialized_copy, etc, need to call construct/destroy.

Easiest way is to take an allocator as a param
```C++
template<typename T, typename Alloc>
void uninitialized_fill(T* start, T* finish, const T &x, Alloc a) {
    ...
    a.construct(---);
    ...
    a.destroy(---);
};
```

How can vector pass an allocator to these f'ns?

```C++
uninitialized_fill(v, v + n, x, static_cast<Alloc &><(*this)); // cast yourself to base class reference
```

Remaining details-exercise

##Conclusion
C++ is easy because it is hard. 