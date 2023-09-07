/*
Question : 2095. Delete the Middle Node of a Linked List
Date : 26-07-23
Problem Difficulty level : Medium
Related Topics : Linked List and Two Pointers

Problem Statement:
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes 
the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 
Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

Constraints:
The number of nodes in the list is in the range [1, 10^5].
1 <= Node.val <= 10^5
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mid = head;
        ListNode* end = head;
        ListNode* prev = NULL;
        while(end!=NULL && end->next!=NULL)
        {
            prev = mid;
            mid = mid->next;
            end = end->next->next;
        }

        if(mid == head)
        {
            head = head->next;
            delete mid;
            return head;
        }

        if(prev != NULL)
        {
            prev->next = mid->next;
        }
        
        return head;
    }

    // time complexity = O(N)
    // space complexity = O(1)
};