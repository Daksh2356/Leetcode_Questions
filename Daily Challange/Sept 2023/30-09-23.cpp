/*
Question : 456. 132 Pattern
Date : 30-09-23
Problem Difficulty level : Easy
Related Topics: Array, Binary Search, Monotonic Stack, Set
Problem Statement:
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and
nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:
n == nums.length
1 <= n <= 2 * 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> stk;
        int third = INT_MIN; // for storing nums[k], we create a third variable initially
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) // reversing array to find value at k index
        {
            if (nums[i] < third)
                return true;

            while (!stk.empty() && stk.top() < nums[i]) // stk.top() holds value at index 'k'
            {
                third = stk.top();
                stk.pop();
            }

            stk.push(nums[i]); // value at 'k' index is pushed into stack
        }

        return false; // if no pattern is found in the loop above
    }

    // Time complexity = O(n)
    // Space complexity = O(n)
};