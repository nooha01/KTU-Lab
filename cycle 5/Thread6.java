import java.util.Scanner;
class Bank
{

     int total=5000;
     Synchronized void withdrawn(String name, int amount)
     {
         if(total>=amount) 
         {
         System.out.println(name+" withdrawn "+amount);
         total=total-amount;
         System.out.println("Balance in bank: "+total);
         try
         {
                  Thread.sleep(1000);
         }
         catch(InterruptedException e)
         {
                  e.printStackTrace();
         }
         }
         else
         {
                  System.out.println("Invalid amount");  
                  try
         {
                  Thread.sleep(1000);
         }
         catch(InterruptedException e)
         {
                  e.printStackTrace();
         }      
         }
     }
     
     Synchronized void deposit(String name, int amount)
     {
          System.out.println(name+" deposited "+amount);
         total=total+amount;
         System.out.println("Balance in bank: "+total);
                  try
         {
                  Thread.sleep(1000);
         }
         catch(InterruptedException e)
         {
                  e.printStackTrace();
         }      
         
     }
   }
   
 class Threadwithdrawal extends Thread
 {
         Bank ob;
         String name;
         int amt;
         Threadwithdrawal(Bank ob, String name, int amt)
         {
                  this.ob=ob;
                  this.name=name;
                  this.amt=amt;
         }
         public void run()
         {
                  ob.withdrawn(name, amt);
                  
          }
          }
 class Threaddeposit extends Thread
 {
         Bank ob;
         String name;
         int amt;
         Threaddeposit(Bank ob, String name, int amt)
         {
                  this.ob=ob;
                  this.name=name;
                  this.amt=amt;
         }
         public void run()
         {
                  ob.deposit(name, amt);
                  
          }
          }       
                  
                  
                  
class Thread6
{
         public static void main(String args[])
         {
                  Bank obj=new Bank();
                  Threadwithdrawal t1=new Threadwithdrawal(obj, "Nooha", 500);
                  Threaddeposit t2=new Threaddeposit(obj, "Nooha", 400);
                  
                  t1.start();
               
                  t2.start();
                  
            
         }
}
        
