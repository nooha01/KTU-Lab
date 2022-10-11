class gmtry
{
	float hgth,r,len,wid;
	void area(int len ,int wid)
    {
    	this.len=len;
    	this.wid=wid;
    	System.out.println("The area of rectangle = " +len*wid);
    }
    void area(float len,float wid,float hgth)
    {
    	this.len=len;
    	this.wid=wid;
    	this.hgth=hgth;
    	System.out.println("The area of Trapezium = " +0.5*(len+wid)*hgth);
    }
    void area(float r)
    {
    	this.r=r;
    	System.out.println("The area of circle = "+3.14*r*r);
    }
    void area(float hgth, float wid)
    {
    	this.hgth=hgth;
    	this.wid=wid;
    	System.out.println("The area of triangle = "+ 0.5*hgth*wid);
    }
}
class Area_method
{
	public static void main(String args[])
	{
		gmtry area1=new gmtry();
		gmtry area2 =new gmtry();
		gmtry area3=new gmtry();
		gmtry area4=new gmtry();
		area1.area(1,2);
		area2.area(1f,2f,3f);
		area3.area(1f);
		area4.area(3f,4f);
	}
}


