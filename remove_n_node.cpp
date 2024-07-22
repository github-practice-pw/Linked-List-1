/*
 *                                  Remove Nth node from end of list
 * 
 *              https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 *  Time Complexity : O(N)
 *  Space Complexity : O(1)
 *  Did this code successfully run on Leetcode : Yes
 *  Any problem you faced while coding this : 
 *  Approach : 
 *       - Brute force approach : Traverse through the LL to get the current length.
 *                                Traverse again length - n times to reach the node that
 *                                needs to be deleted.
 *       - Optimized approach : Use slow and fast pointers. Place the fast pointer at a distance
 *                              n from the slow pointer initially. Once done, keep sliding the slow
 *                              and fast pointers till fast is NULL. The node at which slow will point 
 *                              will be the nth node that needs to be removed.
 *              
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

    // Brute force approach : Calculating length and traversing through the linked list 
    //                        to delete the Nth node.
    //                        TC : O(N) + O(N)
    //                        SC : O(1)
    ListNode* traversal_to_delete(ListNode* head, int n) {
       int length = 0;

       ListNode* dummy = new ListNode(-1);
       dummy->next = head;
       ListNode* current = head;

       while(current != NULL) {
            current = current->next;
            length++;
       }

       current = dummy;
       int delete_node = length - n;

       while(delete_node > 0) {
            current = current->next;
            delete_node--;
       }

       ListNode* temp = current->next;
       current->next = current->next->next;
       delete temp;

       ListNode* newHead = dummy->next;
       delete dummy;

       return newHead;
    }

    // Optimized approach
    ListNode* slow_and_fast_pointer(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(n >= 0) {
            fast = fast->next;
            n--;
        }

        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;

    }
        
};
