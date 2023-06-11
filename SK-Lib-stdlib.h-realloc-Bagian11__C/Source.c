#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    long* buffer, * oldbuffer;
    size_t size;

    if ((buffer = (long*)malloc(1000 * sizeof(long))) == NULL) {
        exit(1);
    }
        
    size = _msize(buffer);
    printf_s("Size of block after malloc of 1000 longs: %u\n", size);

    // Alokasi ulang dan tampilkan ukuran baru:
    oldbuffer = buffer;     // simpan pointer jika realloc gagal
    if ((buffer = realloc(buffer, size + (1000 * sizeof(long)))) == NULL) {
        free(oldbuffer);  // blok asli bebas
        exit(1);
    }

    size = _msize(buffer);
    printf_s("Size of block after realloc of 1000 more longs: %u\n", size);

    free(buffer);

    _getch();
    exit(0);
}