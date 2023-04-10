#define _CRT_SECURE_NO_WARNINGS 1
//BF算法

#include<assert.h>

#include<stdio.h>

//str为主串，sub为子串
int BF(char* str, char* sub)
{
	assert(str != NULL && sub != NULL);
	if (str == NULL || sub == NULL)
		return -1;
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	int i = 0;
	int j = 0;
	while (i < lenStr && j < lenSub)
	{
		if (str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= lenSub)
	{
		return i - j;
	}
	//不存在直接返回-1
	return -1;
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));
	printf("%d\n", BF("ababcabcdabcde", "abcdf"));
	printf("%d\n", BF("ababcabcdabcde", "ab"));
	return 0;
}