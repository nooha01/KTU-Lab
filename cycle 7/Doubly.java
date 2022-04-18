import java.util.*;
class Doubly
{
    public static void main(String args[])
    {
        LinkedList<String> list = new LinkedList<String>();
        list.add("Nooha");
        list.add("Almira");
        list.add("Angath");
        list.add("Asher");
        list.add("Ashwin");
        list.add(0,"Muhammed");
        System.out.println(list+"\n");
        list.remove(4);
        list.remove("Nooha");
        Iterator itr = list.iterator();
        System.out.println("The list, after deletion, contains:");
        while(itr.hasNext())
        System.out.println(itr.next());
    }
}