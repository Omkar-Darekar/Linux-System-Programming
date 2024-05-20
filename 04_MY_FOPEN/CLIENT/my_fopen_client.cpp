#include <cstdio>
#include <cstdlib>
#include "../SERVER/my_fopen.h"



int main() {
    int fd = my_fopen("w.txt", "w");

    my_fclose(fd);

    return(0);

}

