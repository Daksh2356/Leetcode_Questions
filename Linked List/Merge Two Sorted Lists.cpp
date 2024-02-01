/*
Question : 21. Merge Two Sorted Lists
Date : 01-02-24
Problem Difficulty level : Easy
Related Topics : Linked List and Recursion
Problem Statement:
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {
        ListNode *merged = new ListNode(-1);

        ListNode *left, *right, *mptr;
        left = head1;
        right = head2;
        mptr = merged;

        while (left && right)
        {
            if (left->val <= right->val)
            {
                mptr->next = left;
                mptr = mptr->next;
                left = left->next;
            }
            else
            {
                mptr->next = right;
                mptr = mptr->next;
                right = right->next;
            }
        }

        while (left)
        {
            mptr->next = left;
            mptr = mptr->next;
            left = left->next;
        }

        while (right)
        {
            mptr->next = right;
            mptr = mptr->next;
            right = right->next;
        }

        mptr->next = NULL;

        return merged->next;
    }
};