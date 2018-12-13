/* leetcode 426. Convert Binary search Tree to sorted Doubly Linked List
Convert a BsT to a sorted circular doubly-linked list in-place. 
Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.
Let's take the following BsT as an example, it may help you understand the problem better: 
 
We want to transform this BsT into a circular doubly linked list. 
Each node in a doubly linked list has a predecessor and successor. 
For a circular doubly linked list, the predecessor of the first element is the last element, 
and the successor of the last element is the first element.
The figure below shows the circular doubly linked list for the BsT above. 
The "head" symbol means the node it points to is the smallest element of the linked list.

specifically, we want to do the transformation in place. After the transformation, 
the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. 
We should return the pointer to the first element of the linked list.

The figure below shows the transformed BsT. The solid line indicates the successor relationship, 
while the dashed line means the predecessor relationship.
*/

class solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = new Node(0);
        Node* head1 = head;
        helper(root,head);
        head->right = head1->right;
        head1->right->left = head;
        return head1->right;
    }
    helper(Node* root,Node*& head){
        if(!root) return;
        helper(root->left,head);
        head->right = root;
        root->left =  head;
        head = root;
        helper(root->right,head);
    }
};

class solution {
    void goAlongLeftBranch(Node* root, stack<Node*>& s) {
        while (root) { 
            s.push(root); root = root->lChild; 
        } 
    }
public:
    void travIn_I1(Node* root) { 
        stack<Node*> s; 
        Node* head = new Node(0);
        Node* head1 = head;
        while (true) {
            goAlongLeftBranch(x, s); 
            if (s.empty()) break; 
            root = s.top(); s.pop(); 

            head->right = root;
            root->left =  head;
            head = root; 

            root = root->rChild; 
        }
        head->right = head1->right;
        head1->right->left = head;
        return head1->right;
    }
};

