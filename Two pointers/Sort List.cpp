/*
Question : 148. Merge Sorted Array
Date : 21-02-24
Problem Difficulty level : Medium
Related Topics: Linked List, Two pointers, Merge Sort, Sorting, Divide and Conquer

Problem Statement:
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []


Constraints:
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (left && right)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        curr->next = left ? left : right;
        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Split the list into two halves
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second_half = slow->next;
        slow->next = NULL;

        // Recursively sort each half
        ListNode *left_sorted = sortList(head);
        ListNode *right_sorted = sortList(second_half);

        // Merge sorted halves
        return merge(left_sorted, right_sorted);
    }
};