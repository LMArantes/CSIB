#include "maze.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    // random seed
    srand(1);


    Room myRoom; // creates a room
    myRoom.x = 2;
    myRoom.y = 'b';

    // room
    cout << "myRoom, fixed location: ";
    printRoom(myRoom);
    cout << endl;

    Room newMoveRoom = nextMove(myRoom);
    cout << "user selected adjacent room: ";
    printRoom(newMoveRoom);
    cout << endl;

    Room randomRoom = pickAdjacent(myRoom);
    cout << "randomly selected adjacent room: ";
    printRoom(randomRoom);
    cout << endl;

    if (matchRoom(randomRoom, newMoveRoom))
        cout << "randomRoom is the same as newMoveRoom" << endl;


    RoomPair myWall = { {2,'b'}, {2,'c'} };

    // prints wall
    cout << "myWall, fixed location: ";
    printPair(myWall);
    cout << endl;

    // selects and prints a random wall
    myWall = pickPair();
    cout << "myWall, random location: ";
    printPair(myWall);
    cout << endl;

    RoomPair myMove;
    myMove.one = myRoom;
    myMove.two = newMoveRoom;

    if (matchPair(myWall, myMove))
        cout << "there is a wall between these two rooms" << endl;
    else
        cout << "there is no wall between these two rooms" << endl;


    RoomPair myMaze[numWalls]; // array of walls in the maze

    clearWalls(myMaze);

    // walls of the maze
    cout << "uninitialized maze walls: ";
    printMaze(myMaze);
    cout << endl;

    if (checkMaze(myMaze, myMove))
        cout << "checkMaze returned true" << endl;
    else
        cout << "checkMaze returned false" << endl;

    build(myMaze); // walls at random locations in the maze
    cout << "built maze: ";
    printMaze(myMaze);
    cout << endl;

    return 0;
}
