/*
 Date : 17/05/25
 Platform : GFG
 Track : GFG-160-problems

Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into 
the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible 
order (i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

?Examples:

Input: arr[] = [2, 4, 1, 7, 5, 0]
?Output: [2, 4, 5, 0, 1, 7]
*Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.

Input: arr[] = [3, 2, 1]
?Output: [1, 2, 3]
*Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

Input: arr[] = [3, 4, 2, 5, 1]
?Output: [3, 4, 5, 1, 2]
*Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].


! Constraints:
! 0 ≤ arr.size() ≤ 10^5
! 0 ≤ arr[i] ≤ 10^5

*/

code:


class Solution {
    void nextPermutation(int[] arr) {
        
        int n = arr.length, idx = -1;
        
        // finding largest prefix
        for(int i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                idx = i;
                break;
            }
        }
        
        
        // return lowest possible order if next permutation not found -> reverse input array
        if(idx == -1){
            reverse(arr,0,n-1);
            return;
        }
        
        // swap the smallest greatest integer with the element found at idx
        for(int i=n-1; i>=idx; i--){
            if(arr[i] > arr[idx]){
                arr[i] = arr[i] + arr[idx];
                arr[idx] = arr[i] - arr[idx];
                arr[i] = arr[i] - arr[idx];
                break;
            }
        }
        
        // reverse the rem elements to the right of idx
        reverse(arr, idx+1, n-1);
    }
    
    void reverse(int[] arr, int left, int right){
         while(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

// time complexity = O(n)
// space complexity = O(1)