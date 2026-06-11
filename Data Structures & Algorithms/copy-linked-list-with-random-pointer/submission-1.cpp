/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* resNode = new Node(0);
        Node* curr = resNode;

        while (head != nullptr) {
            if (mp.count(head) == 1) {
                // if node was prev created
                curr->next = mp[head];
            } else {
                // node was not prev created
                Node* node = new Node(head->val);
                curr->next = node;
                mp[head] = node;
            }

            curr = curr->next;  // moving to the newly attached node;

            if (head->random == nullptr) {
                // if random is null
                curr->random = nullptr;
            } else if (mp.count(head->random) == 1) {
                // if random was already created
                curr->random = mp[head->random];
            } else {
                // if random was not created, create new node
                Node* rand = new Node(head->random->val);
                curr->random = rand;
                mp[head->random] = rand;
            }

            head = head->next;  // move head to next node
        }

        return resNode->next;
    }
};