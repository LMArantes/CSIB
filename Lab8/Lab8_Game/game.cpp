#include "maze.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(nullptr));

    // generate the maze
    RoomPair myMaze[numWalls];
    clearWalls(myMaze);
    build(myMaze);

    // mouse starting position to corner
    Room currentRoom = startRoom;

    char showWalls;
    cout << "Do you want to see the wall positions? (y/n): ";
    cin >> showWalls;
    if (showWalls == 'y' || showWalls == 'Y') {
        printMaze(myMaze);
    }

    while (true) {
        cout << "You are in room ";
        printRoom(currentRoom);
        cout << endl;

        Room nextRoom = nextMove(currentRoom);

        if (nextRoom.x == -1 && nextRoom.y == '*') {
            cout << "You quit the game." << endl;
            break;
        }

        if (nextRoom.x == -2 && nextRoom.y == '*') {
            printMaze(myMaze);
            continue;
        }

        // move is blocked by a wall
        RoomPair attemptedMove = {currentRoom, nextRoom};
        if (checkMaze(myMaze, attemptedMove)) {
            cout << "Wall." << endl;
        } else {
            currentRoom = nextRoom;
        }

        // cheese!!!! :)
        if (matchRoom(currentRoom, cheeseRoom)) {
            cout << "Congratulations! You found the cheese!" << endl;
            break;
        }
    }

    return 0;
}
