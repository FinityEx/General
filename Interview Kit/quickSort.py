"""Showcase of a really easy implementation of quickSort, using last element of an array as the pivot"""

import random

arr = list()

for _ in range(0, 50): #populate the list randomly
    arr.append(random.randint(0, 100))

print("Array before sorting:\n", arr)

def quickSort(arr):
    if len(arr) <= 1:
        return arr #if arr has one element or less, there's nothing to sort
    
    else:
        piv = arr.pop() #set last array element as pivot
        
    arr_smaller = list() #list of items smaller than pivot
    arr_greater = list() #list of items greater than pivot
    
    for element in arr: #adding smaller elements to lists
        if element < piv:
            arr_smaller.append(element)
        else:
            arr_greater.append(element)
            
    return quickSort(arr_smaller) + [piv] + quickSort(arr_greater) #function returning itself until all is sorted

print("\nSorted array:\n", quickSort(arr))