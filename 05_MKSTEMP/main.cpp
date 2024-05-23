#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <unistd.h>

int main(void) {

    char file_name[] = "temp_file_XXXXXX";
    int fd = mkstemp(file_name);
    
    assert(fd > 0);
    
    char buf[] = "This is temp file\n";

    int cnt = write(fd, buf, sizeof(buf));

    printf("cnt : %d\n", cnt);

    close(fd);

    return(0);
}
