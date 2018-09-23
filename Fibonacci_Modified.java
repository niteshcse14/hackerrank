import java.io.*;
import java.util.*;
import java.math.*;
public class Fibonacci_Modified 
{
    static int bn = 0;
    static BigInteger result = BigInteger.valueOf(0);
    static BigInteger bt1;
    static BigInteger bt2;
    static BigInteger modifiedFib(BigInteger t1, BigInteger t2) 
    {
        return t1.add(t2.multiply(t2));
    }
    static void calculation(BigInteger t1, BigInteger t2) 
    {
        bn--;
        if (bn == 0) {
            result = t1;
        }
         else 
        {
            calculation(t2, modifiedFib(t1, t2));
        }
    }
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        String[] numbersString = s.split(" ");
        int t1 = Integer.parseInt(numbersString[0]);
        int t2 = Integer.parseInt(numbersString[1]);
        int n = Integer.parseInt(numbersString[2]);
        bt1 = BigInteger.valueOf(t1);
        bt2 = BigInteger.valueOf(t2);
        bn = n;
        if (0 <= t1 && 0 <= t2 && t1 <= 2 && t2 <= 2)
        {
            if (3 <= n || n <= 20) 
            {
                calculation(bt1, bt2);
            }
        }
        System.out.println(result);
    }
}
//Fibonacci_Modified.java