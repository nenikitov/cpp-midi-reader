#ifndef MIDI_VOICE_EVENT_TYPE
#define MIDI_VOICE_EVENT_TYPE

enum class MidiVoiceEventType
{
    NOTE_OFF         = 0x80,
    NOTE_ON          = 0x90,
    KEY_PRESSURE     = 0xA0,
    CONTROLLER       = 0xC0,
    CHANNEL_PRESSURE = 0xD0,
    PITCH_BEND       = 0xE0
};

#endif
