#include<stdio.h>

int Binary_Search(int A[],int l,int h,int val)
{
    int mid=(l+h)/2;
    if(A[mid]==val){
    return mid;
    }
    if(A[mid]>val)
    {
        Binary_Search(A,l,mid-1,val);
    }
    else{
        Binary_Search(A,mid+1,h,val);
    }
}
int main()
    {
        int val;
        int A[]={1,2,3,4,5,6,7,8};
        int n=sizeof(A)/sizeof(A[0]);
        printf("Enter value to search :");
        scanf("%d",&val);
        int mid=Binary_Search(A,0,n-1,val);
        printf("Value %d is found at %d",val,mid);
        return 0;
    }