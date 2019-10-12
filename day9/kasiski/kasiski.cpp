#include <bits/stdc++.h>

using namespace std;

map< int , int > global_freq_of_factors;
vector< int > distances_to_be_factored;

void factor(int n)
{
    global_freq_of_factors[n]++;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        {  
            if (n/i == i) global_freq_of_factors[i]++; 
                
  
            else
            {
                global_freq_of_factors[n/i]++;
                global_freq_of_factors[i]++;
            }
        } 
    } 
} 


void final_processing()
{
    for(int i = 0;i<distances_to_be_factored.size();i++)
    {
        factor(distances_to_be_factored[i]);
    }
}


void getDist(string a)
{
    string ai;
    map< string, int > m;
    ai.push_back('0');
    for(int i = 0;i<a.length();i++) ai.push_back(a[i]);
    
    for(int i = 1;i<=a.length();i++)
    {
        string temp1;
        // tackling single digit 
        temp1 += ai[i];
        if(m[temp1] == 0)
            m[temp1] = i;
        else
        {
            distances_to_be_factored.push_back(i - 1 - m[temp1]);
        }
        
        
        // tackling double digit
        string temp2;
        if(i + 1 <= a.length())
        temp2 += ai[i]; temp2 += ai[i+1];
        if(m[temp2] == 0)
            m[temp2] = i;
        else
        {
            distances_to_be_factored.push_back(i - 1 - m[temp2]);
        }
        
        
        
        // tackling three digit
        string temp3;
        if(i + 2 <= a.length())
        temp3 += ai[i]; temp3 += ai[i+1]; temp3 += ai[i+2];
        if(m[temp3] == 0)
            m[temp3] = i;
        else
        {
            distances_to_be_factored.push_back(i - 1 - m[temp3]);
        }
    }   
    // map< string,int> :: iterator it;
    // for(it = m.begin();it!=m.end();it++) cout<<it->first<<endl; 
    final_processing();    
}

int find_max()
{
    global_freq_of_factors[1] = 0;
    int m = INT_MIN;
    int ans;
    map< int,int > :: iterator it;
    for(it = global_freq_of_factors.begin();it!=global_freq_of_factors.end();it++)
    {
        // cout<<it->second<<endl;
        if(m < it->second)
        {
            
            m = it->second;
            ans = it->first;
        }
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
    
    getDist(encrypted_text);
    int ans = find_max();
    
     cout<<ans<<endl;
    
    
    return 0;
}
    
    
    
