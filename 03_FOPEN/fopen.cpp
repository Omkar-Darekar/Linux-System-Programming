#include <cstdio>
#include <cstdlib>


int main(void) {
    const char* file_name = "sample.txt";

    FILE* fp = fopen(file_name, "w+");
    if(fp == 0) {
        puts("Unable to open file. Exiting . . .");
        exit(-1);
    }
       
    fprintf(fp, "First line in the file.\n");

    fclose(fp);
    
    return (0);
}

