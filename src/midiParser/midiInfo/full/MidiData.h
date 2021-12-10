#ifndef MIDI_DATA_H
#define MIDI_DATA_H

#include <vector>
#include "../header/MidiHeader.h"
#include "../track/MidiTrack.h"

class MidiData
{
    public:
        MidiData(MidiHeader header, std::vector<MidiTrack> tracks);
    public:
        const MidiHeader header;
        const std::vector<MidiTrack> tracks;
};

#endif
