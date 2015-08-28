// poj 2084.Game of Connections
// cataland + java BigInteger
// references:
// http://www.cnblogs.com/rainydays/archive/2011/06/06/2073889.html
import java.util.*;
import java.math.*;
import java.io.*;

public class bigint {	// Main
	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger [] h = new BigInteger[105];
		h[0] = h[1] = BigInteger.valueOf(1);
		//h[0] = new BigInteger("1");
		//h[1] = new BigInteger("1");
		for(int i=2; i<=100; i++)
		{
			h[i] = h[i-1].multiply(BigInteger.valueOf(4 * i - 2)).divide(BigInteger.valueOf(i + 1));
		}
		while(true)
		{
			int n = cin.nextInt();
			if(n == -1)
				break;
			System.out.println(h[n]);
		}
	}
}