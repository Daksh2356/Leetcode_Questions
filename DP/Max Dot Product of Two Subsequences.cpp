/*
Question : 1458. Max Dot Product of Two Subsequences
Date : 08-10-23
Problem Difficulty level : Hard
Related Topics : Array and Dynamic Programming
Problem Statement:
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without
disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Example 2:
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.

Example 3:
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.

Constraints:
1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000
*/
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));

        dp[0][0] = nums1[0] * nums2[0];

        int maxDotProd = dp[0][0]; // initialized the maxDotProduct

        // taking the dot product of every element of nums1 with nums2[0]

        for (int i = 1; i < n1; i++)
        {
            dp[i][0] = max(nums1[i] * nums2[0], dp[i - 1][0]);
            maxDotProd = max(maxDotProd, dp[i][0]);
        }

        // taking the dot product of every element of nums2 with nums1[0]

        for (int j = 1; j < n2; j++)
        {
            dp[0][j] = max(nums1[0] * nums2[j], dp[0][j - 1]);
            maxDotProd = max(maxDotProd, dp[0][j]);
        }

        // taking dot product of every element of nums1 with corresponding element of nums2

        for (int i = 1; i < n1; i++)
        {
            for (int j = 1; j < n2; j++)
            {
                dp[i][j] = max(nums1[i] * nums2[j], max(dp[i - 1][j - 1] + nums1[i] * nums2[j],
                                                        max(dp[i - 1][j], dp[i][j - 1])));
                maxDotProd = max(maxDotProd, dp[i][j]);
            }
        }
        return maxDotProd;
    }

    // Time Complexity = O(n1*n2)
    // Space Complexity = O(n1*n2)
};