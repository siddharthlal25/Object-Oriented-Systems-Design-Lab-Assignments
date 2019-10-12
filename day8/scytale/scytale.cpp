#include<bits/stdc++.h>

using namespace std;

string decryption(string s,int d)
{
    string decrypt;
    for(int i = 0;i<d;i++)
    {
        for(int j = i;j<s.length();j+=d)
        {
            decrypt.push_back(s[j]);
        }
    }
    return decrypt;
}

string remove_space(string s)
{
    string ans;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == ' ') continue;
        ans.push_back(s[i]);
    }
    
    return ans;
}

string encryption(string s, int d)
{
    
    string encrypt;
    s = remove_space(s);
    for(int i = 0;i<s.length()/d;i++)
    {
        for(int j = i;j<s.length(); j+= s.length()/d)
        {
            encrypt.push_back(s[j]);
        }  
    }
    return encrypt;
}

int main()
{
    ifstream e;
    e.open("input.txt");
    string s;
    getline(e,s);
    e.close();
    transform(s.begin(),s.end(), s.begin(), ::tolower);
    // cout<<s<<endl;
    
    int d;
    cin>>d;
    string enc = encryption(s,d);
    
    
    ofstream a;
    a.open("encrypt.txt");
    a << enc;
    a.close();
    
    ofstream b;
    b.open("decrypt.txt");
    for(int i = 1;i<=s.length();i++)
    {
        b<<"d:"<<i<<"    ";
        b << decryption(enc,i)<<endl;
    }       
}
