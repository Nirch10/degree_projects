/*
Assigned by:
Ran Abramovich 315942235
Nir Chodorov 316118421
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX 100

//get a letter and a string and creates a matrix of all the substrings that start with the given letter
char **get_letter_string(char str[MAX], char letter, char **arr, int *array_rows);
//get a letter and a string and check if the string starts with the given letter
int start_with_letter(char letter, char *str, int index);
//count how many substrings of string starts with specific letter
int count_words(char *str, char letter);
//get string and matrix and add the new string to a new line in the matrix
void add_string_to_string_array(char ***arr, char temp_str[MAX], int size, int array_index);
//print the matrix of strings
void print_string_array(char **arr, int array_rows);
//free memory of matrix
void FreeMemory(int rows, int **arr);

//remove spaces and numbers from string
char *beutify_string(char *str, char *new_str);
//check if character is a number or space
int check_good_character(char ch);

//get a filename and return the most common letter in it
char commonestLetter(char* filename);

//get an encoded string and decode it by a set of rules : decrease one from the first char, two from the second one and so on. if it encounter space the count starts again
void decode_str(char *str);

//get a decleration string and write to file how much bytes each variable takes 
void decleration_string_to_file(char *str, char *filename);
//get a string that represent a variable type and returns how much byte it takes
int size_of_type(char *str);
//get a string and returns 0 if it does not represent an array, else it return the size of the array that string represent 
int is_array(char *str);
//get a file and print its content
void print_file_content(char *filename);

//For Ex1-Ex5 : Get the requested input from user and call the specific functions.
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

int main()
{
	int num = 0;
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
			} while ((select<0) || (select>5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

void Ex1()
{
	char letter, str[MAX];
	char **arr = NULL;
	int *array_rows = (int*)malloc(sizeof(int));
	printf("Please enter the letter : \n");
	rewind(stdin);
	scanf("%c", &letter);
	printf("Please enter the string : \n");
	rewind(stdin);
	gets(str);
	arr = get_letter_string(str, letter, arr, array_rows);
	printf("The new string is : \n");
	print_string_array(arr, *array_rows);
	free(array_rows);
	FreeMemory(*array_rows, arr);
}

void Ex2()
{
	char str[MAX], *new_str = NULL;
	printf("Please enter the string : \n");
	rewind(stdin);
	gets(str);
	new_str = beutify_string(str, new_str);
	printf("The new string is :\n%s\n", new_str);
}

void Ex3()
{
	char ch, filename[MAX];
	printf("Please enter the file name : \n");
	rewind(stdin);
	gets(filename);
	ch = commonestLetter(filename);
	if (ch)
		printf("The commonest letter is %c\n", ch);
	else
		printf("No letters in the file\n");
}

void Ex4()
{
	char str_to_decode[MAX];
	printf("Please enter the string to decode : \n");
	rewind(stdin);
	gets(str_to_decode);
	decode_str(str_to_decode);
	printf("%s\n", str_to_decode);
}

void Ex5()
{
	char decleration[MAX], filename[MAX];
	printf("Please enter the decleration string : \n");
	rewind(stdin);
	gets(decleration);
	printf("Please enter the file name : \n");
	rewind(stdin);
	gets(filename);
	decleration_string_to_file(decleration, filename);
	print_file_content(filename);
}

char **get_letter_string(char str[MAX], char letter, char **arr, int *array_rows)
{
	int i, j = 0, array_index = 0;
	char temp_str[MAX];
	*array_rows = count_words(str, letter);
	arr = (char**)malloc(sizeof(char*)*(*array_rows));
	for (i = 0; i < strlen(str); i++)
	{
		if (start_with_letter(letter, str, i))
		{
			while (str[i] != ' ' && str[i] != '\0')
				temp_str[j++] = str[i++];
			temp_str[j] = '\0';
			add_string_to_string_array(&arr, temp_str, j + 1, ++array_index);
			j = 0;
		}
	}
	return arr;
}

int start_with_letter(char letter, char *str, int index)
{
	if (index == 0 && (str[index] == letter || str[index] == letter - 32))
		return 1;
	if (index > 0 && (str[index] == letter || str[index] == letter - 32) && str[index - 1] == ' ')
		return 1;
	return 0;
}

int count_words(char *str, char letter)
{
	int counter = 0, i = 0;
	char *index = str;
	while (index[i] != '\0')
		if(start_with_letter(letter, index, i++))
			counter++;
	return counter;
}

void add_string_to_string_array(char ***arr, char temp_str[MAX], int size, int array_index)
{
	int i = 0;
	(*arr)[array_index-1] = (char *)malloc(sizeof(char)*size);
	while (temp_str[i] != '\0')
	{
		(*arr)[array_index-1][i] = temp_str[i];
		i++;
	}
	(*arr)[array_index-1][i] = '\0';
}

void print_string_array(char **arr, int array_rows)
{
	int i = 0;
	while (i < array_rows)
		printf("#%d string : %s \n", i, arr[i++]);
}

void FreeMemory(int rows, int **arr)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		free(arr[i]);
		printf("free row %d\n", i);
	}
	free(arr);
}

char *beutify_string(char *str, char *new_str)
{
	int size_of_new_string = 0, i = 0;
	char *temp_str = str;
	while (*temp_str != '\0')
		size_of_new_string += check_good_character(*temp_str++);
	new_str = (char*)malloc(sizeof(char*)*(size_of_new_string + 1));
	while (*str != '\0')
		if (check_good_character(*str))
			new_str[i++] = *str++;
		else
			str++;
	new_str[i] = '\0';
	return new_str;
	free(new_str);
}

int check_good_character(char ch)
{
	return (ch != ' ' && (ch < '0' || ch > '9'));
}

char commonestLetter(char* filename)
{
	FILE *f = fopen(filename, "r");
	int i, index, character, max = -65, counts[26] = { 0 };
	if (f == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	while ((character = fgetc(f)) != EOF)
		counts[toupper(character) - 'A']++;
	fclose(f);
	for (i = 0; i < 26; i++)
		if (counts[i] >= max)
		{
			max = counts[i];
			index = i;
		}
	return (index + 'A');
}

void decode_str(char *str)
{
	int counter = 0, i = 0;
	while (str[i] != '\0')
		if (str[i] == ' ')
		{
			counter = 0;
			i++;
		}
		else
			str[i++] -= ++counter;
}

void decleration_string_to_file(char *str, char *filename)
{
	char *broken_string;
	int size = 0;
	FILE *decleration_file = fopen(filename, "w");
	broken_string = strtok(str, " ,;");
	if (!strcmp(broken_string, "long"))
	{
		size = size_of_type(broken_string);
		broken_string = strtok(NULL, " ,;");
		if (!strcmp(broken_string, "long"))
		{
			size += size_of_type(broken_string);
			broken_string = strtok(NULL, " ,;");
		}
	}
	else
	{
		size = size_of_type(broken_string);
		broken_string = strtok(NULL, " ,;");
	}
	while (broken_string != NULL)
	{
		if (broken_string[0] == '*')
			fprintf(decleration_file, "%s requires %d bytes\n", broken_string, 4);
		else
			if (is_array(broken_string))
				fprintf(decleration_file, "%s requires %d bytes\n", broken_string, (size * is_array(broken_string)));
			else
				fprintf(decleration_file, "%s requires %d bytes\n", broken_string, size);
		broken_string = strtok(NULL, " ,;");
	}
	fclose(decleration_file);
}

int size_of_type(char *str)
{
	if (!strcmp(str, "char")) return 1;
	if (!strcmp(str, "short")) return 2;
	if (!strcmp(str, "int")) return 4;
	if (!strcmp(str, "float")) return 4;
	if (!strcmp(str, "double")) return 8;
	if (!strcmp(str, "long")) return 4;
	return 0;
}

int is_array(char *str)
{
	char temp_str[MAX];
	int i = 0, index = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '[')
		{
			while (str[i] != ']')
				temp_str[index++] = str[++i];
			temp_str[--index] = '\0';
			return atoi(temp_str);
		}
		i++;
	}
	return 0;
}

void print_file_content(char *filename)
{
	char c;
	FILE *decleration_file = fopen(filename, "r");
	if (decleration_file == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	c = fgetc(decleration_file);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(decleration_file);
	}
	fclose(decleration_file);
}
