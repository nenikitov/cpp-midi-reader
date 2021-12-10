#ifndef MIDI_EVENT_H
#define MIDI_EVENT_H

#include <cstdint>

class MidiEvent
{
    public:
        MidiEvent(uint64_t delta);
    public:
        const uint64_t delta;
};

#endif
