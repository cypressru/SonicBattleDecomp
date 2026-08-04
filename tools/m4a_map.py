"""Derive validated MP2K/M4A data-object starts from the verified ROM."""

from __future__ import annotations


ROM_BASE = 0x08000000
VOICEGROUP_START = 0xBF23F0
VOICEGROUP_END = 0xBF71FC
MPLAY_TABLE_START = 0xBF71FC
SONG_TABLE_START = 0xBF7244
SONG_TABLE_END = 0xBF8C4C
SAMPLE_START = 0xBF8C50
FIRST_SONG = 0xEB2650
DATA_END = 0xEEB690


def word(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 4], "little")


def derive_m4a_ranges(data: bytes) -> list[dict[str, str]]:
    if len(data) < DATA_END:
        raise ValueError("ROM is too small for the M4A data map")

    # Six MusicPlayer records, each {info pointer, track pointer, packed flags}.
    for offset in range(MPLAY_TABLE_START, SONG_TABLE_START, 12):
        if not (0x03000000 <= word(data, offset) < 0x03008000):
            raise ValueError(f"invalid gMPlayTable info pointer at 0x{offset:X}")
        if not (0x03000000 <= word(data, offset + 4) < 0x03008000):
            raise ValueError(f"invalid gMPlayTable track pointer at 0x{offset + 4:X}")

    song_pointers: list[int] = []
    for offset in range(SONG_TABLE_START, SONG_TABLE_END, 8):
        pointer = word(data, offset) - ROM_BASE
        metadata = word(data, offset + 4)
        if not (SONG_TABLE_END <= pointer < DATA_END) or metadata >= 0x01000000:
            raise ValueError(f"invalid gSongTable entry at 0x{offset:X}")
        song_pointers.append(pointer)
    if len(song_pointers) != 833:
        raise ValueError(f"expected 833 song-table entries, found {len(song_pointers)}")

    sample_pointers = sorted(
        {
            word(data, offset) - ROM_BASE
            for offset in range(VOICEGROUP_START, VOICEGROUP_END, 4)
            if SAMPLE_START <= word(data, offset) - ROM_BASE < FIRST_SONG
        }
    )
    if len(sample_pointers) != 437 or sample_pointers[0] != SAMPLE_START:
        raise ValueError("unexpected M4A direct-sound sample inventory")
    for pointer in sample_pointers:
        size = word(data, pointer + 12)
        if not size or pointer + 16 + size > FIRST_SONG:
            # Zero-length SDK wave records are valid sentinels.
            if size or pointer + 16 > FIRST_SONG:
                raise ValueError(f"invalid WaveData record at 0x{pointer:X}")

    unique_songs = sorted({pointer for pointer in song_pointers if pointer >= FIRST_SONG})
    if len(unique_songs) != 249 or unique_songs[0] != FIRST_SONG:
        raise ValueError("unexpected M4A song-object inventory")
    for pointer in unique_songs:
        track_count = data[pointer]
        voicegroup = word(data, pointer + 4) - ROM_BASE
        if not 0 <= track_count <= 16 or not VOICEGROUP_START <= voicegroup < VOICEGROUP_END:
            raise ValueError(f"invalid M4A song header at 0x{pointer:X}")

    rows = [
        {"address": hex(ROM_BASE + MPLAY_TABLE_START), "name": "gMPlayTable", "mode": "data", "confidence": "m4a-structure"},
        {"address": hex(ROM_BASE + SONG_TABLE_START), "name": "gSongTable", "mode": "data", "confidence": "m4a-structure"},
        {"address": hex(ROM_BASE + SONG_TABLE_END), "name": "data_gap_m4a_song_table_alignment", "mode": "data", "confidence": "alignment"},
    ]
    rows.extend(
        {
            "address": hex(ROM_BASE + pointer),
            "name": f"raw_asset_m4a_sample_{index:03d}",
            "mode": "data",
            "confidence": "voicegroup-wave-pointer",
        }
        for index, pointer in enumerate(sample_pointers)
    )
    last_sample = sample_pointers[-1]
    last_sample_end = last_sample + 16 + word(data, last_sample + 12)
    rows.append(
        {
            "address": hex(ROM_BASE + last_sample_end),
            "name": "raw_asset_m4a_sample_tail_gap",
            "mode": "data",
            "confidence": "wave-size",
        }
    )
    rows.extend(
        {
            "address": hex(ROM_BASE + pointer),
            "name": f"raw_asset_m4a_song_{index:03d}",
            "mode": "data",
            "confidence": "song-table-pointer+header",
        }
        for index, pointer in enumerate(unique_songs)
    )
    return rows
