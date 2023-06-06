#include<iostream>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

     
  };
ListNode* insert_first(ListNode *head,int val){
    if(head ==NULL){
        ListNode *node = new ListNode(val,NULL);
    return node;
    }

    ListNode *node = new ListNode(val,head);
    head = node;
    return node;
}
void display(ListNode *head){
    while(head != NULL){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"END"<<endl;
}
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL||head->next == NULL)
            return head;
        
        ListNode *node = head, *prev = NULL;
        bool dup = false;

        while(node !=NULL && node->next !=NULL){
            if(node->next->val ==node->val){
                dup = true;
                node->next ==node->next->next;
                
            }
            else{
                if(dup == false){
                    prev = node;
                }
                else{
                    if(node == head){
                        head = node->next;
                    }
                    else{
                        prev->next = prev->next->next;
                    }
                    dup = true;
                }
                node = node->next;
            }
            // else{
            //     if(node == head && dup == true){
            //         node = node->next;
            //         head = node;
            //         dup = false;
            //     }

            //     else if(node==head && dup==false){
            //         prev = head;
            //         node=node->next;
            //     }
            //     else{
            //         node = node->next;
            //         if(dup ==false){
            //             prev = prev->next;
            //         }
            //         else{
            //             prev->next = prev->next->next;
            //             dup = false;
            //         }

            //     }
            // }
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{   ListNode* head = NULL;
    ListNode* l1 = insert_first(head,5);
    ListNode* l2 =insert_first(l1,4);
    ListNode* l3 =insert_first(l2,3);
    ListNode* l4 =insert_first(l3,2);
    ListNode* l5 =insert_first(l4,1);
    display(head);
    Solution s();
    return 0;
}
