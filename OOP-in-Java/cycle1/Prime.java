class Prime
{	
	public static void main(String args[])
	{
		int num,i;
		num=1;
		if(num==1)
		{
		
			System.out.println("one is neither prime nor composite");
			System.exit(0);
		}
		for (i=2;i<=num/2;i++)
		{
			if(num%i==0)
			{
				System.out.println("The given number "+num+" is not prime");
				System.exit(0);
			}
		}
		System.out.println("The given number"+ num+ " is prime ");
	}
}

