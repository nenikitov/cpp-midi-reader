#ifndef BASE_MIDI_OBJECT_H
#define BASE_MIDI_OBJECT_H


#include <cstdint>
#include <string>


class BaseMidiObject
{
    public:
        BaseMidiObject(uint8_t data);
        virtual std::string toString() = 0;

    protected:
        const uint8_t data;
};


#endif
