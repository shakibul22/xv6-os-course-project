#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    printf("Current year: %d\n", getyear());
    exit(0);
}