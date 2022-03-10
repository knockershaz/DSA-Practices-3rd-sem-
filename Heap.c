#include<stdio.h>
int n=0;
void swap(int *u,int *v)
{
    int temp=*u;
    *u=*v;
    *v=temp;
}

void Heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    while(l<n && arr[largest]<arr[l])
        largest=l;
    while(r<n && arr[largest]<arr[r])
        largest=r;

    if(largest!=i)
    {
        swap(&arr[largest],&arr[i]);
        Heapify(arr,n,largest);
    }
}

void Insert(int A[],int val)
{
    if(n==0)
    {
        A[0]=val;
        n+=1;
    }
    else
    {
        A[n]=val;
        n+=1;
        for(int i=n/2-1;i>=0;i--)
        {
            Heapify(A,n,i);
        }
    }
}

void delete(int A[], int value)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(value==A[i])
        break;
    }
    swap(&A[i],&A[n-1]);
    n-=1;
    for(i=n/2-1;i>=0;i--)
    {
        Heapify(A,n,i);
    }
}

void print(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            printf("%d ",A[i]);
        }
}


int main()
{
    int A[10];
    // int n=0; //sizeof(A)/sizeof(A[0]);
    int c,i;
    printf("\n=====HEAP=====\n");
    do{
    printf("\n\n1.Build Max Heap \n2.Insertion \n3.Deletion \n4.Display \n5.HeapSort\n");
    printf("\nWhat operation you want to perform :: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
        
            for(i=n/2-1;i>=0;i--)
            {
                Heapify(A,n,i);
            }
            break;
        }
        case 2:
        {
            
            int val;
            printf("\nEnter the value you want to add :: ");
            scanf("%d",&val);
            Insert(A,val);
            break;
        }
        case 3:
        {
            int value;
            printf("\nEnter the value you want to delete :: ");
            scanf("%d",&value);
            delete(A,value);
            break;
        }
        case 4:
        {
            
            printf("\nElements in the Heap :: ");
            print(A,n);
            break;
        }
        case 5:
        {
            printf("\nHeapSort :: ");
            for(i=n/2-1;i>=0;i--)
            {
                Heapify(A,n,i);
            }
            for(i=n-1;i>=0;i--)
            {
                swap(&A[i],&A[0]);
                Heapify(A,i,0);
            }
            print(A,n);
            break;
        }
        default:
        {
            printf("\nInvalid choice :: ");
            break;
        }
    }
    }while(1);

}