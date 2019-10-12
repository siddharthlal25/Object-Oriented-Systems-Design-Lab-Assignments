#include<bits/stdc++.h>

using namespace std;

void solve()
{
    string text,pat;
    ifstream myfile;
    myfile.open("input.txt");
    getline(myfile,text);
    getline(myfile,pat);
    myfile.close();
    
    
    
    int c = 0; int counter = 0; int j;
    for(int i = 0;i<text.length();i++)
    {
        counter++;
        if(text[i] == pat[0])
        {
            // cout<<i<<endl;
            int flag = 0;
            for(j = 0;j<pat.length();j++)
            {
                counter++;
                if(i+j < text.length() && text[i+j] != pat[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) c++;
            i += j - 1;      
        }
    }
    
    ofstream o;
    o.open("output.txt"); 
    o <<"Match:"<<c<<endl;
    o <<"Counter:"<<counter<<endl;
    o.close();
}

int main()
{
    solve();
    return 0;
}
