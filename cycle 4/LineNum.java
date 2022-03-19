import java.io.*;
import java.util.*;
public class LineNum 
{
    public static void main(String args[]) throws IOException
    {
        String infile,outfile;
        Scanner filename1 = new Scanner(System.in);
        System.out.println("Enter the input file name");
        infile=filename1.next();
        
        System.out.println("Enter the output file name");
        Scanner filename2 = new Scanner(System.in);
        outfile=filename1.next();
        
        FileReader fi = new FileReader(infile);
        BufferedReader bf = new BufferedReader(fi);
        FileWriter fo = new FileWriter(outfile);

        int num=1;
        String str;
        while((str=bf.readLine())!=null)
        {
            fo.write(num+"."+str+"\n");
            num++;
        }
        System.out.println("Line number added!");
        bf.close();
        fo.close();
        filename1.close();
        filename2.close();

    }
}

