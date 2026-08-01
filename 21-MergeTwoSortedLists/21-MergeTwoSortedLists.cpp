// Last updated: 01/08/2026, 22:47:50
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* l1ptr = list1;
        ListNode* l2ptr = list2;
        ListNode* head = nullptr;
        if(l1ptr->val <= l2ptr->val){
            head = l1ptr;
            l1ptr = l1ptr->next;
        }else{
            head = l2ptr;
            l2ptr = l2ptr->next;
        }
        ListNode* nextNodeptr = head;
        while(nextNodeptr != nullptr){
            ListNode* temp = nullptr;
            if(l1ptr == nullptr && l2ptr == nullptr){
                nextNodeptr = nullptr;
            }else if(l1ptr == nullptr){
                temp = l2ptr;
                l2ptr = l2ptr->next;
            }else if(l2ptr == nullptr){
                temp = l1ptr;
                l1ptr = l1ptr->next;
            }else if(l1ptr->val <= l2ptr->val){
                temp = l1ptr;
                l1ptr = l1ptr->next;
            }else{
                temp = l2ptr;
                l2ptr = l2ptr->next;
            }
            if(temp != nullptr){
                nextNodeptr->next = temp;
                nextNodeptr = temp;
            }

        }
        return head;
    }
};