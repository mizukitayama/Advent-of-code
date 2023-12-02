#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

typedef struct {
    int number;
    char *word;
} number_word_pair;

number_word_pair pairs[] = {
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"}
};

int get_digit(char *str) {
	if ('0' <= str[0] && str[0] <= '9') {
			return str[0] - '0';
	}
	for (int j = 0; j < 9; j++) {
		if (strncmp(&str[0], pairs[j].word, strlen(pairs[j].word)) == 0) {
			return pairs[j].number;
		}
	}
	return -1;
}

int get_number_in_str(char *str) {
	if (str == NULL) return 0;
	int num = 0;
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++) {
		int digit = get_digit(&str[i]);
		if (digit != -1) {
			num += digit * 10;
			break;
		}
	}
	for (size_t j = len; j >= 0; j--) {
		int digit = get_digit(&str[j]);
		if (digit != -1) {
			num += digit;
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
