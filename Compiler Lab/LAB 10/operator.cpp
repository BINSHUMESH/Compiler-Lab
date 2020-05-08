#include<bits/stdc++.h>
using namespace std;
int mat[5][5]={{0,1,1,1},
               {-1,1,-1,1},
               {-1,1,1,1},
               {-1,-1,-1,0}};
int getValue(char c){
    switch(c){
    case 'i':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    case '$':
        return 3;
    }
}
int main(){
    cout<<"Enter string to be parsed: ";
    string s;
    cin>>s;
    s=s+"$";
    stack<char> t;
    vector<char> ct;
    bool accepted=false;
    t.push('$');
    ct.push_back('$');
    for(int i=0;i<s.length();i++){
        int v1=getValue(t.top());
        int v2=getValue(s[i]);
        if(mat[v1][v2]==-1){
            t.push(s[i]);
            ct.push_back(s[i]);
        }
        if(mat[v1][v2]==1){
            while(mat[v1][v2]==1){
                t.pop();
                v1=getValue(t.top());
                if(mat[v1][v2]==-1){
                    t.push(s[i]);
                    ct.push_back(s[i]);
                    break;
                }
            }
        }
        if(mat[v1][v2]==0)
            accepted=true;
    }
    cout<<"stack Contents\n";
    for(int i=0;i<ct.size();i++){
        cout<<ct[i]<<" ";
    }
    cout<<"\nI/P string: ";
    if(accepted){
        cout<<"Accepted";
    }else{
        cout<<"Not Accepted";
    }
}

