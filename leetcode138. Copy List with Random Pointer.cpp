/* leetcode 138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// way 1 recursive Space o(n) Time O(n)
class Solution {
private:
    unordered_map<RandomListNode *,RandomListNode *> nodemap;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if(nodemap.find(head)!= nodemap.end()) return nodemap[head];
        RandomListNode *copyhead = new RandomListNode(head->label);
        nodemap[head] = copyhead;

        copyhead->next   = copyRandomList(head->next);
        copyhead->random = copyRandomList(head->random);

        return copyhead;
    }
};

// way 2 Space o(1) Time O(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        // copy new next and insert after old ones
        RandomListNode *head1 = head;
        while(nullptr!=head1){
            RandomListNode *tmp = new RandomListNode(head1->label);
            tmp->next = head1->next;
            head1->next = tmp;
            head1 = tmp->next;
        }
        // copy new random and connect
        head1 = head;
        while(nullptr!=head1){
            //head1->next will never be null,so head1->next->random is ok to use
            head1->next->random = head1->random ? head1->random->next:nullptr;
            head1 = head1->next->next;
        }
        // serparate two linked list
        RandomListNode *head_old = head;
        RandomListNode *head_new = head->next;
        RandomListNode *head_rst = head->next;
        while(nullptr!=head_old){
            head_old->next =   head_old->next->next;
            head_new->next = head_new->next ? head_new->next->next:nullptr;
            head_old = head_old->next;
            head_new = head_new->next;
        }
        return head_rst;
    }
};