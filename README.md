```c++
#include <windows.h>
#include <tchar.h>

#include "compressor.hpp"
#include "decompressor.hpp"

INT _tmain(INT argc, TCHAR** argv, TCHAR** envp) {
    const char UncompressedData[] = {
        'a', 'b', 'c', 'd'
    };
    int UncompressedDataSize = 4;
    char* CompressedBuffer = NULL;
    size_t CompressedBufferSize = COMPRESS::ALGORITHM::XPRESS::compress(
        UncompressedData, 
        UncompressedDataSize, 
        (void**)&CompressedBuffer
    );
    char* UncompressedBuffer = NULL;
    size_t DecompressedBufferSize = COMPRESS::ALGORITHM::XPRESS::decompress(
        CompressedBuffer, 
        CompressedBufferSize, 
        (void**)&UncompressedBuffer
    );
    delete[] CompressedBuffer;
    delete[] UncompressedBuffer;
}
```
