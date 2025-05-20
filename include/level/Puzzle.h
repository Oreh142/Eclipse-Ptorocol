#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>
#include <optional>

class Player;
class Room;

enum class PuzzleType {
    ITEM_REQUIRED,
    ANSWER_INPUT
};

enum class RewardType {
    CHEST,
    COMPANION,
    DOOR_OPEN
};

class Puzzle {
public:
    Puzzle(PuzzleType type,
        const std::string& promptText,
        RewardType rewardType,
        int rewardTargetId);
    virtual ~Puzzle();

    PuzzleType GetType()         const;
    bool       IsSolved()        const;
    const std::string& GetPrompt() const;


    virtual bool AttemptWithItem(int itemId, Player& player, Room& room);

    virtual bool AttemptWithAnswer(const std::string& answer, Player& player, Room& room);

protected:
    void TriggerReward(Player& player, Room& room);

    PuzzleType   _type;
    std::string  _promptText;
    bool         _solved = false;
    RewardType   _rewardType;
    int          _rewardTargetId;
};

#endif
