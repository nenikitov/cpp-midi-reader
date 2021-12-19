#include "HeaderMidiTrack.h"
#include <sstream>
#include <iostream>
#include "../../../BinaryReader/Stream/BinaryStreamReader.h"


MidiDivisionUnit computeDivisionUnit(uint16_t division)
{
    return static_cast<MidiDivisionUnit>(division > 0x7FFF);
}

uint16_t computeTicksPerUnit(uint16_t division)
{
    MidiDivisionUnit unit = computeDivisionUnit(division);

    switch (unit)
    {
        case MidiDivisionUnit::QUARTER_NOTE:
            return (division & 0x7FFF);
        case MidiDivisionUnit::SECOND:
        {
            uint8_t frames = -(((division & 0x7F00) >> 8) + 0x80);
            uint8_t ticksPerFrame = (division & 0x00FF);
            return frames * ticksPerFrame;
        }
        default:
            return 0;
    }
}

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
}

HeaderMidiTrack::HeaderMidiTrack(std::vector<uint8_t> data)
    : BaseMidiTrack(data)
{
    // Check if the data passed it correct size for the header chunk
    if (this->data.size() != 6)
    {
        throw std::invalid_argument("Header chunk data should be exactly 6 bytes in length");
    }

    // Read the data
    BinaryStreamReader r(data);

    // Midi format
    this->midiFormat = r.readRaw<uint16_t>();
    if (this->midiFormat > 2)
    {
        throw std::invalid_argument("Invalid midi file type, it can only be 0, 1, or 2");
    }

    // Number of tracks
    this->numTracks = r.readRaw<uint16_t>();

    // Division and tick duration
    uint16_t division = r.readRaw<uint16_t>();
    this->divisionUnit = computeDivisionUnit(division);
    this->ticksPerUnit = computeTicksPerUnit(division);
}


std::string HeaderMidiTrack::toString()
{
    std::stringstream ss;

    ss << "MIDI file type:   " << this->midiFormat << std::endl;
    ss << "Number of tracks: " << this->numTracks << std::endl;
    ss << "Unit of time:     " << computeDivisionUnitName(this->divisionUnit) << std::endl;
    ss << "Ticks per unit:   " << this->ticksPerUnit << std::endl;

    return ss.str();
}
