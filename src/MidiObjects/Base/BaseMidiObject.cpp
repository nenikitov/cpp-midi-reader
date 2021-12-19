#include "BaseMidiObject.h"
#include <sstream>


BaseMidiObject::BaseMidiObject(std::vector<uint8_t> data)
    : data(data)
{};

std::string BaseMidiObject::toString()
{
    std::stringstream ss;

    for (uint8_t byte : this->data)
    {
        ss << int(byte) << " ";
    }

    return ss.str();
}
