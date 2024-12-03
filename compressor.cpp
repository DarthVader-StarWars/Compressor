#include "Compressor.hpp"

static SIZE_T _compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    Compressor compressor(Algorithm, AllocationRoutines);
    SIZE_T CompressedDataSize;
    Compress(compressor.getCompressor(), UncompressedData, UncompressedDataSize, NULL, 0, &CompressedDataSize);
    *CompressedBuffer = new BYTE[CompressedDataSize]();
    Compress(compressor.getCompressor(), UncompressedData, UncompressedDataSize, *CompressedBuffer, CompressedDataSize, &CompressedDataSize);
    return CompressedDataSize;
}

SIZE_T COMPRESS::ALGORITHM::XPRESS::compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer) {
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_XPRESS, NULL);
}

SIZE_T COMPRESS::ALGORITHM::XPRESS_HUFF::compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer) {
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_XPRESS_HUFF, NULL);
}

SIZE_T COMPRESS::ALGORITHM::MSZIP::compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer) {
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_MSZIP, NULL);
}

SIZE_T COMPRESS::ALGORITHM::LZMS::compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer) {
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_LZMS, NULL);
}
