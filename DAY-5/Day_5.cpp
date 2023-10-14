#include<bits/stdc++.h>
using namespace std;

void Largest_Rectangular_Area_In_Histogram(vector<int>& v, int n){
    int ans=0;
    stack<int> s;
    for(int i=0;i<=n;i++){
        while(!s.empty() && (v[s.top()] >= v[i] || i==n)){
            int size=v[s.top()],x;
            s.pop(); 
            (s.empty()) ? (x=i) : (x=i-s.top()-1);
            ans=max(ans,x*size);
        }s.push(i);
    }cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    if(n>=1 && n<=106){
        for(int j=0;j<n;j++){
            int data;
            cin >> data;
            if(data>=0 && data<=1012){
                v.push_back(data);
            }
        }
    }Largest_Rectangular_Area_In_Histogram(v,n);
}