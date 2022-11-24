import java.util.Iterator;
import java.util.ArrayList;
import java.util.Scanner;

class principal{

    public static void main( String[] args ){
        
        Scanner sc = new Scanner( System.in );

        int edad;
        String nombre;
        double[] D = { 10, 12, 14, 50, 23 };
        Persona P = new Persona("Juan", 24 , D );
        ArrayList Listado = new ArrayList<Persona>();

        /**
        // experiment
        Listado.add( P );
        System.out.println("##############");
        System.out.println(Listado.get(0));
        System.out.println(Listado.get(0).getClass());
        System.out.println("##############");
        // Funciona !!!!!!!!!!!!!!!!
        **/

        //**
        for(int i=0;i<5;i++){
            System.out.println("\nMenu");
            System.out.println("1) Agregar persona");
            System.out.println("2) Eliminar persona");
            System.out.println("3) Actualizar persona");
            System.out.println("4) Imprimir lista");
            System.out.println("5) Máximo semanal");
            System.out.println("6) Mínimo semanal");
            System.out.println("7) Promedio semanal");
            System.out.println("8) Salir");

            System.out.print("> ");

            int opc = sc.nextInt();

            if ( opc == 1 ){

                sc.nextLine();
                System.out.println("\nIngrese el nombre: ");
                nombre = sc.nextLine();

                System.out.println("Ingrese la edad: ");
                edad = sc.nextInt();

                System.out.println("Ingrese los metro caminados por cada día");
                for (int j=0; j<5; j++ ){
                    System.out.print("\nDía " + (j+1) + " : ");
                    D[j] = sc.nextDouble();
                }

                P = new Persona( nombre, edad, D );
                Listado.add( P );
            }
            else if( opc == 4 ){
                System.out.println( Listado );
            }
            else if ( opc == 5 ){
                try{
                    int n = Listado.size();
                    Persona Max = (Persona)Listado.get(0);
                    for( int k=1;k<n;k++ ){
                        P = (Persona)Listado.get(k);
                        if ( Max.total() < P.total() ){
                            Max = P;
                        }
                    }
                    System.out.println("El máximo es: " + Max );
                    Max.mostrarDatos();
                    System.out.println("\n");
                }
                catch (Exception e){
                    System.out.println("Error, possibly void list");
                    System.out.println(e);
                }
            }
            
        }
        //**/

    }

}

class Persona{
    public int edad;
    public String nombre;
    public double[] metros = new double[5];
    public String[] dias = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

    Persona( String nombre, int edad, double[] metros ){
        this.edad = edad;
        this.nombre = nombre;
        for(int j=0;j<5;j++)
            this.metros[j] = metros[j];
    }

    Persona(){}

    public double total(){
        double suma=0;
        for(int i=0;i<5;i++){
            suma += metros[i];
        }
        return suma;
    }

    public double promedio(){
        double suma=0;
        for(int i=0;i<5;i++){
            suma += metros[i];
        }
        return suma/5;
    }

    public void mostrarDatos(){
        double suma=0;
        for(int i=0;i<5;i++){
            System.out.println(dias[i] + " : " + metros[i]);
        }
        System.out.println("Total de metros semanal : "+total() );
        System.out.println("Promedio de metros semanal : "+promedio() );
    }

    public String toString(){
        return nombre + " de " + Integer.toString(edad) + " anios con promedio " + Double.toString(promedio()) + " mts y total " + Double.toString(total()) + " metros";
    }

}
