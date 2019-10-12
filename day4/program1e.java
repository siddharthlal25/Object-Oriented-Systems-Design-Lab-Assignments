import java.util.*;

public class program1e
{
    public static int gcd(int a, int b)
    {
        if(a > b) 
            gcd(b,a);
        if(a == 0)
            return b;
        return gcd(b%a,a);
    }
    
    public static int coprime(int n)
    {
        int counter = 0;
        for(int i = 1;i<n;i++)
            if(gcd(i,n) == 1)
                counter++;
        return counter;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int counter = coprime(n);
        System.out.println("Number of coprimes:"+counter);    
    }    
}
