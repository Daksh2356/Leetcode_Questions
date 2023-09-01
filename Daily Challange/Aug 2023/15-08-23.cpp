/*
Question : 86. Partition List
Date : 15-08-23
Problem Difficulty level : Medium
Related Topics : Linked List and Two Pointers

Problem Statement:
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode before(0), after(0);    // dummy nodes
        ListNode *before_curr = &before; // linked list for values < x
        ListNode *after_curr = &after;   // linked list for values > x

        while (head)
        {
            if (head->val < x)
            {
                before_curr->next = head;
                before_curr = head;
            }

            else
            {
                after_curr->next = head;
                after_curr = head;
            }

            head = head->next;
        }

        before_curr->next = after.next;
        after_curr->next = nullptr;

        return before.next;
    }

    // time complexity = O(N)
    // space complexity = O(1)
};