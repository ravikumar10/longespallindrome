import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import sun.security.util.BigInt;

public class Solution {
	
	public static void longestPalSubstr(char[] str )
	{
	    int n = str.length; // get length of input string
	 
	    // table[i][j] will be false if substring str[i..j]
	    // is not palindrome.
	    // Else table[i][j] will be true
	    boolean[][] table = new boolean[n][n];
	    for(boolean row[]: table)
	        Arrays.fill(row, false);
	 
	    // All substrings of length 1 are palindromes
	    int maxLength = 1;
	    for (int i = 0; i < n; ++i)
	        table[i][i] = true;
	 
	    // check for sub-string of length 2.
	    int start = 0;
	    for (int i = 0; i < n-1; ++i)
	    {
	        if (str[i] == str[i+1])
	        {
	            table[i][i+1] = true;
	            start = i;
	            maxLength = 2;
	        }
	    }	   
	    for (int k = 3; k <= n; ++k)
	    {	        
	        for (int i = 0; i < n-k+1 ; ++i)
	        {
	            // Get the ending index of substring from
	            // starting index i and length k
	            int j = i + k - 1;
	 
	            if (table[i+1][j-1] && str[i] == str[j])
	            {
	                table[i][j] = true;
	 
	                if (k > maxLength)
	                {
	                    start = i;
	                    maxLength = k;
	                }
	            }
	        }
	    }
	 
	    for(int m=0;m<(n-maxLength+1);m++)
        {
                       int temp=0;int count=0;
                        for(int j=m;j<(maxLength+m);j++)
                        {
                        	
                                        if(str[j]!=str[m+maxLength-count-1]){
                                        temp=1;
                                        break;
                                       }
                                        count++;
                        }
                        if(temp==0)
                        {	
                                       for(int k=m;k<(maxLength+m);k++)
                                        	System.out.print(str[k]);
                                       System.out.println();
                        }
                     
        }	    
	}
	

	
    public static void main(String[] args) {
      
        String a="aaaraaaxyxrrrarrrlmnpprkppp";
        char[] arr = a.toCharArray();
        longestPalSubstr(arr);
        
        
        
    }   
}
