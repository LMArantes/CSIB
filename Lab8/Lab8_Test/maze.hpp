#include <cstdlib>
#include <ctime>

#ifndef MAZE_HPP_
#define MAZE_HPP_

const int mazeSize = 5;
const int numWalls = 8;


struct Room {
    int x;
    char y;
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize - 1 };


struct RoomPair {
    Room one;
    Room two;
};

void clearWalls(RoomPair[]);

bool goodDirection(const Room &rm, const char dr);

Room createAdjacent(const Room &rm, const char dr);

const Room pickAdjacent(const Room &rm);

const RoomPair pickPair();

bool matchRoom(const Room&, const Room&);

bool matchPair(const RoomPair&, const RoomPair&);

bool checkMaze(const RoomPair[], const RoomPair &rp);

void build(RoomPair[]);

void printRoom(const Room&);
void printPair(const RoomPair&);
void printMaze(const RoomPair[]);


const Room nextMove(const Room& currentRoom);

#endif
