class Staff
{
	int code;
	String name;
	Staff(int code,String name)
	{
		this.code=code;
		this.name=name;
	}
	void display()
	{
		System.out.println("Code:"+code);
		System.out.println("name:"+name);
	}		
}
class Faculty extends Staff
{
	String department,sub_taken,r_area;
	Faculty(int code,String name,String department,String sub_taken,String r_area)
	{
		super(code,name);
		this.department=department;
		this.sub_taken=sub_taken;
		this.r_area=r_area;
	}
		void display()
		{
			System.out.println("Code:"+code);
			System.out.println("name:"+name);
			System.out.println("department:"+department);
			System.out.println("Subject taken:"+sub_taken);
			System.out.println("research area:"+r_area);
		}	
}
class Officer extends Staff
{
	int rank;
	char grade;
	Officer(int code,String name ,int rank, char grade)
	{
		super(code,name);
		this.rank=rank;
		this.grade=grade;
	}
	void display()
	{
		System.out.println("Code:"+code);
		System.out.println("name:"+name);
		System.out.println("Rank:"+rank);
		System.out.println("Grade:"+grade);
	}
}
class Typist extends Staff
{
	String office;
	int speed;
	Typist(int code,String name,String office, int speed)
	{
		super(code,name);
		this.office=office;
		this.speed=speed;
	}
	void display()
	{
		System.out.println("Code:"+code);
		System.out.println("name:"+name);
		System.out.println("office:"+office);
		System.out.println("Speed:"+speed+"words per minute");
	}
}
class Permanent extends Typist
{
	float salery;
	Permanent(int code,String name,String office,int speed,float salery)
	{
		super(code,name,office,speed);
		this.salery=salery;
	}
	void display()
	{
		
		System.out.println("Code:"+code);
		System.out.println("name:"+name);
		System.out.println("office:"+office);
		System.out.println("Speed:"+speed+" words per minute");
		System.out.println("salery:"+salery);
	}	
}
class Casual extends Typist
{
	float daily_wage;
	Casual(int code ,String name ,String office,int speed, float daily_wage)
	{
		super(code,name,office,speed);
		this.daily_wage=daily_wage;
	}
	void display()
	{
		System.out.println("Code:"+code);
		System.out.println("name:"+name);
		System.out.println("office:"+office);
		System.out.println("Speed:"+speed+" words per minute");
		System.out.println("Daily wage:"+daily_wage+" rupees per day");
	}
}
class Inheritance3
{	
	public static void main(String args[])
	{
		Permanent p=new Permanent(12,"ajr","cs",170,2500f);
		Typist t=new Typist(12,"ajr","cs",150);
		Casual c=new Casual(142,"shiv","eee",100,4512f);
		Officer o=new Officer(14,"mathew",16,'z');
		Faculty f=new Faculty(12,"vikram","cse","java","inheritance");
		Staff s=new Staff(12,"Ajr");
		System.out.println("\n\nPERMANENT TYPIST");
		System.out.println("----------------");
		p.display();
		System.out.println("\n\nCASUAL TYPIST");
		System.out.println("-------------");
		c.display();
		System.out.println("\n\nFACULTY");
		System.out.println("--------");
		f.display();
		System.out.println("\n\nOFFICER");
		System.out.println("--------");
		o.display();
	}
}
	
