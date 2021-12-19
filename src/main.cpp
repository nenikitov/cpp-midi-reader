#include <iostream>
#include "BinaryReader/File/BinaryFileReader.h"
#include "BinaryReader/Stream/BinaryStreamReader.h"
#include "MidiObjects/Tracks/Header/HeaderMidiTrack.h"


int main()
{
    const char* path = "res/twinkle.mid";

    std::vector<uint8_t> bytes = BinaryFileReader::readFile(path);

    BinaryStreamReader r(bytes);

    std::vector<uint8_t> a;
    // Type
    a.push_back(0x00);
    a.push_back(0x00);
    // Tracks
    a.push_back(0x00);
    a.push_back(0x01);
    // Division
    a.push_back(0xE7);
    a.push_back(0x28);

    HeaderMidiTrack t(a);

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
