/*
 *                                  Linked List Cycle II
 * 
 *              https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 *  Time Complexity : O(N)
 *  Space Complexity : When using a hashset, O(N) else with optimized approach O(1)
 *  Did this code successfully run on Leetcode : Yes
 *  Any problem you faced while coding this : No
 *  Approach : 
 *       - Brute force approach :
 *              Create a hashset of nodes of the linked lists, if while inserting a node, the node
 *              alreadt exists means there is a cycle. Return the node else return null.
 *      - Optimized approach :
 *              Using two pointers slow and fast. The point where the slow and fast pointer meets would
 *              mean that there is a cycle in the list.
 */ 

#include<iostream>
#include<unordered_set>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:

    // Brute force approach : Using hashset
    ListNode* detectCyle_hashset(ListNode* head) {
        unordered_set<ListNode*> hashset;

        while(head != NULL) {
            // If the nodes already exists in the hashset, there is a cycle.
            if (hashset.find(head) != hashset.end()) {
                return head;
            }
            hashset.insert(head);
            head = head->next;
        }
        return NULL;
    }

    // Optimized approach
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        // This condition in case of LL we should always check for
        // even length or odd lenth linked list
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
            }
        }

        if (!hasCycle) {
            return NULL;
        }

        fast = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
