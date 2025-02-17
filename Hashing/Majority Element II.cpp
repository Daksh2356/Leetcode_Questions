/*
Question : 229. Majority Element II
Date : 04-10-23
Problem Difficulty level : Easy
Related Topics : Array, Hash Table, Sorting and Counting
Problem Statement:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]


Constraints:
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9


Follow up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int candidate_1 = INT_MAX;
        int candidate_2 = INT_MAX;

        int n = nums.size();

        int count_1 = 0, count_2 = 0; // for updating the count of both candidates

        for (int num : nums)
        {
            if (num == candidate_1)
                count_1++;
            else if (num == candidate_2)
                count_2++;
            else if (count_1 == 0)
            {
                candidate_1 = num;
                count_1 = 1;
            }
            else if (count_2 == 0)
            {
                candidate_2 = num;
                count_2 = 1;
            }
            else
            {
                count_1--;
                count_2--;
            }
        }

        count_1 = count_2 = 0;

        for (int num : nums)
        {
            if (num == candidate_1)
                count_1++;
            if (num == candidate_2)
                count_2++;
        }

        vector<int> answer;

        if (count_1 > n / 3)
            answer.push_back(candidate_1);
        if (count_2 > n / 3)
            answer.push_back(candidate_2);

        return answer;
    }

    // Time complexity = O(n)
    // Space complexity = O(1)
};