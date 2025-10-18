class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        for(int i = 0 ; i<k; i++){
            if(!tail){
                return head;
            }

            tail = tail->next;
        }

        ListNode* newHead = rev(head, tail);
        head->next = reverseKGroup(tail, k); //head->next is 1->next(after reversal)
        return newHead;
    }

    ListNode* rev(ListNode* curr, ListNode* end){
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        while(curr!= end){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev; //the new head excluding the end/tail/3 in first run
    }
};