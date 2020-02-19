#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
	�ݹ�˼�룺
	���ظ�  n * (n - 1) �� n -1�Ľ׳���������ظ� ����ģ��С���ҵ� ��ģ��С��������
	�ұ仯	�仯����Ϊ����
	�ұ߽�	�ҳ���
*/

//��׳�
int n_n(int n)
{
	if (n == 0)
		return 1;
	
	return n * n_n(n-1);
}
//������ĺ�
int n_n_n(int arr[], int len)
{
	if (len == 1)
		return arr[len - 1];
	return arr[len-1] + n_n_n(arr, len -1);
}

//�ַ����ķ�ת
void reverse(char* str, int n)
{
	if(n<0) 
		return;
	else
	{
		char p1=*str;
		*str=*(str+n);
		*(str+n)=p1;
		reverse(str+1,n-2);
	}

	
}
//쳲���������
int fb(int n)//n��ʾ��������     
{
	if (n == 1||n == 2)
		return 1;
	return fb(n-1) + fb(n - 2);
}

//���Լ��
int gong(int m, int n)
{
	if (n == 0)
		return m;
	return gong(n, m%n);
}
//��������
/*
�ҵ�һ�ֻ��ַ���
�ҵ����ƹ�ʽ���ߵȼ�ת��
������ת�����������
*/
void insertsort(int arr[], int k)
{
	/*�鲢���� ѡ������ ð������*/
	/*
	if (k == 0)
		return;
	
	insertsort(arr, k-1);//1
	
	int x = arr[k];
	int index = k-1;
	
	while (x < arr[index])
	{
		arr[index+1] = arr[index];
		index --;
	}
	arr[index+1] = x;
	*/
	/*
	for(int i = 0; i < k; i ++)
	{
		for (int j = i + 1; j < k; j ++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}*/
	/*
	for (int i = 0; i < k-1; i ++)//��¼ѭ��������
	{
		for (int j = 0; j < k-1-i; j ++)//��¼Ҫ�Ƚϴ�����
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	*/
	/*
	for (int i = 1; i < k; i ++)
	{
		for (int j = i; j>0; j --)
		{
			if (arr[j-1] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	*/
}
//����
int partiton(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high)
{
	if (high <= low) return;
	int j = partiton(arr, low, high);
	QuickSort(arr, low, j-1);
	QuickSort(arr, j+1, high);
}

void Swap(int arr[], int target1, int target2)
{
	int temp = arr[target1];
	arr[target1] = arr[target2];
	arr[target2] = temp;
}

int partiton(int arr[], int low, int high)//partiton �п�
{
	//���ŷ� ����ֵ�ķ���
	//����ɨ�跨  1������Ԫλ��  2��ɨ��ָ�������ָ��  3��С�ڵ�����Ԫ ɨ��ָ������ ������Ԫ���ݽ��� ���ָ������
	/*int pivot = arr[low];//ȷ����Ԫ
	int scanner = low + 1;
	int bigger = high;
	while (scanner <= bigger)
	{
		if (arr[scanner] <= pivot)
		{
			scanner ++;
		}
		else // arr[scanner] > pivot
		{
			Swap(arr, bigger, scanner);
			bigger --;
		}
	}
	Swap(arr, bigger, low);
	return bigger;*/
	
	//˫��ɨ�跨 //˫��ɨ�跨 ����޴�Ԫ�� �ұ���СԪ��
	int scanner = low + 1;
	int pivot = arr[low];
	int bigger = high;
	
	while (scanner <= bigger)
	{
		while(scanner <= bigger && scanner <= high && arr[scanner] <= pivot) scanner ++;
		while(scanner <= bigger && bigger >= low && arr[bigger] > pivot) bigger --;
		if (scanner < bigger)
		{
			Swap(arr,bigger,scanner);
		}
	}
	Swap(arr,bigger, low);
	return bigger;
}





//==================================================================================================

//ϣ������
void shellSort(int arr[], int length)
{
	for (int interval = length/2; interval > 0; interval = interval / 2)
	{
		for (int i = interval; i < length; i ++)
		{
			/*int target = arr[i];
			int j = i - interval;
			for (;j > -1; j -= interval)
			{
				if (target < arr[j])
				arr[j + interval] = arr[j];
				
			}
			arr[j+interval] = target;*/
		for (int j = i; j > 0; j -= interval)
			if (arr[j-interval] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j-interval];
				arr[j-interval] = temp;
			}
		}
	}
}
	


//��ŵ��//��ɫ�ڱ仯
void move(char a, char b)
{
	printf("%c -> %c\n", a, b);
}

void hannuota(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a,c);
		return;
	}
	else
	{
		hannuota(n-1,a,c,b);
		move(a,c);
		hannuota(n-1,b,a,c);
	}
	
}

//���ֲ��ҷ�  ����� �м�� �ұ߱�(�ݹ�ʵ�ֵĶ��ֲ��ҷ�)
int binarySearch(int arr[], int low, int high, int key)
{
	if (low > high)
		return -1;
	int mid = low + ((high - low) >> 1);//�����ǳ˷� �����ǳ���
	int midVal = arr[mid];
	if (midVal < key)
		return binarySearch(arr, mid+1, high, key);
	else if (midVal > key)
		return binarySearch(arr, low, mid-1, key);
	else
		return mid;
}
//��ͨ�Ķ��ֲ��ҷ� ��߲��Һ��ұ߲��� ֻѡ��һ
int binarySearch2(int arr[], int low, int high, int key)
{
	if (low > high)
	{
		return -1;
	}
	
	int mid = low + ((high - low) >> 1);
	int midVal = arr[mid];
	
	while (midVal != key)
	{
		if (midVal < key)
		{
			mid = (mid + 1) + ((high - (mid + 1)) >> 1);
			midVal = arr[mid];
		}
		else if (midVal > key)
		{
			mid = low + (((mid-1) - low) >> 1);
			midVal = arr[mid];
		}
	}
	
	return mid;
}

//�������ģ�½� �������ģ�Ĵ��� ������𰸴��������ĵ�ʱ�� //ʱ�临�Ӷ�/�ռ临�Ӷ�   

//���ֲ��ҵ���������ת�����Сֵ    ��Сֵ��Զ����������Ǳ�
int min(int arr[], int length)
{
	int begin = 0;
	int end = length;
	
	if (arr[begin] < arr[end])
		return arr[begin];
	
	while (begin + 1 < end)//��ͣ���и������begin + 1 = end begin�� end ָ�����ڵ�Ԫ�ؾ��˳�
	{
		int mid = begin+((end - begin) >> 1);
		if (arr[mid] > arr[begin])
			begin = mid; 
		else if (arr[mid] < arr[end])
			end = mid;
		else if (arr[mid] == arr[begin] ||
				arr[mid] == arr[end])
				break;
	}
	
	for (int i = 0; i < length+1; i ++)
		for (int j = i + 1; j < length+1; j ++)
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	
	return arr[end];
}

/*����������ַ����������ַ�����λ��*/
int indexOf(char (*str)[3], int length, char *sstr)
{
	int begin = 0;
	int end = length;
	
	while (begin <= end)
	{
		int indexMid = begin + ((end - begin) >> 1);

		while (strcmp(str[indexMid], " ") == 0) // strcmp(��):�����ַ����Ƚ�  ��Ⱦͷ���0 ��һ���ַ������ڵڶ����ַ�������1 ��һ���ַ���С�ڵڶ����ַ�������-1
		{
			indexMid ++;
			if (indexMid > end)
				return -1;
		}
		
		if (strcmp(str[indexMid], sstr) > 0)
			end = indexMid - 1;
		else if (strcmp(str[indexMid], sstr) < 0)
			begin = indexMid + 1;
		else
			return indexMid;
	}
	
	return -1;
}
/*��������������У�����������������ĵ������� (�ڱ�һ����һ������)*/
int increaseInterval(int arr[], int length)
{
	//int count = 1;
	int i = 0;
	int sub = 0;
	int low = 0;
	int high = 0;
	int begin = 0,end = 0;
	while(begin < length)
	{
		for (; end < length-1; end ++)
		{
			if (arr[end] > arr[end + 1])
			{
				if (end - begin > sub) //Ҫ�ı���ʼ���ʱ���������������ʱ��
				{
					low = begin;
					high = end;
				}
				begin = end+1;
				end = begin;
				break;
			}
			//count ++;
		}
		if (end - begin > sub) //����ʱ������õ�һ��
		{
			low = begin;
			high = end;
		}
		
		if (end+1 == length)
		{
			/*if (i < count)
		{
			i = count;
		}*/
			break;
		}
		/*if (i < count)
		{
			i = count;
		}
		count = 1;*/
	}
	
	for (i = low; i <= high; i ++)
		printf("%d ", arr[i]);
	printf("\n");
	return i-low;
}

void odd_even(int arr[], int length)
{
	int left = 0;
	int right = length - 1; 
	/*
	while (left <= right)
	{
		if (arr[left] % 2 == 0)
		{
			Swap(arr, left, right);
			right --;
		}
		else
		{
			left ++;
		}
	}
	*/
	
	while (left < right)
	{
		while (arr[left] % 2 != 0 && left < right)
		{
			left ++;
		}
		while (arr[right] % 2 == 0 && left < right)
		{
			right --;
		}
		Swap(arr, left, right);
	}
	
	
}


/*�Ծ����ߵ�Ч��������������а���ֵ˳��ĵ�K��Ԫ��*/

int partitionK(int arr[], int low, int high)
{
	int pivot = arr[low];
	int scanner = low + 1;
	int bigger = high;
	
	while (scanner <= bigger)
	{
		while (scanner <= bigger && arr[scanner] <= pivot) scanner ++;
		while (scanner <= bigger && arr[bigger] > pivot) bigger --;
		
		if (scanner < bigger)
			Swap(arr, bigger, scanner);
	}
	
	Swap(arr, bigger, low);
	return bigger;
}

int selectK(int arr[], int low, int high, int k)
{
	int q = partitionK(arr, low, high);
	int qk = q-low + 1;
	if (qk == k) 
		return arr[q];
	else if (qk > k) 
		return selectK(arr, low, q-1, k);
	else
		return selectK(arr, q+1, high, k-qk);
}


int main(void)
{
	
	//char str[][3] = {"a", " ", "ab", "ac","b", " ", "ba"};
	//int a = indexOf(str, 7, "ab");
	//printf("%d", a);
	
	int arr[] = {1,5,3,4,6,8,2,0,2,1};
	//int a = increaseInterval(arr, 10);
	int a = selectK( arr, 0, 9, 6);
	//odd_even(arr, 10);
	printf("%d\n", a);
	
	for (int i = 0; i < 10; i ++)
		printf("%d ", arr[i]);
	
	
	/*int start,end;
	start = clock();
	time_t rm;
	unsigned int t = time(&rm);
	srand(t);
	int arr[100000] = {0};
	for (int i = 0; i < 100000; i ++)
		arr[i] = rand();
	//QuickSort(arr, 0, 99999);
	odd_even(arr, 100000);
	end = clock();
	
	printf("%d\n", end - start);
	
	for (int i = 0; i < 100000; i ++)
		printf("%d ", arr[i]);
	*/
	
	getchar();
	return 0;
}