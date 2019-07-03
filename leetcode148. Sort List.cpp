/* leetcode148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

		ListNode* prev = nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast && fast->next){
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(slow);
		return merge(l1,l2);
    }
	ListNode* merge(ListNode *l1, ListNode *l2) {
		ListNode *l = new ListNode(0), *p = l;
    
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		
		if (l1 != nullptr)
		p->next = l1;
		
		if (l2 != nullptr)
		p->next = l2;
		
		return l->next;
	}

};