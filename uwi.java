import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
class uwi {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	void solve() {
		for(int T = ni();T > 0;T--){
			int n = ni(), m = ni();
			int[][] f = new int[n][];
			for(int i = 0;i < n;i++){
				f[i] = na(m);
				for(int j = 0;j < m;j++){
					f[i][j]--;
				}
			}
			if(n <= 1800){
				long[][] rets = new long[n][n];
				for(int i = 0;i < n;i++){
					int[] lf = new int[m];
					for(int j = 0;j < m;j++){
						lf[j] = j;
					}
					for(int j = i;j < n;j++){
						lf = apply(f[j], lf);
						long s = 0;
						for(int k = 0;k < m;k++){
							s += (long)(k+1)*(lf[k]+1);
						}
						rets[i][j] = s;
					}
				}
				for(int Q = ni();Q > 0;Q--){
					int x = ni()-1, y = ni()-1;
					out.println(rets[x][y]);
				}
			}else{
				SegmentTreeArray st = new SegmentTreeArray(f, m);
				for(int Q = ni();Q > 0;Q--){
					int x = ni()-1, y = ni()-1;
					int[] lf = st.get(x, y+1);
					long s = 0;
					for(int k = 0;k < m;k++){
						s += (long)(k+1)*(lf[k]+1);
					}
					out.println(s);
				}
			}
		}
	}
	
	public static class SegmentTreeArray {
		public int M, H, N;
		public int[][] node;
		public int K;
		
		public SegmentTreeArray(int[][] a, int K)
		{
			this.K = K;
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][];
			for(int i = 0;i < N;i++){
				node[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private int[] prop2(int[] L, int[] R, int[] C)
		{
			if(L != null && R != null){
				if(C == null)C = new int[K];
				C = apply(R, L, C);
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private int[] prop1(int[] L, int[] C)
		{
			if(C == null)C = new int[K];
			System.arraycopy(L, 0, C, 0, K);
			return C;
		}
		
		int[] gv;
		
		public int[] get(int l, int r) {
			gv = new int[K];
			for(int i = 0;i < K;i++)gv[i] = i;
			get(l, r, 0, H, 1);
			return gv;
		}
		
		protected void get(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gv = apply(node[cur], gv);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					get(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					get(l, r, mid, cr, 2*cur+1);
				}
			}
		}
	}
	
	static int[] apply(int[] f, int[] a)
	{
		int n = a.length;
		int[] r = new int[n];
		for(int i = 0;i < n;i++){
			r[i] = f[a[i]];
		}
		return r;
	}
	
	static int[] apply(int[] f, int[] a, int[] r)
	{
		int n = a.length;
		if(r == null){
			r = new int[n];
		}
		for(int i = 0;i < n;i++){
			r[i] = f[a[i]];
		}
		return r;
	}
	
	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
	
	void run() throws Exception
	{
//		int n = 1801, m = 112;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(1 + " ");
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			int[] a = shuffle(m, gen);
//			for(int j = 0;j < m;j++){
//				sb.append(a[j]+1 + " ");
//			}
//			sb.append("\n");
//		}
//		int q = 200000;
//		sb.append(q + " ");
//		for(int i = 0;i < q;i++){
//			int v1 = gen.nextInt(n);
//			int v2 = gen.nextInt(n);
//			sb.append(Math.min(v1, v2) + 1 + " ");
//			sb.append(Math.max(v1, v2) + 1 + " ");
//		}
//		INPUT = sb.toString();
 
		
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new DOCSDEL().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
}