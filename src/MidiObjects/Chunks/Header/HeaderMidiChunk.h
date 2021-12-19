#ifndef HEADER_MIDI_TRACK_H
#define HEADER_MIDI_TRACK_H


#include "MidiDivisionUnit.h"
#include "../Base/BaseMidiChunk.h"


class HeaderMidiChunk : public BaseMidiChunk
{
    public:
        HeaderMidiChunk(uint16_t format, uint16_t numTracks, MidiDivisionUnit divisionUnit, uint16_t ticksPerUnit);
        std::string toString();

    public:
        const uint16_t format;
        const uint16_t numTracks;
        const MidiDivisionUnit divisionUnit;
        const uint16_t ticksPerUnit;
};


#endif
