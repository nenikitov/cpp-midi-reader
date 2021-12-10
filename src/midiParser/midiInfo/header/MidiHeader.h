#ifndef MIDI_HEADER_H
#define MIDI_HEADER_H

#include "MidiType.h"

class MidiHeader
{
    public:
        MidiHeader(MidiType type, int tickPerQuarter);
    public:
        const MidiType type;
        const int ticksPerQuarter;
};

#endif