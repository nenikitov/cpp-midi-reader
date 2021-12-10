#ifndef BINARY_READER_H
#define BINARY_READER_H

#include <vector>
#include <cstdint>

class BinaryReader
{
    private:
        BinaryReader();
    public:
        static std::vector<uint8_t> readFile(const char* filePath);
};

#endif
