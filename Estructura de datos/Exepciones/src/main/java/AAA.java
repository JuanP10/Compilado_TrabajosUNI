
public class AAA {
    private String nombre;
    private int edad;

    public AAA (String nombre, int edad) throws Exception {
        this.nombre = nombre;
        if (edad < 18)
            throw new Exception("No es adulta la persona " + nombre + " porque tiene " + edad + " años.");
        this.edad = edad;
    }

    public void imprimir() {
        System.out.println(nombre + " - " + edad);
    }

    public static void main(String[] ar) {
        try {
            AAA persona1 = new AAA ("Ana", 50);
            persona1.imprimir();
            AAA persona2 = new AAA("Juan", 13);
            persona2.imprimir();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
