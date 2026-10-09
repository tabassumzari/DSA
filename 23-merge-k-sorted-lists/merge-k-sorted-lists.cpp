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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) const {
            // Put the node with the smallest value at the top.
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Add the first node of every non-empty list.
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            // Take the smallest currently available node.
            ListNode* node = pq.top();
            pq.pop();

            // Add the next node from the same list.
            if (node->next)
                pq.push(node->next);

            // Append this node to the merged list.
            tail->next = node;
            tail = node;
        }

        tail->next = nullptr;
        return dummy.next;
    }
};