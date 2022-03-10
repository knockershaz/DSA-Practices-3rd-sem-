#include<stdio.h>
#include<conio.h>

int Linear_search(int arr[],int s,int e,int item)
{
    if(s<=e)
    {
        if(arr[s]==item){
            // printf("\n %d Item found",item);
            return item;
        }
        else
        Linear_search(arr,s+1,e,item);
    }
    else{
        // printf("Not found");
        return 0;
    }
}

int main()
{
    int n,i,item;
    printf("\nEnter how many values ::");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements of array ::");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value you want to search::");
    scanf("%d",& item);
    int search=Linear_search(arr,0,n-1,item);
    if (search==item){
    printf("\n %d item found in the list",item);
    }
    else
    {
    printf("\nValue not found!!!");
    }
}
// we cant write print statement in function we have to use return 
