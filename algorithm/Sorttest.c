#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//=======================================================================================================================
/*ϣ������*/
void shellSort(int arr[], int arrLen)//24888
{
	for (int interval = arrLen / 3; interval > 0; interval /= 3)
	{
		for (int i = interval; i < arrLen; i ++)
		{
			for (int j = i; j >= interval; j -= interval)
			{
				if (arr[j] < arr[j - interval])
				{
					int temp = arr[j];
					arr[j] = arr[j - interval];
					arr[j - interval]  = temp;
				}
			}
		}
	}
}
//==================================================================================================================================================================================================================================================================================================================================================
/*��������*/
void insertSort(int arr[], int arrLen)//17783
{
	for (int i = 1; i < arrLen; i ++)
		for (int j = i; j >= 1; j --)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	
}
//==================================================================================================================================================================================================================================================================================================================================================
/*ð������*/
void bubbleSort(int arr[], int arrLen)//33764
{
	for (int i = 0; i < arrLen-1; i ++)
		for (int j = 0; j < arrLen-i-1; j ++)
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}
//===========================================================================================================================
/*ѡ������*/
void selectSort(int arr[], int arrLen)//26199
{
	for (int i = 0; i < arrLen; i ++)
		for (int j = i + 1; j < arrLen; j ++)
			if (arr[j] < arr[i])
			{
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
	
}
//===========================================================================================================================
/*��������n log^n��*/
void swap(int arr[], int target1, int target2)
{
	int temp = arr[target1];
	arr[target1] = arr[target2];
	arr[target2] = temp;
}
/*����*/
int one_way_partiton(int arr[],int low,int high)
{//
	int pivot = arr[low];
	int scanner = low + 1;
	int bigger = high;
	
	while (scanner <= bigger)
	{
		if (arr[scanner] <= pivot)
		{
			scanner ++;
		}
		else// arr[scanner] > pivot �ֵ�Ŀ���Ƿ���� ��Ԫ�����С����Ԫ �ұ�Ҫ������Ԫ 
		{
			swap(arr, bigger, scanner);
			bigger --;
		}
	}
	
	swap(arr, bigger, low);
	return bigger;
}


/*˫��*/
int two_way_partiton(int arr[],int low,int high)
{
	//���̵��е��Ż� ��Ҫ�Ƕ�ѡ����ԪԪ�ص��Ż�����������Ҫʹ�� ������ֵ�� �� ������ֵ����
	//������ֵ�� �� �м�� ��ʼ�� ������ ������ѡ С�� �м�� ���� ��һ����ʼ���������ֵ
	//������ֵ�� 
	//(�������б�̵�ʱ��ֱ���ò�������)
	int midindex = low + ((high - low) >> 1);
	int midexValueIndex = 0;
	if (arr[low] <= arr[midindex] && arr[low] >= arr[high])
		midexValueIndex = low;
	else if (arr[high] <= arr[midindex] && arr[high] >= arr[low])
		midexValueIndex = high;
	else
		midexValueIndex = midindex;
	swap(arr,low, midexValueIndex);
	
	int pivot = arr[low];
	int scanner = low + 1;
	int bigger = high;
	
	while (scanner <= bigger)
	{
		while (scanner <= bigger && arr[scanner] <= pivot) scanner ++;
		while (scanner <= bigger && arr[bigger] > pivot) bigger --;
		
		if (scanner < bigger)
			swap(arr, bigger, scanner);
	}
	
	swap(arr, bigger, low);
	return bigger;
}
/*������ ���ַ�*/
//С����Ԫ 
int three_way_partiton(int arr[], int low, int high)
{
	int pivot = arr[low];
	int scanner = low + 1;
	int bigger  = high;
	int equal = low + 1;
	
	while (scanner <= bigger)
	{
		if (arr[scanner] <= pivot)
		{
			if (arr[scanner] < pivot)
			{
				swap(arr, scanner, equal);
				equal ++;
			}
			scanner ++;
		}
		else
		{
			swap(arr,scanner, bigger);
			bigger --;
		}
	}
	
	swap(arr,equal-1,low);
	return equal-1;
}

void QuickSort_3(int arr[], int low, int high)
{
	if (high <= low) return;
	int lt = low, i = low + 1, gt = high;
	int v = arr[low];
	
	while (i <= gt)
	{
		if (arr[i] < v)
			swap(arr, lt ++, i ++);
		else if (arr[i] > v)
			swap(arr, i, gt --);
		else
			i ++;
	}
	QuickSort_3( arr, low, lt-1);
	QuickSort_3( arr, gt + 1, high);
}

void QuickSort(int arr[], int low, int high)
{
	/*
	if (high <= low) return;
	int j = partiton(arr, low, high);
	QuickSort(arr, low, j-1);
	QuickSort(arr, j+1, high);
	*/
	//�� �������Ԫ��С�ڻ��ߵ���һ�����ֵ�ʱ�� ֱ��ʹ��ѡ�����򣨺ڿƼ���
	if (low < high)
	{
		
		//int j = one_way_partiton(arr, low, high);
		//int j = two_way_partiton(arr, low, high);
		int j = three_way_partiton(arr, low, high);
		QuickSort(arr, low, j-1);
		QuickSort(arr, j+1, high);
	} 
}
//===========================================================================================================================
/*�鲢����    �Ƚ� �鲢���� �� ��������*/ 
void mearge(int arr[], int low, int middle, int high);
void MergeSort(int arr[], int low, int high)
{
	//��ֻ����֮��ıȽ�
	/*
	�ֽ�
	���
	�ϲ�
	*/
	
	if (low < high)
	{
		int middle = low + ((high - low) >> 1);
		
		MergeSort(arr, low, middle);
		MergeSort(arr, middle+1, high);
		mearge(arr,low, middle, high);
	}
}

void mearge(int arr[], int low, int middle, int high)
{
	int helper[high+1];
	
	for (int i = low; i < high + 1; i ++)
	{
		helper[i] = arr[i];
	}
	
	int left = low;
	int right = middle + 1;
	int current = low;
	
	while (left <= middle && right <= high)
	{
		if (helper[left] <= helper[right])
		{
			arr[current++] = helper[left++];
		}
		else //helper[right] < helper[left]
		{
			arr[current++] = helper[right++];
		}
	}
	
	
	while (left <= middle)
	{
		arr[current] = helper[left];
		left ++;
		current ++;
	}
	
}

//===========================================================================================================================
//(���ŵ�Ӧ�� )  ������ ��partiton�ָ��Ӧ��) 
int selectK(int arr[], int low, int high, int k)
{
	//k ָ���ǵڼ���
	int q = two_way_partiton( arr, low, high);// �� �� 
	int qk = q - low + 1;//��Ԫ�ǵڼ���Ԫ��
	
	if (qk == k)//���ڵ���
	{		
		return arr[q];
	}
	else if (qk > k)
	{		
		return selectK(arr, low, q-1, k);
	}
	else
	{
		return selectK(arr, q+1, high, k - qk);// k - qk ����������ʣ�µ�һ��ĵڼ�����  ��Ϊk>qk��
	}
}
//===========================================================================================================================
/*��������С����*/
void MinHeapFixDown(int arr[], int i,int n)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if (left >= n)
	{
		return;
	}
	
	int min = left;
	
	if (right >= n)
	{
		min = left;
	}
	else
	{
		if (arr[right] < arr[left])
		{
			min = right;
		}
	}
	if (arr[i] <= arr[min])
	{
		return;
	}
	
	int temp = arr[min];
	arr[min] = arr[i];
	arr[i] = temp;
	//���ӵ�λ�÷����仯 ������Ҫ��������
	MinHeapFixDown( arr, min, n);
}
/*��������С����*/
void MinHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i --)
	{
		MinHeapFixDown(arr, i,  n);
	}
}

/*
����� ����ȫ������ ���� ������ȫ�����������һ��Ҷ�ӽ������俿��
����� �����������ԣ�
	1�������ļ�ֵ���Ǵ��ڻ���ڣ�С�ڻ���ڣ��κ�һ���ӽ��ļ�ֵ
	2��ÿ������������ �� ������ ��һ������ѣ��������ѻ�����С�ѣ�
�������ֵ���������ӽڵ��ֵ ---- �󶥶ѣ��������ʱ����
�������ֵ��С�����ӽڵ��ֵ ---- С���ѣ���������ǽ���
*/

/*
1���ѻ��� MinHeap(int arr[], int n)��					MaxHeapFixDown( arr, 0, x-1);
2�����������
*/
void HeapSort(int arr[], int n)
{
	//�ȶ�A ���жѻ�
	void MaxHeap(int arr[], int n);
	void MaxHeapFixDown(int arr[], int i, int n);
	//MinHeap( arr, n);
	MaxHeap( arr, n);
	//�ѶѶ���0��Ԫ�غ����һ��Ԫ�ضԵ�
	for (int x = n-1; x >= 0; x --)
	{
		swap( arr, 0, x);
		//MinHeapFixDown( arr, 0, x-1);
		MaxHeapFixDown( arr, 0, x-1);//ÿ�ζ�һ��
	}
	//��С�ѵķ�Χ���ԶѶ�Ԫ�ؽ������µ���
	
}

//=====================================================================================================================
void MaxHeapFixDown(int arr[], int i, int n) // ��Ҫ�Ƚϴ��� log ^ n  ÿ��һ���2��
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if (left >= n)
	{
		return;
	}
	
	int max = left;
	
	if (right >= n)
	{
		max = left;
	}
	else 
	{
		if (arr[right] > arr[left])
		{
			max = right;
		}
	}
	
	if (arr[i] > arr[max])
	{
		return;
	}
	
	int temp = arr[max];
	arr[max] = arr[i];
	arr[i] = temp;
	MaxHeapFixDown( arr, max, n);
}

void MaxHeap(int arr[], int n) //������  ��Ҫ������Ԫ�ظ�����(2/n)  ʱ�临�Ӷ���nlog^n
{
	for (int i = n / 2 - 1; i >= 0; i --)//ΪɶҪ��n/2 - 1 ��ʼ��Ϊ���һ�㶼��Ҷ�ӽ�� û���ӽ��
	{
		MaxHeapFixDown(arr, i, n);//�󶥶�
	}
}
//===========================================================================================================================
//���������ø�������������г��ֵ����ּ�����Ԫ��ת�±꣬�±�תԪ�ء�
//���� Ԫ�ؾ�����0�� ����ɨ��ԭ���飬��Ԫ��ֵK��¼�ڸ�������Kλ����
//����ɨ�踨�����飬���Ϊ1���������Ŀ������Ŀհ״��������⣺�ظ�Ԫ�ء��и�����
//�������� �ŵ� �� �����ݷ�Χ��Ƚ�ϡ�裩 �ᵼ�¸����ռ�ܴ�Ҳϡ�� ��ɿռ��˷�
//ʱ�临�Ӷ� N + k
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

//=====================================================================================================================
int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

//====================================================================
int main(void)
{
	
	clock_t start,end;
	time_t rm;
	
	unsigned int t = time(&rm);
	srand(t);
	
	int arr[100000] = {0};
	for (int i = 0; i < 100000; i ++)
	{
		arr[i] = rand();
	}
	start = clock();
	/*���پ��ֲ�*/
	//CountSort(arr, 100000);//�������� 0.030000s
	//HeapSort( arr, 100000);//�����򣨴󶥶ѣ� ʱ�临�Ӷ� �Ӵ�С O(NlgN) ԭֵ����
	//HeapSort( arr, 100000);//������С���ѣ���С����
	//MergeSort(arr, 0, 99999);//�鲢���� 0.050000 s
	//qsort(arr, 100000, sizeof(int), comp);//�������� 0.015000 s �������Դ��Ŀ�������
	//QuickSort_3( arr, 0, 99999);//�����зֵĿ������� 0.021000 s��
	QuickSort( arr, 0, 99999); // ����������ָ���������0.042000 s
	//QuickSort( arr, 0, 99999); // ��������˫��ɨ�跨��0.018000 s
	//QuickSort( arr, 0, 99999); // �������򣨵���ɨ�跨��0.019000 s
	/*=========================================================================================================*/
	/*����������*/
	//selectSort( arr, 100000);//ѡ������ 32.083000 s
	//insertSort( arr, 100000);//�������� 20.959000 s
	//bubbleSort( arr, 100000);//ð������ 37.978000 s
	//shellSort( arr, 100000); //ϣ������ 30.970000 s
	end = clock();
	
	printf("%lf s\n", (double)(end - start)/CLOCKS_PER_SEC);
	
	for (int i = 0; i < 100000; i ++)
	{
		printf("%d ", arr[i]);
	}
	
	getchar();
	return 0;
}