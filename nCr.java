import java.io.*;
import java.util.*;
class nCr {
	static int t,n,cnt_o,cnt_z,sum;
	static int maxn = 1000010;
	static long inp[] = new long[maxn];
	static long mod = 1000000007;
	static long mul[] = new long[maxn];
	static long power (long a, long b) {
		long res = 1;
		while (b > 0) {
			if(b % 2 == 1)
				res = (res * a + mod) % mod;
			b = b >> 1;
			a = (a * 1L * a + mod) % mod;
		}
		return res % mod;
	}
	static void pre () {
		mul[1] = 1;
		for (int i = 2; i < maxn; ++i)
			mul[i] = (mul[i - 1] * i % mod + mod) % mod;
	}
	static long nCr(int n_, int r) {
		if (n_ - r >= 0)
	   		r = Math.min (r, n_ - r);
	   	if (r == 0)
	      return 1;
	    long a = mul[n_];
	    long b = mul[r];
	    long c = mul[n_ - r];
	    long d = power(b, mod - 2) % mod;
	    long e = power(c, mod - 2) % mod;
	    //System.out.println (a + " " + b + " " + c + " " + d + " " + e);
	    return (mul[n_] % mod * 1L * d % mod * 1L * e % mod) % mod;
	}
	public static void main(String args[]) {
		pre();
		Scanner ss = new Scanner (System.in);
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		t = ss.nextInt ();
		while(t>0) {
			t--;
			int a,b;
			a = ss.nextInt ();
			b = ss.nextInt ();
			System.out.println (nCr(a, b) % mod);
		}
	}
}