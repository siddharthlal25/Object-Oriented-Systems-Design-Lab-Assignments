#include <bits/stdc++.h>

using namespace std;

bool isNotFull(vector< vector < int > > a)
{
    int cnt = 0;
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<a[0].size();j++)
        {
            if(a[i][j] == 1 || a[i][j] == 2) cnt++;       
        }
    }   
    if(cnt == a.size() * a[0].size()) return false;
    return true; 
}

void printPlayerName(int x)
{
    cout<<"|||||||||||||||||||||||||"<<endl;
    cout<<"Player "<<x<<" move:"<<endl;
}

bool possibleMove(int col, vector< vector < int > > grid)
{
    if(col < 0 || col >= grid[0].size()) return false;   
    for(int i = 0;i<grid.size();i++)
    {
        if(grid[i][col] == 0) return true;    
    }    
    return false;
}
// player 1 is x and player 2 is o
void printGrid(vector< vector < int > > a)
{
    for(int i = 0;i<a.size();i++)
    {
        cout<<"|";
        for(int j = 0;j<a[0].size();j++)
        {
            if(a[i][j] == 1) cout<<"x|";
            else if(a[i][j] == 2) cout<<"o|";
            else cout<<"_|";
        }
        cout<<endl;
    }    
}

bool possh(int y,vector< vector < int > > a)
{
    if(y < a[0].size() && y >= 0) return true;
    return false;
}

bool hwin(int x,int y,vector< vector < int > > a)
{
    int comp = a[x][y];
    if(possh(y+1,a) && possh(y+2,a) && possh(y+3,a))
        if(a[x][y+1] == comp && a[x][y+2] == comp && a[x][y+3] == comp) return true;
    
    if(possh(y+1,a) && possh(y+2,a) && possh(y-1,a))
        if(a[x][y+1] == comp && a[x][y+2] == comp && a[x][y-1] == comp) return true;
    
    if(possh(y+1,a) && possh(y-2,a) && possh(y-1,a))
        if(a[x][y+1] == comp && a[x][y-2] == comp && a[x][y-1] == comp) return true;
    
    if(possh(y-1,a) && possh(y-2,a) && possh(y-3,a))
        if(a[x][y-1] == comp && a[x][y-2] == comp && a[x][y-3] == comp) return true;
    
    return false;
}

bool possv(int x,vector< vector < int > > a)
{
    if(x < a.size() && x >= 0) return true;
    return false;
}

bool vwin(int x,int y,vector< vector < int > > a)
{
    int comp = a[x][y];
    if(possv(x+1,a) && possv(x+2,a) && possv(x+3,a))
        if(a[x+1][y] == comp && a[x+2][y] == comp && a[x+3][y] == comp) return true;
    return false;
} 

bool posst(int x,int y, vector< vector < int > > a)
{
    if(possv(x,a) && possh(y,a)) return true;
    return false;
}

bool dlrwin(int x,int y,vector< vector < int > >& a)
{
    int comp = a[x][y];
    if(posst(x-1,y+1,a) && posst(x-2,y+2,a) && posst(x-3,y+3,a))
        if(a[x-1][y+1] == comp && a[x-2][y+2] == comp && a[x-3][y+3] == comp) return true;
    if(posst(x-1,y+1,a) && posst(x-2,y+2,a) && posst(x+1,y-1,a))
        if(a[x-1][y+1] == comp && a[x+1][y-1] == comp && a[x-2][y+2] == comp) return true;
    if(posst(x-1,y+1,a) && posst(x+2,y-2,a) && posst(x+1,y-1,a))
        if(a[x-1][y+1] == comp && a[x+1][y-1] == comp && a[x+2][y-2] == comp) return true;
    if(posst(x+1,y-1,a) && posst(x+2,y-2,a) && posst(x+3,y-3,a))
        if(a[x+1][y-1] == comp && a[x+3][y-3] == comp && a[x+2][y-2] == comp) return true;
    
    return false;     
} 

bool drlwin(int x,int y,vector< vector < int > >& a)
{
    int comp = a[x][y];
    if(posst(x+1,y+1,a) && posst(x+2,y+2,a) && posst(x+3,y+3,a))
        if(a[x+1][y+1] == comp && a[x+2][y+2] == comp && a[x+3][y+3] == comp) return true;
    if(posst(x+1,y+1,a) && posst(x+2,y+2,a) && posst(x-1,y-1,a))
        if(a[x+1][y+1] == comp && a[x-1][y-1] == comp && a[x+2][y+2] == comp) return true;
    if(posst(x+1,y+1,a) && posst(x-2,y-2,a) && posst(x-1,y-1,a))
        if(a[x+1][y+1] == comp && a[x-1][y-1] == comp && a[x-2][y-2] == comp) return true;
    if(posst(x-1,y-1,a) && posst(x-2,y-2,a) && posst(x-3,y-3,a))
        if(a[x-1][y-1] == comp && a[x-3][y-3] == comp && a[x-2][y-2] == comp) return true;
    
    return false;
}


bool placePiece(vector< vector < int > >& a, int col, int type)
{
    int i;
    for(i = a.size() - 1;i>=0;i--)
    {
        // cout<<a[i][col]<<" "<<endl;
        if(a[i][col] == 0)
        {
            a[i][col] = type;
            break;
        }
    }
    bool horizontal_win = hwin(i,col,a);
    bool vertical_win = vwin(i,col,a);
    bool diagonal_win_lr = dlrwin(i,col,a);
    bool diagonal_win_rl = drlwin(i,col,a);
    
    if(horizontal_win == true || vertical_win == true || diagonal_win_lr == true || diagonal_win_rl == true) return true;
    return false;
}

void game()
{
    int player = 0; int col;
    vector< vector < int > > grid(6,vector< int > (7,0));
    bool win1 = false; bool win2 = false;
    cin>>player;
    while(isNotFull(grid))
    {
        printGrid(grid);
        if(player%2 == 0)
        {
            // printPlayerName(1);
            cout<<"move"<<endl;
            /*cin>>col;
            if(possibleMove(col-1,grid) == false) 
            {
                cout<<"Error move!"<<endl;
                continue;
            }
            // now the move is correct
            // place 1 in col-1
            win1 = placePiece(grid,col-1,1);*/
            
            // smart move
            //0-5 row hai and 0-6 col
            
            int cnt = 0; col = rand()%7;
            int f,f1; f1 = 0;
            for(int i = 0;i<7;i++)
            {
                
                int sum = 0;
                f = 0;
                for(int j = 5;j>=0;j--)
                {
                    if(grid[j][i] == 0) f = 1;
                    if(grid[j][i] == 1) sum++;
                }    
                if(sum > cnt && f == 1)
                {
                    f1 = 1;
                    cnt = sum;
                    col = i;
                }
            }
            // cout<<"here"<<endl;
            
            if(f1 == 1) win1 = placePiece(grid,col,1);
            // cout<<"hi"<<endl;
            else
            {
                for(int i = 0;i<7;i++)
                {
                    if(possibleMove(i,grid))
                    {
                        win1 = placePiece(grid,i,1);
                        //f1 = 1;
                        break;
                    }
                }    
            }
            if(win1 == true) break;        
        }
        else
        {
            // printPlayerName(2);
            cout<<"move"<<endl;
            cin>>col;
            if(possibleMove(col-1,grid) == false) 
            {
                cout<<"Error move!"<<endl;
                continue;
            }
            // now the move is correct
            // place 2 in col-1
            win2 = placePiece(grid,col-1,2);
            if(win2 == true) break;           
        }
        player++;    
    }
    printGrid(grid);   
    if(win1 == true || win2 == true)
    {
        if(win1 == true) cout<<"Player 1 winner!!"<<endl;
        else cout<<"Player 2 winner!!"<<endl;
    }
    else cout<<"Nobody wins!!"<<endl;    
}


int main()
{
    game();
    return 0;
}
