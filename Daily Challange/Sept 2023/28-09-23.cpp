/*
Question : 905. Sort Array By Parity
Date : 28-09-23
Problem Difficulty level : Easy
Related Topics: Array, Two Pointers and Sorting
Problem Statement:

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

*/

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long size = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                size *= s[i] - '0'; // char is converted to integer by sub ASCII val of 0
            }
            else
                size++;
        } // value of size is calculated for the decoded string

        for (int i = n - 1; i >= 0; i--)
        {
            k %= size;
            if (k == 0 && isalpha(s[i]))
            {
                return string(1, s[i]); // creates a string with a single s[i] character
            }

            if (isdigit(s[i]))
            {
                size /= s[i] - '0';
            }

            else
                size--;
        }

        return ""; // return empty string at last if nothing is returned
    }

    // time complexity = O(n)
    // space complexity = O(1)
};