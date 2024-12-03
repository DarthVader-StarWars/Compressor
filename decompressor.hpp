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

#include <windows.h>
#include <compressapi.h>

#pragma comment(lib, "cabinet.lib")

class Decompressor {
private:
    DECOMPRESSOR_HANDLE hDecompressor;
public:
    Decompressor(DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
        CreateDecompressor(Algorithm, AllocationRoutines, &this->hDecompressor);
    }
    ~Decompressor() {
        CloseDecompressor(this->hDecompressor);
    }
    DECOMPRESSOR_HANDLE getDecompressor() {
        return this->hDecompressor;
    }
};

namespace COMPRESS {
    namespace ALGORITHM {
        namespace XPRESS {
            SIZE_T decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace XPRESS_HUFF {
            SIZE_T decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace MSZIP {
            SIZE_T decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace LZMS {
            SIZE_T decompress(CONST BYTE* CompressedData, CONST SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
    }
}
