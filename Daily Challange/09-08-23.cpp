/*
Question :2616. Minimize the Maximum Difference of Pairs
Date : 09-08-23
Problem Difficulty level : Medium
Related Topics : Array
Binary Search
Greedy

Problem Statement:
You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
*/
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int low =0;
       int high = nums.back() - nums.front();
       while(low<high)
       {
           int mid = (low+high)/2;
           if(can_form_pairs(nums,mid,p))
           {
               high = mid;
           }
           else
           {
                low = mid+1;
           }
       }

       return low;

    }

private:
    bool can_form_pairs(vector<int>& nums, int mid , int p)
    {
        int count = 0;
        for(int i=0;i<nums.size()-1 && count<=p;)
        {
            if(nums[i+1] - nums[i] <=mid)
            {
                count++;
                i+=2;
            }
            else i++;
        }

        return count>=p;
    }

    // time complexity = O(nlogn) + O(n) = O(nlogn)
    // space complexity = O(1)

};