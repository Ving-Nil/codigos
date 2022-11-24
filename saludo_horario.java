import java.util.Date;

class saludo{
    public static void main( String[] args ){
        Date date = new Date();
        if ( 0 <= date.getHours() &&  date.getHours()<12 ){
            System.out.println("Buenos días!");
        }
        else if ( 12 <= date.getHours() &&  date.getHours()<19 ){
            System.out.println("Buenas tardes");
        }
        else{
            System.out.println("Buenas noches");
        }
        System.out.println("La hora es "+date.getHours()+":"+date.getMinutes());
    }
}
