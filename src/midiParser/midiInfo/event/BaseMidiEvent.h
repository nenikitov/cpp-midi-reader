#ifndef BASE_MIDI_EVENT_H
#define BASE_MIDI_EVENT_H

#include <cstdint>
#include "types/MidiEventType.h"
#include "types/MidiVoiceEventType.h"
#include "types/MidiModeEventType.h"

class BaseMidiEvent
{
    public:
        static MidiEventType getEventType(uint8_t status, uint8_t firstData);
        static MidiVoiceEventType getVoiceEventType(uint8_t status);
        static MidiModeEventType getModeEventType(uint8_t firstData);

        BaseMidiEvent(uint64_t delta);
    public:
        const uint64_t delta;
};

#endif
