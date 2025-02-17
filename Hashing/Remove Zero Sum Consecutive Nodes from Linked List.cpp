/*
Question : 1171. Remove Zero Sum Consecutive Nodes from Linked List
Date : 11-03-24
Problem Difficulty level : Medium
Related Topics : Hash Table and Linked List
Problem Statement:

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:
The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/
#include <unordered_map>

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> prefixSum;
        int sum = 0;
        ListNode* current = dummy;
        
        while (current != nullptr) {
            sum += current->val;
            if (prefixSum.find(sum) != prefixSum.end()) {
                ListNode* prev = prefixSum[sum]->next; // prev points to last node
                int p = sum;           // p is calculated to find the sum untill next node
                while (prev != current) {
                    p += prev->val;
                    prefixSum.erase(p); // we remove p and node pair from map
                    prev = prev->next;
                }
                prefixSum[sum]->next = current->next;  // delete nodes btw prev and current
            } else {
                prefixSum[sum] = current;  // assign node to cummulative sum
            }
            current = current->next; 
        }
        
        return dummy->next;  // return head of modified list
    }

    // time = O(n)
    // space = O(n)
};
