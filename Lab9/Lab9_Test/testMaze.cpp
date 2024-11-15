#include <iostream>
#include "maze.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // seed set as 1
    srand(1);

    Room myRoom; // room
    cout << "myRoom, default location: ";
    myRoom.print();
    cout << endl;

    myRoom.pick();
    cout << "myRoom, random location: ";
    myRoom.print();
    cout << endl;

    Room startRoom;
    startRoom.makeStartRoom();
    cout << "start room: ";
    startRoom.print();
    cout << endl;

    Room cheeseRoom;
    cheeseRoom.makeCheeseRoom();
    cout << "cheese room: ";
    cheeseRoom.print();
    cout << endl;

    Room newMoveRoom = myRoom.nextMove(); // new adjacent room
    cout << "user selected adjacent room: ";
    newMoveRoom.print();
    cout << endl;

    if (matchRoom(myRoom, newMoveRoom))
        cout << "myRoom is the same as newMoveRoom" << endl;
    else
        cout << "myRoom is not the same as newMoveRoom" << endl;

    RoomPair myPair;
    cout << "myPair, default location: ";
    myPair.print();
    cout << endl;

    RoomPair otherPair(myRoom, newMoveRoom);
    cout << "pair of myRoom, newMoveRoom: ";
    otherPair.print();
    cout << endl;

    myPair.pick();
    cout << "random room pair: ";
    myPair.print();
    cout << endl;

    if (matchPair(myPair, otherPair))
        cout << "myPair is the same as otherPair" << endl;
    else
        cout << "myPair is not the same as otherPair" << endl;

    Maze myMaze;
    cout << "maze with no walls: ";
    myMaze.print();

    myMaze.start();

    myMaze.build();
    cout << "maze with walls: ";
    myMaze.print();

    myRoom = myMaze.getCurrentRoom();
    cout << "maze current room: ";
    myRoom.print();
    cout << endl;

    newMoveRoom = myRoom.nextMove();

    if (myMaze.move(newMoveRoom))
        cout << "move to newMoveRoom is successful" << endl;
    else
        cout << "move to newMoveRoom failed" << endl;

    myRoom = myMaze.getCurrentRoom();
    cout << "maze current room: ";
    myRoom.print();
    cout << endl;

    return 0;
}
