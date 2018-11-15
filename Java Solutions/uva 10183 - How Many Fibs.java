//uva 10183 - How Many Fibs?
package uva;

import java.math.BigInteger;
import java.util.Scanner;import javax.security.auth.login.FailedLoginException;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		
		BigInteger fib[] = new BigInteger[501];
		fib[1] = BigInteger.valueOf(1);
		fib[2] = BigInteger.valueOf(2);
		
		for(int i=3; i<=500; i++)
			fib[i] = fib[i-1].add(fib[i-2]);
		
		while(in.hasNext())
		{
			BigInteger a, b;
			a = in.nextBigInteger();
			b = in.nextBigInteger();
			int count = 0;
			boolean flag = false;
			
			if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO)) 
				break;
			else if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ONE))
				System.out.println(1);
			else if(a.equals(BigInteger.ONE) && b.equals(BigInteger.ZERO))
				System.out.println(1);
			else if(a.equals(BigInteger.ONE) && b.equals(BigInteger.ONE))
				System.out.println(1);
			else 
			{
				for(int i = 1;i<500;i++) 
				{
					 if(fib[i].compareTo(a) >= 0 && fib[i].compareTo(b) <= 0)
					   count++;
				 }
				flag = true;
			}
			if(flag)
				System.out.println(count);
		}
	}

}
