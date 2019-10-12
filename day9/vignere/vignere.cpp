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

string encryption(string s,string key)
{
    string final_key;
    for(int i = 0;i<s.length();i++)
    {
        final_key.push_back(key[i%key.length()]);
    }
    string ans;
    for(int i = 0;i<s.length();i++)
    {
        int shift = final_key[i] - s[0];
        shift += 26;
        shift %= 26;
        ans.push_back((s[i] - 'A' + shift)%26 + 'A');
    }
    return ans;
}


int main()
{
    ifstream e;
    e.open("input.txt");
    string s;
    getline(e,s);
    e.close();
    // transform(s.begin(),s.end(), s.begin(), ::tolower);

    e.open("key.txt");
    string key;
    getline(e,key);
    e.close();
    
    string enc = encryption(s,key);
    
    ofstream a;
    a.open("encrypt.txt");
    a << enc << endl;
    a.close();
    
    
    a.close();
}
