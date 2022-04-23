import java.util.*;
public class DoublyLinkedList 
{
    public static void main(String args[])
    {
        LinkedList <String> list = new LinkedList <String>();
        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the Names:");
        String temp;
        temp="";
        while(!temp.equals("stop"))
        {
            temp=scanner.next();
            if(!temp.equals("stop"))
            list.add(temp);
        } 
        
        System.out.println(list+"\n");
        System.out.println("Enter the index of item to be deleted");
        n=scanner.nextInt();
        list.remove(n);
        Iterator i = list.iterator();
        System.out.println("List after deletion:");
        System.out.println(list+"\n");

        
    }
}
