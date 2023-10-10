/* 
 * File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements
 * the stack abstraction for characters.
 */

#ifndef _charstack_h
#define _charstack_h

/*
 * Class: CharStack
 * ----------------
 * This class models a stack of characters. The fundamental operations 
 * are the same as those for the Stack<char> class.
 */

class CharStack {

 public:

  /*
   * Constructor: CharStack
   * Usage: CharStack catk;
   * ----------------------
   * Initializes a new empty stack that can contain characters.
   */

    CharStack();

  /*
   * Destructor: ~CharStack
   * Usage: (usually implicit)
   * -------------------------
   * Frees any heap storage associated with this character stack. 
   */

    ~CharStack();

  /*
   * Method: printStack
   * Usage: printStack()
   * --------------------
   * Prints out the stack as an array.
   */
    void printStack();

  /*
   * Method: size
   * Usage: int nElems = catk.size();
   * --------------------------------
   * Returns the number of characters in this stack.
   */

    int size();

   /* 
    * Method: isEmpty
    * Usage: if (catk.isEmpty()) . . .
    * --------------------------------
    * Returns true if this stack contains no characters.
    */

    bool isEmpty();

    /*
     * Method: clear
     * Usage: cat.clear();
     * ------------------
     * Removes all characters from this stack. 
     */

    void clear();

    /*
     * Method: push
     * Usage: catk.push(ch);
     * ---------------------
     * Pushes the character ch onto this stack. 
     */

    void push(char ch);

    /* 
     * Method: pop
     * Usage: char ch = catk.pop();
     * ----------------------------
     * Removes the top character from this stack and returns it. 
     */

    char pop();

    /*
     * Method: peek
     * Usage: char ch = catk.peek();
     * -----------------------------
     * Returns the value of top character from this stack without
     * removing it. Raises an error if called on an empty stack. 
     */

    char peek();

 private:
    char* arr = nullptr;
    int topOfStack = 0; // also serves as stack size
};

#endif
