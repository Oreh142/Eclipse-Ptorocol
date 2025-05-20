#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemCategory {
    Consumable,   
    Equipment,    
    Throwing,     
    Quest         
};

class Item {
public:
    Item(const std::string& name, const std::string& description)
        : _name(name), _description(description) {}
    virtual ~Item() = default;

    const std::string& GetName() const { return _name; }
    const std::string& GetDescription() const { return _description; }

    virtual ItemCategory GetCategory() const = 0;

private:
    std::string _name;
    std::string _description;
};

#endif
