#ifndef BINARY_STREAM_READER_H
#define BINARY_STREAM_READER_H


#include <cstdint>
#include <string>
#include <vector>
#include <iostream>


class BinaryStreamReader
{
    public:
        BinaryStreamReader(std::vector<uint8_t> bytes);

        template<class T>
        T readRaw();
        std::string readString(size_t length);
        uint64_t readVariableLength();

        BinaryStreamReader(const BinaryStreamReader&) = delete;
        BinaryStreamReader& operator = (BinaryStreamReader const&) = delete;

    private:
        uint8_t shiftByte();
    private:
        std::vector<uint8_t> bytes;
};


template<class T>
T BinaryStreamReader::readRaw()
{
    const size_t typeSize = sizeof(T);

    union
    {
        T t;
        uint8_t b[typeSize];
    } data;

    for (size_t i = 0; i < typeSize; i++)
    {
        size_t byteIndex = typeSize - 1 - i;
        data.b[byteIndex] = this->shiftByte();
    }

    return data.t;
};

#endif
