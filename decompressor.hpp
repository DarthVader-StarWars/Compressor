#pragma once

#include <windows.h>
#include <compressapi.h>

#pragma comment(lib, "cabinet.lib")

namespace COMPRESS {
    namespace ALGORITHM {
        namespace XPRESS {
            size_t decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer);
        }
        namespace XPRESS_HUFF {
            size_t decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer);
        }
        namespace MSZIP {
            size_t decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer);
        }
        namespace LZMS {
            size_t decompress(const void* CompressedData, const size_t CompressedDataSize, void** UncompressedBuffer);
        }
    }
}