#include <NonBlockingGame.h>
#include <iostream>
#include <time.h>
#include <vector>


//
//  The purpose of this assignment is to learn to 1. The classic game of Snake.
//  Move a "snake" (line of sprites) along a 2D grid attempting to run over a
//  randomly placed object to help it grow. 2. If it runs into itself the game is over
//  and the player has lost. 3. The object of the game is to make the snake as big as possible.
//
using namespace bridges::game;
using namespace std;

// this keeps a list of elements (squares) that represents the snake object
// linked list since it can grow as the game progresses
class Block {
    public:
        Block *next = nullptr;
        int x;
        int y;
        Block() {
            x = 0;
            y = 0;
        }
        Block(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

struct my_game : public NonBlockingGame {
    long frameTime;
    long nextFrameTime;

    Block apple;
    Block head;

    enum Direction {East, West, South, North};

    Direction lastDir = East;
    Direction dir = East;

    int frame = 0;

    my_game(int assID, std::string username, std::string apikey)
        : NonBlockingGame (0, username, apikey, 30, 30) {
    }

    virtual void initialize() override {
        srand(time(NULL));

        head = Block(15,15);
        Block* current = &head;
        //This code draws the rest of the snake
        for (int i = 0; i < 3; i++) {
            setBGColor(15 - i, 15, NamedColor::blue);
            if (i > 0) {
                current->next = new Block(15 - i, 15);
                current = current->next;
            }
        }


        dir = East;
        lastDir = dir;
        apple = Block();
        plantApple();
        paint();
    }

    void handleInput() {
        //test which key was pressed (ex: keyLeftJustPressed())
        //if the user pressed left, change the current direction to west as long as the
        //the last direction does not equal east...the snake can't just flip
        //Do for up, down, left, right


        // NOTE: I flipped around the directions so that the arrow keys correspond to the proper side
        // Of the screen. Press up, snake goes to top of board, down sends snake down to bottom of board, etc.
        if(keyLeftJustPressed() && lastDir != South){
            lastDir = dir;
            dir = North;
        }
        else if(keyRightJustPressed() && lastDir != North){
            lastDir = dir;
            dir = South;
        }
        else if(keyUpJustPressed() && lastDir != East){
            lastDir = dir;
            dir = West;
        }
        else if(keyDownJustPressed() && lastDir != West){
            lastDir = dir;
            dir = East;
        }
    }

    // update snake position
    void updatePosition() {
        Block * current = head.next;
        int nextX = head.x;
        int nextY = head.y;
        Block nextPos = head;

            //loop through the snake's body setting each node's (x,y) to the next node's (x,y)
        while (current != nullptr) {
            int tempX = current->x;
            int tempY = current->y;
            current->x = nextX;
            current->y = nextY;
            nextX = tempX;
            nextY = tempY;
            current = current->next;
        }

            //handle edge cases
        switch (dir) {
            case East:
                head.x += 1;
                break;
            case West:
                head.x -= 1;
                break;
            case South:
                head.y += 1;
                break;
            case North:
                head.y -= 1;
                break;
        }
            //hint: a switch statement on the current direction would be really helpful
        if (head.x >= getBoardWidth()) {
            head.x = 0;
        }
        else if (head.x < 0) {
            head.x = getBoardWidth() - 1;
        }

        if (head.y >= getBoardHeight()) {
            head.y = 0;
        }
        else if (head.y < 0) {
            head.y = getBoardHeight() - 1;
        }
    }

    bool collision(int x, int y) {
        // Detect a colision between an arbitrary point and the snake. Returns true if collides, false if not.
        if(head.x == x && head.y == y){
            return true;
        }
        Block* current = head.next;
        while(current != nullptr){
            if(current->x == x && current->y == y){
            return true;
            }
            current = current->next;
        }

        return false;
    }

    // locate apple at new position
    void plantApple() {
        // get a new random x and a random y for the apple
        //loop through the snake to ensure that the apple's (x,y) does not
        //intersect with any part of the snake, if it does, get new random values to test
        //if it doesn't collide with the snake, set the apple's x and apple's y to the random
        //values that were identified
        int x = rand() % getBoardWidth();
        int y = rand() % getBoardHeight();
        if(collision(x,y)){
            while(collision(x,y)){
                x = rand() % getBoardWidth();
                y = rand() % getBoardHeight();
            }
        }
        apple.x = x;
        apple.y = y;
    }

    // check if snake has found the apple
    void detectApple() {
        //Tests to see if the snake has hit the apple
        //Erases the apple
        if (head.x == apple.x && head.y == apple.y) {
            drawSymbol(apple.x, apple.y, NamedSymbol::none, NamedColor::red);

            Block* current = &head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Block(apple.x, apple.y);
            plantApple();
        }
    }

    // check if snake ate itself! Yuk!
    void detectDeath() {
        Block * current = head.next;
        while (current != nullptr) {
            if (head.x == current->x && head.y == current->y) {
                // need to deallocate storage!
                while(current != nullptr){
                    Block* old_current = current;
                    current = current->next;
                    delete old_current;
                }
                exit(0);
            }
            current = current->next;
        }
    }


    // redraw
    void paint() {
        //Paints the board by looping through the rows and columns
        //Optional: change the color of the board
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
            if (i % 2 == j % 2) {
                setBGColor(i, j, NamedColor::green);
            }
            else {
                setBGColor(i, j, NamedColor::forestgreen);
            }
            }
        }

            //Optional: change the color of the head of the snake
        setBGColor(head.x, head.y, NamedColor::lightblue);

            //Optional: use a different symbol or color
        drawSymbol(apple.x, apple.y, NamedSymbol::circle, NamedColor::red);

            //Paints the snake
            //Optional: change the color of the snake
        Block * current = head.next;
        while (current != nullptr) {
            setBGColor(current->x, current->y, NamedColor::blue);
            current = current->next;
        }
    }

    // handle input, check if apple was detected, update position, redraw,
    // detect if snake ate itself
    virtual void gameLoop() override {
        frame += 1;
        handleInput();
        if (frame >= 3) {
            lastDir = dir;
            detectApple();
            updatePosition();
            paint();
            detectDeath();
            frame = 0;
        }
    }
};

// Initialize your game
// Call your game class with your assignment id, username, and api key
int main (int argc, char** argv) {
    my_game g(1, "dylcal13", "546959860721");

    g.start();
}
