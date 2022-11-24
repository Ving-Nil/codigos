// importamos Math para sqrt y acos
import java.lang.Math;

// importamos el escaner para leer los datos
import java.util.Scanner;

class arco{
    public static void main( String[] args ){
        System.out.println("Ingrese las coordenadas");
        double u1,u2,v1,v2;
        Scanner sc = new Scanner(System.in);

        System.out.print("u1 : ");
        u1 = sc.nextDouble();
        System.out.print("u2 : ");
        u2 = sc.nextDouble();
        System.out.print("v1 : ");
        v1 = sc.nextDouble();
        System.out.print("v2 : ");
        v2 = sc.nextDouble();

        // las normas deben ser igual a 1.0 ya que se encuentran sobre el círculo unitario
        // System.out.println("Norma de ("+u1+","+u2+") = "+ norma(u1,u2) );
        // System.out.println("Norma de ("+v1+","+v2+") = "+ norma(v1,v2) );

        if ( norma(u1,u2)==1.0 && norma(v1,v2)==1.0 ){
            double theta = angle(u1,u2,v1,v2);
            double arc   = theta/Math.PI;
            System.out.println("La longitud de arco es : "+ arc +" rad");
            System.out.println("La longitud de arco es : "+ arc*180 +" grados");
        }
        else{
            System.out.println("\nLos puntos deben estar sobre la circunferencia unitaria\n");
             
            System.out.println("Norma de ("+u1+","+u2+") = "+ norma(u1,u2) );
            System.out.println("Norma de ("+v1+","+v2+") = "+ norma(v1,v2) );
        }
    }

    public static double norma(double u1, double u2){
        return Math.sqrt(u1*u1 + u2*u2);
    }
    public static double angle( double u1, double u2, double v1, double v2){
        return Math.acos( (u1*v1 + u2*v2) / (norma(u1,u2)*norma(v1,v2)) );
    }
}
