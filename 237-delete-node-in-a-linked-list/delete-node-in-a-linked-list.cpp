/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        
        while(node && node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete(node);
        prev->next = NULL;
    }
};
