
import java.util.*;

interface  Libreria{
	void mostrarLibros();
	void mostrarOrdenamientoPorAutor();
	Libro buscarLibroPorTitulo(String titulo);
	LinkedList<Libro> buscarLibroPorAutor(String autor);
	void agregarLibro(Libro libro);
	void agregarLibro(ArrayList<Libro> l);
	void eliminarLibrosPorAutor(String autor);
	void eliminarLibrosPorISBN(String autor);
}

class Libro{
	String Titulo;
	String Autor;
	String ISBN ;
	//La fecha es problematica
	GregorianCalendar calendar = new GregorianCalendar();
	int year;
	int mes;
	int dia;
	String numeroDeEdicion;
	String Resumen;
    String Fecha;

	public Libro(String titulo,String autor,String isbn, Date fecha,String num, String Res){
		Titulo=titulo;
		Autor=autor;
		ISBN=isbn;
		numeroDeEdicion=num;
		Resumen=Res;
		calendar.setTime(fecha);
		year = calendar.get(Calendar.YEAR);
		mes = calendar.get(Calendar.MONTH); // empieza desde 0
		dia = calendar.get(Calendar.DAY_OF_MONTH);
        String[] Meses = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
        Fecha = Integer.toString(dia) +"/"+ Meses[mes] +"/"+ Integer.toString(year);
	}
    public void print(){
        System.out.println("["+Titulo+", "+Autor+", "+ISBN+", "+Fecha+", "+numeroDeEdicion+"]");
    }

    public String getAutor(){
        return Autor;
    }
    public String getTitulo(){
        return Titulo;
    }
    public String getISBN(){
        return ISBN;
    }
}


class Gandhi implements Libreria{

    LinkedList<Libro> Almacen = new LinkedList<Libro>();
    String Sucursal;

    Gandhi( String nombreSuc ){
        Sucursal = nombreSuc;
    }



	public void mostrarLibros(){
        System.out.println("Gandhi - Sucursal: "+Sucursal+", listado de libros:\n{");
        if(!Almacen.isEmpty()){
            int i=1;
            for(Libro L: Almacen){
                System.out.print(i+".- ");
                L.print();
                i++;
            }
        }
        System.out.println("}");
	};

	public void mostrarOrdenamientoPorAutor(){
		LinkedList<Libro> A = new LinkedList<Libro>();
        A = (LinkedList) Almacen.clone();
        int n = A.size(), y, x;
        for(y=0;y<n;y++){
            for(x=1;x<n-y;x++){
                Libro Aux1 = A.get(x-1);
                Libro Aux2 = A.get(x);
                if( Aux1.getAutor().compareTo( Aux2.getAutor() ) > 0 ){
                    A.set( x-1, Aux2 );
                    A.set( x  , Aux1 );
                }
            }
        }
        System.out.println("Gandhi - Sucursal: "+Sucursal+", listado de libros ordenado por Autor:\n{");
        if(!A.isEmpty()){
            int i=1;
            for(Libro L: A){
                System.out.print(i+".- ");
                L.print();
                i++;
            }
        }
        System.out.println("}");
	};
	
	
	public static Libro BLPT(LinkedList<Libro> A, String titulo){
		if( A.isEmpty() ){
			return null;
		}
		Libro L = A.removeFirst();
		if( L.getTitulo().compareTo( titulo ) == 0 ){
			return L;
		}
		else{
			return BLPT( A, titulo );
		}
	}
	public Libro buscarLibroPorTitulo(String titulo){
		LinkedList<Libro> A = new LinkedList<Libro>();
        A = (LinkedList) Almacen.clone();
        
        return BLPT( A, titulo );
	};
	
	
	public static LinkedList<Libro> BLPA(LinkedList<Libro> A, String autor, int n){
		if( n==0 ){
			return A;
		}
		else{
			Libro Aux = A.removeFirst();
			if( autor.compareTo( Aux.getAutor() ) == 0 ){
				A.add( Aux );
				return BLPA(A, autor, n-1);
			}
			else{
				return BLPA(A, autor, n-1);
			}
		}
	}
	public LinkedList<Libro> buscarLibroPorAutor(String autor){
		LinkedList<Libro> A = new LinkedList<Libro>();
        A = (LinkedList) Almacen.clone();
        int n = A.size();
        
        return BLPA(A, autor, n);
	};
	
	public void agregarLibro(Libro libro){
		Almacen.add(libro);
	};
	
	public void agregarLibro(ArrayList<Libro> L){
		for(Libro l : L){
            Almacen.add( l );
        }
	};
	
	public void eliminarLibrosPorAutor(String autor){
		int i=0;
        for( Libro L : Almacen ){
            if(autor.compareTo(L.getAutor())==0){
                break;
            }
            i++;
        }
        Almacen.remove( i );
	};
	
	public void eliminarLibrosPorISBN(String isbn){
		int i=0;
        for( Libro L : Almacen ){
            if(isbn.compareTo(L.getISBN())==0){
                break;
            }
            i++;
        }
        Almacen.remove( i );
	};


}


class Porrua implements Libreria{
	ArrayList<Libro> Almacen = new ArrayList<Libro>();
    String Sucursal;

    Porrua( String nombreSuc ){
        Sucursal = nombreSuc;
    }



	public void mostrarLibros(){
        System.out.println("Porrua - Sucursal: "+Sucursal+", listado de libros:\n{");
        if(!Almacen.isEmpty()){
            int i=1;
            for(Libro L: Almacen){
                System.out.print(i+".- ");
                L.print();
                i++;
            }
        }
        System.out.println("}");
	};

	public void mostrarOrdenamientoPorAutor(){
		ArrayList<Libro> A = new ArrayList<Libro>();
        A = (ArrayList) Almacen.clone();
        int n = A.size(), y, x;
        for(y=0;y<n;y++){
            for(x=1;x<n-y;x++){
                Libro Aux1 = A.get(x-1);
                Libro Aux2 = A.get(x);
                if( Aux1.getAutor().compareTo( Aux2.getAutor() ) > 0 ){
                    A.set( x-1, Aux2 );
                    A.set( x  , Aux1 );
                }
            }
        }
        System.out.println("Porrua - Sucursal: "+Sucursal+", listado de libros ordenado por Autor:\n{");
        if(!A.isEmpty()){
            int i=1;
            for(Libro L: A){
                System.out.print(i+".- ");
                L.print();
                i++;
            }
        }
        System.out.println("}");
	};
	
	
	public static Libro BLPT(ArrayList<Libro> A, String titulo){
		if( A.isEmpty() ){
			return null;
		}
		Libro L = A.remove(0);
		if( L.getTitulo().compareTo( titulo ) == 0 ){
			return L;
		}
		else{
			return BLPT( A, titulo );
		}
	}
	public Libro buscarLibroPorTitulo(String titulo){
		ArrayList<Libro> A = new ArrayList<Libro>();
        A = (ArrayList) Almacen.clone();
        
        return BLPT( A, titulo );
	};
	
	
	public static ArrayList<Libro> BLPA(ArrayList<Libro> A, String autor, int n){
		if( n==0 ){
			return A;
		}
		else{
			Libro Aux = A.remove(0);
			if( autor.compareTo( Aux.getAutor() ) == 0 ){
				A.add( Aux );
				return BLPA(A, autor, n-1);
			}
			else{
				return BLPA(A, autor, n-1);
			}
		}
	}
	public LinkedList<Libro> buscarLibroPorAutor(String autor){
		ArrayList<Libro> A = new ArrayList<Libro>();
        A = (ArrayList) Almacen.clone();
        int n = A.size();
        A = BLPA(A, autor, n);
        
        LinkedList B = new LinkedList();
        while(!A.isEmpty()){
			B.add(A.remove(A.size()-1));
		}
		return B;
	};
	
	public void agregarLibro(Libro libro){
		Almacen.add(libro);
	};
	
	public void agregarLibro(ArrayList<Libro> L){
		for(Libro l : L){
            Almacen.add( l );
        }
	};
	
	public void eliminarLibrosPorAutor(String autor){
		int i=0;
        for( Libro L : Almacen ){
            if(autor.compareTo(L.getAutor())==0){
                break;
            }
            i++;
        }
        Almacen.remove( i );
	};
	
	public void eliminarLibrosPorISBN(String isbn){
		int i=0;
        for( Libro L : Almacen ){
            if(isbn.compareTo(L.getISBN())==0){
                break;
            }
            i++;
        }
        Almacen.remove( i );
	};

}



class principal{
	public static void main(String[] args){
		System.out.println("\n\nLibrerías Gandhi y Porrua\n");
        
        Date D1 = new Date();
        
        Libro L1 = new Libro("Data Structures and Algorithms","Alfred V. Aho","9780201000238",D1,"001","This book presents the data structures and algorithms that underpin much of today's computer programming. The basis of this book is the material contained in the first six chapters of our earlier work. The Design and Analysis of Computer Algorithms. We have expanded that coverage and have added material on algorithms for external storage and memory management. As a consequence, this book should be suitable as a text for a first course on data structures and algorithms. The only prerequisite we assume is familiarity with some high-level programming language such as Pascal.");
        Libro L2 = new Libro("Introduction to algorithms","Thomas H. Cormen","9780262531962",D1,"002","The updated new edition of the classic Introduction to Algorithms is intended primarily for use in undergraduate or graduate courses in algorithms or data structures. Like the first edition, this text can also be used for self-study by technical professionals since it discusses engineering issues in algorithm design as well as the mathematical aspects.\nIn its new edition, Introduction to Algorithms continues to provide a comprehensive introduction to the modern study of algorithms. The revision has been updated to reflect changes in the years since the book's original publication. New chapters on the role of algorithms in computing and on probabilistic analysis and randomized algorithms have been included. Sections throughout the book have been rewritten for increased clarity, and material has been added wherever a fuller explanation has seemed useful or new information warrants expanded coverage.\nAs in the classic first edition, this new edition of Introduction to Algorithms presents a rich variety of algorithms and covers them in considerable depth while making their design and analysis accessible to all levels of readers. Further, the algorithms are presented in pseudocode to make the book easily accessible to students from all programming language backgrounds.\nEach chapter presents an algorithm, a design technique, an application area, or a related topic. The chapters are not dependent on one another, so the instructor can organize his or her use of the book in the way that best suits the course's needs. Additionally, the new edition offers a 25% increase over the first edition in the number of problems, giving the book 155 problems and over 900 exercises that reinforce the concepts the students are learning.");
		Libro L3 = new Libro("Introduction to computer theory","Cohen","0-471-80271-9",D1,"003","Yet  we  find  today,  that  the  subjects  of  Automata  Theory,  Formal  Languages,\nand Turing machines are almost exclusively relegated to  the very advanced\nstudent. Only  textbooks  demanding intense  mathematical  sophistication discuss\nthese  topics. Undergraduate Computer Science majors are unlikely to  develop\nthe  familiarity  with  set  theory,  logic, and  the  facility  with  abstract  manipulation\nearly enough in their college careers to digest the material in the existing\nexcellent but difficult texts.");
		Libro L4 = new Libro("Compilers: principles, techniques, & tools","Alfred V. Aho","9780321486813",D1,"004","This book provides the foundation for understanding the theory and pracitce of compilers. Revised and updated, it reflects the current state of compilation. Every chapter has been completely revised to reflect developments in software engineering, programming languages, and computer architecture that have occurred since 1986, when the last edition published.  The authors, recognizing that few readers will ever go on to construct a compiler, retain their focus on the broader set of problems faced in software design and software development. Computer scientists, developers, and aspiring students that want to learn how to build, maintain, and execute a compiler for a major programming language.");
		Libro L5 = new Libro("Elements of artificial intelligence: an introduction using LISP","S. Tanimoto","9780881751130",D1,"005","The purpose of this book is to provide an up-to-date and didactically coherent introduction to the principles and programming methods of artificial intelligence. It is appropriate for an undergraduate or first-year graduate course. While it is possible for the student to get acquainted with artificial intelligence in a single quarter or semester, a sequence of two to three quarters or semesters is preferable. The author covers most of the material in two academic quarters at the University of Washington. During the first quarter, Chapters 1 through 6 or 7 are tackled, laying a foundation of symbol manipulation, knowledge representation and inference. The second quarter takes on the more advanced topics: learning, natural language understanding, vision and the integration of AI technology into expert systems.");
		
		Gandhi G1 = new Gandhi("Satelite");
		Gandhi G2 = new Gandhi("Acoxpa");
		Porrua P1 = new Porrua("Polanco");
		Porrua P2 = new Porrua("Buenavista");
		G1.agregarLibro(L1);
		G1.agregarLibro(L2);
		G1.agregarLibro(L3);
		G1.agregarLibro(L4);
		G1.agregarLibro(L5);
		G2.agregarLibro(L1);
		G2.agregarLibro(L2);
		G2.agregarLibro(L3);
		G2.agregarLibro(L4);
		G2.agregarLibro(L5);
		P1.agregarLibro(L1);
		P1.agregarLibro(L2);
		P1.agregarLibro(L3);
		P1.agregarLibro(L4);
		P1.agregarLibro(L5);
		P2.agregarLibro(L1);
		P2.agregarLibro(L2);
		P2.agregarLibro(L3);
		P2.agregarLibro(L4);
		P2.agregarLibro(L5);
		
        System.out.println("\nMostrando el listado de libros\n");
		G1.mostrarLibros();
		//G2.mostrarLibros();
		//P1.mostrarLibros();
		//P2.mostrarLibros();
		
        System.out.println("\nMostrando ordenados por autor (orden lexicografico)\n");
		//G1.mostrarOrdenamientoPorAutor();
		//G2.mostrarOrdenamientoPorAutor();
		P1.mostrarOrdenamientoPorAutor();
		//P2.mostrarOrdenamientoPorAutor();
		
        System.out.println("\nBuscando por titulo -Data Structures and Algorithms-\n");
		//G1.buscarLibroPorTitulo("Data Structures and Algorithms").print();
		G2.buscarLibroPorTitulo("Data Structures and Algorithms").print();
		//P1.buscarLibroPorTitulo("Data Structures and Algorithms").print();
		//P2.buscarLibroPorTitulo("Data Structures and Algorithms").print();
		
        System.out.println("\n\nBusqueda por Autor -Alfred V. Aho-");
		for( Libro L : P2.buscarLibroPorAutor("Alfred V. Aho") ){
			L.print();
		}
		
        System.out.println("\nEliminamos el libro con Autor -Alfred V. Aho-\n");
        G1.eliminarLibrosPorAutor("Alfred V. Aho");
        G2.eliminarLibrosPorAutor("Alfred V. Aho");
        P1.eliminarLibrosPorAutor("Alfred V. Aho");
        P2.eliminarLibrosPorAutor("Alfred V. Aho");
        
        System.out.println("\nMostrando libros para verificar que se elimino correctamente\n");
        //G1.mostrarLibros();
        G2.mostrarLibros();
        //P1.mostrarLibros();
        //P2.mostrarLibros();
        
        System.out.println("\nEliminando por ISBN -0-471-80271-9-\n");
        G1.eliminarLibrosPorISBN("0-471-80271-9");
        G2.eliminarLibrosPorISBN("0-471-80271-9");
        P1.eliminarLibrosPorISBN("0-471-80271-9");
        P2.eliminarLibrosPorISBN("0-471-80271-9");
        
        System.out.println("\nMostramos el listado para verificar que se borro correctamente\n");
        //G1.mostrarLibros();
        //G2.mostrarLibros();
        //P1.mostrarLibros();
        P2.mostrarLibros();
        System.out.println("\n\n");
        
	}
}

