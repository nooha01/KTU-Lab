class Time
{
	int hr,min;
	Time(int hr, int min)
	{
		this.hr=hr;
		this.min=min;
	}
	Time()
	{
		hr=0;
		min=0;
	}
	Time Sum(Time t2)
	{
		Time t3=new Time(0,0);		
		int temp;
		t3.hr=hr+t2.hr;
		temp=min+t2.min;
		if(temp>60)
		{
			t3.min=temp%60;
			t3.hr=t3.hr+temp/60;
		}
		else
			t3.min=temp;
		return t3;
	}
}
class Time_Sum
{
	public static void main(String args[])
	{
		Time t1=new Time(45,14);
		Time t2=new Time(50,98);
		Time t3=new Time();
		t3=t1.Sum(t2);
		System.out.println("Time 1 is "+t1.hr+" hours and "+ t1.min +" minutes");
		System.out.println("Time 2 is "+t2.hr+" hours and "+ t2.min +" minutes");
		System.out.println("Total timeis "+t3.hr+" hours and "+ t3.min +" minutes");
	}
}
		
		
