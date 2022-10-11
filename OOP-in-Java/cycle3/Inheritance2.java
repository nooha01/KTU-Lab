class Employee1
{
	void calc_salery()
	{
		System.out.println("The salery of Employee is 10000");
	}
	void display()
	{
		System.out.println("The name of the class is Empployee");
	}
}
class Engineer extends Employee1
{
	void calc_salery()
	{
		System.out.println("The salery of engineer is 20000");
		super.display();
		super.calc_salery();
	}
	void display()
	{
		System.out.println("The name of the class is Engineer");
	}
}
class Inheritance2
{
	public static void main(String args[])
	{
		Engineer eng =new Engineer();
		eng.display();
		eng.calc_salery();
	}

}
		
	

