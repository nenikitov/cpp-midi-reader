#include "MetaEvent.h"

MetaEvent::MetaEvent(uint64_t delta, std::vector<uint8_t> data)
    : BaseTrackEvent(delta, data)
{}
