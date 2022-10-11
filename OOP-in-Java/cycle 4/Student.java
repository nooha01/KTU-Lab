import java.util.Scanner;

class AgeException extends Exception
{
    AgeException(String str)
    {
        super(str);
    }
}

class Student
{
    public static void main(String args[])
    {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter Name:");
        String name=obj.nextLine();
        System.out.println("Enter course name");
        String course=obj.nextLine();
        System.out.println("Enter roll number:");
        int roll=obj.nextInt();
        System.out.println("Enter age:");
        try{
            int age=obj.nextInt();
           if(ageCheck(age)==1) 
           {
            System.out.println("Name:"+name);
            System.out.println("Rollno.:"+roll);
            System.out.println("Age:"+age);
            System.out.println("Course name:"+course);
            }
        }
        catch(AgeException e)
        {
            System.out.println(e);
        }
        obj.close();
    }
    public static int ageCheck(int age) throws AgeException
    {
        if(age<=15 || age>=21)
                throw new AgeException("Invalid Age");
        else
            return 1;
    }
}
