/*
Question : 143. Reorder List
Date : 23-03-24
Problem Difficulty level : Medium
Related Topics: Linked List, Two Pointers, Recursion, Stack

Problem Statement:
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 
Constraints:
The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000

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
class Solution {
public:

    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* temp){
        ListNode* prev = nullptr;
        while(temp){
            ListNode* f = temp->next;
            temp->next = prev;
            prev = temp;
            temp = f;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        // handling empty or single-node list
        if(!head || !head->next)
            return;

        ListNode* mid = middle(head);
        ListNode* secondHalf = reverse(mid->next);
        mid->next = nullptr;

        ListNode* c1 = head;
        ListNode* c2 = secondHalf;

        ListNode *f1 = nullptr, *f2 = nullptr;

        while(c1 && c2){
            f1 = c1->next;
            f2 = c2->next;
            
            c1->next = c2;
            c2->next = f1;

            c1 = f1;
            c2 = f2;
        }

        // time = O(n)
        // space = O(1)
    }
};