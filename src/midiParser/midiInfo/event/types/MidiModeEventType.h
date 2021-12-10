#ifndef MIDI_MODE_EVENT_TYPE
#define MIDI_MODE_EVENT_TYPE

enum class MidiModeEventType
{
    SOUND_OFF        = 0x78,
    CONTROLLER_RESET = 0x79,
    DEVICE_CONTROL   = 0x7A,
    NOTES_OFF        = 0x7B,
    OMNI_MODE_OFF    = 0x7C,
    OMNI_MODE_ON     = 0x7D,
    MONO_MODE_ON     = 0x7E,
    POLY_MODE_ON     = 0x7F
}

#endif
