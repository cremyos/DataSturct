/*
 ************************************************
 * Name : match_common.c
 * Author : Lniper
 * Date : 2016-05-07
 * Aim : Matching the string.
 ************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Index(char str[], char pat[], int pos)
{
	int i = pos;
	int j = 0;
	int k = 0;

	while(i < strlen(str) && j < strlen(pat)) {
		if(str[i] == pat[j]) {
			i++;
			j++;
			k++;
		}
		else {
			if(k != 0) {
				printf("i = %d\n", i);
				k = 0;
			}
			i = i-j+2;
			j = 0;			
		}
	}
	if(k != 0) {
		printf("i = %d\n", i-j);
		k = 0;
	}
	if (j > strlen(pat))
		return i - strlen(pat);
	else
		return 0;
}

int main(void)
{
	char *str, *pat;

	str = (char *)malloc(sizeof(char) * 1000);
	pat = (char *)malloc(sizeof(char) * 1000);
	memset(str, '\0', sizeof(str));
	memset(pat, '\0', sizeof(pat));

	strcpy(str, "abcdefgoogle")	;
	strcpy(pat, "google");
	
	Index(str, pat, 0);
	return 0;
}
