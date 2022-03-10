def JobSequencing(arr,t):
    n=len(arr)

    for i in range(n):
        for j in range(n-1-i):
            if(arr[j][2]<arr[j+1][2]):
                arr[j],arr[j+1]=arr[j+1],arr[j]

    slot=[False]*t
    job=[-1]*t

    for i in range(n):
        for j in range(min(t-1,arr[i][1]-1),-1,-1):
            if slot[j] is False:
                slot[j]=True
                job[j]=arr[i][0]
                break

    print(job)

# arr=[['a',2,50],
#     ['b',1,15],
#     ['c',2,10],
#     ['d',1,25]]

# JobSequencing(arr,2)

arr=[]
n=int(input("Enter how many jobs are there ::"))
for i in range(n):
    arr.append([])
for i in range(n):
    for j in range(1):
        arr[i].append(str(input("Enter job name :: ")))
        arr[i].append(int(input("Enter Deadline :: ")))
        arr[i].append(int(input("Enter profit :: ")))
# print(arr)
m=[]
for i in range(n):
    m.append((arr[i][1]))
# print(m)
t=max(m)
# print(t)
print("\n The job sequencing will be done on this basis :: \n")
JobSequencing(arr,t)