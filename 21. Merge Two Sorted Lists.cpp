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
class Solution
{
public:
    ListNode *insertIntoList(ListNode *list, int val){
        ListNode *temp = list;
        ListNode *newNode = new ListNode(val);
        if(temp == NULL){
            list = newNode;
            return list;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return list;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *newList = NULL;
        while(1){
            if(l1 == NULL || l2 == NULL){
                break;
            }
            else if(l1->val <= l2->val){
                newList = insertIntoList(newList, l1->val);
                l1 = l1->next;
            }
            else{
                newList = insertIntoList(newList, l2->val);
                l2 = l2->next;
            }
        }
        if(newList == NULL){
            if(l1 == NULL){
                newList = l2;
            }
            else{
                newList = l1;
            }
            return newList;
        }
        ListNode *temp = newList;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(l1 == NULL){
            temp->next = l2;
        }
        else if(l2 == NULL){
            temp->next = l1;
        }
        return newList;
    }
};
