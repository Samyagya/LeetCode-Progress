// Last updated: 01/08/2026, 22:46:24
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
        //mapping location of old node to location of new node
        unordered_map<Node* , Node*> oldToNew; 
        Node* oldHead = head;
        Node* oldTemp = oldHead;
        while(oldTemp != NULL){
            Node* temp = new Node(oldTemp->val);
            // (*temp).val = oldTemp->val;
            oldToNew[oldTemp] = temp;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        while(oldTemp != NULL){
            Node* copy = oldToNew[oldTemp];
            copy->next = oldToNew[oldTemp->next];
            copy->random = oldToNew[oldTemp->random];
            oldTemp = oldTemp->next;
        }

        return oldToNew[head];
    }
};