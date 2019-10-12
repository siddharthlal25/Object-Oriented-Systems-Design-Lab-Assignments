#include <bits/stdc++.h>

using namespace std;

bool sb(const pair< char,int> &a, const pair< char,int> &b)
{
    return a.second > b.second;
}

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

string getFreqChar(string a)
{
    a = remove_space(a);
    vector< pair < char, int > > freq(26);
    for(int i = 0;i<26;i++)
    {
        freq[i].first = 'a' + i;
        freq[i].second = 0;
    }
    
    for(int i = 0;i<a.length();i++)
    {
        ++freq[a[i] - 'a'].second;
    }
    sort(freq.begin(),freq.end(),sb);
    string ans;
    for(int i = 0;i<26;i++)
    {
        ans.push_back(freq[i].first);
        ans.push_back(' ');    
    }   
    return ans;
}

string getRepeats(string a)
{
    a = remove_space(a);
    vector< pair < char, int > > freq(26);
    for(int i = 0;i<26;i++)
    {
        freq[i].first = 'a' + i;
        freq[i].second = 0;
    }
    for(int i = 0;i<a.length();i++)
    {
        if(i+1<a.length() && a[i] == a[i+1])
        ++freq[a[i] - 'a'].second;
    }
    
    sort(freq.begin(),freq.end(),sb);
    string ans;
    for(int i = 0 ; i < 5;i++)
    {
        if(freq[i].second == 0) break;
        ans.push_back(freq[i].first);
        ans.push_back(freq[i].first);
        ans.push_back(' ');
    }
    return ans;
}

int main()
{
    ifstream e;
    e.open("input.txt");
    string encrypted_text;
    getline(e,encrypted_text);
    e.close();
    transform(encrypted_text.begin(),encrypted_text.end(), encrypted_text.begin(), ::tolower);
    
    e.open("sample.txt");
    string normal_text;
    getline(e,normal_text);
    e.close();
    transform(normal_text.begin(),normal_text.end(), normal_text.begin(), ::tolower);
    
    ofstream f;
    f.open("output.txt");
    f << "Sample:"<<endl;
    f << "Single_letter:"<<getFreqChar(normal_text)<<endl;
    f << "Repeats:" <<getRepeats(normal_text)<<endl;
    
    f << "Encrypted:"<<endl;
    f << "Single_letter:"<<getFreqChar(encrypted_text)<<endl;
    f << "Repeats:" <<getRepeats(encrypted_text)<<endl;
    f.close();
    
    return 0;
}
    
    
    
