/*
 Date : 11/05/25
 Platform : GFG
 Track : GFG-160-problems

You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the array to the right end 
while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you 
should not use extra space for another array.

?Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
?Output: [1, 2, 4, 3, 5, 0, 0, 0]
*Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
?Output: [10, 20, 30]
*Explanation: No change in array as there are no 0s

Input: arr[] = [0,0]
?Output: [0,0]
*Explanation: No change in array as there are all 0s.


!Constraints:
!2 ≤ arr.size() ≤ 10^5
!1 ≤ arr[i] ≤ 10^5

*/

code:

class Solution {
    void pushZerosToEnd(int[] arr) {
        int n = arr.length;
        int i = 0, pos = 0;
        
        for(; i<n; i++){
            if(arr[i] != 0){
                if(i!= pos){
                    int temp = arr[i];
                    arr[i] = arr[pos];
                    arr[pos] = temp;
                }
                pos++;
            }
        }
    }
}

// time complexity = O(n)
// space complexity = O(1)