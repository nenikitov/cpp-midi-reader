#ifndef MIDI_PARSER_H
#define MIDI_PARSER_H

#include <vector>
#include <cstdint>
#include "../../midiInfo/full/MidiData.h"

class MidiParser
{
    public:
        static MidiData parseMidi(std::vector<uint8_t> bytes);
    private:
        MidiParser();
        static MidiHeader parseHeader(std::vector<uint8_t>& bytes);
        static MidiTrack parseTrack(std::vector<uint8_t>& bytes);
};

#endif
