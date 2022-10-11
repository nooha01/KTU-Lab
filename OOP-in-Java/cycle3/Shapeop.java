interface Area
{
    double findArea();
}

interface Volume
{
    double findVolume();
}

class Shape
{
    String name;
    Shape(String n)
    {
        name=n;
    }
    public String getName()
    {
        return name;
    }
}

class Circle extends Shape implements Area
{
    double radius;
    Circle(double r, String n)
    {
        super(n);
        radius=r;
        
    }
    public double findArea()
    {
        return (3.14*radius*radius);
    }
}

class Square extends Shape implements Area
{
    double side;
    Square(double s,String n)
    {
        super(n);
        side=s;
    }
    public double findArea()
    {
        return(side*side);
    }
}

class Cube extends Square implements Volume
{
    Cube(double s,String n)
    {
        super(s,n);
    }
    public double findVolume()
    {
        return (side*side*side);
    }
}

class Sphere extends Circle implements Volume
{
   Sphere(double r, String n) 
   {
    super(r,n);
   }

   public double findVolume()
   {
       return (4.186*radius*radius*radius);
   }
}

class Cylinder extends Circle implements Volume
{
    double height;
    Cylinder(double h,double r,String n)
    {
        super(r,n);
        height=h;
    }

    public double findVolume()
    {
        return (3.14*radius*radius*height);
    }
    
}

class Glome extends Sphere
{
    Glome(double r,String n)
    {
        super(r,n);
    }
    public double findVolume()
    {
        return (4.9298*radius*radius*radius*radius);
    }
}

class Shapeop
{
    public static void main(String args[])
    {
        Glome glm = new Glome(1,"Glome");
        Cube cb = new Cube(2,"Cube");
        Sphere sp = new Sphere (1,"Sphere");
        Cylinder cyl = new Cylinder (4,5,"Cylinder");
         
        System.out.println(glm.getName() +" area is "+ glm.findArea()+" and volume is "+glm.findVolume()); 
        System.out.println(sp.getName() +" area is "+ sp.findArea()+" and volume is "+sp.findVolume()); 
        System.out.println(cyl.getName() +" area is "+ cyl.findArea()+" and volume is "+cyl.findVolume()); 
        System.out.println(cb.getName() +" area is "+ cb.findArea()+" and volume is "+cb.findVolume()); 
    }
}
