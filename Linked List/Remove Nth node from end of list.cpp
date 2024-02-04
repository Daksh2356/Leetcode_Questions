/*
Question : 19. Remove Nth Node From End of List
Date : 04-02-24
Problem Difficulty level : Medium
Related Topics : Linked List and Two pointers
Problem Statement:

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Follow up: Could you do this in one pass? - ** STILL LEFT TO DO

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
    ListNode *removeNthFromEnd(ListNode *head, int N)
    {
        int len = 0;
        ListNode *temp = head;

        while (temp)
        {
            temp = temp->next;
            len++; // length of linked list
        }

        if (len == N)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        if (len < N)
            return head;

        temp = head;

        for (int i = 1; i < len - N + 1; i++)
        {
            temp = temp->next; // temp is the node to be deleted from end of list
        }

        if (temp->next != nullptr)
        {
            temp->val = temp->next->val;
            temp->next = temp->next->next;
        }

        else
        {
            ListNode *prev = head;
            while (prev->next != temp)
            {
                prev = prev->next;
            }

            prev->next = nullptr;
            delete temp;
        }

        return head;
    }
};