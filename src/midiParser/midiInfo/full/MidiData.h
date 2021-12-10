#ifndef MIDI_DATA_H
#define MIDI_DATA_H

#include "../header/MidiHeader.h"

class MidiData
{
    public:
        MidiData(MidiHeader header);
    public:
        const MidiHeader const header;
};

#endif
