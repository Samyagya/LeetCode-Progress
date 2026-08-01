// Last updated: 01/08/2026, 22:46:21
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
    void reorderList(ListNode* head) {
        deque<ListNode*> nodes;
        ListNode* currNodeptr = head;
        while(currNodeptr != nullptr){
            nodes.push_back(currNodeptr);
            currNodeptr = currNodeptr->next;
        }
        int val = 1; //odd-> back , even ->front
        currNodeptr = head;
        while(!nodes.empty()){
            if(val%2 == 0){
                currNodeptr->next = nodes.back();
                nodes.pop_back();
                currNodeptr = currNodeptr->next;
            }else{
                currNodeptr->next = nodes.front();
                nodes.pop_front();
                currNodeptr = currNodeptr->next;
            }
            val++;
        }
        currNodeptr->next = nullptr;
    }
};