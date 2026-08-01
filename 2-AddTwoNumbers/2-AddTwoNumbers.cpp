// Last updated: 01/08/2026, 22:48:10
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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* ansHead = nullptr;
        ListNode* temp = ansHead;
        while(temp1 != NULL || temp2 != NULL || carry != 0){
            int val1 = (temp1 != NULL ? temp1->val : 0);
            int val2 = (temp2 != NULL ? temp2->val : 0);
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            
            if(ansHead == nullptr){
                ansHead = newNode;
                temp = ansHead;
            }else{
                temp->next = newNode;
                temp = temp->next;
            }

            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }

        return ansHead;
    }
};