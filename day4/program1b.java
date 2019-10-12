import java.util.*;

public class program1b
{
    public static int fact(int x)
    {
        int ans = 1;
        for(int i = 1;i<=x;i++)
            ans = ans*i;
        
        return ans;
    }
    
    public static double fun(double x)
    {
        double ans = 1,val = x;
        int i;
        for(i = 1;i<10;i++)
        {
            ans += Math.pow(x,i)/fact(i);
        }
        return ans;
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        
        double ans = fun(x);
        
        System.out.println(ans);
    }    
}
