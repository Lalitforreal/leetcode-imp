//brute force using nested while
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp;
//         while(headA != nullptr){
//             temp = headB;
//             while(temp != nullptr){
//                 if(headA == temp ){
//                     return headA;
//                 }
//                 temp = temp->next;
//             }
//             headA = headA->next;
//         }
//         return NULL;
//     }
// };

//optimized two pointer 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;

        while(currA != currB){
            if(currA == NULL){
                currA = headB;
            }else{
                currA = currA->next;
            }

            if(currB == NULL){
                currB = headA;
            }else{
                currB = currB->next;
            }
        }
        return currA;
    }
};