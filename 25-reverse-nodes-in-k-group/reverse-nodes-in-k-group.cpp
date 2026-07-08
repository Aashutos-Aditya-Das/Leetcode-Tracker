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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k==1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* _1_start = dummy->next;
        ListNode* _1_end = dummy->next;
        ListNode* pre_start = dummy;

        while(_1_start){
            int length = 0;

            while(_1_end && length<k){
                length++;
                if(length == k) break;
                _1_end = _1_end->next;
            }

            if(length<k) break;

            ListNode* _2_start = _1_end->next;
            ListNode* curr = _1_start;
            ListNode* prev = _2_start;

            while(length--){
                ListNode* getNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = getNext;
            }

            pre_start->next = prev;

            pre_start = _1_start;
            _1_start = _2_start;
            _1_end = _1_start;
        }

        return dummy->next;
    }
};