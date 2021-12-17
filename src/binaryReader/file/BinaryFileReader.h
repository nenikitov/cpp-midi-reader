#ifndef BINARY_FILE_READER_H
#define BINARY_FILE_READER_H


#include <vector>
#include <cstdint>
#include <string>


class BinaryFileReader
{
    public:
        static std::vector<uint8_t> readFile(const char* filePath);

        BinaryFileReader() = delete;
        BinaryFileReader(const BinaryFileReader&) = delete;
        ~BinaryFileReader() = delete;
        BinaryFileReader& operator = (BinaryFileReader const&) = delete;
};


#endif
