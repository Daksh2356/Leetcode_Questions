/*
Question :138. Copy List with Random Pointer
Date : 05-09-23
Problem Difficulty level : Medium
Related Topics : Hash Table and Linked List
Problem Statement:
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list,
or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the
value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list
such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point
to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the
copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
1) val: an integer representing Node.val
2) random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Constraints:
0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/

// CODE :

/**
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map <Node*, Node*> nodeMap;  // map for storing new copied list

        Node* copy = head;
        while(copy)                   // FIRST PASS : copying val from org list to copy list
        {
            nodeMap[copy] = new Node(copy->val);
            copy = copy -> next;
        }

        copy = head;

        while(copy)                 // SECOND PASS : setting up random and next pointers
        {
            nodeMap[copy] -> next = nodeMap[copy->next];
            nodeMap[copy] -> random = nodeMap[copy->random];
            copy = copy->next;
        }

        return nodeMap[head];

        // time complexity = O(n) for each individual linear pass ( first and second )
        // space complexity = O(n) for the hashmap and 'n' new nodes created 
    }
};