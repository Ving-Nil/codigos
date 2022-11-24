
import java.util.Scanner;
import java.lang.Math;

class principal{
    public static void main( String[] args ){
        Scanner entrada = new Scanner(System.in);
        int opc = 1;
        while(opc != 4){
            System.out.println("\nMENU");
            System.out.println("1) Polares a cartesianas");
            System.out.println("2) Cartesianas a polares");
            System.out.println("3) Ambas");
            System.out.println("4) Salir");

            if(opc==1 || opc==3){
                System.out.println("Introduzca las coordenadas polares");
                System.out.print("r = ");
                double r = entrada.nextDouble();
                System.out.print("theta = ");
                double theta = entrada.nextDouble();

                double x = r*Math.cos(theta*Math.PI/180.0);
                double y = r*Math.sin(theta*Math.PI/180.0);

                System.out.println("x = "+x+", y = ",y);

            }
            if(opc==2 || opc==3){
                System.out.println("Introduzca las coordenadas cartesianas");
                System.out.print("x = ");
                double r = entrada.nextDouble();
                System.out.print("y = ");
                double theta = entrada.nextDouble();

                double r = Math.sqrt( Math.pow(x,2) + Math.pow(y,2) );
                double t = Math.atan(y/x)*180/Math.PI;

                System.out.println("r = "+r+", theta = ",t);

            }
            if(opc<1 || 4<opc){
                System.out.println("Opcion no válida");
            }
        }
    }
}
