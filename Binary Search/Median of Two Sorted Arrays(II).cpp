/*
Question : 4. Median of Two Sorted Arrays
Date : 21-09-23
Problem Difficulty level : Hard
Related Topics: Array, Binary Search, Divide and Conquer

Problem Statement:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/
// BRUTE FORCE APPROACH

class Solution
{
public:
    int solve(vector<int> &A, vector<int> B, int k, int aStart, int aEnd, int bStart, int bEnd)
    {
        if (aEnd < aStart)
        {
            return B[k - aStart];
        }

        if (bEnd < bStart)
        {
            return A[k - bStart];
        }

        int aIndex = (aStart + aEnd) / 2;
        int bIndex = (bStart + bEnd) / 2;

        int aVal = A[aIndex];
        int bVal = B[bIndex];

        if (aIndex + bIndex < k) // when we are in the left half of the merged array
        {
            if (aVal > bVal)
            {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd); // b is moved towrads right
            }
            else
            {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd); // a is moved towarrds right
            }
        }
        else // we are in the right half of the merged array
        {
            if (aVal > bVal)
            {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd); // a is moved towards left
            }
            else
            {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1); // b is moved towards left
            }
        }

        // Time complexity = O(log(min(na,nb))) => Divide and Conquer method
        // Space complexity = O(log(min(na,nb)))  => due to recursive call stack
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int na = nums1.size();
        int nb = nums2.size();

        int n = na + nb;

        if (n % 2 == 0)
            return (double)(solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1) +
                            solve(nums1, nums2, n / 2 - 1, 0, na - 1, 0, nb - 1)) /
                   2;
        else
            return solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1);
    }
};
