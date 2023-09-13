/*
Question : 135. Candy
Date : 13-09-23
Problem Difficulty level : Hard
Related Topics : Array and Greedy (Two Pass Method - Different way to solve )

Problem Statement:

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.


Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);

        for(int i=1;i<n;i++)           // LEFT TO RIGHT PASS
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] +=candies[i-1];
            }
        }

        for(int i=n-2;i>=0;i--)          // RIGHT TO LEFT PASS
        {
            if(ratings[i] > ratings[i+1])
            {
                candies[i] = max(candies[i] , candies[i+1] + 1);
            }
        }

        return  accumulate(candies.begin(), candies.end() , 0); // 0 passed here is the initial value given to the accumulate function

    }

    // time complexity = O(n)
    // space complexity = O(n)
};