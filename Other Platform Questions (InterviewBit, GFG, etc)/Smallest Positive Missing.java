/*
Date : 05/06/25
Platform : GFG
Track : GFG-160-problems
Difficulty: Medium

You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

?Examples:
Input: prices[] = [2, -3, 4, 1, 1, 7]
? Output: 3
*Explanation: Smallest positive missing number is 3.

Input: prices[] = [5, 3, 2, 5, 1]
? Output: 4
*Explanation: Smallest positive missing number is 4.

Input: prices[] = [-8, 0, -1, -4, -3]
? Output: 1
*Explanation: Smallest positive missing number is 1.

!Constraints:
! 1 <= arr.size() <= 10^5
! -10^6 <= arr[i] <= 10^6

*/

code:

// User function Template for Java

class Solution {
    // Function to find the smallest positive number missing from the array.
    public int missingNumber(int[] nums) {
        
        int n = nums.length;
        for(int i=0; i<n; i++){
            int x = nums[i]; // current element

            // x>=1 and x<=n is the check for positive integer and range
            // x!= i+1 is to check if correct index value is there
            // nums[x-1]!=x is to check if element at x-1 is correct or not
            
            while(x>=1 && x<=n && x!= i+1 && nums[x-1] != x){
                int temp = nums[i];
                nums[i] = nums[x-1];
                nums[x-1] = temp;
                x = nums[i];
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        
        return n+1;
        
        // time = O(n)
        // space = O(1)
    }
}
