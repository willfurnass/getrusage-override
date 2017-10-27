#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <sys/resource.h>
#include <sys/time.h>


int getrusage(int who, struct rusage *r_usage) {
    int result = 0;
    struct timeval utime;

    int (*orig_getrusage)(int, struct rusage *) = (int (*)(int, struct rusage *))dlsym(RTLD_NEXT, "getrusage");

    result = orig_getrusage(RUSAGE_SELF, r_usage);
    r_usage->ru_utime.tv_sec = 666;
    return result;
}
