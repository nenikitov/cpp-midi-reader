#include "FileReader.h"

#include <fstream>

std::vector<unsigned char> FileReader::readFile(const char* filePath)
{
    std::fstream fileData(filePath, std::fstream::in);

    std::vector<unsigned char> bytes;

    unsigned char currentByte;
	while (fileData >> std::noskipws >> currentByte)
	{
        bytes.push_back(currentByte);
    }

    fileData.close();
    return bytes;
}
