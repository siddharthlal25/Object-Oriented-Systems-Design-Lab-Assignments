#include<bits/stdc++.h>

using namespace std;

void longest(vector< int > a)
{
    int counter = 0;
    vector< int > dp(a.size(),1);
    vector< int > c(a.size() + 1,INT_MAX);
    c[1] = a[0];
    int len = 1;
    for(int i = 1;i<a.size();i++)
    {
        //Here there was O(n^2) algo
        //Now lets improve it
        /*for(int j = 0;j<i;j++)
        {
            counter++;
            if(a[j] < a[i])
                dp[i] = max(dp[i],dp[j]+1);
        }*/
        counter++;
        if(a[i] < c[1])
        {
            dp[i] = 1;
            c[1] = a[i];
        }
        else if(a[i] > c[len])
        {
            c[len+1] = a[i];
            len++;
            dp[i] = len;
        }
        else
        {
            // search greatest value c[k] smaller than a[i] between 1 and len using binary search inclusive ends
            int k;
            int left = 1; int right = len; int mid;
            while(left <= right)
            {
                counter++;    
                mid = left + (right - left)/2;
                if(c[mid] < a[i])
                {
                    left = mid + 1;
                    k = mid;
                }
                else
                {
                    right = mid - 1;   
                }
            }
            c[k + 1] = a[i];
            dp[i] = k + 1;
        }
    }
    int m = 0;
    
    for(int i = 0;i<a.size();i++)
    {
        if(m < dp[i]) m = dp[i];
        counter++;
    }    

    int idx;
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
