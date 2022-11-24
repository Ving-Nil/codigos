
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

        // biyección
        for( int i = 1; i<=n*n; i++ ){
            A[ (i-1)/n ][ (i-1)%n ] = n*n-i+1;
            System.out.println("Paso "+i);
            showMatrix( A , n );
        }

        /** Ejemplo
        columnas:     0   1   2   3   4 

        fila    0   [ 1,  2,  3,  4,  5]
                1   [ 6,  7,  8,  9, 10]
                2   [11, 12, 13, 14, 15]
                3   [16, 17, 18, 19, 20]
                4   [21, 22, 23, 24, 25]
        
        **/

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
