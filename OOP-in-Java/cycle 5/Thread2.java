import java.util.Scanner;
class MyThread extends Thread
{
    public void run()
    {
        System.out.println("Inside MyThread");
    }
}

class Thread2
{
    public static void main(String args[]) throws Exception
    {
        MyThread t = new MyThread();
        Scanner s = new Scanner(System.in);
        System.out.println("Priority of My Thread: "+Thread.currentThread().getPriority());

        System.out.println("Enter priority for your thread");

        t.setPriority(s.nextInt());
        System.out.println("Priority of  Mythread: "+t.getPriority());
        System.out.println("Priority of Main Thread: "+Thread.currentThread().getPriority());

        s.close();
    }
}

