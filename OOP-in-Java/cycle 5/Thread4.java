class MyThread implements Runnable
{
    public void run()
    {
        System.out.println("Inside MyThread before sleep");
        try
        {
            Thread.sleep(500);
        }
        catch(InterruptedException e)
        {
            System.out.println(e);
        }
        System.out.println("Inside MyThread after sleep");
    }
}


class Thread4
{
    public static void main(String args[]) throws Exception
    {
        Runnable obj = new MyThread();
        Thread t= new Thread(obj);
        Thread t1= new Thread(obj);
        t.start();
        t1.start();
        t.join();
        t1.join();
    }
}

