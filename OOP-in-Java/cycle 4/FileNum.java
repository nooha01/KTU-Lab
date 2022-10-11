import java.io.*;
import java.util.*;
public class FileNum 
{
    public static void main(String args[]) throws IOException
    {
        String file;
        Scanner filename = new Scanner(System.in);
        System.out.println("Enter the file name");
        file=filename.nextLine();

        File ob =  new File(file);
        Scanner f = new Scanner(ob);

        double temp,min,max,sum;
        int count=1;
            min=max=sum=f.nextInt();
            while(f.hasNextInt())
            {
                temp=f.nextInt();
                if(temp<min)
                    min=temp;
                if(temp>max)
                    max=temp;

                sum=sum+temp;
                count++;

            }
            System.out.println("Minimum:"+min+"\nMaximum:"+max+"\nRange:"+(max-min)+"\nAverage:"+sum/count);
        
        filename.close();
            f.close();
    }
    
}
