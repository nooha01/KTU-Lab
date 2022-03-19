import java.io.*;
public class FileMergeAlt
{
    public static void main(String args[]) 
    {
        try
        {
            FileReader f1 = new FileReader("file1.txt");
            BufferedReader bf1 = new BufferedReader(f1);
            FileReader f2 = new FileReader("file2.txt");
            BufferedReader bf2 = new BufferedReader(f2);
            FileWriter f = new FileWriter("file3.txt");
            
            String str;
            while((str=bf1.readLine())!=null)
            {
                f.write(str);
                f.write('\n');
                if((str=bf2.readLine()) != null)
                {
                    f.write(str);
                    f.write('\n');
                }
            }
            while((str=bf2.readLine()) != null)
            {
                f.write(str);
                f.write('\n');
            }
            System.out.println("Files are merged alternatively");

            f1.close();
            f2.close();
            f.close();
        }
        catch(IOException e)
        {
            System.out.println("Error");
        }  
    }
}
