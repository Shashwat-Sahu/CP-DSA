# Insertion sort also takes n-1 passes to complete
# In this algorithm a sorted and unsorted part is created
# Firstly a single element is picked which becomes the sorted part and the rest of the elements become part of unsorted collection.
# Then during each iteration the first element of unsorted collection is taken and inserted in appropriate position in the sorted collection.
# This goes on until the sorted collection is complete or unsorted collection is empty.
# Worst Time Complexity: O(n^2)
# Average Time Complexity: O(n^2)
# Best Time Complexity: O(n)

print("Number Sequence Before Insertion Sort")
seq=[5,2,1,8,3,5,3]
print(seq)

def insertionSort(nums):
    n=len(nums)
    for i in range(1,n):
        hole=i
        value=nums[i]
        while(hole>0 and nums[hole-1]>value):
            nums[hole]=nums[hole-1]
            hole-=1
        nums[hole]=value
    return nums

print("Number Sequence After Insertion Sort")
print(insertionSort(seq))
