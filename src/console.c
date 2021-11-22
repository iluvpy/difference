#include "console.h"

void print_color(const char *str, const char *color) {
	printf("%s%s%s", color, str, RES);
}