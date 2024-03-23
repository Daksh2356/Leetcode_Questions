/*
Question : 234. Palindrome Linked List
Date : 22-03-24
Problem Difficulty level : Easy
Related Topics: Linked List, Two Pointers, Recursion, Stack

Problem Statement:
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
 

Constraints:
The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?  - ALREADY DONE !!

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
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)  // for empty or single node list
            return true;


        // finding middle node of list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the second half of the list
        ListNode* curr = slow->next;       // slow contains the middle node of list
        ListNode* prev = NULL;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        // compare the first half and reversed second half of the list
        ListNode* firstHalf = head;     // head of the original list
        ListNode* secondHalf = prev;    // prev is head of the reversed list
        while(secondHalf){
            if(firstHalf->val != secondHalf->val)
                return false;
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }

        return true;
    }
};