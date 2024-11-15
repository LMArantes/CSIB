#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Room {
public:
    // constructor
    Room();

    Room(int x, char y);

    void pick();                // random room
    const Room pickAdjacent();  // random adjacent room
    const Room nextMove() const; // next move
    void print() const;         // room coordinates

    void makeStartRoom();
    void makeCheeseRoom();

    friend bool matchRoom(const Room&, const Room&);

private:
    bool goodDirection(const char) const;    // direction is valid
    const Room createAdjacent(const char) const; // adjacent room

    static const int mazeSize_ = 5; // 5x5
    int x_;
    char y_;
};

class RoomPair {
public:
    // constructor
    RoomPair();

    RoomPair(const Room& one, const Room& two);

    void pick();
    void print() const;

    friend bool matchPair(const RoomPair&, const RoomPair&);

private:
    Room one_;
    Room two_;
};

class Maze {
public:
    Maze();

    void print() const;        // walls and current mouse location
    void build();
    void start();
    bool move(const Room&);
    const Room getCurrentRoom(); // mouse location

private:
    bool checkMaze(const RoomPair&) const;

    static const int numWalls_ = 8;
    RoomPair walls_[numWalls_];
    Room currentRoom_;
};

#endif // MAZE_HPP_
