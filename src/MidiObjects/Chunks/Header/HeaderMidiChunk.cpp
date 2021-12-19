#include "HeaderMidiChunk.h"
#include <sstream>
#include <iostream>
#include "../../../BinaryReader/Stream/BinaryStreamReader.h"


const char* computeDivisionUnitName(MidiDivisionUnit unit)
{
    switch (unit)
    {
        case MidiDivisionUnit::QUARTER_NOTE:
            return "Quarter note";
        case MidiDivisionUnit::SECOND:
            return "Second";
        default:
            return "UNKNOWN";
    }
};

HeaderMidiChunk::HeaderMidiChunk(uint16_t format, uint16_t numTracks, MidiDivisionUnit divisionUnit, uint16_t ticksPerUnit)
    : format(format),
    numTracks(numTracks),
    divisionUnit(divisionUnit),
    ticksPerUnit(ticksPerUnit)
{};


std::string HeaderMidiChunk::toString()
{
    std::stringstream ss;

    ss << "MIDI file type:   " << this->format << std::endl;
    ss << "Number of tracks: " << this->numTracks << std::endl;
    ss << "Unit of time:     " << computeDivisionUnitName(this->divisionUnit) << std::endl;
    ss << "Ticks per unit:   " << this->ticksPerUnit << std::endl;

    return ss.str();
};
