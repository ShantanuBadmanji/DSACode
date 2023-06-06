#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

} ListNode;

// class Solution {

//      unsigned long long int addNum(ListNode* node){
//         if(node->next == NULL){
//             return node->val;
//         }
//          unsigned long long int num = addNum(node->next);
//         return num*10 +node->val;
//     }
//     ListNode* formNum(unsigned long long int num){
//         if(num/10 == 0){
//         ListNode* node = new ListNode(num,NULL);
//             return node;
//         }
//         ListNode* temp = formNum(num/10);
//         ListNode* node = new ListNode(num%10,temp);
//         return node;
//     }

// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         unsigned long long int num1 = addNum(l1);
//         unsigned long long int num2 = addNum(l2);
//         unsigned long long int sum = num1+num2;
//         ListNode* head = formNum(sum);
//         return head;
//     }
// };

class Solution
{
    ListNode *revList(ListNode *node, ListNode **head)
    {
        if (node->next == NULL)
        {
            *head = node;
            return node;
        }
        ListNode *temp = revList(node->next, head);
        temp->next = node;
        node->next = NULL;
        return node;
    }

public:
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     revList(l1,&l1);
    //     revList(l2,&l2);
    //     ListNode* temp1 = l1,*temp2 = l2,*l3 =NULL;
    //     ListNode*temp3 = l3;
    //     int carry=0;
    //     while(temp1!= NULL || temp2 != NULL || carry ==1){
    //         ListNode *temp = new ListNode(0,NULL);

    //         if(temp1 != NULL){
    //             temp->val +=temp1->val;
    //             temp1 = temp1->next;
    //         }

    //         if(temp2 != NULL){
    //             temp->val +=temp2->val;
    //             temp2 = temp2->next;
    //         }

    //         temp->val +=carry;
    //         carry =0;
    //         if(temp->val >9){
    //             carry = 1;
    //             temp->val -=10;
    //         }

    //         if(temp3 ==NULL){
    //             temp3 = temp;
    //             l3 = temp3;
    //         }
    //         else{
    //             temp3->next = temp;
    //             temp3 = temp3->next;
    //         }

    //     }
    //     return l3;
    // }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // revList(l1,&l1);
        // revList(l2,&l2);
        ListNode *temp1 = l1, *temp2 = l2, *l3 = NULL, *prev = NULL;
        ListNode *temp3 = l3;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL || carry == 1)
        {
            ListNode *temp = new ListNode(0, NULL);

            if (temp1 != NULL)
            {
                temp->val += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL)
            {
                temp->val += temp2->val;
                temp2 = temp2->next;
            }
            //             if(prev != NULL)
            // {
            //                 prev->val +=carry;
            //                 carry =0;
            //             }
            temp->val += carry;
            carry = 0;
            if (temp->val > 9)
            {
                carry = 1;
                temp->val -= 10;
            }

            if (temp3 == NULL)
            {
                temp3 = temp;
                l3 = temp3;
            }
            else
            {
                temp3->next = temp;
                prev = temp3;
                temp3 = temp3->next;
            }
        }
        return l3;
    }

    void insertfirst(struct ListNode **head, int val)
    {
        ListNode *temp = new ListNode(val, NULL);
        if (head == NULL)
        {
            *head = temp;
        }
        temp->next = *head;
        *head = temp;
    }

    void display(ListNode *l)
    {

        while (l != NULL)
        {
            cout << l->val << " -> ";
            l = l->next;
        }
        printf("END\n");
    }
    // INSERSTION SORT
    ListNode *insertionSortList_using_StackQue(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        stack<ListNode *> sort;
        sort.push(head);
        ListNode *node = head->next;
        while (node != NULL)
        {
            queue<ListNode *> rec;
            while (sort.top()->val > node->val)
            {
                rec.push(sort.top());
                sort.pop();
                if (sort.empty())
                {
                    break;
                }
            }
            // cout << "after finding the posi :";
            // display(head);
            if (!sort.empty())
            {
                sort.top()->next = node;
            }
            else
            {
                head = node;
            }

            if (!rec.empty())
            {
                rec.front()->next = node->next;
                node->next = rec.back();
                node = rec.front()->next;
            }
            else
            {
                node = node->next;
            }
            // cout << "after inserting node   :";
            // display(head);
            while (sort.empty() || sort.top() != node)
            {
                if (sort.empty())
                {
                    sort.push(head);
                }
                else
                {
                    sort.push(sort.top()->next);
                }
            }
            sort.pop();
            // cout << "after fill stack       :";
            // display(head);
            // cout << endl;
        }
        return head;
    }
    ListNode *insertionSortList(ListNode *head){
        if(head ==NULL||head->next ==NULL) {
            return head;
        }
        ListNode*dummy = new ListNode(),
                *node = head,
                *sort;
        dummy->next = head;
        while(node!=NULL && node->next!=NULL){
            sort = dummy;
            while(sort !=node && sort->next->val<node->next->val){
                sort = sort->next;
            }
            if(sort==node){
                node = node->next;
            }
            else{
                if(sort->next ==head){
                    head = node->next;
                }
                ListNode*temp = node->next;
                node->next = node->next->next;
                temp->next = sort->next;
                sort->next = temp;
                
            }
            // display(head);
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution a;
    ListNode *l1 = NULL, *l2 = NULL;
    a.insertfirst(&l1, 9);
    a.insertfirst(&l1, 4);
    a.insertfirst(&l1, 2);

    // a.insertfirst(&l1,5);
    // a.insertfirst(&l2, 1);
    
    a.insertfirst(&l2, 3);
    a.insertfirst(&l2, 7);
    a.insertfirst(&l2, 4);
    a.insertfirst(&l2, 1);
    // a.insertfirst(&l2, -1);

    a.display(l1);
    a.display(l2);
    ListNode *l3 = a.addTwoNumbers(l1, l2);
    a.display(l1);
    a.display(l2);
    a.display(l3);
    cout << endl;
    ListNode *l4 = a.insertionSortList(l2);
    a.display(l4);
    l4 = a.insertionSortList_using_StackQue(l2);
    a.display(l4);
    return 0;
}