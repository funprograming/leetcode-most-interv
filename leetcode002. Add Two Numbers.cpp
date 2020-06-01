/*
leetcode 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single 
digit.Add the two numbers and return it as a linked list.You may assume the two 
numbers do not contain any leading zero, except the number 0 itself.

Example:
// 注意:两个链表的长度不一定等长
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		#if 0
		ListNode* node = new ListNode(0);
		ListNode* head = node;
		int i,j=0;
		while(l1||l2){
			i=0;
			if(l1) {i+=l1->val,l1=l1->next;};
			if(l2) {i+=l2->val,l2=l2->next;};
			ListNode* l = new ListNode((j+i)%10);
			j = (j+i)/10;
			head->next = l;
			head=head->next;
			
		}
		if(j) head->next = new ListNode(j);
		return node->next;        
		#endif	
        ListNode* rst = new ListNode(0);
        ListNode* rsthead = rst;
        int sum = 0;
        while(l1 || l2){
            sum /=10;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            // 最初先创建个表头有利于简便代码操作
            rst->next = new ListNode(sum%10);
            rst = rst->next;
        }

        if(sum /=10) rst->next = new ListNode(1);
        return rsthead->next;
    }
};