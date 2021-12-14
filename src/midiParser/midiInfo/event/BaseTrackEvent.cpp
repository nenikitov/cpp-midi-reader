#include "BaseTrackEvent.h"

#include <stdexcept>

BaseTrackEvent::BaseTrackEvent(uint64_t delta, std::vector<uint8_t> data)
    : delta(delta),
    data(data)
{}

/*
MidiEventType BaseMidiEvent::getEventType(uint8_t status, uint8_t firstData)
{
    if (status < 0x80)
    {
        return MidiEventType::PREVIOUS;
    }

    if (status == 0xFF)
    {
        return MidiEventType::META;
    }

    if (status == 0xF0 || status == 0xF7)
    {
        return MidiEventType::SYS_EX;
    }

    if ((status & 0xF0) == 0xB0 && firstData > 0x77)
    {
        return MidiEventType::MODE;
    }

    return MidiEventType::VOICE;
}


MidiVoiceEventType BaseMidiEvent::getVoiceEventType(uint8_t status)
{
    return static_cast<MidiVoiceEventType>(status & 0xf0);
}

MidiModeEventType BaseMidiEvent::getModeEventType(uint8_t firstData)
{
    return static_cast<MidiModeEventType>(firstData);
}
*/
