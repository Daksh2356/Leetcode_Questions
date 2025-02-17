/*
Question : 2251. Number of Flowers in Full Bloom
Date : 11-10-23
Problem Difficulty level : Hard
Related Topics : Array, Hash Table, Binary Search, Sorting, Prefix Sum and Ordered Set
Problem Statement:
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom
from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the
ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

Example 1:
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Example 2:
Input: flowers = [[1,10],[3,3]], people = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Constraints:
1 <= flowers.length <= 5 * 10^4
flowers[i].length == 2
1 <= starti <= endi <= 10^9
1 <= people.length <= 5 * 10^4
1 <= people[i] <= 10^9
*/

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> st, end;

        for (auto i : flowers) // auto is used to handle pairs
        {
            int x = i[0];
            int y = i[1];
            st.push_back(x);  // start times of flowers are stored in st vector
            end.push_back(y); // end times of flowers are stored in end vector
        }

        sort(st.begin(), st.end()); // sorting to get full bloom times in an order
        sort(end.begin(), end.end());

        vector<int> answer; // to store bloom status for each person-i from people 1d array

        for (int i = 0; i < people.size(); i++)
        {
            int p = st.size() - (upper_bound(st.begin(), st.end(), people[i]) - st.begin());
            // calculating the no of flowers at or before the arrival of person[i]

            int q = end.size() - (lower_bound(end.begin(), end.end(), people[i]) - end.begin());
            // calculating the no of flowers at or after the arrival of parent[i]

            answer.push_back(q - p); // to get bloom status for person[i]
        }

        return answer;
    }

    // time complexity = O(nlogn) due to sorting
    // space complexity = O(n) due to linear data structures used in st, end and answer
};