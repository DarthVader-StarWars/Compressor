#pragma once

#include <windows.h>
#include <compressapi.h>

#pragma comment(lib, "cabinet.lib")

class Compressor {
private:
    COMPRESSOR_HANDLE hCompressor;
public:
    Compressor(DWORD Algorithm, PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines) {
        CreateCompressor(Algorithm, AllocationRoutines, &this->hCompressor);
    }
    ~Compressor() {
        CloseCompressor(this->hCompressor);
    }
    COMPRESSOR_HANDLE getCompressor() {
        return this->hCompressor;
    }
};

namespace COMPRESS {
    namespace ALGORITHM {
        namespace XPRESS {
            SIZE_T compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer);
        }
        namespace XPRESS_HUFF {
            SIZE_T compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer);
        }
        namespace MSZIP {
            SIZE_T compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer);
        }
        namespace LZMS {
            SIZE_T compress(CONST BYTE* UncompressedData, CONST SIZE_T UncompressedDataSize, BYTE** CompressedBuffer);
        }
    }
}
