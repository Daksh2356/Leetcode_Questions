/*
Question : 42. Trapping Rain Water
Date : 12-04-24
Problem Difficulty level : Hard
Related Topics: Array, Two Pointers, Dynammic Programming, Stack, Monotonic Stack

Problem Statement:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water 
(blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // size of given height vector 
        int left = 0, right = n-1;  // left and right pointer
        int left_max = 0, right_max = 0;  // variables to store max height from left and right sides
        int water = 0; // total amount of trapped water

        while(left<right){    // loop goes till the left and right height don't overlap
            if(height[left] < height[right]){   // the left wall is less than right one
                left_max = max(left_max, height[left] ); // max height from left side updated
                water += left_max - height[left++];  // diff of max height and curr height trapped
            }
            else{
                right_max = max(right_max, height[right]); // max height from right side updated
                water += right_max - height[right--]; // diff of max height and curr height trapped
            }
        }

        return water;  // returning the total trapped water

        // time complexity = O(n)    => traversed the array once only ( linear apporach)
        // space complexity = O(1)   =>  no extra space used ( constant space used )

    }
};