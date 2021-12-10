#include <iostream>
#include "binaryReader/BinaryReader.h"


int main()
{
    const char* path = "res/twinkle.mid";

    std::vector<uint8_t> bytes = BinaryReader::readFile(path);

    for (int i = 0; i < bytes.size(); i++)
    {
        std::cout << int(bytes[i]) << ", ";
    }

    std::cout << std::endl;
}
