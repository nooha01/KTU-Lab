import java.util.Scanner;
class Bank


{
     
    synchronized void withdraw(String name,int amtwithdraw,int total)
    {
        if(amtwithdraw>total)
        {
            System.out.println("Insufficient balance");
            System.out.println("BALANCE for "+name+":Rs "+total);
        }
        else
        {s
            total=total-amtwithdraw;
            System.out.println("Rs "+amtwithdraw+" Withdrawn by "+name);
            System.out.println("BALANCE for "+name+":Rs "+total);
        }
        try {
            Thread.sleep(1000);
        }
        catch (InterruptedException e) 
        {
            System.out.println(e);
        }
    }
    synchronized void deposit(String name,int amtdep,int total)
    {
        total=total+amtdep;
        System.out.println("Rs "+amtdep+" Deposited by "+name);
        System.out.println("BALANCE for "+name+":Rs "+total);
        try {
            Thread.sleep(1000);
        }
        catch (InterruptedException e) 
        {
            System.out.println(e);
        }
    }
}

class Withdraw extends Thread
{
    Bank ob;
    String name;
    int amt;
    int total;
    Withdraw(String name,Bank obj,int amt,int total)
    {
        ob=obj;
        this.name=name;
        this.amt=amt;
        this.total=total;
    }
    public void run()
    {
        ob.withdraw(name,amt,total);
    }
}
class Deposit extends Thread
{
    Bank ob;
    String name;
    int amt,total;
    Deposit(String name,Bank obj,int amt,int total)
    {
        ob=obj;
        this.name=name;
        this.amt=amt;
        this.total=total;

    }
    public void run()
    {
       ob.deposit(name,amt,total);
    }
}

class Thread5 
{
    public static void main(String args[]) throws Exception
    {
        Bank obj = new Bank();
        Withdraw w1 = new Withdraw("Almira",obj,40,500);
        Withdraw w2 = new Withdraw("Neha",obj,70,500);
        Deposit d = new Deposit("Amar",obj,50,500);

        w1.start();
        w2.start();
        d.start();
    }
    
}

