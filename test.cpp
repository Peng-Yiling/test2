#include<stdio.h>
typedef int ElementType;
int arr1[11]={0,2,87,39,49,34,62,53,6,44,98};
#define LeftChild(i) (2 * (i) + 1)

void Swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


void PercDown(int  A[], int i, int N)	//构成堆
{
    int child;
    ElementType Tmp;

    for (Tmp = A[i]; 2*i+1 < N; i = child){
        child = 2*i+1;				 //左孩子节点
        if (child != N - 1 && A[child + 1] > A[child])
            ++child;                //找到最大的儿子节点
        if (Tmp < A[child])			//如果小于最大孩子的值，就将自己的值变为最大孩子的值
            A[i] = A[child];
        else
            break;					//否则，退出该非叶子节点的所有循环
    }
    A[i] = Tmp;
}

void HeapSort(int A[], int N)	//排序，每次都把最大数排到堆顶，然后再与最后一个未定位的点交换
								//这样就可以得到一个固定的顺序
{
    int i;
    for (i = N / 2; i >= 0; --i) //i=5,4,3,2,1,0
        PercDown(A, i, N);    //构造堆
    for(i=N-1;i>0;--i)//i=9, ... ,1
    {
        Swap(&A[0],&A[i]);        //将最大元素（根）与数组末尾元素交换，从而删除最大元素，重新构造堆
        PercDown(A, 0, i);
    }
}

void Print(int A[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf(" %d ",A[i]);
    }
}
int main()
{
    int arr[10]={2,87,39,49,34,62,53,6,44,98};
    Print(arr,10);
    printf("\n");
    HeapSort(arr,10);
    Print(arr,10);
    printf("\n");
    return 0;
}