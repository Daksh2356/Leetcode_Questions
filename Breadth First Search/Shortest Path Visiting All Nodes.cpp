/*
Question : 847. Shortest Path Visiting All Nodes
Date : 17-09-23
Problem Difficulty level : Hard
Related Topics :Graph, BFS, Bitmask, DP, Bit Manipulation
Problem Statement:

You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i]
is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times,
and you may reuse edges.

Example 1:
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]

Constraints:
n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.

*/
class Solution
{

    struct State
    {
        int mask, node, dist;
    };

public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();           // size of given graph
        int all_visited = (1 << n) - 1; // to check if all nodes are visited - goal state

        queue<State> q;
        unordered_set<int> visited; // storing the hash value of each visited node

        // initialising the queue and visited set with values of the state

        for (int i = 0; i < n; i++)
        {
            q.push({1 << i, i, 0});            // initial state passed to the queue
            visited.insert((1 << i) * 16 + 1); // initial hash value to create space for ith node
        }

        while (!q.empty())
        {
            State curr = q.front(); // initial state of q is stored in curr
            q.pop();                // the front value is popped from the queue

            if (curr.mask == all_visited) // all nodes are visited
            {
                return curr.dist;
            }

            for (int neighbour : graph[curr.node])
            {
                int new_mask = curr.mask | (1 << neighbour);    // new mask value ( OR operation )
                int new_hash_value = new_mask * 16 + neighbour; // hash based on new mask value

                if (visited.find(new_hash_value) == visited.end())
                {
                    visited.insert(new_hash_value);
                    q.push({new_mask, neighbour, curr.dist + 1});
                }
            }
        }

        return -1;
    }

    // time complexity = O(2^n * n) as each node has 2^n subset of nodes
    // space complexity = O(2^n * n) for the visited set and queue ( to store states)
};