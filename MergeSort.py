def Mergeing(A,l,h,mid):
    n1=mid-l+1
    n2=h-mid
    X=[0]*(n1)
    Y=[0]*(n2)
    for i in range(0,n1):
        X[i]=A[l+i]
    for j in range(0,n2):
        Y[j]=A[mid+1+j]
    i=0
    j=0
    k=l
    while(i<n1 and j<n2):
        if(X[i]<=Y[j]):
            A[k]=X[i]
            i=i+1
        else:
            A[k]=Y[j]
            j=j+1
        k=k+1
    while(i<n1):
        A[k]=X[i]
        k=k+1
        i=i+1
    while(j<n2):
        k=k+1
        j=j+1
def MergeSort(A,l,h):
    if l<h :
        mid=l+(h-l)//2
        MergeSort(A,l,mid)
        MergeSort(A,mid+1,h)
        Mergeing(A,l,h,mid)

def print_it(A,n):
    for i in range(0,n,1):
        print("%d"% A[i],end=" ")

A=[2,5,8,35,6,42,4]
n=len(A)
print("\nUnsorted array :")
print_it(A,n)
MergeSort(A,0,n-1)
print("\nSorted array :")
print_it(A,n)
