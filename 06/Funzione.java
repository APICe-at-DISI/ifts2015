public class Funzione {

	public static void main(String[] s){
		stampa(10);
		System.out.println("-----------");
		stampa(20);
		double d1 = quadrato(10.4);
		System.out.println("d1 vale: "+d1);
	}
	
	public static void stampa(int max){
		for (int i = 1; i <= max; i++){
			System.out.println("Quadrato: "+(i*i));
		}
	}
	
	public static double quadrato(double d){
		return d*d;
	}

}