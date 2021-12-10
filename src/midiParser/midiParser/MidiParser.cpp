#include "MidiParser.h"

#include <sstream>
#include <iostream>
#include <stdexcept>

MidiData MidiParser::parseMidi(std::vector<uint8_t> bytes)
{
    MidiHeader header = MidiParser::parseHeader(bytes);
    std::cout << static_cast<int>(header.type) << " " << header.ticksPerQuarter << std::endl;

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
    // Header chunk header beginning
    std::string chunkHeader = MidiParser::readString(bytes, 4);
    if (chunkHeader != "MThd")
    {
        throw std::invalid_argument("Invalid chunk header beginning");
    }

    // Header chunk length
    uint32_t chunkLength = MidiParser::read32UInt(bytes);
    if (chunkLength != 6)
    {
        throw std::invalid_argument("Invalid chunk header length");
    }

    // Header chunk info
    uint16_t midiFormat = MidiParser::read16Uint(bytes);
    if (midiFormat > 2)
    {
        throw std::invalid_argument("Invalid midi format");
    }

    // Track number
    MidiParser::read16Uint(bytes);

    // Division
    uint16_t division = MidiParser::read16Uint(bytes);

    return MidiHeader(static_cast<MidiType>(midiFormat), division);
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

uint16_t MidiParser::read16Uint(std::vector<uint8_t>& bytes)
{
    return uint16_t(MidiParser::readNumber(bytes, 2));
}

uint32_t MidiParser::read32UInt(std::vector<uint8_t>& bytes)
{
    return uint32_t(MidiParser::readNumber(bytes, 4));
}

uint64_t MidiParser::readNumber(std::vector<uint8_t>& bytes, int numBytes)
{
    uint64_t result = 0;

    for (int i = 0; i < numBytes; i++)
    {
        result |= MidiParser::shiftBytes(bytes) << ((numBytes - 1 - i) * 8);
    }

    return result;
}