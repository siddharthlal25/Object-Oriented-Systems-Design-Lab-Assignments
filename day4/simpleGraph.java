import java.util.*;

public class simpleGraph
{
    public static void getInput(int[][] adj, int n)
    {
        Scanner sc = new Scanner(System.in);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                adj[i][j] = sc.nextInt();
            }
        }        
    }   
    
    public static boolean isSimpleGraph(int[][] adj, int n)
    {
        int f = 0;
        for(int i = 0;i<n;i++)
            if(adj[i][i] != 0)
                f = 1;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(adj[i][j] != adj[j][i] || !(adj[i][j] == 0 || adj[i][j] == 1))
                    f = 1;
            }
        }
        
        if(f == 1) return false;
        return true;
    }
            
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int[][] adj = new int[n][n];
        
        getInput(adj,n);   
        
        if(isSimpleGraph(adj,n))
            System.out.println("Simple Graph");
        else
            System.out.println("Not a Simple Graph");                                  
        
    }    
}
