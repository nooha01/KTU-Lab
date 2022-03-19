class Second_small
{
	public static void main(String args[])
	{
		int ar[]={2,2,2,2};
		int s1=ar[0],s2=ar[0];
		int i,num;
		for(i=0;i<4;i++)
		{
			if(s1>ar[i])
			{
				s1=ar[i];
			}
			if(s2<ar[i])
			{
				s2=ar[i];
			}
		}
		for(i=0;i<4;i++)
		{
			if(ar[i]!=s1)
			{
				if(ar[i]<s2)
				{ 
					s2=ar[i];
				}
		    }
		}
		if(s2==s1)
			System.out.println("All elements are equal ");
		else
			System.out.println("The second smallest element is " +s2);
	}
}	
		
		
 
		
