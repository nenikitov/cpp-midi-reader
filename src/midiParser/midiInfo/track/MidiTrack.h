#ifndef MIDI_TRACK_H
#define MIDI_TRACK

#include <vector>
#include "../event/MidiEvent.h"

class MidiTrack
{
    public:
        MidiTrack(std::vector<MidiEvent> events);
    public:
        const std::vector<MidiEvent> events;
};

#endif
