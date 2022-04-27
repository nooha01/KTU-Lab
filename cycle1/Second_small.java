class Second_small
{
	public static void main(String args[])
	{
		int ar[]={1,3,4,1,3};
		int small=ar[0],small2=ar[0]; //small:1 smalll2:1
		int i; 
		for(i=0;i<5;i++)
		{
			if(small>ar[i]) 
			{
				small=ar[i]; //small : 1,1,1,1,1
			}
			if(small2<ar[i]) 
			{
				small2=ar[i]; //small2 : 1,3,4,4,4
			}
		}
		for(i=0;i<5;i++)
		{
			if(ar[i]!=small)
			{
				if(ar[i]<small2)
				{ 
					small2=ar[i]; //small2: 4,3,3,3,3
				}
		    }
		}
		if(small2==small)
			System.out.println("All elements are equal ");
		else
			System.out.println("The second smallest element is " +small2);
	}
}	
		
		
 
		
