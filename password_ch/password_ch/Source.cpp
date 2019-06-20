#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996)

using namespace std;

void replaceAll(char* str, const char* oldWord, const char* newWord);


int main()
{
	cout << "Content-Type: text/html\r\n\r\n";
	char Data[1000];
	char* Token;
	FILE* fPtr;
	FILE* fTemp;
	char path[100] = "C:\\temp\\test.txt";
	char altpass[20 + 1];
	char neupass[20 + 1];
	char agin[20 + 1];

	char buffer[200];

	cin >> Data;

	if (Data != NULL)
	{
		Token = strtok(Data, "&");
		sscanf(Token, "old=%s", altpass);

		Token = strtok(NULL, "&");
		sscanf(Token, "new=%s", neupass);

		Token = strtok(NULL, "&");
		sscanf(Token, "agin=%s", agin);
	}
	fPtr = fopen(path, "r");
	fTemp = fopen("C:\\temp\\test2.txt", "w");

	if (fPtr == NULL || fTemp == NULL)
	{
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write privilege.\n");
		exit(EXIT_SUCCESS);
	}


	while ((fgets(buffer, sizeof(buffer), fPtr)) != NULL)
	{
		replaceAll(buffer, altpass, neupass);

		fputs(buffer, fTemp);
	}
	fclose(fPtr);
	fclose(fTemp);
	remove(path);
	rename("C:\\temp\\test2.txt", path);
	return 0;
}



void replaceAll(char* str, const char* oldWord, const char* newWord)
{
	char* pos, temp[1000];
	int index = 0;
	int owlen;

	owlen = strlen(oldWord);


	while ((pos = strstr(str, oldWord)) != NULL)
	{
		strcpy(temp, str);

		index = pos - str;

		str[index] = '\0';

		strcat(str, newWord);

		strcat(str, temp + index + owlen);
	}
}
