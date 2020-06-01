/* leetcode 328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note 
here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) 
time complexity.
Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd   = head;
        ListNode* even  = head->next,* even1=head->next;
        ListNode* head1 = head->next?head->next->next:nullptr;
        int x = 1;
        while(head1){
            if(1==x){
                odd->next = head1;
                odd = odd->next;
            }
            else{
                even->next = head1;
                even = even->next;		
            }
            x = 1-x;
            head1 = head1->next;
        }
        if(x==0) even->next = nullptr;
        odd->next = even1;
        return head;
    }
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        
        // 若选择以奇数项作为判断推进则复杂一些
		// 可保证偶数list以null结尾
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
