#ifndef MIDI_TRACK_H
#define MIDI_TRACK

#include <vector>
#include "../event/BaseMidiEvent.h"

class MidiTrack
{
    public:
        MidiTrack(std::vector<BaseMidiEvent> events);
    public:
        const std::vector<BaseMidiEvent> events;
};

#endif
