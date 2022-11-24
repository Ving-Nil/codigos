
class sum{
    public static void main(String[] args){
        int[] A = new int[10];
        for(int i=0;i<10;i++){
            A[i] = 2*(i+1)-1;
            System.out.print(A[i]+" ");
        }
        int n = sumOfFactors(A,50);
        System.out.println("\nSum of factors = "+n);
    }
    public static int sumOfFactors(int[] A, int n){
        int s=0;
        for(int i=0;i<A.length;i++){
            if(n%A[i]==0){
                s+=A[i];
            }
        }
        return s;
    }
}
