#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include "../SERVER/my_fopen.h"

int main() {
    MY_FILE fd = my_fopen("w.txt", "w");
    assert(fd > 0);

    my_fprintf(fd, "Omkar");

    my_fclose(fd);

    MY_FILE fd1 = my_fopen("w.txt", "w+");
    assert(fd1 > 0);

    my_fprintf(fd1, "Darekar");

    my_fclose(fd1);

    MY_FILE fd2 = my_fopen("w.txt", "a");
    assert(fd2 > 0);

    my_fprintf(fd2, "Darekar1");

    my_fclose(fd2);

    MY_FILE fd3 = my_fopen("w.txt", "a+");
    assert(fd3 > 0);

    my_fprintf(fd3, "+++Darekar");

    my_fclose(fd3);

    return(0);

}

