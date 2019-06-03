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


void PercDown(int  A[], int i, int N)	//���ɶ�
{
    int child;
    ElementType Tmp;

    for (Tmp = A[i]; 2*i+1 < N; i = child){
        child = 2*i+1;				 //���ӽڵ�
        if (child != N - 1 && A[child + 1] > A[child])
            ++child;                //�ҵ����Ķ��ӽڵ�
        if (Tmp < A[child])			//���С������ӵ�ֵ���ͽ��Լ���ֵ��Ϊ����ӵ�ֵ
            A[i] = A[child];
        else
            break;					//�����˳��÷�Ҷ�ӽڵ������ѭ��
    }
    A[i] = Tmp;
}

void HeapSort(int A[], int N)	//����ÿ�ζ���������ŵ��Ѷ���Ȼ���������һ��δ��λ�ĵ㽻��
								//�����Ϳ��Եõ�һ���̶���˳��
{
    int i;
    for (i = N / 2; i >= 0; --i) //i=5,4,3,2,1,0
        PercDown(A, i, N);    //�����
    for(i=N-1;i>0;--i)//i=9, ... ,1
    {
        Swap(&A[0],&A[i]);        //�����Ԫ�أ�����������ĩβԪ�ؽ������Ӷ�ɾ�����Ԫ�أ����¹����
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