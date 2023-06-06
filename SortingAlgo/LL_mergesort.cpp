#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode():val(0), next(NULL) {}
    ListNode(int value):val(value), next(NULL) {}
    ListNode(int val,ListNode *next):val(val), next(next) {}
};

class LL{
    ListNode *head;
    ListNode *tail;
    int size;
    public:
    LL(): size(0), head(NULL), tail(NULL){}

    void insertFirst(int val){
        ListNode *node = new ListNode(val);

        if(head != NULL){
            node->next = head;
        }
        head = node;
        if(tail ==NULL){
            tail = node;
        }
    }

    void insertLast(int val){
        ListNode *node = new ListNode(val);
        if(tail !=NULL){
            tail->next = node;
        }
        if(head ==NULL){
            head = node;
        }
        tail = node;
    }

    int  deletefirst(){
        if(head == NULL){
            cout<<"NO element is the LL."<<endl;
        }
        else{
            head = head->next;
        }
    }
    int deleteLast(){
        if(head == NULL){
            cout<<"NO element is the LL."<<endl;
        }
        else{
            ListNode* secLast =head;
            while(secLast->next !=tail){
                secLast = secLast->next;
            } 
            tail = secLast;
            tail->next = NULL;
        }
    }

    ListNode* getHead(){
        return head;
    }
    void setHead(ListNode* head){
        this->head = head;
    }
    void display(){
        ListNode* temp = head;
        while(temp!= NULL){
            cout<<temp->val<<" -> ";
            temp= temp->next;
        }
        cout<<"END."<<endl;
    }
};

class Solution{
public:
    ListNode* mid_node(ListNode *head){
        if(head==NULL){
            return head;
        }
        ListNode *slow,*fast;
        slow = head;
        fast = head->next;
        while (fast !=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<slow->val<<endl;
    return slow;
    }

    ListNode *merge_two_sorted(ListNode*head1,ListNode *head2){
        ListNode *head3 = new ListNode();
        ListNode*temp =head3;
        while(head1 != NULL && head2 != NULL){
            if(head1->val<head2->val){
                temp->next = new ListNode(head1->val,NULL);
                head1 = head1->next;
            }
            else{
                temp->next = new ListNode(head2->val,NULL);
                head2 = head2->next;
            }
            temp = temp->next;
        }
        while(head1!= NULL){
            temp->next = new ListNode(head1->val,NULL);
            head1 = head1->next;
            temp = temp->next;
        }
        while(head2!= NULL){
            temp->next = new ListNode(head2->val,NULL);
            head2 = head2->next;
            temp = temp->next;
        }
        return head3->next;
    }

    ListNode * copyLL(ListNode *head,ListNode* tail){
        if(head ==NULL){
            return head;
        }
        ListNode* dummy_head = new ListNode();
        ListNode *temp = dummy_head;
        if(tail ==NULL){
            while(head != tail){
            temp->next = new ListNode(head->val);
            temp = temp->next;
            head = head->next;
        }
        }
        else{
            while(head != tail->next){
                temp->next = new ListNode(head->val);
                temp = temp->next;
                head = head->next;
            } 
        }
        return dummy_head->next;
    }
    
    ListNode *mergeSort(ListNode*head){
        if(head != NULL&&head->next ==NULL){
            return head;
        }
        ListNode *mid = mid_node(head);
        //left
        ListNode* left = mergeSort(copyLL(head,mid));
        //right
        ListNode* right = mergeSort(copyLL(mid->next,NULL));

        ListNode *head3= merge_two_sorted(left,right);
        return head3;
    }
    ListNode *revListInplace(ListNode *node){
    if(node->next ==NULL){
        return node;
    }
    ListNode* head = revListInplace(node->next);
    node->next->next = node;
    node->next =NULL;
    return head;
    }

    ListNode *revList(ListNode *node,ListNode*dummyHead){
    if(node->next ==NULL){
        dummyHead->next = new ListNode(node->val);
        return dummyHead->next;
    }
    ListNode *retnode = revList(node->next,dummyHead);
    retnode->next = new ListNode(node->val);
    return retnode->next; 
    }
};

int main(int argc, char const *argv[]){   
    LL l1,l2,l3,l4;
    l1.insertFirst(0);
    l1.insertFirst(2);
    l1.insertFirst(4);
    l1.insertFirst(6);
    l1.display();

    l2.insertFirst(5);
    l2.insertFirst(3);
    l2.insertFirst(1);
    l2.display();
    
    Solution s;
    s.mid_node(l1.getHead());
    s.mid_node(l2.getHead());
    l3.setHead(s.merge_two_sorted(l1.getHead(),l2.getHead()));
    l3.display();
    l1.display();
    l2.display();
    l1.setHead(s.mergeSort(l1.getHead()));
    l1.display();
    l2.setHead(s.copyLL(l2.getHead(),NULL));
    l2.display();
    ListNode* mid =  s.mid_node(l1.getHead());
    l1.setHead(s.copyLL(l1.getHead(),mid));
    l1.display();
    l3.display();
    ListNode *dummyhead = new ListNode();
    l3.setHead(s.revList(l3.getHead(),dummyhead));
    l4.setHead(dummyhead->next);
    l4.display();

    return 0;

}
