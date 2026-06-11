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
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode* curr = &res;

        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;

            carry = sum >= 10 ? sum / 10 : 0;
            sum = sum >= 10 ? sum % 10 : sum;

            ListNode* node = new ListNode(sum);
            curr->next = node;

            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }

        while (l1 || l2) {
            int sum = ((l1 != nullptr) ? l1->val : l2->val )+ carry;

            carry = sum >= 10 ? sum / 10 : 0;
            sum = sum >= 10 ? sum % 10 : sum;

            ListNode* node = new ListNode(sum);
            curr->next = node;

            if (l1 != nullptr) {
                l1 = l1->next;
            } else {
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // while (l2) {
        //     int sum = l2->val + carry;

        //     carry = sum >= 10 ? sum / 10 : 0;
        //     sum = sum >= 10 ? sum % 10 : sum;

        //     ListNode* node = new ListNode(sum);
        //     curr->next = node;

        //     l2 = l2->next;
        //     curr = curr->next;
        // }

        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            curr->next = node;
        }

        return res.next;
    }
};
