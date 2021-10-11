# It is rarely used here we iterate each element.
def linearSearch(self, arr, n):
    for i in range(0, len(arr)):
        if(arr[i]== n):
            return i
    return -1

arr = [2, 5, 9 , 0]

elem = linearSearch(arr, 6)
print(elem)
# complexity O(n)
