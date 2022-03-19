class Account
{
	String ac_name,ac_type,add;
	float ac_no,i_amt,amt,c_bal;
	Account(String ac_name,float ac_no,float amt)
	{
		this.ac_name=ac_name;
		this.ac_no=ac_no;
		this.amt=amt;
	}
	Account(String ac_name,float ac_no,String add,String ac_type,float c_bal)
	{
		this.ac_name=ac_name;
		this.ac_no=ac_no;
		this.add=add;
		this.ac_type=ac_type;
		this.c_bal=c_bal;
	}
	void Display()
	{
		System.out.println("Name="+ac_name);
		System.out.println("Account number="+ac_no);
		System.out.println("Address="+add);
		System.out.println("Account type="+ac_type);
		System.out.println("current balance ="+c_bal);
		
	}
	void Deposit(float amt)
	{
		c_bal+=amt;
		System.out.println("The amount deposited it is "+ amt);
		
	}
	void Withdraw(float amt)
	{
		if(c_bal<amt)
			System.out.println("Insufficient amount to withdraw !!!");
		else
		{
			c_bal-=amt;
			System.out.println("The balance withdrawn is  "+amt);
			
		}
		
	}
	void Get_balance()
	{
		System.out.println("The balance amount is "+ c_bal);
		
	}
}
class Bank
{
	public static void main(String args[])
	{
		
		Account ac1=new Account("Angath",300f,1000f);
		Account ac2=new Account("Angath",300f,"keezhumadathil","savings",1000f);
		ac2.Display();
		ac2.Deposit(500f);
		ac2.Get_balance();
		ac2.Withdraw(2000f);
		ac2.Get_balance();
	}
}
	
	
	
	
	
	
