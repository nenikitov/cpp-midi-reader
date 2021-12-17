#ifndef BASE_MIDI_TRACK_H
#define BASE_MIDI_TRACK_H


#include "../../base/BaseMidiObject.h"


class BaseMidiTrack : public BaseMidiObject
{
    public:
        BaseMidiTrack(uint8_t data);
};


#endif
