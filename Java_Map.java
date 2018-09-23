import java.io.*;
import java.util.*;
class Java_Map {
	public static void main (String []args) throws Exception {
		HashMap<String, Integer> mp = new HashMap <> ();
		String str;
		int val;
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
		Scanner in = new Scanner (System.in);
		int n = Integer.parseInt (br.readLine ());
		for (int i = 0; i < n; ++i) {
			str = br.readLine ();
			val = Integer.parseInt(br.readLine ());
			mp.put (str,val);
		}
		while (!(str = br.readLine ().trim ()).isEmpty ()) {
			if (mp.containsKey (str))
                System.out.println (str + "=" + mp.get (str));
			else
                System.out.println ("Not found");
		}
	}
}