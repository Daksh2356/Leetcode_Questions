/*
!Question : 852. Peak Index in a Mountain Array
?Date : 13-03-25
Problem Difficulty level : Medium
Related Topics : Array, Binary Search

Problem Statement:
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
 

! Constraints:
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.


*/
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        
        int n = arr.length;
        int high = n-1;
        int low = 0;
        int mid;

        while(low != high){
            mid = (low+high)/2;
            if(arr[mid] > arr[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;

        // time complexity = O(logn)
        // space complexity = O(1)
    }
}