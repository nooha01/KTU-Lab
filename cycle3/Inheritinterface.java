interface P
{
    final int p=10;
    void displayP();
}

interface P1 extends P
{
    final int p1=30;
    void displayP1();
}

interface P2 extends P
{
    final int p2=50;
    void displayP2();
}

interface P12 extends P1,P2
{
    final int p12=60;
    void displayP12();
}

class Q implements P12
{
    public void displayP()
    {
        System.out.println("Value of P is "+p);
    }
    public void displayP1()
    {
        System.out.println("Value of p1 is "+p1);
    }
    public void displayP2()
    {
        System.out.println("Value of P2 is "+p2);
    }
    public void displayP12()
    {
        System.out.println("Value of P12 is "+p12);
    }
    
}

class Inheritinterface
{
    public static void main(String arg[])
    {
        Q q=new Q();
        q.displayP();
        q.displayP1();
        q.displayP2();
        q.displayP12();
    }
}