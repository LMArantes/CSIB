#include "maze.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// location of the room
void printRoom(const Room &rm) {
    cout << rm.y << rm.x;
}

// moving in the given direction keeps inside the maze
bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u': // Up
            return rm.y > 'a';
        case 'd': // Down
            return rm.y < 'a' + mazeSize - 1;
        case 'l': // Left
            return rm.x > 1;
        case 'r': // Right
            return rm.x < mazeSize;
        default:
            return false;
    }
}

// room adjacent to the given room in the direction
Room createAdjacent(const Room &rm, const char dr) {
    Room adjRoom = rm;
    switch (dr) {
        case 'u':
            adjRoom.y--;
            break;
        case 'd':
            adjRoom.y++;
            break;
        case 'l':
            adjRoom.x--;
            break;
        case 'r':
            adjRoom.x++;
            break;
        default:
            break;
    }
    return adjRoom;
}

// random room adjacent
const Room pickAdjacent(const Room &rm) {
    char directions[] = {'u', 'd', 'l', 'r'};
    char validDirs[4];
    int count = 0;
    for (char dir : directions) {
        if (goodDirection(rm, dir)) {
            validDirs[count++] = dir;
        }
    }

    if (count == 0) {
        return rm;
    }

    char randomDir = validDirs[rand() % count];
    return createAdjacent(rm, randomDir);
}

// coordinates of two rooms match
bool matchRoom(const Room &rm1, const Room &rm2) {
    return (rm1.x == rm2.x) && (rm1.y == rm2.y);
}

// wall
void printPair(const RoomPair &rp) {
    printRoom(rp.one);
    cout << " | ";
    printRoom(rp.two);
}

// if two walls are the same
bool matchPair(const RoomPair &rp1, const RoomPair &rp2) {
    return ((matchRoom(rp1.one, rp2.one) && matchRoom(rp1.two, rp2.two)) ||
            (matchRoom(rp1.one, rp2.two) && matchRoom(rp1.two, rp2.one)));
}

// random wall in the maze
const RoomPair pickPair() {
    Room rm;
    rm.x = rand() % mazeSize + 1;
    rm.y = 'a' + rand() % mazeSize;

    Room adjRm = pickAdjacent(rm);
    return {rm, adjRm};
}

// array of walls to default values
void clearWalls(RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        walls[i].one = {-1, '*'};
        walls[i].two = {-1, '*'};
    }
}

// wall exists in the maze
bool checkMaze(const RoomPair walls[], const RoomPair &rp) {
    for (int i = 0; i < numWalls; ++i) {
        if (walls[i].one.x != -1 && matchPair(walls[i], rp)) {
            return true;
        }
    }
    return false;
}

// walls at random locations
void build(RoomPair walls[]) {
    int count = 0;
    while (count < numWalls) {
        RoomPair rp = pickPair();
        if (!checkMaze(walls, rp)) {
            walls[count++] = rp;
        }
    }
}

// all the wall in the maze
void printMaze(const RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        if (walls[i].one.x != -1) {
            cout << "[";
            printPair(walls[i]);
            cout << "]";
        }
    }
    cout << endl;
}

const Room nextMove(const Room &currentRoom) {
    char dir;
    cout << "Enter direction (u,d,l,r), p to print walls, or q to quit: ";
    cin >> dir;

    if (dir == 'q') {
        return {-1, '*'};
    }
    if (dir == 'p') {
        return {-2, '*'};
    }

    if (!goodDirection(currentRoom, dir)) {
        cout << "Invalid direction. You can't move outside the maze." << endl;
        return currentRoom;
    }

    return createAdjacent(currentRoom, dir);
}
