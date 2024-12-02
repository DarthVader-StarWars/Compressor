#include "compressor.hpp"

static size_t _compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    COMPRESSOR_HANDLE compressor;
    CreateCompressor(Algorithm, AllocationRoutines, &compressor);
    SIZE_T CompressedDataSize;
    Compress(compressor, UncompressedData, UncompressedDataSize, NULL, 0, &CompressedDataSize);
    *CompressedBuffer = new void* [CompressedDataSize];
    Compress(compressor, UncompressedData, UncompressedDataSize, *CompressedBuffer, CompressedDataSize, &CompressedDataSize);
    CloseCompressor(compressor);
    return CompressedDataSize;
}

size_t COMPRESS::ALGORITHM::XPRESS::compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer)
{
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_XPRESS, NULL);
}

size_t COMPRESS::ALGORITHM::XPRESS_HUFF::compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer)
{
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_XPRESS_HUFF, NULL);
}

size_t COMPRESS::ALGORITHM::MSZIP::compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer)
{
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_MSZIP, NULL);
}

size_t COMPRESS::ALGORITHM::LZMS::compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer)
{
    return _compress(UncompressedData, UncompressedDataSize, CompressedBuffer, COMPRESS_ALGORITHM_LZMS, NULL);
}
