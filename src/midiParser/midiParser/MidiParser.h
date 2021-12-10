#ifndef MIDI_PARSER_H
#define MIDI_PARSER_H

#include <vector>
#include <string>
#include <cstdint>
#include "../midiInfo/full/MidiData.h"

class MidiParser
{
    public:
        static MidiData parseMidi(std::vector<uint8_t> bytes);
    private:
        MidiParser();
        static MidiHeader parseHeader(std::vector<uint8_t>& bytes);
        static MidiTrack parseTrack(std::vector<uint8_t>& bytes);
        static MidiEvent parseEvent(std::vector<uint8_t>& bytes);
        static uint8_t shiftBytes(std::vector<uint8_t>& bytes);


        static std::string readString(std::vector<uint8_t>& bytes, int length);
        static uint16_t read16Uint(std::vector<uint8_t>& bytes);
        static uint32_t read32UInt(std::vector<uint8_t>& bytes);
        static uint64_t readNumber(std::vector<uint8_t>& bytes, int numBits);

        static uint64_t readVariableLength(std::vector<uint8_t>& bytes);
};

#endif
