class ThreadA extends Thread
{
    public void run()
    {
        for(int i=1;i<=100;i+=2)
        {
            System.out.print("Thread A:"+i + "\t");
        }
    }
}

class ThreadB extends Thread
{
    public void run()
    {
        for(int i=2;i<=100;i+=2)
        {
            System.out.print("Thread B:"+i+ "\t");
        }
    }
}

class Thread1
{
    public static void main(String args[]) throws Exception
    {
        new ThreadA().start();
        new ThreadB().start();

        new ThreadB().join();
        new ThreadA().join();

        System.out.println("Main thread here!");
    }
}

