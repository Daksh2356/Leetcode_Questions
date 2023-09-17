/*
Question : 1584. Min Cost to Connect All Points
Date : 15-09-23
Problem Difficulty level : Medium
Related Topics : Array, Graph, Union Find, Minimum Spanning Tree
Problem Statement:

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path 
between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.


Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/


class Solution {
public:

    int manhattan_distance(vector<int>& p1, vector<int>& p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited (n,false); // to check a visited node
        unordered_map<int,int> heap_dict;
        for(int i=0;i<n;i++)
        {
            heap_dict[i] = INT_MAX;  // Initialize all distances to infinity
        }

        heap_dict[0] = 0; // start node

        auto cmp = [] (pair<int,int> left , pair<int,int> right) { 
            return left.first > right.first; };
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, decltype(cmp)> min_heap(cmp);
        min_heap.push({0,0});

        int mst_weight = 0;

        while(!min_heap.empty())
        {
            auto[w,u] = min_heap.top();
            min_heap.pop();

            if(visited[u] || heap_dict[u] < w) continue;

            visited[u] = true;
            mst_weight += w;

            for(int v =0; v<n;v++)
            {
                if(!visited[v])
                {
                    int new_distance = manhattan_distance(points[u],points[v]);
                    if(new_distance < heap_dict[v])
                    {
                        heap_dict[v] = new_distance;
                        min_heap.push({new_distance,v});
                    }
                }
            }
        }

        return mst_weight;
    }

    // time complexity is O(n * log n)
    // space complexity is O(n).

};