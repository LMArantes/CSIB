#include "maze.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // random seed
    srand(time(nullptr));

    Maze myMaze;

    myMaze.build();

    cout << "Maze walls:" << endl;
    myMaze.print();

    Room cheeseRoom;
    cheeseRoom.makeCheeseRoom();

    myMaze.start();

    while (true) {
        Room currentRoom = myMaze.getCurrentRoom();
        cout << "You are in room ";
        currentRoom.print();
        cout << endl;

        // mouse found the cheese
        if (matchRoom(currentRoom, cheeseRoom)) {
            cout << "Congratulations! You found the cheese!" << endl;
            break;
        }

        // next move
        Room nextRoom = currentRoom.nextMove();

        // quit
        if (nextRoom.getX() == -1 && nextRoom.getY() == '*') {
            cout << "You quit the game." << endl;
            break;
        }

        if (myMaze.move(nextRoom)) {
            cout << "Moved to ";
            nextRoom.print();
            cout << "." << endl;
        } else {
            cout << "Wall. You can't move to ";
            nextRoom.print();
            cout << "." << endl;
        }
    }

    return 0;
}
