/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    private:
ListNode* reverse(ListNode* head, ListNode* newNext) {
    if (head->next == nullptr) {
        head->next = newNext;
        return head;  
    }

    ListNode* newHead = head->next;
    head->next = newNext;

    return reverse(newHead, head);
}
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        return reverse(head, nullptr);
    }
};
