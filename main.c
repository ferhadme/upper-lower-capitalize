#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *to_uppercase(char *);
char upper(char);
char *to_lowercase(char *);
char lower(char);
char *capitalize(char *);
int string_equal(char *, char *);

/*
 * size of string
 * just for testing small strings
 */
#define STRING_LENGTH 100

int main(void) {
	char *test_strings[] = {"TEST", "test", "Test", "TesT", "tEsT", "teST", "teSt"};
	printf("%s\n", test_strings[0]);
	for (int i = 0; i < 7; i++) {
		char *string = to_uppercase(test_strings[i]);
		assert(string_equal(string, "TEST"));
		free(string);
		string = to_lowercase(test_strings[i]);
		assert(string_equal(string, "test"));
		free(string);
		string = capitalize(test_strings[i]);
		assert(string_equal(string, "Test"));
		free(string);
	}
	printf("Success...\n");
}

int string_equal(char *s1, char *s2) {
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] != s2[i]) {
			return 0;
		}
		i++;
	}
	return (s1[i] == '\0') && (s2[i] == '\0');
}

char *to_uppercase(char *string) {
	//printf("%s\n", string);
	char *upper_string = malloc(STRING_LENGTH * sizeof(char));
	//printf("%s2222\n", upper_string);
	int i = 0;
	while (string[i] != '\0') {
		upper_string[i] = upper(string[i]);
		//printf("%c\n", upper_string[i]);
		i++;
	}
	upper_string[i] = '\0';
	return upper_string;
}

char upper(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return ch - 32;
	}
	return ch;
}

char *to_lowercase(char *string) {
	char *lower_string = malloc(STRING_LENGTH * sizeof(char));
	int i = 0;
	while (string[i] != '\0') {
		lower_string[i] = lower(string[i]);
		i++;
	}
	lower_string[i] = '\0';
	return lower_string;
}

char lower(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch + 32;
	}
	return ch;
}

char *capitalize(char *string) {
	if (string[0] == '\0') {
		return "";
	}
	char *capitalized_string = malloc(STRING_LENGTH * sizeof(char));
	capitalized_string[0] = upper(string[0]);
	int i = 1;
	while (string[i] != '\0') {
		capitalized_string[i] = lower(string[i]);
		printf("get stuck\n");
		i++;
	}
	capitalized_string[i] = '\0';
	return capitalized_string;
}
