#include<bits/stdc++.h>
using namespace std;

int Minimum_Operation(vector<int>& A, int n, vector<int>& B, int m) {
    unordered_set<int> s;
    vector<int> v;
    vector<int> v1;
 
    for(int i=0;i<m;i++){
        s.insert(B[i]);
    }

    for(int i=0;i<n;i++){
        if(s.find(A[i])!=s.end()){
            v.push_back(A[i]);
        }
    }
 
    for(auto i : v){
        auto it=lower_bound(v1.begin(),v1.end(),i);
        if(it!=v1.end()){
            *it = i;
        }
        else{
            v1.push_back(i);
        }
    }
 
    int ins=n-v1.size(),del=m-v1.size();
    return ins+del;
}

int main() {
    vector<int> A;
    int n;
    cin >> n;
    if(n>=1 && n<=105){
        for(int i=0;i<n;i++){
            int data;
            cin >> data;
            if(data>=1 && data<=105){
                A.push_back(data);
            }
        }
    }

    vector<int> B;
    int m;
    cin >> m;
    if(n>=1 && n<=105){
        for(int j=0;j<m;j++){
            int data;
            cin >> data;
            if(data>=1 && data<=105){
                B.push_back(data);
            }
        }
    }

    cout << Minimum_Operation(A,n,B,m) << endl;
}
