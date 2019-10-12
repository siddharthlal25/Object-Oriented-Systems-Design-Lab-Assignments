#include<bits/stdc++.h>

using namespace std;

string remove_space(string s)
{
    string ans;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == ' ' || s[i] == '!' || s[i] == ',' || s[i] == '.') continue;
        ans.push_back(s[i]);
    }
    
    return ans;
}

string encryption(string s,int d)
{
    s = remove_space(s);
    string encrypt;
    for(int i = 0;i<s.size();i++)
        encrypt.push_back('a' + (s[i] + d - 'a')%26);
        
    return encrypt;     
}

string decryption(string s, int d)
{
    string decrypt;
    for(int i = 0;i<s.size();i++)
        decrypt.push_back('a' + ((s[i] - d - 'a')%26 + 26)%26);
    
    return decrypt;
}
int main()
{
    ifstream e;
    e.open("input.txt");
    string s;
    getline(e,s);
    e.close();
    transform(s.begin(),s.end(), s.begin(), ::tolower);

    int d;
    cin>>d;
    
    string enc = encryption(s,d);
    
    ofstream a;
    a.open("encrypt.txt");
    a << enc;
    a.close();
    
    a.open("decrypt.txt");
    for(int i = 0;i<=25;i++)
    {
        a<<"s:"<<i<<"      ";
        a<<decryption(enc,i)<<endl;
    }
    a.close();
}
