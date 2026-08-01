// Last updated: 01/08/2026, 22:46:08
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
    ListNode* reverseList(ListNode* head) {
        ListNode* nextNodeptr = head;
        ListNode* currNodeptr = nullptr;
        ListNode* prevNodeptr = nullptr;
        while(nextNodeptr != nullptr){
            currNodeptr = nextNodeptr;
            nextNodeptr = currNodeptr->next;
            currNodeptr->next = prevNodeptr;
            prevNodeptr = currNodeptr;
        }
        head = currNodeptr;
        return head;
    }
};