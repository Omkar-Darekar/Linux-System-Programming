#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("%s: missing file operand\n", argv[0]);
		exit(0);
	}else if(argc == 2) {
		printf("%s: missing destination file operand after '%s'\n", argv[1]);
		exit(1);
	}

	void* read_buffer = calloc(BUFSIZ, sizeof(char));
	if(read_buffer == 0) {
		puts("No virtual space. Exiting . . . ");
		exit(-1);
	}
	

	const char* dest_path = (const char*)argv[argc - 1];
	int dest_fd = open(dest_path, O_CREAT|O_WRONLY|O_TRUNC, 0666);

	if(dest_fd == -1) {
		printf("Error occured while opening %s\n", dest_path);
		exit(-1);
	}
	
	ssize_t read_byte = 0;
	
	const char* src_file = argv[1];	
	int src_fd = open(src_file, O_RDONLY);
	if(src_fd < 0) {
		printf("Unable to open file : %s\n", src_file);
		close(dest_fd);
		exit(-1);
	}
	
	while((read_byte = read(src_fd, read_buffer, BUFSIZ)) > 0)  {
		if(write(dest_fd, read_buffer, read_byte) < 0) {
			puts("Error while copying.");
			break;
		}
		
		bzero(read_buffer, BUFSIZ);
	}


	if(close(dest_fd) == -1) {
		puts("Error while closing file\n");
	}

	if(close(src_fd) == -1) {
		puts("Error while closing file\n");
	}
	
	
	free(read_buffer);	
	return (0);
}
