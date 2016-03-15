/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void rev(char* str, int l, int e){
	int i, j,temp;
	for (i = l, j = e-1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void convert(char* str, int num1, int num2,int start){
	int i = start;
	while (num1 > 0){
		str[i++] = (num1 % 10) + '0';
		num1 = num1 / 10;
	}
	rev(str, start, i);
	str[i++] = '.';
	int m = i;
	while (num2 > 0){
		str[i++] = (num2 % 10) + '0';
		num2 = num2 / 10;
	}
	rev(str, m, i);
	str[i] = '\0';
}

void number_to_str(float number, char *str,int afterdecimal){
	if (afterdecimal == 0){
		int len, i = 0;
		if (number > 0){
			int num = (int)number;
			while (num > 0){
				str[i++] = (num % 10) + '0';
				num = num / 10;
			} 
			str[i] = '\0';
			rev(str, 0, i);
		}
		else{
			number = number * -1;
			int num = (int)number;
			str[0] = '-';
			i = 1;
			while (num > 0){
				str[i++] = (num % 10) + '0';
				num = num / 10;
			}
			str[i] = '\0';
			rev(str, 1, i);
		}
	}
	else{
		//345.344
		int start;
		if (number < 0){
			number *= -1;
			str[0] = '-';
			start = 1;
		}
		else{
			start = 0;
		}
		int ival = (int)number;
		float f = number - ival;
		int temp = afterdecimal;
		while (temp > 0){
			f = f * 10;
			temp--;
		}
		int fval = (int)f;
		convert(str, ival, fval,start);
	}
}
