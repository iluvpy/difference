#include "compare.h"
#include <stdlib.h>

char *compare(char *str1, char *str2) {
	size_t len1 = strlen(str1);	
	size_t len2 = strlen(str2);	
	// size_t result_len = LEN;
	// char *result = malloc(result_len);
	// int i = 0;
	// for (;;) {
	// 	if (i < len1 && i < len2) {
	// 		if (str1[i] != str2[i]) {

	// 		}	
	// 	}
	// 	i++;
	// }

	result = realloc(result, strlen(result)+1);
	result[strlen(result)+1] = '\0';
	return result;
}