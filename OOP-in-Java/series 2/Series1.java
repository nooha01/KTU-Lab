import java.io.*;
import java.util.*;

class StringOperation
{
   
    void methodString()
    {
        try
    {
        FileReader fr = new FileReader("String.txt");
    }
    catch(Exception e)
    {
        System.out.println(e);
    }
    }
    
    

}

class NumericalOperation
{
    int k;
    
    void methodNum()
    {
        try
        {
            String s;
            FileReader fr = new FileReader("Number.txt");
            BufferedReader bf = new BufferedReader(fr);
            FileWriter fe = new FileWriter("Even.txt");
            //FileWriter fo = new FileWriter("Odd.txt");
            
            //System.out.println(k);
              
            while((s=bf.readLine())!= null)
            {
                //System.out.println(k);
                k=Integer.parseInt(s);//System.out.println(k);
                if(k%2==0)
                {
                    
                    fe.write(s);
                    fe.write("\n");

                }
                else if(k%2!=0)
                {
                   // System.out.println("Odd numbers:");
                    System.out.println(s);
                }
                
            }
            fr.close();
            fe.close();
            bf.close();
            
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        
        
        
    }
    
}




class Series1
{
    public static void main(String args[]) throws IOException
    {
        int item;
        String str;
        StringOperation so = new StringOperation();
        NumericalOperation no = new NumericalOperation();
        FileWriter fw1 = new FileWriter("Number.txt");
        FileWriter fw2 = new FileWriter("String.txt");
        for(int i=0;i<args.length;i++) 
        {
            Scanner s = new Scanner(args[i]);
            if(s.hasNextInt())
            {
                
                 item=s.nextInt();
                
                 fw1.write(String.valueOf(item));
                 fw1.write("\n");
                

            }
            else
            {
               str=s.next();
             
                fw2.write(str);
            }
            s.close();
        }
        fw1.close();
        fw2.close();

        no.methodNum();
        
        
    }
}
