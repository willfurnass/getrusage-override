#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void)
{
    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret;
    struct timeval end;
    double cnt = 1000.0;
    int i;

    for (i=0; i<100000000; i++) {
        cnt /= 2.0;
    }

    ret = getrusage(who, &usage);
    end = usage.ru_utime;
    printf("Ended at: %ld.%lds\n", end.tv_sec, end.tv_usec);

    return 0;
}
