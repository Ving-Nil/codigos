class rem{
    public static void main(String[] args){
        int[] A = new int[10];
        for(int i=0;i<A.length;i++){A[i]=i%3;}
        for(int i=0;i<A.length;i++){
            System.out.print(A[i]+" ");
        }
        System.out.println("\n");
        int n = removeAll(A,A.length,2);
        for(int i=0;i<A.length-n;i++){
            System.out.print(A[i]+" ");
        }
    }
    public static int removeAll(int[] A, int size, int num){
        int k=0;
        for(int i=0;i<size;i++){
            if(A[i]==num){k++;}
            else{A[i-k]=A[i];}
        }
        return k;
    }
}
