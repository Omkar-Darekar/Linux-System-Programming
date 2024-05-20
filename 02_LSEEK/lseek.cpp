#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

int main() {
        const char* src_file = "/home/odarekar/Documents/test.txt";
        const char* des_file ="/home/odarekar/Documents/_test.txt";

        int src_fd = open(src_file, O_RDONLY);
        if(src_fd < 0) {
                printf("Error while opening file : %s . Exiting . . .\n", src_file);
                exit(-1);
        }

        int des_fd = open(des_file, O_CREAT|O_TRUNC|O_WRONLY, 0666);
        if(des_fd < 0) {
                printf("Error while opening file : %s . Exiting . . .\n", des_file);
                close(src_fd);
                exit(-1);
        }

//        if(lseek(src_fd, -5, SEEK_END) < 0) {
//                puts("Error while lseek\n");
//                close(src_fd);
//                close(des_fd);
//        }

//        if(lseek(src_fd, 5, SEEK_CUR) < 0) {
//                puts("Error while lseek\n");
//                close(src_fd);
//                close(des_fd);
//        }

        if(lseek(src_fd, 15, SEEK_SET) < 0) {
                puts("Error while lseek\n");
                close(src_fd);
                close(des_fd);
        }

        void* read_buf = calloc(BUFSIZ, sizeof(char));
        int total_byte_read = 0;

        while((total_byte_read = read(src_fd, read_buf, BUFSIZ)) > 0) {
                if(write(des_fd, read_buf, total_byte_read) < 0) {
                        break;
                }
        }

        close(src_fd);
        close(des_fd);

        return (0);
}


