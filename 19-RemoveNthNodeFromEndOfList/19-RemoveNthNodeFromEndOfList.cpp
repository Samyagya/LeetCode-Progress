// Last updated: 01/08/2026, 22:47:55
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* currNodeptr = head;
        while(currNodeptr != nullptr){
            currNodeptr = currNodeptr->next;
            size++;
        }
        int toTraverse = size - n;
        if(n == size){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* prevNodeptr = nullptr;
        currNodeptr = head;
        while(toTraverse != 0){
            prevNodeptr = currNodeptr;
            if(currNodeptr) currNodeptr = currNodeptr->next;
            toTraverse--;
        }
        
        
        if(currNodeptr == nullptr) {
            prevNodeptr->next = nullptr;
        }else{
            ListNode* nextNodeptr = currNodeptr->next;
            prevNodeptr->next = nextNodeptr;
        }

        return head; 
    }
};