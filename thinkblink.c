/*
Copyright (c) 2010, Bjoern Heller <tec@hellercom.de>. All rights reserved
This code is licensed under GNU/ GPL
*/
#include <stdio.h>

const char FILENAME[] = "/proc/acpi/ibm/light";

int main(int argc, char *argv[])
{
    FILE *light;
    int i = atoi(argv[1]);      /* The number of times to blink. */
    int interval = atoi(argv[2]); /* The interval between blinks.
                                 100000 seems like a good number.*/

    for (; i > 0; i--) {
        light = fopen(FILENAME, "w");
        fprintf(light, "on");
        fclose(light);

        usleep(interval);

        light = fopen(FILENAME, "w");
        fprintf(light, "off");
        fclose(light);

        if (i > 0)
            usleep(interval);
    }

    return 0;
}

