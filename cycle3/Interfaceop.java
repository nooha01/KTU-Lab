interface Operations
{
    public void area();
    public void volume();
    final float PI=3.14f;
}

class Cylinder implements Operations
{
    float height,radius;
    Cylinder(float height,float radius)
    {
        this.height=height;
        this.radius=radius;
    }
    public void area()
    {
        float ar=(2*PI*radius*height)+(2*PI*radius*radius);
        System.out.println("Area of cylinder: "+ar);
    }
    public void volume()
    {
        float vol=PI*radius*radius*height;
        System.out.println("Volume of cylinder: "+vol);
    }
}

class Interfaceop
{
    public static void main(String args[])
    {
        Cylinder cyl=new Cylinder(1f,1f);
        cyl.area();
        cyl.volume();
    }
}
