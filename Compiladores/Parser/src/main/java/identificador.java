/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */
/*
1.	<E> - > <T><E’>
2.	<E’> - > +<T><E’>
3.	<E’> - > -<T><E’>
4.	<E’> - > λ
5.	<T> - > <P><T’>
6.	<T’> - >*<P><T’>
7.	<T’> - >/<P><T’>
8.	<T’> - > λ
9.	<P> - > <F><P’>
10.	<P’> - > ^<F><P’>
11.	<P’> - > λ
12.	<F> - >(<E>)
13.	<F> - > num|var 
14.	<F>-> sin(<E>)| cos(<E>)| tan(<E>) 

*/
import java.util.*;


public class identificador {
    
    public static void main (String args[]){
        //Construyendo el manejador del token
        ArgsTokenMgr tm = new ArgsTokenMgr(args);
        //Construyendo el parser, pasando el manejador del token
        G1Parser parser = new G1Parser(tm);
        
        
        if(!parser.parse())
        {
            System.out.println("Iniciando proceso de evaluación semántica...");

            G1Parser evaluador = new G1Parser(tm);
            System.out.println("Evaluando...");
            evaluador.parse();
        }
        else
        {
            System.out.println("Corregir secuencia...");
        }
       
    }
}

class ArgsTokenMgr{
    private int index;
    String input;

    public ArgsTokenMgr(String args[]){
        if(args.length > 0)
            input = args[0];
        else
            input = "1";
        index = 0;
        System.out.println("Entrada = ");
        
        if(input.equals("Sen"))
        System.out.println("Aceptado ");
    }

    public String getNextToken(){
        if(index < input.length())
            return input.charAt(index++)+"";
        else
            return "#";  //Fin de cadena Alt+180
    }
    public String getNextToken2(){
        String[] identidades = input.split(" "); // intentando contar palabras
        if(index < identidades.length)
            return identidades[index++];
        else
            return "##";
    }
}

//return input.charAt(index++); //retorna el proximo caracter
class G1Parser {
    private  ArgsTokenMgr tm;  //manejador de Token
    private  LinkedList<String> List; //pila para el parser
    private String currentToken; //token actual
    private String currentToken2;

    public G1Parser (ArgsTokenMgr tm) {
        this.tm = tm;
        avance();
        List = new LinkedList<>();
        List.push("$");  //Pila vacia Alt+31
        List.push("S");
    }

    private void avance(){
        currentToken = tm.getNextToken();
        currentToken2 = tm.getNextToken2();
    }

    public boolean parse(){
        //int [] numero = {0,1,2,3,4,5,6,7,8,9};
        boolean done = false;

        while(!done){
            OUTER:
            switch (List.peek()) {
                
                case "E" -> {
                        if ("sin(".equals(currentToken2) || "cos(".equals(currentToken2) || "tan(".equals(currentToken2) || currentToken == "("){
                        List.push("E"); 
                        List.push("T");
                    }
                    else
                        done = true;
                    
                    
                    break;
                }
                    
                case "E’" -> {
                    if ("+".equals(currentToken) || "-".equals(currentToken)){
                        List.push("E"); //Reemplace
                        List.push("T");
                        avance();
                    }
                    else if("#".equals(currentToken))
                        List.pop(); 
                    else
                        done = true;
                    break;
                }
                    
                case "T" -> {
                    if ("T'".equals(currentToken) || "sin(".equals(currentToken2) || "cos(".equals(currentToken2) || "tan(".equals(currentToken2) || "(".equals(currentToken)){
                            List.push("E'"); 
                            List.push("P");
                        }
                        else
                            done = true;
                }
                    
                case "T’" -> {
                    if ("*".equals(currentToken) || "/".equals(currentToken)){
                        List.push("E´"); 
                        List.push("P");
                        avance();
                    }
                    else if("#".equals(currentToken)){
                        List.pop(); 
                    }
                    else
                        done = true;
                    break;
                }
                 case "P" -> {
                        if ("T'".equals(currentToken) || "sin(".equals(currentToken2) || "cos(".equals(currentToken2) || "tan(".equals(currentToken2) || "(".equals(currentToken)){
                        List.push("P'"); 
                        List.push("F");
                        }
                        else
                            done = true;
                
                break;
                }
                case "P’" -> {
                    if ("^".equals(currentToken)){
                        List.push("P'"); 
                        List.push("F");
                        avance();
                    }
                    else if("#".equals(currentToken)|| "##".equals(currentToken2)){
                        List.pop(); 
                    }
                    else
                        done = true;
                    break;
                }   
                
                case "F" -> {
                    if ("T´".equals(currentToken)){
                        List.pop();
                        avance();
                    }else if ("T'".equals(currentToken) || "sin(".equals(currentToken2) || "cos(".equals(currentToken2) || "tan(".equals(currentToken2) || "(".equals(currentToken)){
                        List.push(")"); 
                        List.push("E");
                        avance();
                        }
                            else
                                done = true;
                    break; 
                    }
                case ")" -> {
                    if (List.peek().equals(currentToken)){
                        List.pop();
                        avance();
                    }
                    else
                        done = true;
                    break;
                }

                case "$" -> {
                   done = true;
                    break;
                }
            }    
                
            
        }

        if ("#".equals(currentToken)  && List.peek().equals("$") && "##".equals(currentToken2))
            System.out.println("Acepte");
        else
            System.out.println("Rechace");
        return done;
    }
}
