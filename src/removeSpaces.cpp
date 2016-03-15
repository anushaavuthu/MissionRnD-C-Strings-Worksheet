/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	int i, j, k,l;
	if ((str == "")||(str=='\0'))
		return '\0';
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (l = 0; str[l] != '\0'; l++)
			{
				if (str[i] == ' ')
				{
					k = i;
					for (j = k; str[j] != '\0'; j++)
					{
						str[j] = str[j + 1];
					}
				}
			}
		}
	
		return *str;
	}
	
}