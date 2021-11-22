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



