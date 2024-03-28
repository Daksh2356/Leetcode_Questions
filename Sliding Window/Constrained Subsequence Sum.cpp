/*
Question : 1425. Constrained Subsequence Sum
Date : 21-10-23
Problem Difficulty level : Hard
Related Topics : Array, DP, Queue, Sliding Window, Heap and Monotonic Queue
Problem Statement:

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that
for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is
satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining
elements in their original order.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].

Constraints:

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        std::deque<int> dq; // for storing the max sum in current window of size k

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] += dq.empty() ? 0 : nums[dq.front()]; // check if deque is empty

            // check for condition on indices : j - i <=k & (current val >= value at dq.back)
            while (!dq.empty() && ((i - dq.front() >= k) || (nums[i] >= nums[dq.back()])))
            {
                if (nums[i] >= nums[dq.back()]) // remove from dq.back() if true
                    dq.pop_back();
                else // else remove from dq.front() if false
                    dq.pop_front();
            }

            if (nums[i] > 0) // if(value > 0) push index into dq
                dq.push_back(i);
        }

        return *max_element(nums.begin(), nums.end()); // return max value from nums
    }

    // Time complexity = O(n)   -> nums is traversed once
    // Space complexity = O(k)  -> deque has only "k" elements at any point of time
};