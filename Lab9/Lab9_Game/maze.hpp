// maze.hpp

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Room {
public:
    Room();                   //  constructors
    Room(int x, char y);

    void pick();              // random room
    const Room pickAdjacent();
    const Room nextMove() const; // the next move
    void print() const;       // coordinates

    void makeStartRoom();     //start room
    void makeCheeseRoom();

    int getX() const;         // x
    char getY() const;        // y

    friend bool matchRoom(const Room&, const Room&);

private:
    bool goodDirection(const char) const; // good direction
    const Room createAdjacent(const char) const;

    static const int mazeSize_ = 5;
    int x_;
    char y_;
};

class RoomPair {
public:
    RoomPair();                             // construtors
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

    void print() const;
    void build();
    void start();
    bool move(const Room&);
    const Room getCurrentRoom(); // mouse location

private:
    bool checkMaze(const RoomPair&) const;

    static const int numWalls_ = 8;
    RoomPair walls_[numWalls_];
    Room currentRoom_;               // current mouse location
};

#endif // MAZE_HPP_
