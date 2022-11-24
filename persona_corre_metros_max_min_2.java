import java.util.ArrayList;
import java.util.Scanner;

class principal{

    public static void main( String[] args ){
        
        Scanner sc = new Scanner( System.in );

        int edad, opc = 1;
        String nombre;
        double[] D = { 10, 12, 14, 50, 23 };
        Persona P = new Persona("Juan", 24 , D );
        ArrayList Listado = new ArrayList<Persona>();

        while(opc != 8){
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

            opc = sc.nextInt();

            if ( opc == 1 ){

                sc.nextLine();
                System.out.println("\nIngrese el nombre: ");
                nombre = sc.nextLine();

                System.out.println("Ingrese la edad: ");
                edad = sc.nextInt();

                System.out.println("Ingrese los metros caminados por cada día");
                for (int j=0; j<5; j++ ){
                    System.out.print("\nDía " + (j+1) + " : ");
                    D[j] = sc.nextDouble();
                }

                P = new Persona( nombre, edad, D );
                Listado.add( P );
            }
            else if(opc==2){
                sc.nextLine();
                System.out.println("\nIngrese el nombre de la persona a eliminar");
                nombre = sc.nextLine();
                for(int k=0;k<Listado.size();k++){
                    if( nombre.equalsIgnoreCase(((Persona)Listado.get(k)).nombre) ){
                        System.out.println("Index : "+k+", Persona : "+(Persona)Listado.get(k));
                    }
                }
                System.out.print("\nIngrese el Index a eliminar: ");
                Listado.remove(sc.nextInt());
            }
            else if(opc==3){
                sc.nextLine();
                System.out.println("\nIngrese el nombre de la persona a actualizar");
                nombre = sc.nextLine();
                for(int k=0;k<Listado.size();k++){
                    if( nombre.equalsIgnoreCase(((Persona)Listado.get(k)).nombre) ){
                        System.out.println("Index : "+k+", Persona : "+(Persona)Listado.get(k));
                    }
                }
                System.out.print("\nIngrese el Index a actualizar: ");
                int index = sc.nextInt();
                P = (Persona)Listado.get(index);

                System.out.print("\nDesea modificar el nombre? [1 si, 0 no] : ");
                if ( sc.nextInt() != 0 ){
                    sc.nextLine();
                    System.out.print("\nIngrese el nuevo nombre: ");
                    P.nombre = sc.nextLine();
                }

                System.out.print("\nDesea modificar la edad? [1 si, 0 no] : ");
                if ( sc.nextInt() != 0 ){
                    sc.nextLine();
                    System.out.print("\nIngrese la nueva edad: ");
                    P.edad = sc.nextInt();
                }

                System.out.print("\nDesea modificar los metros recorridos por día? [1 si, 0 no] : ");
                if ( sc.nextInt() != 0 ){
                    sc.nextLine();
                    for(int k=0;k<5;k++){
                        System.out.print("\nDía "+(k+1)+" : ");
                        P.metros[k] = sc.nextDouble();
                    }
                }
                Listado.set( index, P );
            }
            else if( opc == 4 ){
                int n = Listado.size();
                for(int k=0;k<n;k++){
                    System.out.println(  "\nPersona " + (k+1) + " : " + (Persona)Listado.get(k) );
                }
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
                    System.out.println("El máximo es: " + Max + "\n" );
                    Max.mostrarDatos();
                    System.out.println("\n");
                }
                catch (Exception e){
                    System.out.println("Error, possibly void list");
                }
            }
            else if ( opc == 6 ){
                try{
                    int n = Listado.size();
                    Persona Min = (Persona)Listado.get(0);
                    for( int k=1;k<n;k++ ){
                        P = (Persona)Listado.get(k);
                        if ( Min.total() > P.total() ){
                            Min = P;
                        }
                    }
                    System.out.println("El mínimo es: " + Min + "\n" );
                    Min.mostrarDatos();
                    System.out.println("\n");
                }
                catch (Exception e){
                    System.out.println("Error, possibly void list");
                }
            }
            else if ( opc == 7 ){
                try{
                    double suma=0;
                    int n = Listado.size();
                    for(int k=0;k<n;k++){
                        suma += ((Persona)Listado.get(k)).total();
                    }
                    suma /= n;
                    System.out.println("El promedio de metros totales de todas las personas es : "+ suma);
                }
                catch (Exception e){
                    System.out.println("Error, possibly void list");
                }
            }
        }
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
