#include "files.h"
#include <unistd.h>

// returns true if file exsits and false if not
bool file_exists(const char *path) {
	return access(path, F_OK);
}

void argv_files(files *_files, int argc, char **argv) {
	if (argc > 2) {
		char *file_path1 = argv[1];
		char *file_path2 = argv[2];
		_files->f1 = fopen(file_path1, "r");
		_files->f2 = fopen(file_path2, "r");
	}
	else {
		_files->f1 = NULL;
		_files->f2 = NULL;
	}
}

void close_files(files *_files) {
	if (_files->f1)
		fclose(_files->f1);
	if (_files->f2)
		fclose(_files->f2);
}

int validate_files(files *_files) {
	if (!_files->f1 || !_files->f2)
		return INVALID_FILES;
	return FILES_OK; // everything ok
}

size_t get_file_size(FILE *fd) {
	fseek(fd, 0, SEEK_END);
	size_t size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	return size;
}

// returns file content
char *get_fcontent(FILE *fd) {
	size_t size = get_file_size(fd);
	char *file_content = calloc(size+1, 1);
	for (int i = 0; i < size; i++) {
		file_content[i] = fgetc(fd);
	}
	return file_content;
}

void delete_fcontent(char *content) {
	free(content);
}