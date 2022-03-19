class Frequency
{
	public static void main(String args[])
	{
	
	    int i,count=0;
	    String str="malayalam";
    	
		char ch='a';
		for(i=0;i<str.length();i++)
		{
			if(ch==str.charAt(i))
			{	
				count++;
			}
		}
		System.out.println("The given charachter " +ch+"  occurs " + count +" times in the string "+ str );
	}
}
	
