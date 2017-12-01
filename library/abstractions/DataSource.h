//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_DATASOURCE_H
#define VM_DATASOURCE_H

#include <vector>

class DataSource {

    /*template<typename Child>
     * class DS {
     *   public:
     *     void doAddChar(typename Child::iterator, ...)
     *     ...
     * };
     * */

    class iterator;
    //iterator currentPos;
    // How do I make this the right iterator?

    virtual void doAddChar(iterator it, size_t linePos, char c) = 0;
    virtual void doRemoveChar(iterator it, size_t linePos) = 0;
    virtual void doAddLine(iterator it,const std::string &str) = 0;
    virtual void doRemoveLine(iterator it) = 0;

    virtual iterator createBegin() = 0;
    virtual iterator createEnd() = 0;

    // How do I enforce that a subclass must implement a bidirectional iterator?

public:
    void addChar(iterator it, size_t linePos, char c) { doAddChar(it, linePos, c); }
    void removeChar(iterator it, size_t linePos) { doRemoveChar(it, linePos); }
    void addLine(iterator it, const std::string &str) { doAddLine(it, str); }
    void removeLine(iterator it) { doRemoveLine(it); }

    iterator begin() { return createBegin(); }
    iterator end() { return createEnd(); }
};

#endif //VM_DATASOURCE_H
