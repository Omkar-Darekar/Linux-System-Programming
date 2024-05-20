#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include "my_fopen.h"

int get_mode(const char* mode) {
    int _mode = -1;
    
    if(strcmp(mode, "w") == 0) {
        _mode = 1;    
    }
    else if(strcmp(mode, "w+") == 0) {
        _mode = 2;
    }else if(strcmp(mode, "r") == 0) {
        _mode = 3;
    }else if(strcmp(mode, "r+") == 0) {
        _mode = 4;
    }else if(strcmp(mode, "a") == 0) {
        _mode = 5;
    }else if(strcmp(mode, "a+") == 0) {
        _mode = 6;
    }
    
    return _mode;
}


int my_fclose(int fd) {
    return (close(fd));
}

int my_fopen(const char* file_name, const char* mode) {
    if((strlen(file_name) < 1) || (strlen(mode) < 1)) {
        puts("Input error.");
        return (-1);
    }   

    int status = -1;

    switch(get_mode(mode)) {
        case 1:
            status = open(file_name, O_TRUNC | O_CREAT | O_WRONLY, 0666);
            break;
            
        case 2:
             status = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0666);
            break;

        case 3:
            status = open(file_name, O_RDONLY);
            break;

        case 4:
            status = open(file_name, O_RDWR);
            break;

        case 5:
        case 6:
            status = open(file_name, O_CREAT | O_WRONLY, 0666);
            if(status > 0) {
                if(lseek(status, 0, SEEK_END) >= 0) {
                    puts("Offset at the end.");
                    break;
                }
                else {
                    my_fclose(status);
                    status = -1;
                }
            }
            break;

        default:
                break;
    }

    return (status);

}



