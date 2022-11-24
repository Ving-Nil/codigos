import static java.lang.Math.sqrt;
class p{
    public static void main(String[] args){
        Vector V1 = new Vector(1,2,3);
        Vector V2 = new Vector(7,4,1);
        System.out.println("Vectors");
        System.out.println("V1 = "+V1.toString());
        System.out.println("V2 = "+V2.toString());

        System.out.println("V1.sum(V2) = "+V1.sum(V2));
        System.out.println("V1.times(V2) = "+V1.times(V2));

        System.out.println("V1.norm() = "+V1.norm());

        V2.normalize();
        System.out.println("V2.normalize() = "+V2.toString());

    }
}

class Vector{
    double x,y,z;
    Vector(double x,double y,double z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public Vector sum(Vector V){
        Vector k = new Vector(x+V.x,y+V.y,z+V.z);
        return k;
    }
    public double times(Vector V){
        return V.x*x + V.y*y + V.z*z;
    }
    public double norm(){
        return sqrt(x*x + y*y + z*z);
    }
    public void normalize(){
        if(x!=0 && y!=0 && z!=0){
            double n = sqrt(x*x + y*y + z*z);
            x = x/n;
            y = y/n;
            z = z/n;
        }
    }
    public String toString(){
        return "("+Double.toString(x)+", "+Double.toString(y)+", "+Double.toString(z)+")";
    }
}
