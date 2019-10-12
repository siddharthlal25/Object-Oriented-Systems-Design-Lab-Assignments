#include<bits/stdc++.h>

using namespace std;

void longest(vector< int > a)
{
    int counter = 0;
    vector< int > dp(a.size(),1);
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<i;j++)
        {
            counter++;
            if(a[j] < a[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int m = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(m < dp[i]) m = dp[i];
        counter++;
    }    

    int len = m; int idx;
    for(int i = 0;i<a.size();i++)
    {
        counter++;
        if(dp[i] == len)
        {
            idx = i-1;
            break;
        }    
    }
    len--;
    vector< int > result;
    result.push_back(a[idx+1]);
    
    while(len > 0 && idx >= 0)
    {
        counter++;
        if(a[idx] < result[result.size()-1] && dp[idx] == len)
        {
            result.push_back(a[idx]);
            len--;
        }
        idx--;
    }
    reverse(result.begin(),result.end());
    ofstream ofile;
    ofile.open("output.txt");
    ofile <<"Counter:"<<counter<<endl;
    ofile <<"Length:"<<m<<endl;
    for(int i = 0;i<result.size();i++) ofile <<result[i]<<" "; ofile<<endl;
    ofile.close();
}

int main()
{
    int n,type;
    cin>>n;
    cout<<"1.input from input.txt"<<endl;
    cout<<"2.Generate random numbers"<<endl;
    cin>>type;
    
    if(type == 1)
    {
          ifstream e;
          e.open("input.txt");
          vector< int > a(n);
          for(int i = 0 ;i<n;i++) e >> a[i];
          e.close();
          longest(a);       
    }
    else
    {
        ofstream o;
        o.open("input.txt");
        vector< int > a(n);
        for(int i = 0 ;i<n;i++) a[i] = rand()%200;
        for(int i = 0;i<n;i++) o << a[i] << " ";
        o.close();
        longest(a);              
    }
    
    return 0;
}
