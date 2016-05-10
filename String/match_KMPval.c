/*
 ************************************************
 * Name : match_KMPval.c
 * Author : Lniper
 * Date : 2016-05-10
 * Aim : Matching the string using the new KMP.
 ************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_nextval(char pat[], int *nextval)
{
	int i, j;
	i = 0;
	j = -1;
	nextval[0] = -1;
	while (i<strlen(pat)) {
		if(j == -1 || pat[i] == pat[j]) {
			i++;
			j++;
			if(pat[i] != pat[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	
	for(i = 0; i < strlen(pat); i++)
		printf("nextval[ %d ] = %d\n", i, nextval[i]+1);
}

int Index_KMP(char str[], char pat[])
{
	int i, j;
	int nextval[255];
	
	memset(nextval, 0, sizeof(nextval));
	i = 0;	
	j = 0;
	get_nextval(pat, nextval);
	
	while(i < strlen(str) && j < strlen(pat)) {
		if (j > 0 || str[i] == pat[j])	 {
			i++;
			j++;
		}
		else {		
			j = nextval[j];
		}
			
	}
	
	return 0;
}

int main(void)
{
	char *str, *pat;

	str = (char *)malloc(sizeof(char) * 1000);
	pat = (char *)malloc(sizeof(char) * 1000);
	memset(str, '\0', sizeof(str));
	memset(pat, '\0', sizeof(pat));

	strcpy(str, "aaaaaababaaaba");
	strcpy(pat, "ababaaaba");
	Index_KMP(str, pat);
	//printf("Index = %d\n", );
	return 0;
}
