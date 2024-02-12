/*
Question : 229. Majority Element
Date : 04-10-23
Problem Difficulty level : Easy
Related Topics : Array, Hash Table, Sorting and Counting

Problem Statement:

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists
in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

// solution 1:

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = INT_MAX;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
            {
                count++;
            }
            else if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else
            {
                count--;
            }
        }

        count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
                count++;
        }

        if (count > n / 2)
            return candidate;

        return 0;
    }

    // time complexity = O(n)
    // space complexity = O(1)
};

// solution 2 :

public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int majorityElement(final List<Integer> A) {
        int candidate = Integer.MAX_VALUE;
        int count = 0; 
        int n = A.size();
        
        // loop to find the candidate
        for(int i =0; i<n ;i++){
            if(A.get(i) == candidate)
                count++;
            else if(count == 0){
                candidate =  A.get(i);
                count = 1;
            }
            else
                count--;
        }
        
        count = 0;    // iterating again to find the "candidate"
        for(int i=0; i<n; i++){
            if(A.get(i) == candidate)
                count++;
        }
        
        if(count > n/2)
            return candidate;
            
        return 0;
    }
}
