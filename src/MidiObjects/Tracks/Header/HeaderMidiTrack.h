#ifndef HEADER_MIDI_TRACK_H
#define HEADER_MIDI_TRACK_H


#include "MidiDivisionUnit.h"
#include "../Base/BaseMidiTrack.h"


class HeaderMidiTrack : public BaseMidiTrack
{
    public:
        HeaderMidiTrack(std::vector<u_int8_t> data);
        uint16_t getMidiFormat();
        uint16_t getNumTracks();
        MidiDivisionUnit getDivisionUnit();
        uint16_t getTicksPerUnit();
    private:
        uint16_t midiFormat;
        uint16_t numTracks;
        MidiDivisionUnit divisionUnit;
        uint16_t ticksPerUnit;
};


#endif
