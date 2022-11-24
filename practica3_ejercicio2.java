
import java.util.Scanner;

class principal{
    public static void main( String[] args ){
        Scanner entrada = new Scanner(System.in);
        System.out.print("Ingrese la cantidad de minutos: ");
        int minutos = entrada.nextInt();

        if( minutos<=10 ){
            System.out.println("El costo total es "+minutos);
        }
        else if( minutos<=20 ){
            System.out.println("El costo total es "+ (10+2*(minutos-10)) );
        }
        else{
            System.out.println("El costo total es "+ (30+3*(minutos-20)) );
        }
    }
}
