/*
Date : 14/07/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Medium

Problem Statement:
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:
? Input: arr[] = [2, 4, 1, 3, 5]
? Output: 3
* Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

? Input: arr[] = [2, 3, 4, 5, 6]
? Output: 0
* Explanation: As the sequence is already sorted so there is no inversion count.

? Input: arr[] = [10, 10, 10]
? Output: 0
* Explanation: As all the elements of array are same, so there is no inversion count.

Constraints:
! 1 ≤ arr.size() ≤ 10^5
! 1 ≤ arr[i] ≤ 10^4

*/


class Solution {
    
    static int count = 0;
    
    static int inversionCount(int arr[]) {
        int n = arr.length;
        count = 0;
        mergeSort(arr, 0, n-1);
        
        return count;
    }
    
    static void mergeSort(int[] arr, int low, int high){
        
        if(low >= high)
            return;
            
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
        
    }
    
    static void merge(int[] arr, int low, int mid, int high){
        int k =0, i = low, j = mid + 1;
        int[] temp = new int[high - low + 1];
        
        while(i<= mid && j<= high){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            } else{
                count += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= high){
            temp[k++] = arr[j++];
        }
        
        
        for(int p = 0; p<temp.length; p++){
            arr[low + p] = temp[p];
        }
    }
}

// time complexity = O(n log n)
// space complexity = O(n)