import java.util.*;

public class program1c
{

    public static boolean palindrome(String s)
    {
        int flag = 0, n = s.length();
        for(int i = 0; i <= n/2 ;i++)
        {
            if(s.charAt(i) != s.charAt(n-1-i))
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            return false;
        return true;
    }    
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        
        if(palindrome(input))
            System.out.println("Yes");
        else
            System.out.println("No");
    }            
}
