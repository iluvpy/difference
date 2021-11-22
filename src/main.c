#include <stdio.h>
#include <string.h>

#include "console.h"
#include "files.h"

int main(int argc, char **argv) {
	printf("argc: %d\n", argc);
	
	files files_;
	argv_files(files_, argc, argv);
	if (validate_files(files_) == INVALID_FILES) {
		printf("error: ");
		print_color("invalid input or invalid file path/s\n", BRED);
		return -1;
	}

	

	close_files(files_);

	return 0;
}