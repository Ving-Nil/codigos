import java.util.Scanner;

class cadena{
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese una frase o palabra: ");
        String S = sc.nextLine().split(" ")[0].toUpperCase();
        int n = S.length();
        char[] A = S.toCharArray();
        for( int i=0 ; i<n-1 ; i++ ){
            System.out.print( A[i] );
        }
        for( int i=n-1 ; 0<=i ; i-- ){
            System.out.print( A[i] );
        }
    }
}
