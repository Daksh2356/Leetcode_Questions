/*
Question : 1361. Validate Binary Tree Nodes
Date : 17-10-23
Problem Difficulty level : Medium
Related Topics : Tree, BFS, DFS, Union find, graph, binary tree
Problem Statement:
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if
and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

Example 1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false


Constraints:
n == leftChild.length == rightChild.length
1 <= n <= 10^4
-1 <= leftChild[i], rightChild[i] <= n - 1

*/

class Solution
{
public:
    bool isValidBinaryTree(int root, vector<int> &leftChild, vector<int> &rightChild)
    {
        int n = leftChild.size();
        vector<bool> visited(n, false); // track of visited nodes in BFS
        queue<int> Queue;               // for pushing a valid node acc to the binary tre
        Queue.push(root);
        visited[root] = true; // since its a valid node

        while (!Queue.empty())
        {
            int current = Queue.front();
            Queue.pop();

            // checking in the leftChild array
            if (leftChild[current] != -1)
            {
                if (visited[leftChild[current]])
                    return false; // prev visited node is visited again ! Cycle formed

                Queue.push(leftChild[current]);     // pushed in queue
                visited[leftChild[current]] = true; // visited node is marked "true"
            }

            // checking in rightChild array
            if (rightChild[current] != -1)
            {
                if (visited[rightChild[current]])
                    return true; // cycle is formed

                Queue.push(rightChild[current]);     // pushed new node in the queue
                visited[rightChild[current]] = true; // visited node is marked "true"
            }
        }

        // check if all nodes are visited
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                return false; // multiple components found
        }

        return true; // a valid binary tree is found !!
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<bool> childCount(n, false); // tracks child count for each node

        for (auto child : leftChild) // checks in leftchild array
        {
            if (child != -1)
                childCount[child] = true; // leftchild is having a parent
        }

        for (auto child : rightChild) // checks in rightChild array
        {
            if (child != -1)
            {
                if (childCount[child]) // multiple parents -> false is returned
                    return false;
                childCount[child] = true; // rightChild is having a parent
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (!childCount[i])
            {
                if (root == -1)
                    root = i; // root is assigned as current node 'i'
                else
                    return false; // as root is already assigned
            }
        }

        if (root == -1)
            return false; // multiple components / not a valid bianry tree

        return isValidBinaryTree(root, leftChild, rightChild); // check now if tree is binary
    }

    // Time Complexitty = O(n)
    // Space Complexitty = O(n)
};