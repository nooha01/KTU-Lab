/*Write a Java program to demonstrate the use of garbage collector.*/
//gc() method is used to invoke garbage collector

public class garbage{
         public void finalize()
         {
                  System.out.println("Object is garbage collected");
         }
         public static void main(String args[])
         {
                  garbage g1 = new garbage();
                  garbage g2 = new garbage();
                  g1=null;
                  g2=null;
                  System.gc();
         }
}
