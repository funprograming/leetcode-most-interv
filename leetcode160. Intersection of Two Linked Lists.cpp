/* leetcode160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto currA = headA, currB = headB;
        int countA = 0, countB = 0;
        
        while (currA) { 
            currA = currA->next, countA++;
        }
        while (currB) {
            currB = currB->next, countB++;
        }
        int diff = std::abs(countA - countB);
        if(countA>countB){
            while (diff--) headA = headA->next; 
        }else{
            while (diff--) headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next, headB = headB->next;
        }
        return headA;
    }
};