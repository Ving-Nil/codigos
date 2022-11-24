
// Scanner sirve pare recibir datos
import java.util.Scanner;

class principal{
    public static void main( String[] args ){
        int n=-1;
        Scanner input = new Scanner(System.in);

        while( n<0 || n%2==0 ){
            System.out.print("Dim matriz: ");
            n = input.nextInt();
        }

        int[][] A = new int[n][n];

        for( int y=0; y<n; y++ ){
            for( int x=0; x<n; x++ ){
                A[y][x] = 0;
            }
        }

        showMatrix( A , n );

        int x = n/2, y = 0;
        // biyección
        for( int i = 1; i<=n*n; i++ ){
            A[ y ][ x ] = i;

            // excepción 1
            // si i es sucesor de un multiplo de n
            if ( (i+1)%n==1 ){
                // renglón posterior
                y = (y + 1)%n;
                // mísma columna
                // x = x;
            }
            else{
                //renglón anterior
                y = (y - 1 + n)%n;
                // columna posterior
                x = (x + 1)%n;
            }

            // impresión paso a paso
            System.out.println("Paso "+i);
            showMatrix( A , n );
        }

        showMatrix( A , n );
    }

    public static void showMatrix( int[][] A, int n ){
        for( int y=0; y<n; y++ ){
            for( int x=0; x<n; x++ ){
                if ( A[y][x] < 10 ){System.out.print(" ");}
                System.out.print( A[y][x] + " " );
            }
            System.out.println("");
        }
        System.out.println("");
    }
}
