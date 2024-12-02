#include "decompressor.hpp"

static size_t _decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    DECOMPRESSOR_HANDLE decompressor;
    CreateDecompressor(Algorithm, AllocationRoutines, &decompressor);
    SIZE_T UncompressedDataSize;
    Decompress(decompressor, CompressedData, CompressedDataSize, NULL, 0, &UncompressedDataSize);
    *UncompressedBuffer = new void* [UncompressedDataSize];
    Decompress(decompressor, CompressedData, CompressedDataSize, *UncompressedBuffer, UncompressedDataSize, &UncompressedDataSize);
    CloseDecompressor(decompressor);
    return UncompressedDataSize;
}

size_t COMPRESS::ALGORITHM::XPRESS::decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer)
{
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS, NULL);
}

size_t COMPRESS::ALGORITHM::XPRESS_HUFF::decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer)
{
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS_HUFF, NULL);
}

size_t COMPRESS::ALGORITHM::MSZIP::decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer)
{
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_MSZIP, NULL);
}

size_t COMPRESS::ALGORITHM::LZMS::decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer)
{
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_LZMS, NULL);
}
