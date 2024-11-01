#include "maze.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// coordinates of a room
void printRoom(const Room& rm) {
    cout << rm.y << rm.x;
}

// if moving in the given direction keeps the mouse inside the maze
bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u': // up
            return (rm.y > 'a');
        case 'd': // down
            return (rm.y < 'a' + mazeSize - 1);
        case 'l': // left
            return (rm.x > 1);
        case 'r': // right
            return (rm.x < mazeSize);
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
            // invalid direction
            break;
    }
    return adjRoom;
}

// next move and returns the new room
const Room nextMove(const Room& currentRoom) {
    char dir;
    cout << "Enter direction (u,d,l,r) or q to quit: ";
    cin >> dir;

    if (dir == 'q') {
        return {-1, '*'};
    }

    if (!goodDirection(currentRoom, dir)) {
        cout << "Invalid direction. You can't move outside the maze." << endl;
        return currentRoom;
    }

    return createAdjacent(currentRoom, dir);
}

// if two rooms have the same coordinates
bool matchRoom(const Room& rm1, const Room& rm2) {
    return (rm1.x == rm2.x) && (rm1.y == rm2.y);
}

// random valid adjacent room to the given room
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

void printPair(const RoomPair& rp) {
    printRoom(rp.one);
    cout << " | ";
    printRoom(rp.two);
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2) {
    return ( (matchRoom(rp1.one, rp2.one) && matchRoom(rp1.two, rp2.two)) ||
             (matchRoom(rp1.one, rp2.two) && matchRoom(rp1.two, rp2.one)) );
}

const RoomPair pickPair() {
    Room rm;
    rm.x = rand() % mazeSize + 1;
    rm.y = 'a' + rand() % mazeSize;

    Room adjRm = pickAdjacent(rm);
    return {rm, adjRm};
}

void clearWalls(RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        walls[i].one = {-1, '*'};
        walls[i].two = {-1, '*'};
    }
}

bool checkMaze(const RoomPair walls[], const RoomPair &rp) {
    for (int i = 0; i < numWalls; ++i) {
        if (walls[i].one.x != -1 && matchPair(walls[i], rp)) {
            return true;
        }
    }
    return false;
}

void build(RoomPair walls[]) {
    int count = 0;
    while (count < numWalls) {
        RoomPair rp = pickPair();
        if (!checkMaze(walls, rp)) {
            walls[count++] = rp;
        }
    }
}

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
