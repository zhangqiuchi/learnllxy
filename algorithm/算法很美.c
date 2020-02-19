#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
	递归思想：
	找重复  n * (n - 1) 求 n -1的阶乘是问题的重复 （规模更小）找到 规模更小的子问题
	找变化	变化量作为参数
	找边界	找出口
*/

//求阶乘
int n_n(int n)
{
	if (n == 0)
		return 1;
	
	return n * n_n(n-1);
}
//求数组的和
int n_n_n(int arr[], int len)
{
	if (len == 1)
		return arr[len - 1];
	return arr[len-1] + n_n_n(arr, len -1);
}

//字符串的反转
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
//斐波那契数列
int fb(int n)//n表示的是项数     
{
	if (n == 1||n == 2)
		return 1;
	return fb(n-1) + fb(n - 2);
}

//最大公约数
int gong(int m, int n)
{
	if (n == 0)
		return m;
	return gong(n, m%n);
}
//插入排序
/*
找到一种划分方法
找到递推公式或者等价转换
父问题转化求解子问题
*/
void insertsort(int arr[], int k)
{
	/*归并排序 选择排序 冒泡排序*/
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
	for (int i = 0; i < k-1; i ++)//记录循环次数的
	{
		for (int j = 0; j < k-1-i; j ++)//记录要比较次数的
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
//快排
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

int partiton(int arr[], int low, int high)//partiton 切开
{
	//快排法 定中值的方法
	//单项扫描法  1、定主元位置  2、扫描指针和最后的指针  3、小于等于主元 扫描指针右移 大于主元数据交换 最后指针左移
	/*int pivot = arr[low];//确定主元
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
	
	//双向扫描法 //双向扫描法 左边无大元素 右边无小元素
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

//希尔排序
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
	


//汉诺塔//角色在变化
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

//二分查找法  左边找 中间比 右边比(递归实现的二分查找法)
int binarySearch(int arr[], int low, int high, int key)
{
	if (low > high)
		return -1;
	int mid = low + ((high - low) >> 1);//左移是乘法 右移是除法
	int midVal = arr[mid];
	if (midVal < key)
		return binarySearch(arr, mid+1, high, key);
	else if (midVal > key)
		return binarySearch(arr, low, mid-1, key);
	else
		return mid;
}
//普通的二分查找法 左边查找和右边查找 只选其一
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

//子问题规模下降 子问题规模的处理 子问题答案处理所消耗的时间 //时间复杂度/空间复杂度   

//二分查找递增数组旋转后的最小值    最小值永远藏在无序的那边
int min(int arr[], int length)
{
	int begin = 0;
	int end = length;
	
	if (arr[begin] < arr[end])
		return arr[begin];
	
	while (begin + 1 < end)//不停的切割最后让begin + 1 = end begin和 end 指向相邻的元素就退出
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

/*查找有序的字符串数组中字符串的位置*/
int indexOf(char (*str)[3], int length, char *sstr)
{
	int begin = 0;
	int end = length;
	
	while (begin <= end)
	{
		int indexMid = begin + ((end - begin) >> 1);

		while (strcmp(str[indexMid], " ") == 0) // strcmp(，):两个字符串比较  相等就返回0 第一个字符串大于第二个字符串返回1 第一个字符串小于第二个字符串返回-1
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
/*最长连续递增子序列（部分有序）求其中最长的递增序列 (哨兵一个动一个不动)*/
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
				if (end - begin > sub) //要改变起始点的时候是数组个数最大的时候
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
		if (end - begin > sub) //满的时候是最好的一次
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


/*以尽量高的效率求出乱序数组中按数值顺序的第K个元素*/

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