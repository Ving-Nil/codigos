import java.util.Scanner;
import java.util.NoSuchElementException;
class ArrayFill{
    public static void main(String[] args){
        int[] A = new int[20];
        int n = setNum(A);
        System.out.println("\nResult:");
        for(int i=0;i<n;i++){
            System.out.print(A[i]+" ");
        }
    }
    public static int setNum(int[] A){
        int k=0;
        Scanner sc = new Scanner(System.in);
        while(k<20){
            System.out.print("\n> ");
            try{
                int num = sc.nextInt();
                if(num<0){
                    break;
                }
                A[k] =  num;
                k++;
            }
            catch(NoSuchElementException E){break;}
        }
        sc.close();
        return k;
    }
}
