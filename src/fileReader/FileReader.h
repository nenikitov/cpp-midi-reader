#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>

class FileReader
{
    private:
        FileReader();
    public:
        static std::vector<unsigned char> readFile(const char* filePath);
};

#endif
