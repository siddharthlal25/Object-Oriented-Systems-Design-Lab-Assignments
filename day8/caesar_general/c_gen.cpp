#include<bits/stdc++.h>

using namespace std;

map< char, char > m;

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

void init()
{
    for(char a = 'a'; a<= 'z' ; a++) m[a] = a;
    
    ifstream file;
    file.open("key.txt");
    string str;
    while(!file.eof())
    {
        getline(file,str);
        m[str[0]] = str[2];
    }
}

string encryption(string s)
{
    // cout<<s<<endl;
    s = remove_space(s);
    string encrypt;
    for(int i = 0;i<s.length();i++)
        encrypt.push_back(m[s[i]]);
    
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
    
    init();
    
    ofstream fil;
    fil.open("encrypt.txt");
    fil << encryption(s) <<endl;
    fil.close();    
    // encryption(s);
    return 0;
}
    
