#ifndef HEADER_MIDI_TRACK_H
#define HEADER_MIDI_TRACK_H


#include "MidiDivisionType.h"
#include "../base/BaseMidiTrack.h"


class HeaderMidiTrack : public BaseMidiTrack
{
    public:
        HeaderMidiTrack(u_int8_t data);
        uint16_t getMidiFormat();
        uint16_t getNumTracks();
        MidiDivisionType getDivisionType();
        uint16_t getTicks();
    private:
        uint16_t midiFormat;
};


#endif
