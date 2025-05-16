/*

Date : 16/05/25
Platform : GFG
Track : GFG Practice Set Questions

Given an integer array of N elements. You need to find the maximum sum of two elements such that sum is closest to zero.

? Examples:
Input: N = 3 ,arr[] = {-8 -66 -60}
? Output: -68
* Explanation: Sum of two elements closest to zero is -68 using numbers -60 and -8.

Input: N = 6 ,arr[] = {-21, -67, -37, -18, 4, -65}
? Output: -14
* Explanation: Sum of two elements closest to zero is -14 using numbers -18 and 4.

! Note : In Case if we have two of more ways to form sum of two elements closest to zero return the maximum sum.

! Your Task: 
You don't need to read input or print anything. You just need to complete the function closestToZero() which takes an 
array arr[] and its size n as inputs and returns the maximum sum closest to zero that can be formed by summing any two 
elements in the array.

!Constraints:
2 ≤ N ≤ 5 * 10^5
-10^6 ≤ arr[i] ≤ 10^6

*/

// code to above problem =>

class Solution {
    public static int closestToZero(int arr[], int n) {
        int res = Integer.MAX_VALUE;
        
        Arrays.sort(arr);
        
        for(int i =0; i<n; i++){
            int x = arr[i]; // first element of pair
            
            int left = i+1, right = n-1;
            
            while(left<=right){
                int mid = (left+right)/2;
                int sum = arr[mid] + x;
                
                if(sum == 0)
                    return 0;
                
                if(Math.abs(sum) < Math.abs(res))
                    res = sum;
                    
                else if(Math.abs(sum) == Math.abs(res))
                    res = Math.max(res, sum);
                
                if(sum < 0)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        
        return res;
    }
}