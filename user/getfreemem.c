#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int free = getfreemem();
    printf("Free memory: %d KB\n", free);
    exit(0);
}