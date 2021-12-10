#include "MidiParser.h"

#include <sstream>
#include <iostream>

MidiData MidiParser::parseMidi(std::vector<uint8_t> bytes)
{
    MidiHeader header = MidiParser::parseHeader(bytes);

    return MidiData(MidiHeader(MidiType::MULTI_TRACK, 100), std::vector<MidiTrack>());
}

uint8_t MidiParser::shiftBytes(std::vector<uint8_t>& bytes)
{
    uint8_t byte = bytes[0];
    bytes.erase(bytes.begin());
    return byte;
}

MidiHeader MidiParser::parseHeader(std::vector<uint8_t>& bytes)
{
    std::string chunkHeader = MidiParser::readString(bytes, 4);
    std::cout << chunkHeader << std::endl;
}

std::string MidiParser::readString(std::vector<uint8_t>& bytes, int length)
{
    std::stringstream ss;

    for (int i = 0; i < length; i++)
    {
        ss << MidiParser::shiftBytes(bytes);
    }

    return ss.str();
}
