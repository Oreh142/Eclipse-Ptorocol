#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <chrono>

class Note {
public:
    Note(int id, const std::string& content);

    int GetId() const;
    const std::string& GetContent() const;
    std::chrono::system_clock::time_point GetFoundAt() const;

private:
    int   _id;
    std::string _content;
    std::chrono::system_clock::time_point _foundAt;
};

#endif
