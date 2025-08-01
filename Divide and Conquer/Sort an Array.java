/*

Question : 912. Sort an Array
Date : 20-07-25
Problem Difficulty level : Medium
Related Topics : Array, Divide and Conquer, Sorting, Heap (Priority Queue), Merge Sort, Bucket Sort, Radix Sort, Counting Sort

Problem Statement:
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

? Example 1:
! Input: nums = [5,2,3,1]
! Output: [1,2,3,5]
* Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

? Example 2:
! Input: nums = [5,1,1,2,0,0]
! Output: [0,0,1,1,2,5]
* Explanation: Note that the values of nums are not necessarily unique.

? Constraints:
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4

*/

class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        mergeSort(nums, 0, n-1);
        return nums;
    }

    public void mergeSort(int[] nums, int low, int high){
        if (low>= high)
            return;
        
        int mid = (low + high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }

    public void merge(int[] arr, int low, int mid, int high){
        int[] temp = new int[high-low+1];
        int k=0, i=low, j=mid+1;

        while(i<=mid && j<=high){
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while(i<=mid){
            temp[k++] = arr[i++];
        }

        while(j<= high){
            temp[k++] = arr[j++];
        }

        for(int p=0; p<temp.length; p++){
            arr[low+p] = temp[p];
        }
    }

    // time complexity = O(nlogn)
    // space complexity = O(n)

}