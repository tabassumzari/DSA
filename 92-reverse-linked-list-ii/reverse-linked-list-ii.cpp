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
     ListNode* reverse(ListNode* head, ListNode* rightNode) {
        if(!head || !head->next || head == rightNode) {
            return head;
        }
        
        ListNode* last = reverse(head->next, rightNode);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode  = NULL;
        ListNode* leftPrev  = NULL;
        ListNode* rightNode = NULL;
        ListNode* rightNext = NULL;
        
        ListNode* curr = head;
        int c = 1;
        while(c < left) {
            leftPrev = curr;
            curr = curr->next;
            c++;
        }
        leftNode = curr;
        
        while(c < right) {
            curr = curr->next;
            c++;
        }
        
        rightNode = curr;
        rightNext = rightNode->next;
                
        // Reverse nodes [leftNode, rightNode]
        ListNode* temp = reverse(leftNode, rightNode);
        
       // Adjust the (left-1) node and (right+1) node
        if(leftPrev && leftPrev->next) {
            leftPrev->next->next = rightNext;
            leftPrev->next = temp;
        } else {
            //corner case (left  = 1)
            head->next = rightNext;
            head = temp;
        }
                        
        return head;
    }
};