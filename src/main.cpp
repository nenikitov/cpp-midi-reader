#include <iostream>
#include "BinaryReader/File/BinaryFileReader.h"
#include "BinaryReader/Stream/BinaryStreamReader.h"
#include "MidiObjects/Chunks/Header/HeaderMidiChunk.h"


int main()
{
    const char* path = "res/twinkle.mid";

    std::vector<uint8_t> bytes = BinaryFileReader::readFile(path);

    BinaryStreamReader r(bytes);

    HeaderMidiChunk t(10, 12, MidiDivisionUnit::QUARTER_NOTE, 2000);

    std::cout << t.toString() << std::endl;

    /*
    std::cout << r.readString(4) << std::endl;
    std::cout << r.readRaw<uint32_t>() << std::endl;
    std::cout << r.readRaw<uint16_t>() << std::endl;
    std::cout << r.readRaw<uint16_t>() << std::endl;
    std::cout << r.readRaw<uint16_t>() << std::endl;
    std::cout << r.readString(4) << std::endl;
    */

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
