/*
Question : 61. Rotate List
Date : 06-09-23
Problem Difficulty level : Medium
Related Topics : Linked List and Two Pointers
Problem Statement:

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        int N = 1;

        ListNode *tail = head;
        while (tail->next)
        {
            N++;
            tail = tail->next;
        }

        k %= N;

        if (k == 0)
            return head;

        ListNode *newTail = head;

        for (int i = 0; i < N - k - 1; i++)
        {
            newTail = newTail->next;
        }

        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
    // time complexity = O(N)
    // space complexity = O(1)
};