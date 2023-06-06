#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LLnode{
    int data;
    struct LLnode* next;
}NODE;
NODE* head;

NODE* createNode(int value){
    NODE* node = (NODE*)malloc(1*sizeof(NODE));
    return node;
}

NODE* getnodeValue(int value){
    NODE* node = head;

    while(node!= NULL){
        if(node->data == value){
            return node;
        }
        node = node->next;
    }
    printf("the value not found.\n");
    return NULL;
}

NODE* getNodeIndex(int index){
    NODE* node = head;

    for(int i=0;i<index;i++){
        if( node->next == NULL){
            perror("Index out of bound.\n");
            return NULL;
        }
        node = node->next;
    }

    return node;
}

void insertFirst(int val){
    NODE * node =(NODE *)malloc(1*sizeof(NODE));
    node->data = val;
    node->next = NULL;

    if(head == NULL){
        head = node;
        return;
    }
    
    node->next = head;
    head = node;
} 
/*
3 conditon:
if head ==NULL then assign node to head;
else if index ==0(insert at zeroth postion)
else
*/
void insert(int value, int index){
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = value;
    node->next = NULL;
    if(head != NULL){
        if(index == 0){
            node->next = head;
            head = node;
            return;
        }
        
        NODE * temp = head;
        //get (index-1) node
        for(int  i = 1; i<index ; i++ ){

            if(temp->next ==NULL && i<index -1){
                printf("the index exceed the range.Node appended at end.\n");
                break;
            }
            temp = temp->next;
        }
        
        node->next = temp->next;
        temp->next = node;
        return;
    }

    else{
        head = node; 
    }
}

int deleteIndex(int index) {
    if(head == NULL) {
        printf("No element in the list");
    }

    else {
        int delValue;
        if(index == 0){
            delValue = head->data;
            head = head->next;
        }

        else {

            NODE* temp = getNodeIndex(index-1);
            if(temp->next ==NULL){
                printf("Index out of bound.\n");
                return 0;
            }
            delValue = temp->next->data;
            temp->next = temp->next->next;
        }

        return delValue;
    }
    return 0;
}

int deleteAfterValue(int value){
    NODE* node = getnodeValue(value);

    if(node->next == NULL){
        printf("No after element found.\n");
        return 0;
    }
    int delValue = node->data;
    node = node->next;

    return delValue;
    
}

void display(){


    NODE* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }


    printf("END.\n");
}

void displayRev(NODE* node){
    if(node ==NULL){
        printf("END");
        return;
    }
    displayRev(node->next);
    printf(" <- %d",node->data);
    if(node ==head){
        printf(" <- START.\n");
    }
}
NODE* invertNode(NODE* node,NODE *  head){
    if(node->next == NULL){
        head = node;
        return node;
    }
    NODE* retNode = invertNode(node->next,head);
    retNode->next = node;
    node->next = NULL;
    return node;
}

bool invertList(){
    NODE* retNode =invertNode(head,head);
    if(retNode->next ==NULL){
        printf("List is inverted successfully.\n");
        return true;
    }

    printf("List not inverted!\n");
    return false;
}

// void swapNodes(int index_1, int index_2){
//     NODE *node1,*node2;
//     if(index_1 ==0)
//         node1 = head;
//     else
//         node1 = getNodeIndex(index_1 -1);

//     if(index_2 ==0)
//         node2 = head;
//     else
//         node2 = getNodeIndex(index_2 -1);
    
//     NODE *temp;
    
//     if(index_1 !=0 && index_2 != 0){
//         temp = node1->next;
//         node1->next = node2->next;
//         node2->next = temp;
//         node1 = node1->next;
//         node2 = node2->next;
//         temp = node1->next;
//         node1->next = node2->next;
//         node2->next = temp;
//     }
//     else{
//         head = node2->next;
//         temp = node1->next ;
//         node1->next = node2->next->next;
//         node2->next->next = temp;
//         node2->next = node1;
//     }
//}
void swapNodesIndex(int index1,int index2){
   
    if(index1 == 0){
        NODE *node1 = head,
            *prev2 = getNodeIndex(index2-1),
            *temp = prev2->next;
        
        head = temp;

        //CONNECT THE prev to NODES
        prev2->next = node1;
        
        //CONNECT THE NEXT OF NODES
        temp = node1->next;
        node1->next = head->next;
        head->next = temp;
    }
    else if(index2 == 0){
        swapNodesIndex(index2,index1);
        // NODE *node1 = head,
        //     *prev2 = getNodeIndex(index1-1),
        //     *temp = prev2->next;
        
        // head = temp;

        // //CONNECT THE prev to NODES
        // prev2->next = node1;
        
        // //CONNECT THE NEXT OF NODES
        // temp = node1->next;
        // node1->next = head->next;
        // head->next = temp;
    }
     else {
        NODE *prev1 = getNodeIndex(index1-1),
            *prev2 = getNodeIndex(index2-1),
            *temp = prev1->next;

        //CONNECT THE prev to NODES
        prev1->next = prev2->next;
        prev2->next = temp;

        //append the prevs to the nexts
        prev1 = prev1->next;
        prev2 = prev2->next;
        
        //CONNECT THE NEXT OF NODES
        temp = prev1->next;
        prev1->next = prev2->next;
        prev2->next = temp;
    }
    
}
int main(){
    if(head == NULL)
        printf("right\n");

    insertFirst(5);
    // insertFirst(6);
    insert(10,0);
        display();
    insert(20,0);
        display();
    insert(30,0);
        display();
    insert(40,1);
        display();
    insert(50,4);
        display();
    insert(70,100);
        display();
    printf("%d deleted\n",deleteIndex(0));
        display();
    printf("%d deleted\n",deleteIndex(3));
        display();
    printf("%d deleted\n",deleteIndex(5));
        display();
    printf("%d deleted\n",deleteAfterValue(10));
        display();
    printf("%d deleted\n",deleteAfterValue(70));
        display();
    displayRev(head);
    // invertList();       //ABSTRACTION OF HEAD.
    //     display();
    // invertList(head,head); //no abstracttion 
    //     display();
    swapNodesIndex(1,3);
        display();
    swapNodesIndex(0,3);
        display();
    swapNodesIndex(3,1);
        display();
    swapNodesIndex(2,4);
        display();
    swapNodesIndex(0,4);
        display();
swapNodesIndex(4,0);
        display();
    return 0;
}