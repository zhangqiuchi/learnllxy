#include <stdio.h>
#include <stdlib.h>
//���� ���� ���� 
//�������  ��������ڵ㣨������нڵ㣩
void prefixOrder(int arr[], int i, int length)
{
	if (i >= length)
		return;
	printf("%d \n", arr[i]);
	prefixOrder( arr, i*2+1, length);
	prefixOrder( arr, i*2+2, length);
}
//������� �м�������ڵ�
void infixOrder(int arr[], int i, int length)
{
	if (i >= length)
		return;
	infixOrder( arr, i*2+1, length);
	
	printf("%d \n", arr[i]);
	infixOrder( arr, i*2+2, length);
}  
//������� ���������ڵ�
void suffixOrder(int arr[], int i, int length)
{
	if (i >= length)
		return;
	suffixOrder( arr, i*2+1, length);
	suffixOrder( arr, i*2+2, length);
	printf("%d", arr[i]);
}

int ArrayMax(int arr[], int length)
{
	for (int i = 0; i < length-1; i ++)
	{
		if (arr[i] > arr[i+1])
		{
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	return arr[length-1];//���� 6
}

void CountSort(int arr[], int length)//length Ϊ7
{
	int j = 0;
	int max = ArrayMax(arr, length)+1;
	int* helper = calloc(sizeof(int), max);
	
	for (int i = 0; i < length; i ++)
	{
		helper[arr[i]] ++;
	}
	
	for (int i = 0; i < max; i ++)
	{
		while (helper[i] > 0)
		{
			arr[j] = i;
			helper[i] --;
			j ++;
		}
	}
	
	free(helper);
	helper = NULL;
}

int main(void)
{
	int arr[] = {1,4,5,6,3,4,5};//0,1,3,4,2,5,6//�������
	prefixOrder( arr, 0, 7);
	printf("=============\n");
	int arr2[] = {1,4,5,6,3,4,5};
	infixOrder(arr2, 0, 7);//  		�������
	printf("=============\n");
	suffixOrder(arr2, 0, 7);//		�������
	printf("=============\n");
	CountSort( arr, 7);
	for (int i = 0; i < 7; i ++)
	{
		printf("%d ", arr[i]);
	}
	getchar();
	return 0;
}













