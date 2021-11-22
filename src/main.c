#include <stdio.h>
#include <string.h>

#include "console.h"
#include "files.h"


int main(int argc, char **argv) {
	
	files files_;
	argv_files(&files_, argc, argv);
	if (validate_files(&files_) == INVALID_FILES) {
		printf("error: ");
		print_color("invalid input or invalid file path/s\n", BRED);
		return -1;
	}

	char *f1_content = get_fcontent(files_.f1);
	char *f2_content = get_fcontent(files_.f2);
	printf("content of file 1: \n%s\n", f1_content);
	printf("content of file 2: \n%s\n", f2_content);

	delete_fcontent(f1_content);
	delete_fcontent(f2_content);
	close_files(&files_);

	return 0;
}