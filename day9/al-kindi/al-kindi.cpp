#include <bits/stdc++.h>

using namespace std;

bool sb(const pair< char,int> &a, const pair< char,int> &b)
{
    return a.second > b.second;
}

int min(int a, int b)
{
    if(a < b) return a;
    return b;
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

string getBigrams(string a)
{
    a = remove_space(a);
    vector< vector < int > > count(27,vector< int >(27,0));
    
    for(int i = 0;i<a.size();i++)
    {
        if(i+1 < a.size())
        {
            ++count[a[i] - 'a' + 1][a[i+1] - 'a' + 1];
        }
    }
    
    vector< pair < int , pair < int , int  > > > final_count;
    for(int i = 1;i<=26;i++)
    {
        for(int j = 1;j<=26;j++)
        {
            if(count[i][j] != 0)
            {
                final_count.push_back(make_pair(count[i][j],make_pair(i,j)));
            }       
        }
    }
    sort(final_count.begin(),final_count.end());
    string ans;
    for(int i = 0;i<min(5,final_count.size());i++)
    {
        ans.push_back(final_count[i].second.first + 'a' - 1);
        ans.push_back(final_count[i].second.second + 'a' - 1);
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
    f << "Bigrams:" <<getBigrams(normal_text)<<endl;
    
    f << "Encrypted:"<<endl;
    f << "Single_letter:"<<getFreqChar(encrypted_text)<<endl;
    f << "Repeats:" <<getRepeats(encrypted_text)<<endl;
    f << "Bigrams:" <<getBigrams(encrypted_text)<<endl;
    f.close();
    
    //f.open("decrypt.txt");
    //f << partial_decrypt(getFreqChar(normal_text),getFreqChar(encrypted_text),encrypted_text) << endl;
    //f.close();
    
    return 0;
}
    
    
    
