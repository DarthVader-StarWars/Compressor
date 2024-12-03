```c++
#include <windows.h>
#include <tchar.h>

#include "compressor.hpp"
#include "decompressor.hpp"

INT _tmain(INT argc, TCHAR** argv, TCHAR** envp) {
    CONST BYTE UncompressedData[] = {
        'a', 'b', 'c', 'd'
    };
    SIZE_T UncompressedDataSize = 4;
    BYTE* CompressedBuffer = nullptr;
    SIZE_T CompressedBufferSize = COMPRESS::ALGORITHM::XPRESS::compress(
        UncompressedData,
        UncompressedDataSize,
        &CompressedBuffer
    );
    BYTE* UncompressedBuffer = nullptr;
    SIZE_T DecompressedBufferSize = COMPRESS::ALGORITHM::XPRESS::decompress(
        CompressedBuffer,
        CompressedBufferSize,
        &UncompressedBuffer
    );
    delete[] CompressedBuffer;
    delete[] UncompressedBuffer;
}
```
