#include<bits/stdc++.h>

using namespace std;

void printBoard(vector< vector < int > > a)
{
    for(int i = 1;i<=3;i++)
    {
        for(int j = 1;j<= 3;j++)
        {
            if(a[i][j] == 1)
                cout<<"x|";
            else if(a[i][j] == 2)
                cout<<"o|";
            else cout<<"_|";
        }
        cout<<endl;
    }
}

bool boardEmpty(vector< vector < int > > grid)
{
    for(int i = 1;i<=3;i++)
        for(int j = 1;j<=3;j++)
            if(grid[i][j] == 0) return true;

    return false;
}
// player 1 goes for x and player 2 goes for o

int win(vector< vector < int > > a)
{
    // row wise check kar lo for 1 and 2
    if(a[1][1] == 1 && a[1][2] == 1 && a[1][3] == 1) return 1;
    if(a[2][1] == 1 && a[2][2] == 1 && a[2][3] == 1) return 1;
    if(a[3][1] == 1 && a[3][2] == 1 && a[3][3] == 1) return 1;
    
    if(a[1][1] == 2 && a[1][2] == 2 && a[1][3] == 2) return 2;
    if(a[2][1] == 2 && a[2][2] == 2 && a[2][3] == 2) return 2;
    if(a[3][1] == 2 && a[3][2] == 2 && a[3][3] == 2) return 2;
    
    // check column wise for 1 or 2
    if(a[1][1] == 1 && a[2][1] == 1 && a[3][1] == 1) return 1;
    if(a[1][2] == 1 && a[2][2] == 1 && a[3][2] == 1) return 1;
    if(a[1][3] == 1 && a[2][3] == 1 && a[3][3] == 1) return 1;
    
    if(a[1][1] == 2 && a[2][1] == 2 && a[3][1] == 2) return 2;
    if(a[1][2] == 2 && a[2][2] == 2 && a[3][2] == 2) return 2;
    if(a[1][3] == 2 && a[2][3] == 2 && a[3][3] == 2) return 2;
    
    // check diagonals for 1 and 2
    if(a[1][1] == 1 && a[2][2] == 1 && a[3][3] == 1) return 1;
    if(a[1][3] == 1 && a[2][2] == 1 && a[3][1] == 1) return 1;
    
    if(a[1][1] == 2 && a[2][2] == 2 && a[3][3] == 2) return 2;
    if(a[1][3] == 2 && a[2][2] == 2 && a[3][1] == 2) return 2;
    
    // 0 signifies there is no winner uptil now
    return 0;
}

bool row(int r,vector< vector < int > > a, int type)
{
    if(a[r][1] + a[r][2] + a[r][3] == 2*type)
        if((a[r][1] == type || a[r][1] == 0) && (a[r][2] == type || a[r][2] == 0) && (a[r][3] == type || a[r][3] == 0)) return true;
    return false;
}

bool col(int c,vector< vector < int > > a, int type)
{
    if(a[1][c] + a[2][c] + a[3][c] == 2*type)
        if((a[1][c] == type || a[1][c] == 0) && (a[2][c] == type || a[2][c] == 0) && (a[3][c] == type || a[3][c] == 0)) return true;
    return false;
}

bool d1(vector< vector < int > > a, int type)
{
    if(a[1][1] + a[2][2] + a[3][3] == 2*type)
        if((a[1][1] == type || a[1][1] == 0) && (a[2][2] == type || a[2][2] == 0) && (a[3][3] == type || a[3][3] == 0)) return true;
    return false;
}

bool d2(vector< vector < int > > a, int type)
{
    if(a[3][1] + a[2][2] + a[1][3] == 2*type)
        if((a[3][1] == type || a[3][1] == 0) && (a[2][2] == type || a[2][2] == 0) && (a[1][3] == type || a[1][3] == 0)) return true;
    return false;
}
    
void intelligent_move(vector< vector < int > > & a,int x)
{
    // sabse pehle kaato
    // fir center
    // nahi toh corner
    // nahi toh jahan khali ho
    
    // row me kaato 
    for(int i = 1;i<=3;i++)
    {
        if(x == 1)
        {
            if(row(i,a,2))
            {
                for(int j = 1;j<=3;j++)
                    if(a[i][j] == 0) a[i][j] = 1;
                return;    
            }    
        }
        else if(x == 2)
        {
            if(row(i,a,1))
            {
                for(int j = 1;j<=3;j++)
                    if(a[i][j] == 0) a[i][j] = 2;
                return;    
            }    
        }
    }
    
    // col me kaato
    for(int i = 1;i<=3;i++)
    {
        if(x == 1)
        {
            if(col(i,a,2))
            {
                for(int j = 1;j<=3;j++)
                    if(a[j][i] == 0) a[j][i] = 1;
                return;    
            }    
        }
        else if(x == 2)
        {
            if(col(i,a,1))
            {
                for(int j = 1;j<=3;j++)
                    if(a[j][i] == 0) a[j][i] = 2;
                return;    
            }    
        }
    }
    
    //d1 me kaato
    if(x == 1)
    {
        if(d1(a,2))
        {
            if(a[1][1] == 0) a[1][1] = 1;
            else if(a[2][2] == 0) a[2][2] = 1;
            else a[3][3] = 1;
            return;
        }
    }
    else if(x == 2)
    {
        if(d1(a,1))
        {
            if(a[1][1] == 0) a[1][1] = 2;
            else if(a[2][2] == 0) a[2][2] = 2;
            else a[3][3] = 2;
            return;
        }
    }
    
    //d2 me kaato
    if(x == 1)
    {
        if(d2(a,2))
        {
            if(a[3][1] == 0) a[3][1] = 1;
            else if(a[2][2] == 0) a[2][2] = 1;
            else a[1][3] = 1;
            return;
        }
    }
    else if(x == 2)
    {
        if(d2(a,1))
        {
            if(a[1][3] == 0) a[1][3] = 2;
            else if(a[2][2] == 0) a[2][2] = 2;
            else a[3][1] = 2;
            return;
        }
    }
    
    // center me kaato
    if(a[2][2] == 0)
    {
        a[2][2] = x;
        return;
    }
    // corners
    if(a[1][1] == 0)
    {
        a[1][1] = x;
        return;
    }
    if(a[3][1] == 0)
    {
        a[3][1] = x;
        return;
    }
    if(a[1][3] == 0)
    {
        a[1][3] = x;
        return;
    }
    if(a[3][3] == 0)
    {
        a[3][3] = x;
        return;
    }
    
    // random jahan pehle khali
    for(int i = 1;i<=3;i++)
    {
        for(int j = 1;j<=3;j++)
        {   
            if(a[i][j] == 0)
            {
                a[i][j] = x;
                return;
            }
        }
    }
}

void game()
{
    vector< vector < int > > grid(4,vector< int > (4,0));
    
    int player = 0; int w = 0; int cnt = 0;
    int x,y;
    cout<<"You want to be player 1/2 ?:";
    cin>>player;
    while(boardEmpty(grid))
    {
        printBoard(grid);
        if(cnt%2 == 0)
        {
            cout<<"##########################"<<endl;
            cout<<"Player 1 move:"<<endl;
            if(player == 1)
            {
                cin>>x>>y;
                if(grid[x][y] != 0)
                {
                    cout<<"Invalid Move!!"<<endl;
                    continue;
                }
                else grid[x][y] = 1;
            }
            else
                intelligent_move(grid,1);
        }
        else
        {
            cout<<"##########################"<<endl;
            cout<<"Player 2 move:"<<endl;
            if(player == 2)
            {
                cin>>x>>y;
                if(grid[x][y] != 0)
                {
                    cout<<"Invalid Move!!"<<endl;
                    continue;
                }
                else grid[x][y] = 2;
            }
            else
                intelligent_move(grid,2);
        }
        cnt++;
        w = win(grid);
        if(w == 1 || w == 2) break;
    }
    cout<<"##########################"<<endl;
    printBoard(grid);
    if(w == 0) cout<<"Game is draw"<<endl;
    else if(w == 1) cout<<"Player 1 wins!!"<<endl;
    else if(w == 2) cout<<"Player 2 wins!!"<<endl;
}   

int main()
{
    game();
    return 0;
}
