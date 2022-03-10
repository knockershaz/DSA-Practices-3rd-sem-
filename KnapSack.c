#include<stdio.h>

void swap(int *u,int *v)
{
    int temp=*u;
    *u=*v;
    *v=temp;
}

void knapsack(int n,float weight[],float profit[],int capacity)
{
    int i,j,u;
    float x[20],tp=0;
    u=capacity;

    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }

    for(i=0;i<n;i++)
    {
        
        if(weight[i]>u)
        break;
        else
        {
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }

    if(i<n)
    {
        x[i]=(u/weight[i]);
        tp=tp+(x[i]*profit[i]);
    }

    printf("\nThe resultant quantity is :: ");
    for(i=0;i<n;i++)
    {
        printf("%.2f\t",x[i]);
    }

    printf("\nTotal profit is %.2f",tp);
}
int main()
{
    float weight[20],profit[20],capacity;
    int num,i,j;
    float ratio[20];

    printf("\nEnter the number of objects :: ");
    scanf("%d",&num);

    printf("Enter the capacity :: ");
    scanf("%f",&capacity);

    printf("\nEnter the weights and profits of each objects :: \n");
    for(i=0;i<num;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
    }
    for(i=0;i<num;i++)
    {
        ratio[i]=(profit[i]/weight[i]);
    }

    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(ratio[i]<ratio[j])
            {
                swap(&ratio[i],&ratio[j]);
                swap(&weight[i],&weight[j]);
                swap(&profit[i],&profit[j]);
            }
        }
    }
    knapsack(num,weight,profit,capacity);
    return(0);
}