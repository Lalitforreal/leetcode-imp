class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* temp = head;
        ListNode* tail = nullptr;
        while(temp!= nullptr){
             count++;
             temp = temp->next;
        }

        if (!head || left == right) return head; //dafety patch for edge case

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        temp = dummy; //new list

        
        int leftPointer = left;
        int rightPointer = right;


        for (int i = 1; i < leftPointer; i++) {
            temp = temp->next;
        }
        ListNode* leftPrev = temp;
        
        ListNode* scan = leftPrev->next;
        for (int i = left; i < right && scan; i++) {
            scan =scan->next;
        }
        ListNode* rightP = scan;

        if(!rightP){
            return dummy->next;
        }

        tail = rightP->next; //
        rightP->next = nullptr;
        
        
        //  //now rotate
        // rightP->next = leftPrev->next; //circular banado
        ListNode* dFront = nullptr;
        ListNode* dPrev = nullptr;

        ListNode* curr = leftPrev->next;
        while(curr != nullptr){
            dFront = curr->next;
            curr->next = dPrev;
            dPrev = curr;
            curr = dFront;
        }//the the part is reversed adn curr == 4

        if (dPrev) {
            leftPrev->next = dPrev; // connect start
            while (dPrev && dPrev->next) {
                dPrev = dPrev->next;
            }
            dPrev->next = tail; // connect end
        } else {
            leftPrev->next = tail; // if nothing was reversed
        }
        return dummy->next;
        

    }
};