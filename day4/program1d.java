import java.util.*;

public class program1d
{
    
    public static void prime(boolean[] isPrime, int n)
    {
        for(int i = 2;i<=n;i++)
            if(isPrime[i] == true)
                for(int j = 2*i;j<=n; j += i)
                    isPrime[j] = false;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        boolean[] isPrime = new boolean[n+1];
        
        for(int i = 2;i<=n;i++)
            isPrime[i] = true;
         
        prime(isPrime,n);
        int count = 0;
        for(int i = 2;i<=n;i++)
            if(isPrime[i] == true)
                count++;
                
        System.out.println("Number of Primes:" + count);
    }
}
