class Complex
{
	float im,rl;
	Complex(float rl, float im)
	{
		this.rl=rl;
		this.im=im;
	}
	Complex sum(Complex c2)
	{
		Complex c3=new Complex(0f,0f);		
		c3.rl=rl+c2.rl;
		c3.im=im+c2.im;
		return c3;
	}
}
class Complex_sum
{
	public static void main(String args[])
	{
		Complex c1=new Complex(4f,3f);	
		Complex c2=new Complex(5f,7f);
		Complex c3=new Complex(0f,0f);
		c3=c1.sum(c2);
		System.out.println("The first complex number is "+ c1.rl+"+ i"+c1.im);
		System.out.println("The second complex number is "+ c2.rl+"+ i"+c2.im);
		System.out.println("The sum of complex number is "+ c3.rl+"+ i"+c3.im);
	}
}
