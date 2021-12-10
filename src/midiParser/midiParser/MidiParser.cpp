#include "MidiParser.h"

#include <sstream>
#include <iostream>
#include <stdexcept>

MidiData MidiParser::parseMidi(std::vector<uint8_t> bytes)
{
    MidiHeader header = MidiParser::parseHeader(bytes);
    std::cout << static_cast<int>(header.type) << " " << header.ticksPerQuarter << std::endl;

    MidiTrack track = MidiParser::parseTrack(bytes);

    return MidiData(MidiHeader(MidiType::MULTI_TRACK, 100), std::vector<MidiTrack>());
}

MidiHeader MidiParser::parseHeader(std::vector<uint8_t>& bytes)
{
    // Chunk header
    std::string chunkHeader = MidiParser::readString(bytes, 4);
    if (chunkHeader != "MThd")
    {
        // Invalid if does not begin with MThd
        throw std::invalid_argument("Header chunk - Invalid chunk header");
    }

    // Chunk length
    uint32_t chunkLength = MidiParser::read32UInt(bytes);
    if (chunkLength != 6)
    {
        // Invalid if has a length other than 6
        throw std::invalid_argument("Header chunk - Invalid chunk length");
    }

    // Midi format
    uint16_t midiFormat = MidiParser::read16Uint(bytes);
    if (midiFormat > 2)
    {
        // Invalid if file format is not 0, 1 or 2
        throw std::invalid_argument("Header chunk - Invalid midi format");
    }

    // Number of tracks
    MidiParser::read16Uint(bytes);

    // Division
    uint16_t division = MidiParser::read16Uint(bytes);

    return MidiHeader(static_cast<MidiType>(midiFormat), division);
}


MidiTrack MidiParser::parseTrack(std::vector<uint8_t>& bytes)
{
    // Chunk header
    std::string chunkHeader = MidiParser::readString(bytes, 4);
    if (chunkHeader != "MTrk")
    {
        // Invalid if does not begin with MTrk
        throw std::invalid_argument("Track chunk - Invalid chunk header");
    }

    // Chunk length
    uint32_t chunkLength = MidiParser::read32UInt(bytes);

    // Chunk data - events
    std::vector<MidiEvent> events;

    events.push_back(MidiParser::parseEvent(bytes));

    return MidiTrack(events);
}


MidiEvent MidiParser::parseEvent(std::vector<uint8_t>& bytes)
{
    uint64_t delta = MidiParser::readVariableLength(bytes);

    std::cout << delta << std::endl;

    return MidiEvent(delta);
}


uint8_t MidiParser::shiftBytes(std::vector<uint8_t>& bytes)
{
    uint8_t byte = bytes[0];
    bytes.erase(bytes.begin());
    return byte;
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
    return uint16_t(MidiParser::readNumber(bytes, 16));
}

uint32_t MidiParser::read32UInt(std::vector<uint8_t>& bytes)
{
    return uint32_t(MidiParser::readNumber(bytes, 32));
}

uint64_t MidiParser::readNumber(std::vector<uint8_t>& bytes, int nimBits)
{
    uint64_t result = 0;

    for (int i = 0; i < nimBits; i += 8)
    {
        result |= MidiParser::shiftBytes(bytes) << (nimBits - 8 - i);
    }

    return result;
}


uint64_t MidiParser::readVariableLength(std::vector<uint8_t>& bytes)
{
    uint64_t result = 0;

    for (int i = 0; i < 64; i += 8)
    {
        uint8_t byte = MidiParser::shiftBytes(bytes);

        result |= (byte & 0x0fff) << (56 - i);

        if (! (byte & 0xf000))
        {
            return result;
        }
    }

    throw std::invalid_argument("Midi delta time - unable to parse delta time");
}
