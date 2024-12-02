#pragma once

#include <windows.h>
#include <compressapi.h>

#pragma comment(lib, "cabinet.lib")

namespace COMPRESS {
    namespace ALGORITHM {
        namespace XPRESS {
            size_t compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer);
        }
        namespace XPRESS_HUFF {
            size_t compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer);
        }
        namespace MSZIP {
            size_t compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer);
        }
        namespace LZMS {
            size_t compress(const void* UncompressedData, const size_t UncompressedDataSize, void** CompressedBuffer);
        }
    }
}