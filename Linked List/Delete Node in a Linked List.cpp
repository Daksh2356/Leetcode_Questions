/*
Question : 237. Delete Node in a Linked List
Date : 04-02-24
Problem Difficulty level : Medium
Related Topics : Linked List
Problem Statement:

1 ) There is a singly-linked list head and we want to delete a node node in it.

2) You are given the node to be deleted node. You will not be given access to the first node of head.

3) All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

4) Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.

Custom testing:

1. For the input, you should provide the entire linked list head and the node to be given node. "node" should not be the last node of the
list and should be an actual node in the list.
2. We will build the linked list and pass the node to your function.
3. The output will be the entire list after calling your function.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Example 1:
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Constraints:
The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // store the value of next node to the given node
        node->val = node->next->val;

        // link the given node to the link of next node
        node->next = node->next->next;
    }
};