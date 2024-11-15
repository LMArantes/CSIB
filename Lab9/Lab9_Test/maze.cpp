#include "maze.hpp"

// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


// constructor
Room::Room() : x_(-1), y_('*') {}

Room::Room(int x, char y) : x_(x), y_(y) {}

// random room
void Room::pick() {
    x_ = rand() % mazeSize_ + 1;
    y_ = 'a' + rand() % mazeSize_;
}

bool Room::goodDirection(const char dir) const {
    switch (dir) {
        case 'u':
            return y_ > 'a';
        case 'd':
            return y_ < 'a' + mazeSize_ - 1;
        case 'l':
            return x_ > 1;
        case 'r':
            return x_ < mazeSize_;
        default:
            return false;
    }
}

const Room Room::createAdjacent(const char dir) const {
    Room adjRoom = *this;
    switch (dir) {
        case 'u':
            adjRoom.y_--;
            break;
        case 'd':
            adjRoom.y_++;
            break;
        case 'l':
            adjRoom.x_--;
            break;
        case 'r':
            adjRoom.x_++;
            break;
        default:
            break;
    }
    return adjRoom;
}

// random adjacent room
const Room Room::pickAdjacent() {
    char directions[] = {'u', 'd', 'l', 'r'};
    vector<char> validDirs;

    for (char dir : directions) {
        if (goodDirection(dir)) {
            validDirs.push_back(dir);
        }
    }

    // no valid directions
    if (validDirs.empty()) {
        return *this;
    }

    char randomDir = validDirs[rand() % validDirs.size()];
    return createAdjacent(randomDir);
}

// next move
const Room Room::nextMove() const {
    char dir;
    cout << "Enter direction (u,d,l,r) or q to quit: ";
    cin >> dir;

    if (dir == 'q') {
        return Room(-1, '*'); // quit
    }

    if (!goodDirection(dir)) {
        cout << "Invalid direction. You can't move outside the maze." << endl;
        return *this; // current room
    }

    return createAdjacent(dir);
}

// coordinates
void Room::print() const {
    cout << y_ << x_;
}

void Room::makeStartRoom() {
    x_ = 1;
    y_ = 'a';
}

void Room::makeCheeseRoom() {
    x_ = mazeSize_;
    y_ = 'a' + mazeSize_ - 1;
}

bool matchRoom(const Room& r1, const Room& r2) {
    return (r1.x_ == r2.x_) && (r1.y_ == r2.y_);
}


// construtor
RoomPair::RoomPair() : one_(), two_() {}

RoomPair::RoomPair(const Room& one, const Room& two) : one_(one), two_(two) {}

void RoomPair::pick() {
    one_.pick();
    two_ = one_.pickAdjacent();
}

void RoomPair::print() const {
    one_.print();
    cout << "|";
    two_.print();
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2) {
    return (matchRoom(rp1.one_, rp2.one_) && matchRoom(rp1.two_, rp2.two_)) ||
           (matchRoom(rp1.one_, rp2.two_) && matchRoom(rp1.two_, rp2.one_));
}


// construtor
Maze::Maze() {
    for (int i = 0; i < numWalls_; ++i) {
        walls_[i] = RoomPair();
    }
    currentRoom_ = Room();
}

void Maze::print() const {
    cout << "Walls in the maze: ";
    for (int i = 0; i < numWalls_; ++i) {
        walls_[i].print();
        cout << " ";
    }
    cout << endl;
    cout << "Current mouse location: ";
    currentRoom_.print();
    cout << endl;
}

void Maze::build() {
    int count = 0;
    while (count < numWalls_) {
        RoomPair rp;
        rp.pick();
        if (!checkMaze(rp)) {
            walls_[count++] = rp;
        }
    }
}

void Maze::start() {
    currentRoom_.makeStartRoom();
}

bool Maze::move(const Room& newRoom) {
    RoomPair attemptedMove(currentRoom_, newRoom);
    if (checkMaze(attemptedMove)) {
        return false; // fail
    } else {
        currentRoom_ = newRoom;
        return true; // success
    }
}

// mouse location
const Room Maze::getCurrentRoom() {
    return currentRoom_;
}

bool Maze::checkMaze(const RoomPair& rp) const {
    for (int i = 0; i < numWalls_; ++i) {
        if (matchPair(walls_[i], rp)) {
            return true;
        }
    }
    return false;
}
