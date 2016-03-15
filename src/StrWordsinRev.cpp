/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev1(char* str, int l, int e){
	int i, j, temp;
	for (i = l, j = e - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}


void str_words_in_rev(char *input, int len){//"a b c d"
	int i = 0;
	int start = 0;
	for (i = 0; input[i] != '\0'; i++){
		if (input[i] == ' '){
			rev1(input, start, i);
			start = i + 1;
		}
	}
	rev1(input, start, i);
	rev1(input, 0, i);
}
