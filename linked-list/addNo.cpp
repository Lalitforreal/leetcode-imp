class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry){
           int sum = carry;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }

            if(sum<10){//no carry 
                curr->next = new ListNode(sum);
                carry = 0; //no carry    
            }else{
                //when there is carry 
                int digit = sum%10;
                carry = sum /10; //this will go in the next iteration and sum = caryy in start
                curr->next = new ListNode(digit);
            }
            curr = curr->next; //end of teh loop
        }
        return dummy->next;
    }
};