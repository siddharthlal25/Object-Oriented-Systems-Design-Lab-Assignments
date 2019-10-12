#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    
    int siz_a = a.length();
    int siz_b = b.length();
    
    int dp[siz_a+1][siz_b+1];
    
    for(int i =0;i<=siz_a;i++) dp[i][0] = 0;
    for(int i =0;i<=siz_b;i++) dp[0][i] = 0;
    
    for(int i = 1;i<=siz_a;i++)
    {
        for(int j = 1;j<=siz_b;j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);       
        }
    }
    
    cout<<"length of LCS:"<<dp[siz_a][siz_b]<<endl;
    string result;
    for(int i = 1;i<=siz_a;i++)
    {
        for(int j = 1;j<=siz_b;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    int i = siz_a; int j = siz_b; 
    while (i > 0 && j > 0) 
    { 
       
       if (a[i-1] == b[j-1]) 
       { 
           result.push_back(a[i-1]); 
           i--;
           j--;      
       } 
    
       else if (dp[i-1][j] > dp[i][j-1]) 
          i--; 
       else
          j--; 
    } 
    
    reverse(result.begin(),result.end());
    
    for(i = 0;i<result.size();i++)
        cout<<result[i];
    cout<<endl; 
    
    
    return 0;
}
