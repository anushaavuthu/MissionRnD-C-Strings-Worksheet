/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 != NULL || str2 != NULL){
		int count = 0;
		char** res = (char**)malloc(sizeof(char*) * 5);
		for (int i = 0; i < 5; i++){
			res[i] = (char*)malloc(sizeof(char) * 31);
		}
		int start = 0;
		int start1 = 0, start2 = 0;
		for (start1 = 0; str1[start1] != '\0'; start1++)
		{
			if ((start1 == 0 || str1[start1] == ' '))
			{
				while (str1[start1] == ' ')
				{
					start1 += 1;
				}
				if (str1[start1] == '\0')		/*	char *str1 = "       ";
													char *str2 = " who what";

													char *str1 = "the are all is well";
													char *str2 = " who what"
													char *str1 = "the are all is well";
													char *str2 = "is who the";
			*/
				{
					break;
				}
				for (start2 = 0; str2[start2] != '\0'; start2++)
				{
					if (start2 == 0 || str2[start2] == ' ')
					{
						while (str2[start2] == ' ')
						{
							start2 += 1;
						}
						if (str2[start2] == '\0')
						{
							break;
						}
						int i, j;
						for (i = start1, j = start2; ((str1[i] != '\0' && str2[j] != '\0') || (str1[i] != '\0' && str2[j] != ' ') || (str1[i] != ' ' && str2[j] != '\0') || ((str1[i] == ' ') && (str2[j] == ' '))); i++, j++)
						{
							if (str1[i] != str2[j])
							{
								break;
							}

							if ((str1[i] == ' ') && (str2[j] == ' '))
							{
								break;
							}
						}
						if ((str1[i] == '\0' && str2[j] == '\0') || (str1[i] == '\0' && str2[j] == ' ') || (str1[i] == ' ' && str2[j] == '\0') || (str1[i] == ' ' && str2[j] == ' '))
						{
							count++;
							char* str = (char*)malloc(sizeof(i - start1 + 1));
							int p = 0;
							for (int k = start1; k < i; k++)
							{
								str[p++] = str1[k];
							}
							str[p] = '\0';
							res[start++] = str;
						}
					}
				}
			}
		}
		if (count > 0){
			return res;
		}
		return NULL;
	}
	return NULL;
}
