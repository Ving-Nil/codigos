import java.util.Scanner;
import javax.swing.JOptionPane;
import javax.swing.JFrame;

// Objetos tienen atributos y métodos
class principal{

    public static void main( String[] args ){

        int n=-1;
        double prom;
        //Scanner sc = new Scanner(System.in);
        JFrame F = new JFrame();
        JOptionPane sc = new JOptionPane();
        
        //System.out.print("Cantidad de datos: ");
        //n = sc.nextInt();
        while( n<=0 ){
			try{
				n = Integer.valueOf(sc.showInputDialog(F,"Ingrese la cantidad de valores del arreglo"));
			}
			catch (Exception e){
				sc.showMessageDialog(F,"El número debe ser un entero");
			}
		}
		
		String[] S = new String[n];
        double[] J = new double[n];
        for( int i=0; i<n; i++ ){
            //System.out.print("\nValor "+(i+1)+" .- ");
            String[] dat = sc.showInputDialog(F,"Posición "+(i+1)+" .- "+"Ingresa: nombre,promedio (separados por coma): ").split(",");
            S[i] = dat[0];
            try{
				J[i] = Double.valueOf(dat[1]);
			}
			catch (Exception e){
				sc.showMessageDialog(F,"Error al recibir los datos!!");
				J[i] = 0;
				i--;
				continue;
			}
            if( J[i]<0 || 10<J[i] ){
				while( J[i]<0 || 10<J[i] ){
					try{
						J[i] = Double.valueOf(sc.showInputDialog(F,"Posición "+(i+1)+" .- "+" El promedio debe estar entre 0 y 10 (inclusive). Ingrese solamente el promedio:"));
					}catch(Exception e){
						sc.showMessageDialog(F,"Error al convertir el promedio!!");
						J[i] = -1;
					}
				}
			}
        }

        prom = average(J);
        System.out.println("El promedio de J es " + prom +"\n");

        for( int i=0; i<n; i++ ){
            
            if( J[i] < prom ){
                System.out.print(" - ");
            }
            else if( J[i] == prom ){
                System.out.print(" = ");
            }
            else{
                System.out.print(" + ");
            }
            System.out.println("Nombre: "+S[i]+", promedio: "+J[i]);
        }
		System.exit( 0 );
    }

    public static double average( double[] J ){
        int longitud = J.length;
        double sum = 0;
        for( int i=0;i<longitud;i++ ){
            sum += J[i];
        }
        return sum/longitud;
    }
}


