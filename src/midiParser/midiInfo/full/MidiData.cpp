#include "MidiData.h"

MidiData::MidiData(MidiHeader header, std::vector<MidiTrack> tracks)
    : header(header), tracks(tracks)
{}
