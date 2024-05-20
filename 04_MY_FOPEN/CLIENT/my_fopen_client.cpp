#include <cstdio>
#include <cstdlib>
#include "../SERVER/my_fopen.h"



int main() {
    int fd = my_fopen("w.txt", "w");
    if(fd < 1) {
        puts("Error while opening file. Exiting . . .");
        exit(-1);
    }

    my_fclose(fd);

    return(0);

}

