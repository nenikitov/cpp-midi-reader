#include <iostream>
#include "binaryReader/BinaryReader.h"
#include "midiParser/midiParser/MidiParser.h"


int main()
{
    const char* path = "res/twinkle.mid";

    std::vector<uint8_t> bytes = BinaryReader::readFile(path);
    MidiParser::parseMidi(bytes);

    /*
    for (int i = 0; i < bytes.size(); i++)
    {
        std::cout << bytes[i] << "-" << int(bytes[i]) << ", ";
    }
    std::cout << std::endl;
    */
}
