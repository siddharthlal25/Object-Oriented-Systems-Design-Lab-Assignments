#include<bits/stdc++.h>

using namespace std;
  
vector< int > a,b,c;
  
  
  
void tower(int n, char from, char to, char via)
{
    //from   via        to
    //       //        //
    
    if(n == 1)
    {
        if(from == 'a') a.pop_back();
        if(from == 'b') b.pop_back();
        if(from == 'c') c.pop_back();
        
        if(to == 'a') a.push_back(1);
        if(to == 'b') b.push_back(1);
        if(to == 'c') c.push_back(1);
        cout<<"////////////////////////////////////////////////////////"<<endl;    
        cout<<"A: "; for(int i = 0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
        cout<<"B: "; for(int i = 0;i<b.size();i++) cout<<b[i]<<" "; cout<<endl;                
        cout<<"C: "; for(int i = 0;i<c.size();i++) cout<<c[i]<<" "; cout<<endl;
        return;
    }
    tower(n-1,from,via,to);
    if(from == 'a') a.pop_back();
    if(from == 'b') b.pop_back();
    if(from == 'c') c.pop_back();
        
    if(to == 'a') a.push_back(1);
    if(to == 'b') b.push_back(1);
    if(to == 'c') c.push_back(1);
    cout<<"////////////////////////////////////////////////////////"<<endl;
    cout<<"A: "; for(int i = 0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"B: "; for(int i = 0;i<b.size();i++) cout<<b[i]<<" "; cout<<endl;                
    cout<<"C: "; for(int i = 0;i<c.size();i++) cout<<c[i]<<" "; cout<<endl;        
    

    tower(n-1,via,to,from);


    /*cout<<"A: "; for(int i = 0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
    cout<<"B: "; for(int i = 0;i<b.size();i++) cout<<b[i]<<" "; cout<<endl;                
    cout<<"C: "; for(int i = 0;i<c.size();i++) cout<<c[i]<<" "; cout<<endl;        
    */            
        
}
           
    
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) a.push_back(1);
    
    tower(n,'a','c','b');
    
}




