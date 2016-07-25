#include <stdio.h>
#include "common.h"

Enc enc;

int main (void) {
    printf("Start...\n");
    ps_init(&enc, 48000, true);
    printf("done.\n");
    return 0;
}
