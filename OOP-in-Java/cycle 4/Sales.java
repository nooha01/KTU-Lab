import java.io.*;
import java.util.*;
class SalesException extends Exception
{
    SalesException(String exc)
    {
        super(exc);
    }
}
class SalesMan 
{
   
    String name;
    double code,amt,comm;

    SalesMan(double code,double amt,String name)
    {
        this.code=code;
        this.amt=amt;
        this.name=name;
    }
    double commission()
    {
        
            
                if(amt<2000)
                    comm=0.08*amt;
                else if(amt>=2000 && amt<=5000)
                    comm=0.1*amt;
                else
                    comm=0.12*amt;
            
            return comm;
    }
}
class Sales
{
    public static void main(String args[]) 
    {
        String n;
        double c,a;
        Scanner s = new Scanner(System.in);
        
        System.out.println("Enter name:");
        n=s.nextLine();
        System.out.println("Enter Sales code:");
        c=s.nextInt();
        System.out.println("Enter Sales amount:");
        
        try
        {
            a=s.nextInt();
            SalesMan obj = new SalesMan(c,a,n);

            if(a>=0)
            {
                System.out.println("Name:"+n);
                System.out.println("Sales Code:"+c);
                System.out.println("Sales Amount:"+a);
                System.out.println("Commission:"+obj.commission());
            }
            else
                throw new SalesException("Invalid Amount");
                
        }
        catch(SalesException e)
        {
            System.out.println(e);
        }
        s.close();
    }
}

