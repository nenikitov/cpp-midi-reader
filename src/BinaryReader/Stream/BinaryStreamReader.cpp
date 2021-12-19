#include "BinaryStreamReader.h"
#include <sstream>


BinaryStreamReader::BinaryStreamReader(std::vector<uint8_t> bytes)
    : bytes(bytes)
{};


uint8_t BinaryStreamReader::shiftByte()
{
    uint8_t byte = bytes[0];
    this->bytes.erase(this->bytes.begin());
    return byte;
};

std::string BinaryStreamReader::readString(size_t length)
{
    std::stringstream ss;

    for (size_t i = 0; i < length; i++)
    {
        ss << this->shiftByte() << " ";
    }

    return ss.str();
};

uint64_t BinaryStreamReader::readVariableLength()
{
    uint64_t result = 0;
    const size_t resultLastByte = sizeof(result) - 1;

    for (int i = 0; i < 8; i++)
    {
        uint8_t byte = this->shiftByte();

        result |= (byte & 0b01111111) << (resultLastByte - i);

        if (! (byte & 0b10000000))
        {
            return result;
        }
    }

    throw std::invalid_argument("Midi delta time - unable to parse delta time");
}
