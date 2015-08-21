#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#define isOp(c) ((c == '!')||(c == '*')||(c == '^')||(c == '+')||(c == '-')||(c == '/'))

using namespace std;
int main(){
    int tCases;
    scanf("%d",&tCases);
    cin.ignore();
    for(int p=0;p<tCases;++p){
        stack<char> symbolStack;
        string str;
        string output = "";
        getline(cin,str);
        //cout << str << endl;
        for(int i=0;i<str.size();i++){
            if(isalpha(str[i])){
                //cout <<"#bc"<<i<<" "<< output << endl;
                output += str[i];
            }else if(str[i]=='('){
                //cout <<"#"<<i<<" "<< output << endl;
                symbolStack.push(str[i]);
            }else if(isOp(str[i])){
                //cout <<"#"<<i<<" "<< output << endl;
                symbolStack.push(str[i]);
            }else if(str[i]==')'){
                //cout <<"#"<<i<<" "<< output << endl;
                while(symbolStack.top()!= '('){
                    output += symbolStack.top();
                    symbolStack.pop();
                }
                if(!symbolStack.empty());
                    symbolStack.pop();
            }
            //cout <<"#"<<i<<" "<< output << endl;
        }
        while(!symbolStack.empty()){
            if(symbolStack.top()!='(' || symbolStack.top() == ')'){
                output += symbolStack.top();
            }
            if(!symbolStack.empty())
                symbolStack.pop();
        }
        cout << output << endl;
    }
    return 0;
}
