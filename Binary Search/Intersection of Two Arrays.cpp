/*
Question : 349. Intersection of Two Arrays
Date : 10-03-24
Problem Difficulty level : Easy
Related Topics : Array, Hash Table, Two Pointers, Binary Search, Sorting
Problem Statement:

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be
unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        unordered_set<int> aSet(nums1.begin(), nums1.end());
        vector<int> answer;

        for (int num : nums2)
        {
            if (aSet.count(num))
            {
                answer.push_back(num);
                aSet.erase(num);
            }
        }

        return answer;
    }

    // time = O(n+m)
    // space = O(n)  where 'n' is size of nums1 and 'm' is size of nums2
};