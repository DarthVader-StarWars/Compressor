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
            SIZE_T decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace XPRESS_HUFF {
            SIZE_T decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace MSZIP {
            SIZE_T decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
        namespace LZMS {
            SIZE_T decompress(CONST BYTE* CompressedData, const SIZE_T CompressedDataSize, BYTE** UncompressedBuffer);
        }
    }
}
