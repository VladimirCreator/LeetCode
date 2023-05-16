/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     public:
 *         int val;
 *         ListNode *next;
 *         ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
 * };
*/
int count_list(const ListNode *list) {
    int count{1};
    while (list -> next) {
        list = list -> next;
        count += 1;
    }
    return count;
}

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int l1_count = count_list{l1},
                l2_count = count_list{l2};

            ListNode *l1_current{l1},
                     *l2_current{l2};

            if (l1_count < l2_count) {
                l1_current = l2;
                l2_current = l1;
            }

            bool hasOverflow = false;
            while (l1_count > 0 || l2_count > 0) {
                if (l1_count > 0 && l2_count > 0) {
                    l1_current -> val += l2_current -> val;
                }

                if (hasOverflow) {
                    l1_current -> val += 1;
                    hasOverflow = false;
                }

                if (l1_current -> val >= 0x0A) {
                    l1_current -> val = l1_current -> val % 10;
                    hasOverflow = true;
                }

                if (l1_current -> next) {
                    l1_current = l1_current -> next;
                }
                if (l2_current -> next) {
                    l2_current = l2_current -> next;
                }
                l1_count -= 1;
                l2_count -= 1;
            }
            if (hasOverflow) {
                l1_current -> next = new ListNode;
                l1_current -> next -> val = 1;
            }

            if (l1_count >= l2_count) {
                return l1;
            } else {
                return l2;
            }
        }
};
