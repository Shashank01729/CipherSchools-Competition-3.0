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

void Reorder(Node* &head){
    if(head==NULL || head->next==NULL || head->next->next==NULL){
        return;
    }

    Node* temp1=head;
    Node* temp2=head->next;
    while(temp2 && temp2->next){
        temp1=temp1->next;
        temp2=temp2->next->next;
    }

    Node* mid=temp1;
    Node* temp3=mid->next;
    mid->next=NULL;
    Node* temp4=NULL;
    while(temp3!=NULL){
        Node* nextNode=temp3->next;
        temp3->next=temp4;
        temp4=temp3;
        temp3=nextNode;
    }

    Node* a=head;
    Node* b=temp4;
    while(b!=NULL){
        Node* x=a->next;
        Node* y=b->next;
        a->next=b;
        b->next=x;
        a=x;
        b=y;
    }
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
    if(n>=1 && n<=5*105){
        for(int i=0;i<n;i++){
            cin >> data;
            if(data>=1 && data<=105){
                insert(head,data);
            }
        }
        Reorder(head);
        print(head);
    }
}