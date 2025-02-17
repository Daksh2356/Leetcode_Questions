/*
Question: 448. Find All Numbers Disappreared in an Array
Date : 19-02-24
Problem Difficulty level : Easy
Related Topics : Array, Hash Table
Problem Statement:

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n]
that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]

Constraints:
n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n


Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

class Solution
{
public
    List<Integer> findDisappearedNumbers(int[] nums)
    {
        List<Integer> ans = new ArrayList<Integer>();
        Set<Integer> hset = new HashSet<>();

        for (int num : nums)
        {
            hset.add(num);
        }

        for (int i = 1; i <= nums.length; i++)
        {
            if (!hset.contains(i))
                ans.add(i);
        }

        return ans;
    }

    // time complexity = O(n)
    // space complexity = O(n)
}

// solution for follow-up :

class Solution
{
public
    List<Integer> findDisappearedNumbers(int[] nums)
    {
        List<Integer> ans = new ArrayList<Integer>();

        for (int num : nums)
        {
            int idx = Math.abs(num) - 1;
            if (nums[idx] > 0)
                nums[idx] *= -1;
        }

        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] > 0)
                ans.add(i + 1);
        }

        return ans;
    }

    // Time complexity = O(n)
    // Space complexity = O(1)
}