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

int get_next(char pat[], int *next)
{
	int i, j, len = 0;
	
	i = 0;
	j = 0;
	next[0] = -1;
	while(i < strlen(pat)) {
		if( j == 0 || pat[i] == pat[j]) {
			i++;
			j++;
			next[i] = j;
		}
	else
		j = next[j];
	}

	i = 0;
	len = strlen(pat);
	while(len--) {
		printf("%d next[ %d ] = %d ",__LINE__, i++, next[i]);
	}
	printf("\n");
	return 0;
}

int Index_KMP(char str[], char pat[])
{
	int i, j;
	int next[255];
	
	memset(next, 0, sizeof(next));
	i = 0;	
	j = 0;
	get_next(pat, next);
	
	while(i < strlen(str) && j < strlen(pat)) {
		if (j > 0 || str[i] == pat[j])	 {
			i++;
			j++;
		}
		else {		
			j = next[j];
		}
			
	}
		
	return i;
}

int main(void)
{
	char *str, *pat;

	str = (char *)malloc(sizeof(char) * 1000);
	pat = (char *)malloc(sizeof(char) * 1000);
	memset(str, '\0', sizeof(str));
	memset(pat, '\0', sizeof(pat));

	strcpy(str, "0000000001");
	strcpy(pat, "00001");
	
	printf("Index = %d\n", Index_KMP(str, pat));
	return 0;
}
