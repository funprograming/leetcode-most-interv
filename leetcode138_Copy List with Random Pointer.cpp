/* leetcode 138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

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
// way 1 recursive
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