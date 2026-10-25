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
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode d(0);
        ListNode* t = &d;
        while(a && b) {
            if(a->val < b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }
        t->next = a ? a : b;
        return d.next;
    }

    ListNode* solve(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return NULL;
        if(l == r) return lists[l];
        int m = l + (r - l) / 2;
        ListNode* left = solve(lists, l, m);
        ListNode* right = solve(lists, m + 1, r);
        return mergeTwo(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        return solve(lists, 0, lists.size() - 1);
    }
};

