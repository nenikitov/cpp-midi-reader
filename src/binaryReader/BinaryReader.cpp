#include "BinaryReader.h"

#include <fstream>

std::vector<uint8_t> BinaryReader::readFile(const char* filePath)
{
    std::fstream fileData(filePath, std::fstream::in | std::ifstream::binary);

    std::vector<uint8_t> bytes;

    uint8_t currentByte;
	while (fileData >> currentByte)
	{
        bytes.push_back(currentByte);
    }

    fileData.close();
    return bytes;
}
