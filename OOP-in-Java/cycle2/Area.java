class Shape
{
	float hgth,r,len,wid;
	Shape(int len, int wid)//constructor overloading
	{
		this.len=len;
		this.wid=wid;
	}
	Shape(float len, float wid,float hgth)
	{
		this.len=len;
		this.wid=wid;
		this.hgth=hgth;
    }
    Shape(float r)
    {	
    	this.r=r;
    }
    Shape(float wid,float hgth)
    {
    	this.wid=wid;
    	this.hgth=hgth;
    }
    void area1()
    {
    	System.out.println("The area of rectangle = " +len*wid);
    }
    void area2()
    {
    	System.out.println("The area of Trapezium = " +0.5*(len+wid)*hgth);
    }
    void area3()
    {
    	System.out.println("The area of circle = "+3.14*r*r);
    }
    void area4()
    {
    	System.out.println("The area of triangle = "+ 0.5*hgth*wid);
    }
}
class Area
{
	public static void main(String args[])
	{
		Shape area1=new Shape(1,2);
		Shape area2 =new Shape(1f,2f,3f);
		Shape area3=new Shape(1f);
		Shape area4=new Shape(3f,4f);
		area1.area1();
		area2.area2();
		area3.area3();
		area4.area4();
	}
}





