class ocurrences{
    public static void main(String[] args){
        String[] A = new String[5];
        A[0] = "Anna";
        A[1] = "John";
        A[2] = "Richard";
        A[3] = "John";
        A[4] = "Richard";
        System.out.println(countOcurrences(A,"John"));
        System.out.println(countOcurrences(A,"Anna"));
        System.out.println(countOcurrences(A,"Sara"));
    }
    public static int countOcurrences(String[] Arr, String S){
        int n = 0;
        for(String s : Arr){
            if(S.equals(s)){n++;}
        }
        return n;
    }
}
