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

#include "Decompressor.hpp"

static SIZE_T _decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer, DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
    Decompressor decompressor(Algorithm, AllocationRoutines);
    SIZE_T UncompressedBufferSize;
    Decompress(decompressor.getDecompressor(), CompressedData, CompressedDataSize, NULL, 0, &UncompressedBufferSize);
    *UncompressedBuffer = (BYTE*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, UncompressedBufferSize);
    SIZE_T UncompressedDataSize;
    Decompress(decompressor.getDecompressor(), CompressedData, CompressedDataSize, *UncompressedBuffer, UncompressedBufferSize, &UncompressedDataSize);
    return UncompressedDataSize;
}

SIZE_T COMPRESS::ALGORITHM::XPRESS::decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS, NULL);
}

SIZE_T COMPRESS::ALGORITHM::XPRESS_HUFF::decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_XPRESS_HUFF, NULL);
}

SIZE_T COMPRESS::ALGORITHM::MSZIP::decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_MSZIP, NULL);
}

SIZE_T COMPRESS::ALGORITHM::LZMS::decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer) {
    return _decompress(CompressedData, CompressedDataSize, UncompressedBuffer, COMPRESS_ALGORITHM_LZMS, NULL);
}
