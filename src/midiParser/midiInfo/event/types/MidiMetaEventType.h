#ifndef MIDI_META_EVENT_TYPE
#define MIDI_META_EVENT_TYPE

enum class MidiMetaEventType
{
    TRACK_NUMBER    = 0x00,
    TEXT            = 0x01,
    COPYRIGHT       = 0x02,
    TRACK_NAME      = 0x03,
    INSTRUMENT_NAME = 0x04,
    LYRIC           = 0x05,
    MARKER          = 0x06,
    CUE             = 0x07,
    CHANNEL_PREFIX  = 0x20,
    TRACK_END       = 0x2F,
    SET_TEMPO       = 0x51,
    SMTPE_OFFSET    = 0x54,
    TIME_SIGNATURE  = 0x58,
    KEY_SIGNATURE   = 0x59,
}

#endif
