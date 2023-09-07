/*
Question : 92. Reverse Linked List II
Date : 07-09-23
Problem Difficulty level : Medium
Related Topics : Linked List
Problem Statement:
Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

Follow up: Could you do it in one pass?     => STILL NEED TO WORK ON THIS !!
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        int moves = right - left + 1;

        left = left - 1;

        while (left)
        {
            prev = curr;
            curr = curr->next;
            left--;
        }

        ListNode *sp = curr;
        ListNode *last = prev;

        while (moves)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            moves--;
        }

        sp->next = curr;
        if (last == NULL)
            return prev;
        else
            last->next = prev;
        return head;
    }
    // time complexity = O(N)
    // space complexity = O(1)
};