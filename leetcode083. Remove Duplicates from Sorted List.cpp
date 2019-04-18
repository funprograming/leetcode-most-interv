/* leetcode083. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that 
each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* headNew = head;
        while(head){
            if(head->next && (head->next->val == head->val)){
                ListNode* tmp = head->next->next;
                delete head->next;
                head->next = tmp;
            }
            else{
                head = head->next;
            }
        }
        return headNew;
    }
};