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
        T readNumber();
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
T BinaryStreamReader::readNumber()
{
    const size_t typeSize = sizeof(T);

    union
    {
        T t;
        uint8_t b[typeSize];
    } data;

    for (int i = typeSize - 1; i >= 0; i--)
    {
        data.b[i] = shiftByte();
    }

    return data.t;
};

#endif
