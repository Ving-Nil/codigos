class reversed{
    public static void main(String[] args){
        int[] A = new int[4];

        for(int i=0;i<A.length;i++){
            A[i] = i+3;
        }

        for(int i=0;i<A.length;i++){
            System.out.print(A[i]+" ");
        }
        System.out.println("\n");
        Reversed(A);
        for(int i=0;i<A.length;i++){
            System.out.print(A[i]+" ");
        }
    }
    public static int[] Reversed(int[] A){
        int n = A.length;
        for(int i=0;i<n/2;i++){
            int aux = A[i];
            A[i] = A[n-i-1];
            A[n-i-1] = aux;
        }
        return A;
    }
}
