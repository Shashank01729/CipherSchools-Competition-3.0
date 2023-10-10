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

void Number_Of_Connected_Components(Node* &head, vector<int>& v){
    int number=0;
    unordered_set<int> s(v.begin(),v.end());

    while(head!=NULL){
        if(s.find(head->data)!=s.end()){
            number++;
            while(head->next && s.find(head->data)!=s.end()){
                head=head->next;
            }
        }
        head=head->next;
    }
    cout << number << endl;
}

int main(){
    int n,m,data;
    vector<int> v;
    Node* head=NULL;
    cin >> n;
    if(n>=1 && n<=104){
        for(int i=0;i<n;i++){
            cin >> data;
            if(data>=0 && data<n){
                insert(head,data);
            }
        }

        cin >> m;
        if(m>=1 && m<=n){
            for(int i=0;i<m;i++){
                cin >> data;
                if(data>=0 && data<n){
                    v.push_back(data);
                }
            }

            Number_Of_Connected_Components(head,v);
        }
    }
}