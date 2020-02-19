#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//=======================================================================================================================
/*希尔排序*/
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
/*插入排序*/
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
/*冒泡排序*/
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
/*选择排序*/
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
/*快速排序（n log^n）*/
void swap(int arr[], int target1, int target2)
{
	int temp = arr[target1];
	arr[target1] = arr[target2];
	arr[target2] = temp;
}
/*单向*/
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
		else// arr[scanner] > pivot 分的目的是分完后 主元的左边小于主元 右边要大于主元 
		{
			swap(arr, bigger, scanner);
			bigger --;
		}
	}
	
	swap(arr, bigger, low);
	return bigger;
}


/*双向*/
int two_way_partiton(int arr[],int low,int high)
{
	//工程当中的优化 主要是对选择主元元素的优化（工程中主要使用 三点中值法 和 绝对中值法）
	//三点中值法 从 中间点 起始点 结束点 当中挑选 小于 中间点 大于 另一个起始点或结束点的值
	//绝对中值法 
	//(当排序列表短的时候直接用插入排序)
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
/*三区间 三分法*/
//小于主元 
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
	//当 待排序的元素小于或者等于一个数字的时候 直接使用选择排序（黑科技）
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
/*归并排序    比较 归并排序 和 快速排序*/ 
void mearge(int arr[], int low, int middle, int high);
void MergeSort(int arr[], int low, int high)
{
	//两只队伍之间的比较
	/*
	分解
	解决
	合并
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
//(快排的应用 )  快排中 怕partiton分割的应用) 
int selectK(int arr[], int low, int high, int k)
{
	//k 指的是第几个
	int q = two_way_partiton( arr, low, high);// 切 割 
	int qk = q - low + 1;//主元是第几个元素
	
	if (qk == k)//等于等于
	{		
		return arr[q];
	}
	else if (qk > k)
	{		
		return selectK(arr, low, q-1, k);
	}
	else
	{
		return selectK(arr, q+1, high, k - qk);// k - qk 是留下来的剩下的一半的第几个？  因为k>qk的
	}
}
//===========================================================================================================================
/*将数组变成小顶堆*/
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
	//孩子的位置发生变化 所以需要继续调整
	MinHeapFixDown( arr, min, n);
}
/*将数组变成小顶堆*/
void MinHeap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i --)
	{
		MinHeapFixDown(arr, i,  n);
	}
}

/*
二叉堆 是完全二叉树 或者 近似完全二叉树（最后一层叶子结点往左变靠）
二叉堆 满足两个特性：
	1、父结点的键值总是大于或等于（小于或等于）任何一个子结点的键值
	2、每个结点的左子树 和 右子树 是一个二叉堆（都是最大堆或者最小堆）
任意结点的值都大于其子节点的值 ---- 大顶堆（排序出来时升序）
任意结点的值都小于其子节点的值 ---- 小顶堆（排序出来是降序）
*/

/*
1、堆化： MinHeap(int arr[], int n)；					MaxHeapFixDown( arr, 0, x-1);
2、按序输出：
*/
void HeapSort(int arr[], int n)
{
	//先对A 进行堆化
	void MaxHeap(int arr[], int n);
	void MaxHeapFixDown(int arr[], int i, int n);
	//MinHeap( arr, n);
	MaxHeap( arr, n);
	//把堆顶，0号元素和最后一个元素对调
	for (int x = n-1; x >= 0; x --)
	{
		swap( arr, 0, x);
		//MinHeapFixDown( arr, 0, x-1);
		MaxHeapFixDown( arr, 0, x-1);//每次丢一个
	}
	//缩小堆的范围，对堆顶元素进行向下调整
	
}

//=====================================================================================================================
void MaxHeapFixDown(int arr[], int i, int n) // 需要比较次数 log ^ n  每下一层比2次
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

void MaxHeap(int arr[], int n) //创建堆  需要调整的元素个数是(2/n)  时间复杂度是nlog^n
{
	for (int i = n / 2 - 1; i >= 0; i --)//为啥要从n/2 - 1 开始因为最后一层都是叶子结点 没有子结点
	{
		MaxHeapFixDown(arr, i, n);//大顶堆
	}
}
//===========================================================================================================================
//计数排序：用辅助数组对数组中出现的数字计数，元素转下标，下标转元素。
//假设 元素均大于0， 依次扫描原数组，将元素值K记录在辅助数组K位置上
//依次扫描辅助数组，如果为1，将其插入目标数组的空白处。（问题：重复元素、有负数）
//计数排序 优点 快 （数据范围大比较稀疏） 会导致辅助空间很大也稀疏 造成空间浪费
//时间复杂度 N + k
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
	return arr[length-1];//返回 6
}

void CountSort(int arr[], int length)//length 为7
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
	/*神速俱乐部*/
	//CountSort(arr, 100000);//计数排序 0.030000s
	//HeapSort( arr, 100000);//堆排序（大顶堆） 时间复杂度 从大到小 O(NlgN) 原值排序
	//HeapSort( arr, 100000);//堆排序（小顶堆）从小到大
	//MergeSort(arr, 0, 99999);//归并排序 0.050000 s
	//qsort(arr, 100000, sizeof(int), comp);//快速排序 0.015000 s 函数库自带的快速排序
	//QuickSort_3( arr, 0, 99999);//三向切分的快速排序 0.021000 s·
	QuickSort( arr, 0, 99999); // 快速排序（三指针分区法）0.042000 s
	//QuickSort( arr, 0, 99999); // 快速排序（双向扫描法）0.018000 s
	//QuickSort( arr, 0, 99999); // 快速排序（单向扫描法）0.019000 s
	/*=========================================================================================================*/
	/*慢性子天堂*/
	//selectSort( arr, 100000);//选择排序 32.083000 s
	//insertSort( arr, 100000);//插入排序 20.959000 s
	//bubbleSort( arr, 100000);//冒泡排序 37.978000 s
	//shellSort( arr, 100000); //希尔排序 30.970000 s
	end = clock();
	
	printf("%lf s\n", (double)(end - start)/CLOCKS_PER_SEC);
	
	for (int i = 0; i < 100000; i ++)
	{
		printf("%d ", arr[i]);
	}
	
	getchar();
	return 0;
}