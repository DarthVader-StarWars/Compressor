/*
MIT License

Copyright (c) 2024 DarthVader-StarWars

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Compressor.hpp"

static SIZE_T _compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    Compressor compressor(Algorithm, AllocationRoutines);
    SIZE_T CompressedBufferSize;
    Compress(compressor.getCompressor(), UncompressedData, UncompressedDataSize, NULL, 0, &CompressedBufferSize);
    *CompressedBuffer = (BYTE*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, CompressedBufferSize);
    SIZE_T CompressedDataSize;
    Compress(compressor.getCompressor(), UncompressedData, UncompressedDataSize, *CompressedBuffer, CompressedBufferSize, &CompressedDataSize);
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
