#ifndef BASE_MIDI_OBJECT_H
#define BASE_MIDI_OBJECT_H


#include <cstdint>
#include <string>
#include <vector>


class BaseMidiObject
{
    public:
        virtual std::string toString() = 0;
};


#endif
