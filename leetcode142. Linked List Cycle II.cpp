/* leetcode142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        bool cycle = false;
        
        while(slow && fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                cycle = true;
                break;
            }
        }
        if(!cycle) return nullptr;

        // slow and fast will meet after fast walk the first cycle
        // which is 2(a+t) = a+s+t --> a = s-t
        // a is head1 to cycle p,s-t is slow pointer to the cycle p
        ListNode *head1 = head;
        while(head1!=slow){
            slow = slow->next;
            head1 = head1->next;
        }
        return head1;
    }
};