// poj 1001.Exponentiation
// exponential BigDecimal
//
import java.io.*;
import java.math.*;
import java.util.*;

public class Exponentiation {	//Main
	static Scanner cin = new Scanner(System.in);

	public static void main(String[] args) {
		BigDecimal a, c;
		int b;
		while(cin.hasNext())
		{
				a = cin.nextBigDecimal();
				b = cin.nextInt();
				c = a.pow(b);
				String ans = c.toPlainString();
				//System.out.println(ans);
				int x = 0, y = ans.length() - 1;
				while(ans.charAt(x) == '0')		x++;
				while(ans.charAt(y) == '0')		y--;
				if(ans.charAt(y) != '.')	y++;
				System.out.println(ans.substring(x, y));
		}
	}
}