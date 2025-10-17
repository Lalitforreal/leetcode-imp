class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k == 0){
            return head;
        }
        int count = 1;
        ListNode* tail = head;

        while(tail && tail->next){
            count++; 
            tail=tail->next; 
        }
        tail->next = head;//make the list circular

        //adjust k to avoid uneccessary rotations
        //when k>count the for loop will return i < -1 adn not work;
        k = k % count;
        if (k == 0) {
            tail->next = nullptr; // break the circle
            return head;
        }

        ListNode* temp = head;
        for(int i = 1; i< count-k ; i++){
            temp = temp->next;
        }
        head = temp->next;

        temp->next = nullptr;
        return head;

    }
};