#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "Room.h"

class Floor {
public:
    explicit Floor(int number);
    ~Floor();

    int GetNumber() const;
    void AddRoom(Room* r);
    const std::vector<Room*>& GetRooms() const;

    void SetStart(Room* r);
    Room* GetStart() const;

private:
    int _number;
    std::vector<Room*> _rooms;
    Room* _startRoom = nullptr;
};

#endif
