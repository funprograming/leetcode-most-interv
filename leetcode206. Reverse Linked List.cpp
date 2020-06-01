/* leetcode206. Reverse Linked List
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head1 = new ListNode(0);
        while(head){
            ListNode* t = head->next;
            head->next = head1->next;
            head1->next = head;
            head = t;
        }
        return head1->next;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(!head) return head;
        ListNode* head1 = head;
		head = head->next;
		head1->next=nullptr;
        while(head){
            ListNode* t = head->next;
            head->next = head1;
            head1 = head;
            head = t;
        }
        return head1;
    }
};
// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ((!head)|| (!head->next)) return head;
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
    }
};
