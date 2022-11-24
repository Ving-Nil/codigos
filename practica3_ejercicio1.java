
import java.util.Scanner;

class principal{
    public static void main( String[] args ){
        Scanner entrada = new Scanner(System.in);
        System.out.print("Introduzca el monto a pagar: ");
        float monto = entrada.nextFloat();
        if( monto<1000 ){
            System.out.println("No hay descuento");
            System.out.println("El monto a pagar es "+monto);
        }
        else if( 1000<=monto && monto <5000 ){
            System.out.println("El descuento es "+monto*0.1+" (10%)");
            System.out.println("El monto a pagar es "+monto*0.9);
        }
        else if( 5000<=monto && monto <10000 ){
            System.out.println("El descuento es "+monto*0.2+" (20%)");
            System.out.println("El monto a pagar es "+monto*0.8);
        }
        else{
            System.out.println("El descuento es "+monto*0.3+" (30%)");
            System.out.println("El monto a pagar es "+monto*0.7);
        }
    }
}
