#define _CRT_SECURE_NO_WARNINGS 1
//BF�㷨

#include<assert.h>

#include<stdio.h>

//strΪ������subΪ�Ӵ�
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
	//������ֱ�ӷ���-1
	return -1;
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));
	printf("%d\n", BF("ababcabcdabcde", "abcdf"));
	printf("%d\n", BF("ababcabcdabcde", "ab"));
	return 0;
}