/* Reconstructed from GCC libgcc2's byte-wide count-leading-zeros table. */
const unsigned char libgcc_clz_tab[256] = {
    [1] = 1,         [2 ... 3] = 2,   [4 ... 7] = 3,    [8 ... 15] = 4,
    [16 ... 31] = 5, [32 ... 63] = 6, [64 ... 127] = 7, [128 ... 255] = 8,
};
