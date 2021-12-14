#ifndef BASE_TRACK_EVENT_H
#define BASE_TRACK_EVENT_H

#include <cstdint>
#include <vector>

class BaseTrackEvent
{
    public:
        BaseTrackEvent(uint64_t delta, std::vector<uint8_t> data);
    public:
        const uint64_t delta;
        const std::vector<uint8_t> data;
};

#endif
