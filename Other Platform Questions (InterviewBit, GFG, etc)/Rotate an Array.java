/*
 Date : 14/05/25
 Platform : GFG
 Track : GFG-160-problems

Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 
Do the mentioned change in the array in place.

Note: Consider the array as circular.

?Examples:

Input: arr[] = [1, 2, 3, 4, 5], d = 2
?Output: [3, 4, 5, 1, 2]
*Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
?Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
*Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

Input: arr[] = [7, 3, 9, 1], d = 9
?Output: [3, 9, 1, 7]
*Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.


!Constraints:
!1 ≤ arr.size() ≤ 10^5
!0 ≤ arr[i] ≤ 10^5

*/

code:

class Solution {
    // Function to rotate an array by d elements in counter-clockwise direction.
    static void rotateArr(int arr[], int d) {
        int n = arr.length;
        d = d%n;
        if (d == 0) return;
        
        for(int i=0; i<n/2; i++){
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
        }
        
        for(int i=0; i<(n-d)/2; i++){
            int temp = arr[i];
            arr[i] = arr[n-d-1-i];
            arr[n-d-1-i] = temp;
        }
        
        for(int i=n-d; i<(n-d + n)/2; i++){
            int temp = arr[i];
            arr[i] = arr[n-1 - (i- (n-d))];
            arr[n-1-(i-(n-d))] = temp;
        }
        
    }
}