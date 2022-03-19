class Palindrome
{
	public static void main(String args[])
	{
		int i,	flag=0;
		String str="india";
		str=str.toLowerCase();
	    int len=str.length();
		for(i=0;i<len/2;i++)
		{
			if(str.charAt(i)==str.charAt(len-i-1))
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			System.out.println("The given string "+ str + " is not palindrome");
		}
		else
		{
			System.out.println("The given string " +str +" is palindrome");
		}
	}
}
