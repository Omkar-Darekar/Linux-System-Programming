#ifndef __MY_FOPEN_H__
#define __MY_FOPEN_H__

typedef int MY_FILE;

MY_FILE my_fopen(const char* file_name, const char* mode);
int my_fclose(MY_FILE fd);
int my_fprintf(MY_FILE fd, const char* str);

#endif //__MY_FOPEN_H__
