class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* temp = head;

        while(temp){
            //move runner pointer till the value changes
            while(temp->next!=nullptr && temp->val == temp->next->val){
                temp = temp->next;
            }
            //now temp is at the last duplicate
            if(head == temp){
                curr->next = head;
                curr = curr->next; //if you dont do this, it will keep changing the first index of dummy
            }
            //change the value of temp and head to the next unique
            temp = temp->next;
            head = temp;
        }
        //now when out of while loop make sure curr->next == nullptr
        curr->next = nullptr;
        return dummy->next;
    }
};