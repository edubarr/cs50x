#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *imageout = NULL;

    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // Image pointer
    FILE *image = fopen(argv[1], "r");

    // Check pointer
    if (image == NULL)
    {
        printf("Could not open image.\n");
        fclose(image);
        return 1;
    }

    BYTE buffer[BLOCK];
    int count = 0;
    char name[sizeof(int) + 4];

    while (fread(buffer, BLOCK, 1, image))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (imageout != NULL)
            {
                fclose(imageout);
            }

            sprintf(name, "%03d.jpg", count);
            imageout = fopen(name, "w");

            fwrite(buffer, BLOCK, 1, imageout);

            count++;
        }
        else if (imageout != NULL)
        {
            fwrite(buffer, BLOCK, 1, imageout);
        }
    }
    fclose(image);

    return 0;
}