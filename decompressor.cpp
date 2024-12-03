#include "Decompressor.hpp"

static SIZE_T _decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    Decompressor decompressor(Algorithm, AllocationRoutines);
    SIZE_T UncompressedDataSize;
    Decompress(decompressor.getDecompressor(), CompressedData, CompressedDataSize, NULL, 0, &UncompressedDataSize);
    *UncompressedBuffer = new BYTE[UncompressedDataSize]();
    Decompress(decompressor.getDecompressor(), CompressedData, CompressedDataSize, *UncompressedBuffer, UncompressedDataSize, &UncompressedDataSize);
    return UncompressedDataSize;
}

SIZE_T COMPRESS::ALGORITHM::XPRESS::decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS, NULL);
}

SIZE_T COMPRESS::ALGORITHM::XPRESS_HUFF::decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS_HUFF, NULL);
}

SIZE_T COMPRESS::ALGORITHM::MSZIP::decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_MSZIP, NULL);
}

SIZE_T COMPRESS::ALGORITHM::LZMS::decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_LZMS, NULL);
}

