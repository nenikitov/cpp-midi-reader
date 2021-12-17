#ifndef BASE_MIDI_OBJECT_H
#define BASE_MIDI_OBJECT_H


#include <cstdint>
#include <string>
#include <vector>


class BaseMidiObject
{
    public:
        BaseMidiObject(std::vector<uint8_t> data);
        virtual std::string toString() = 0;

    protected:
        const std::vector<uint8_t> data;
};


#endif
