# For searching a value, if we had a sorted array we could have performed a binary search. 
#  we use divide and conquer approach to achieve this. At each state half data is discarded. Binary search and hash tables give faster-searching capability.

# Algo-
# Find mid element
# If mid value less than searched element then increase lower index
# If mid value greater than searched element then decrease upper index

# Application-
# When you search for a name of song in a sorted list of songs, it performs binary search and string-matching to quickly return the results.
# Used to debug in git through git bisect

# find elemnet in sorted and unsorted list
class search:

    def binarySearch2(self, arr, n):
        lb = 0
        ub = len(arr) - 1
        found = False
        while found == False and  lb <= ub:
            mid = (lb + ub)//2
            if(arr[mid]== n):
                print('number found')
                found = True
                return mid
            elif(arr[mid]<n):
                lb = lb +1
            else:
                ub = ub-1
        if(found == False):
            print('not found')

    # Standard Binary Search function*/ 
    def binarySearch(self, arr, low, high, key): 
    
        if high < low: 
            return -1
            
        # low + (high - low)/2     
        mid = int((low + high)/2) 
        
        if key == arr[mid]: 
            return mid 
        if key > arr[mid]: 
            return self.binarySearch(arr, (mid + 1), high, 
                                                key) 
        return self.binarySearch(arr, low, (mid -1), key)
        
    def pivotedBinarySearch(self, arr, n, key): 
  
        pivot = self.findPivot(arr, 0, n-1) 
    
        # If we didn't find a pivot,  
        # then array is not rotated at all 
        if pivot == -1: 
            return self.binarySearch(arr, 0, n-1, key) 
    
        # If we found a pivot, then first 
        # compare with pivot and then 
        # search in two subarrays around pivot 
        if arr[pivot] == key: 
            return pivot 
        if arr[0] <= key: 
            return self.binarySearch(arr, 0, pivot-1, key) 
        return self.binarySearch(arr, pivot + 1, n-1, key) 
    # Function to get pivot. For array  
    # 3, 4, 5, 6, 1, 2 it returns 3  
    # (index of 6)  
    def findPivot(self, arr, low, high): 
        
        # base cases 
        if high < low: 
            return -1
        if high == low: 
            return low 
        
        # low + (high - low)/2 
        mid = int((low + high)/2) 
        
        if mid < high and arr[mid] > arr[mid + 1]: 
            return mid 
        if mid > low and arr[mid] < arr[mid - 1]: 
            return (mid-1) 
        if arr[low] >= arr[mid]: 
            return self.findPivot(arr, low, mid-1) 
        return self.findPivot(arr, mid + 1, high)
    #    improved version of above method : Instead of two or more pass of binary search the result can be found in one pass of binary search. 
    # Index by using recursive function
    def search (self, arr, l, h, key): 
        if l > h: 
            return -1
        
        mid = (l + h) // 2
        if arr[mid] == key: 
            return mid 
    
        # If arr[l...mid] is sorted  
        if arr[l] <= arr[mid]: 
    
            # As this subarray is sorted, we can quickly 
            # check if key lies in half or other half  
            if key >= arr[l] and key <= arr[mid]: 
                return self.search(arr, l, mid-1, key) 
            return self.search(arr, mid + 1, h, key) 
    
        # If arr[l..mid] is not sorted, then arr[mid... r] 
        # must be sorted 
        if key >= arr[mid] and key <= arr[h]: 
            return self.search(arr, mid + 1, h, key) 
        return self.search(arr, l, mid-1, key) 

    def countZeroes(self, arr, n):
        # code here
        if(arr[n-1] == 1):
            return 0
        if(arr[0] == 0):
            return n
        l = 0
        h = n-1
        while(l < h):
            mid = (l + h)//2
            if(arr[mid] == 0):
                h = mid
            else:
                l = mid + 1
        return n - h


a = search()


c = a.binarySearch2([3, 6, 8, 9, 10], 9)
print(c, 'num')

arr = ["Brian", "Joe", "Lois", "Meg", "Peter", "Stewie"]
b = a.binarySearch2(arr, "Stewie")
print(b, 'str')

print(a.pivotedBinarySearch(arr, 4, 5))

print(a.search(arr, 0, 4, 5))


print(a.countZeroes([1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0], 12))

# time  complexity O(log2N)

