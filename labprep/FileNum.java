import java.io.*;
import java.util.*;
public class FileNum
{
    public static void main(String args[]) throws IOException
    {
        System.out.println("Enter Integers:");
        Scanner s = new Scanner(System.in);
        String num = s.nextLine();

        StringTokenizer st = new StringTokenizer(num);
        
        int sum=0,count=1;
        int n;
        System.out.println("The numbers are:");
        while(st.hasMoreTokens())
        {
            n=Integer.parseInt(st.nextToken());
            System.out.println("Token "+count+":"+n);
            sum+=n;
            count++;
        }
        System.out.println("Total no.of tokens:"+(count-1));
        System.out.println("Sum:"+sum);
        s.close();
    }
    
}

