#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <cstdlib>
#include <ctime>

const int mazeSize = 5;
const int numWalls = 8;


struct Room {
    int x;   // horizontal
    char y;  // Vertical
};

const Room startRoom = {1, 'a'};
const Room cheeseRoom = {mazeSize, 'a' + mazeSize - 1};

struct RoomPair {
    Room one;
    Room two;
};


void clearWalls(RoomPair walls[]);

bool goodDirection(const Room &rm, const char dr);

Room createAdjacent(const Room &rm, const char dr);

const Room pickAdjacent(const Room &rm);

const RoomPair pickPair();

bool matchRoom(const Room &rm1, const Room &rm2);

bool matchPair(const RoomPair &rp1, const RoomPair &rp2);

bool checkMaze(const RoomPair walls[], const RoomPair &rp);

void build(RoomPair walls[]);

void printRoom(const Room &rm);

void printPair(const RoomPair &rp);

void printMaze(const RoomPair walls[]);


// asks for direction and generates next
const Room nextMove(const Room &currentRoom);

#endif
