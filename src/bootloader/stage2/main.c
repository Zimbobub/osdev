#include "stdint.h"
#include "stdio.h"
#include "disk.h"

void horizonalLine(bool padStart, bool padEnd)
{
    if (padStart)
        puts("\r\n");

    puts("--------------------------------------------------------------------------------");

    if (padEnd)
        puts("\r\n");
}

void _cdecl cstart_(uint16_t bootDrive){

    int count;
    for(count = 0; count <= 10; count++)
    {
        printf("%d\r\n", count);
    }

    puts("Hello world from C!!!\r\n");
    printf("Formatted %% %c %s\r\n", 'a', "string");
    printf("Formatted %d %i %x %p %o %hd %hi %hhu %hhd\r\n", 1234, 5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (char)-10);
    printf("Formatted %ld %lx %lld %llx\r\n", -100000000l, 0xdeadbeeful, 10200300400ll, 0xdeadbeeffeebdaedull);
    
    horizonalLine(true, true);

    // borken
    // DISK disk;
    // char output[512] = "asdf";
    // DISK_Initialise(&disk, bootDrive);
    // DISK_ReadSectors(&disk, 0, 1, &output[0]);
    // printf("%s", output);
    

    for (;;);
}

