'''
 * Find the Minimum length Unsorted Subarray,
 * sorting which makes the complete array sorted

Given an unsorted array arr[0..n-1] of size n,
find the minimum length subarray arr[s..e] such that
sorting this subarray makes the whole array sorted.

 * Examples: 
1) If the input array is
    [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60],
    your program should be able to find that the subarray
    lies between the indexes 3 and 8.
2) If the input array is
    [0, 1, 15, 25, 6, 7, 30, 40, 50],
    your program should be able to find that the subarray
    lies between the indexes 2 and 5.

'''


from distutils.command.build_scripts import first_line_re
from copy import deepcopy

def minimumUnsortedArray( arr ):
    n = len(arr)

    begin = 0
    end = 0

    #Finding the first disturbance
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            begin = i
            break

    #Finding the second disturbance
    for i in range(n-1,0,-1):
        if arr[i] < arr[i-1]:
            end = i
            break

    #Check if the array is sorted (just in case)
    if begin == end:
        return begin,end

    max = deepcopy(begin)
    min = deepcopy(end)

    #Get the minimum and maximum elements in the array
    for i in range( begin, end+1):
        if arr[i] > arr[max]: max = i
        if arr[i] < arr[min]: min = i
    
    beg2 = deepcopy(begin)
    end2 = deepcopy(end)

    #Get the smallest element greater than min
    for i in range(0,begin):
        if arr[i] > arr[min]:
            beg2 = i
            break

    #Largest number smaller than max
    for i in range(n-1,end,-1):
        if arr[i] < arr[max]:
            end2 = i
            break
    
    return beg2, end2

if __name__ == '__main__':
    beg, end = minimumUnsortedArray( [1, 3, 4, 5, 2, 7, 6, 8, 9] )  # case 1, kinda normal
    print( 'Begin: ',beg, ' End: ', end )
    beg, end = minimumUnsortedArray(
        [2, 3, 4, 1, 9, 8, 6, 7, 5])  # case 2, two sided shithead
    print('Begin: ', beg, ' End: ', end)
    beg, end = minimumUnsortedArray(
        [1, 2, 3, 4, 5, 9, 7, 6, 8])  # case 3, one sided shithead
    print('Begin: ', beg, ' End: ', end)
    beg, end = minimumUnsortedArray(
        [9, 8, 7, 6, 5, 4, 3, 2, 1])  # case 4, reverse sorted
    print('Begin: ', beg, ' End: ', end)
    beg, end = minimumUnsortedArray(
        [1, 2, 3, 4, 5, 6, 7, 8, 9] )  # case 5, straight sorted
    print( 'Begin: ',beg, ' End: ', end )