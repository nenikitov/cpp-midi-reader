#include "BinaryStreamReader.h"


BinaryStreamReader::BinaryStreamReader(std::vector<uint8_t> bytes)
    : bytes(bytes)
    {};


uint8_t BinaryStreamReader::shiftByte()
{
    uint8_t byte = bytes[0];
    this->bytes.erase(this->bytes.begin());
    return byte;
};