/* leetcode21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *newhead = &dummy;
        ListNode *ret = newhead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                newhead->next = l1;
                l1 = l1->next;
            }
            else{
                newhead->next = l2;
                l2 = l2->next;   
            }
            newhead = newhead->next;
        }
        if(l1) newhead->next = l1;
        else if(l2) newhead->next = l2;

        return ret->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *head = &dummy;
        while(l1||l2){
            if((l1==NULL)||((l2!=NULL)&&(l1->val>=l2->val))){
                head->next = l2;
                l2=l2->next;
            }
            else{
                head->next = l1;
                l1=l1->next;
            }
            head = head->next;
        }    
        return dummy.next;
    }
};
