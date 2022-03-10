#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void Heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    while(l<n && arr[largest]<arr[l])
    {
        largest=l;
    }
    while(r<n && arr[largest]<arr[r])
    largest=r;
    if(largest!=i)
    {
        swap(&arr[largest],&arr[i]);
        Heapify(arr,n,largest);
    }
}
void Heap_Sort(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        Heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        Heapify(arr,i,0);
    }
}

int main()
{
    int n;
    printf("\nEnter number of elements want to add in the array :: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements in the array :: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("\nUnsorted array :: ");
    print(arr,n);
    Heap_Sort(arr,n);
    printf("\nSorted array :: ");
    print(arr,n);
}