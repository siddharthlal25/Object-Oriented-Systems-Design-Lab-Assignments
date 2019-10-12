#include<bits/stdc++.h>

using namespace std;

int main()
{
    int val,i,n,w,j,x,y;
    cin>>n>>w;
    
    vector< pair < int,int > > a; // value and weight of ith element
    
    a.push_back(make_pair(0,0));
    
    for(i = 1;i<=n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    
    int dp[n+1][w+1];
    for(i = 0;i<=n;i++) dp[i][0] = 0;
    for(i = 0;i<=w;i++) dp[0][i] = 0;
    
    for(int i = 1;i<=n;i++)
    {
        for(j = 1;j<=w;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(a[i].second <= j)
                dp[i][j] = max(dp[i][j], a[i].first + dp[i-1][j - a[i].second]);       
        }
    }
        
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=w;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    i = n; j = w; val = dp[n][w];
    cout<<"Objects:";
    while(i > 0 && j > 0 && val > 0)
    {
        if(dp[i-1][j] == dp[i][j]) i--;
        else
        {
            //cout<<"a[i-1].first:"<<a[i].first<<endl;
            //cout<<"a[i-1].second:"<<a[i].second<<endl;
            val -= a[i].first;
            j -= a[i].second;
            cout<<i<<" ";
            i--;
        }    
    }
    cout<<endl;
    cout<<"Maxm_Value:"<<dp[n][w]<<endl;
}
