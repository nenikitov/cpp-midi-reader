#include <iostream>
#include "binaryReader/file/BinaryFileReader.h"
#include "binaryReader/stream/BinaryStreamReader.h"


int main()
{
    const char* path = "res/twinkle.mid";

    std::vector<uint8_t> bytes = BinaryFileReader::readFile(path);

    BinaryStreamReader r(bytes);

    std::cout << r.readRaw<int>() << std::endl;
    std::cout << r.readRaw<int>() << std::endl;

    /*
    for (size_t i = 0; i < bytes.size(); i++)
    {
        uint8_t byte = bytes[i];
        char display = (byte < ' ') ? '.' : bytes[i];

        std::cout << int(byte) << "-" << display << "\t";
    }
    std::cout << std::endl;
    */
}
