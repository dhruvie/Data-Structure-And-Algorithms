#include<bits/stdc++.h>
using namespace std;
string infixToPostfix(string e)
{
    string ans="";
    unordered_map<char,int> hash={
        {'^',3},{'/',2},{'*',2},{'-',1},{'+',1}
    };
    stack<char> s;
    int l=e.length();
    for(int i=0; i<l; ++i)
    {
        char ch=e[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
            ans+=ch;
        else if(ch=='(')
            s.push(ch);
        else if(ch==')')
        {
            while(s.top()!='(')
            {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if(s.empty())
                s.push(ch);
            else if(hash[s.top()]<hash[ch])
                s.push(ch);
            else
            {
                while(!s.empty() && (hash[s.top()]>=hash[ch]))
                {
                    ans+=s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
    }
    while(!s.empty())
    {
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string exp;
    cin>>exp;
    cout<<infixToPostfix(exp)<<endl;
}