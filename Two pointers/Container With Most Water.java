/*
! Question: 11. Container With Most Water
* Problem Difficulty level : Medium
? Related Topics : Array, Two Pointers, Greedy
? Date : 10th March 2025

Problem Statement:

! You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line 
! are (i, 0) and (i, height[i]).

! Find two lines that together with the x-axis form a container, such that the container contains the most water.

! Return the maximum amount of water a container can store.

? Notice that you may not slant the container.

* Note that s may contain leading or trailing spaces or multiple spaces between two words. 
* The returned string should only have a single space separating the words. Do not include any extra spaces.

? Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

? Example 2:
Input: height = [1,1]
Output: 1

 
? Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

*/


//!  CODE :

class Solution {
    public int maxArea(int[] height) {
        
        int n = height.length;
        int left = 0;
        int right = n-1;
        int max_area = 0;

        while(left < right){
            int curr = Math.min(height[left], height[right]) * (right-left);
            max_area = Math.max(curr, max_area);

            if(height[left] < height[right])
                left++;
            else
                right--;
            
        }

        return max_area;

        // time complexity = O(n)
        // space complexity = O(1)

    }
}