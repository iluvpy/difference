#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INVALID_PATH -1
#define INVALID_FILES -2
#define FILES_OK 1

typedef struct files{
	FILE *f1;
	FILE *f2;
} files;

void argv_files(files *_files, int argc, char **argv);
void close_files(files *_files);
int validate_files(files *_files);
bool file_exists(const char *path);
size_t get_file_size(FILE *fd);
char *get_fcontent(FILE *fd);
void delete_fcontent(char *content);