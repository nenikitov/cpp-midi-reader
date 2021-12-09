#include <iostream>
#include "fileReader/FileReader.h"


int main()
{
    const char* path = "midi/twinkle.mid";

    std::vector bytes = FileReader::readFile(path);

    for (int i = 0; i < bytes.size(); i++)
    {
        std::cout << bytes[i] << ", ";
    }

    std::cout << std::endl;
}
