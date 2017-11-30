#VM
By: Sebastian Gawęda and Chase Haddleton
 
CS246E Final Project

Milestone completed! Sebastian is on board!

 * Model will be told it is in macro playback mode
 * while the macro are being played back, the model will *ignore* `saveFrame()`s
 * when the mode is changed back to something else model will trigger `saveFrame()` on it self
 * commands will be registered to notify a collection of objects (which will probably just be VMWindow) upon their
 * Completion (can be done entirely in the Command abstract class)
 * VMWindow then notifies anyone subscribed to it
 * For CompositeCommands, the subCommands are not registered to any listener, but the CompositeCommand itself is
 * During macro playback we will unregister VMModel from listening to VMWindow
