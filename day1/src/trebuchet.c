#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

bool is_digit(char c) {
	if ('0' <= c && c <= '9') {
		return true;
	}
	return false;
}

int get_number_in_str(char *str) {
	if (str == NULL) return 0;
	int num = 0;
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++) {
		if (is_digit(str[i])) {
			num += (str[i] - '0') * 10;
			break;
		}
	}
	for (size_t j = len; j >= 0; j--) {
		if (is_digit(str[j])) {
			num += (str[j] - '0');
			break;
		}
	}
	// printf("[str]: %s", str);
	// printf("[num]: %d\n", num);
	return num;
}

int main()
{
	int sum = 0;
	char *test = "";
	int fd = open("test.txt", O_RDONLY);
	while (test)
	{
		test = get_next_line(fd);
		sum += get_number_in_str(test);
		free(test);
	}
	printf("sum: [%d]", sum);
	close(fd);
	// system("leaks -q ./a.out");
}
