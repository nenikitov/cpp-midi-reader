#ifndef MIDI_TRACK_H
#define MIDI_TRACK

#include <vector>
#include "../event/BaseTrackEvent.h"

class MidiTrack
{
    public:
        MidiTrack(std::vector<BaseTrackEvent> events);
    public:
        const std::vector<BaseTrackEvent> events;
};

#endif
