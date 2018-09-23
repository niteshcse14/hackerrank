import java.io.*;
import java.util.*;
import java.math.*;
class HR
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long sum=0;
		while(n>1)
		{
			n=n/2;
			sum++;
		}
		BigInteger b=new BigInteger(String.valueOf(n)),b1=new BigInteger(String.valueOf(sum));
		System.out.println(b.bitCount());	
	}
}