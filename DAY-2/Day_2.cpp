#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void insert(Node* &head, int d){
    Node* newNode=new Node();
    newNode->data=d;
    newNode->next=NULL;
    
    if(head==NULL){
        head=newNode;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void Even_Odd(Node*& head) {
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* e_head=NULL;
    Node* o_head=NULL;
    Node* e_tail=NULL;
    Node* o_tail=NULL;
    Node* temp=head;

    while(temp!=NULL){
        Node* &curr = (temp->data%2==0) ? e_tail : o_tail;
        if(curr==NULL){
            curr=temp;
            if(temp->data%2==0 && e_head==NULL){
                e_head=temp;
            } 
            else if(temp->data%2!=0 && o_head==NULL){
                o_head=temp;
            }
        } 
        else{
            curr->next=temp;
            curr=temp;
        }
        temp=temp->next;
    }

    if(e_tail){
        e_tail->next=o_head;
    }

    if(o_tail){
        o_tail->next=NULL;
    }

    head = e_head ? e_head : o_head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main(){
    int n,data;
    Node* head=NULL;
    cin >> n;
    if(n>=1 && n<=105){
        for(int i=0;i<n;i++){
            cin >> data;
            if(data>=1 && data<=105){
                insert(head,data);
            }
        }

        Even_Odd(head);
        print(head);
    }
}