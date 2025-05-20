#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <optional>

#include "Direction.h"
#include "Item.h"
#include "Enemy.h"
#include "Puzzle.h"
#include "Note.h"

struct Connection {
    Direction dir;
    int       roomId;   // связывает по ID, сам Map/Level потом переведёт в указатель
    bool      open = true;
};

class Room {
public:
    Room(int id,
        const std::string& name,
        const std::string& description);

    int GetId() const;
    const std::string& GetName() const;
    const std::string& GetDescription() const;

    const std::vector<Item*>& GetItems()   const;
    const std::vector<Enemy*>& GetEnemies() const;
    Puzzle* GetPuzzle()  const;   // nullptr, если нет
    const std::vector<Item*>& GetChest()   const;   // предметы в сундуке
    bool IsChestLocked() const;
    std::optional<Connection>  GetStairs() const;     // nullptr, если нет
    Note* GetNote() const;
    const std::vector<Connection>& GetConnections() const;

    std::optional<int> GetTriggerEventId() const;

    void AddItem(Item* item);
    void AddEnemy(Enemy* enemy);
    void SetPuzzle(Puzzle* p);
    void SetChest(const std::vector<Item*>& items);
    void SetChestLocked(bool locked);
    void SetStairs(const Connection& stairs);
    void AddConnection(const Connection& conn);
    void AddNote(const Note& note);
    void SetTriggerEvent(int eventId);

    bool TrySolveWithItem(int itemId, Player& player);
    bool TrySolveWithAnswer(const std::string& ans, Player& player);

private:
    int    _id;
    std::string _name;
    std::string _description;

    std::vector<Item*>  _items;
    std::vector<Enemy*> _enemies;

    Puzzle* _puzzle = nullptr;
    Note* _tine = nullptr;
    std::vector<Item*> _chestItems;
    bool _chestLocked = false;
    std::optional<Connection> _stairs;
    std::vector<Connection> _connections;
    std::optional<int> _triggerEventId;
};

#endif
