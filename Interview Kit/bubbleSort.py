"""Showcase of bubble sort algorithm with bit of optimisation implemented"""


import random

arr = list()

for _ in range(0, 50):
    arr.append(random.randint(0, 100))

print("Array before sorting:\n", arr)


for _ in range(len(arr)):
    sort = False
    for index in range(0, len(arr)-1):
        if arr[index] > arr[index+1]:
            arr[index], arr[index+1] = arr[index+1], arr[index]
            sort = True
            
    if sort == False:
        break

print("\nSorted array:\n", arr)