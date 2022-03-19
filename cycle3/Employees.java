class Employee
{
	String name,add;
	float salery;
	int phno,age;
	Employee(String name,String add, int phno,int age,float salery)
	{
		this.name=name;
		this.add=add;
		this.phno=phno;
		this.salery=salery;
		this.age=age;
	}
	void print_salery()
	{
		System.out.println("The salery of employee="+salery);
	}
}
class Officer extends Employee
{
	String specialization;
	Officer(String name,String add, int phno,int age,float salery)
	{
		super(name,add,phno,age,salery);
		specialization="M.TECH";
		
	}
	void details()
	{
		System.out.println("The details of the officer is ");
		System.out.println("_______________________________");
		System.out.println("\nName:"+name);
		System.out.println("Address:"+add);
		System.out.println("Phone number:"+phno);
		System.out.println("Age="+age);
		System.out.println("Specialization:"+specialization);
	}
}
class Manager extends Employee
{
	String department;
	Manager(String name,String add, int phno,int age,float salery)
	{
		super(name,add,phno,age,salery);
	    department="SALES";
	}
	void details()
	{
		System.out.println("\n\nThe details of the manager is ");
		System.out.println("_______________________________");
		System.out.println("Name:"+name);
		System.out.println("Address:"+add);
		System.out.println("Phone number:"+phno);
		System.out.println("Age:"+age);
		System.out.println("Department:"+department);
	}
}
class Employees
{
	public static void main(String args[])
	{
		Officer ofcr=new Officer("Angath","kkd",1334545871,20,45000);
		Manager mngr=new Manager("Sumesh","palazhi",45575,25,452456);
		ofcr.details();
		ofcr.print_salery();
		mngr.details();
		mngr.print_salery();	
	}
}
		
