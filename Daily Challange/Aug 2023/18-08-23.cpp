/*
Question : 1615. Maximal Network Rank
Date : 18-08-23
Problem Difficulty level : Medium
Related Topics : Graph and adjacency list 

Problem Statement:
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

Example 1:

Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.

*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int max_count = 0;
        vector<vector<int>> network(n);

        for(auto road: roads)
        {
            int a = road[0];
            int b = road[1];

            network[a].push_back(b);
            network[b].push_back(a);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1; j<n;j++)
            {
                int n1 = network[i].size();
                int n2 = network[j].size();
                int common = count(network[i].begin(), network[i].end() , j);
                max_count = max(max_count, n1+n2-common);
            }
        }

        return max_count;
    }

    // time complexity = O(n^2) -> n is no. of cities
    // space complexity = O(n+m) -> n and m are no. of cities and roads respectively 
};