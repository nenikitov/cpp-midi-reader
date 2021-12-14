#ifndef META_EVENT_H
#define META_EVENT_H

#include "../../BaseTrackEvent.h"

class MetaEvent : public BaseTrackEvent
{
    public:
        MetaEvent(uint64_t delta, std::vector<uint8_t> data);
};

#endif
