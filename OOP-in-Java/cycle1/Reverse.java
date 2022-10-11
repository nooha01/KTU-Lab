class Reverse
{
	public static void main(String args[])
	{
		int i;
		String str="malayalam";
		int len=str.length();
		System.out.println("The given string is " + str);
		System.out.print("The reversed string is ");
		for(i=len-1;i>=0;i--)
		{
			System.out.print(str.charAt(i));
		}
	}
}
		
	
