/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */
import java.util.Stack;
import static javax.management.Query.or;


class clase1 {
    public static void main (String args[]){
        ArgsTokenMgr tm = new ArgsTokenMgr(args);
        G1Parser parser = new G1Parser(tm);
        parser.parse();
        //String palabras = tm.getNextToken2();
        char palabra2 = tm.getNextToken();
        System.out.println(palabra2);
    }
}
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

stk.pop();: desapile 
*/

class ArgsTokenMgr{
    private int index;
    String input;

    public ArgsTokenMgr(String args[]){
        if(args.length > 0)
            input = args[0];
        else
            input = "1";
        index = 0;
        System.out.println("Entrada = " + input);
    }

    public char getNextToken(){
        if(index < input.length())
            return input.charAt(index++);
        else
            return '#';
    }
    public String getNextToken2(){
        String[] identidades = input.split(" "); // intentando contar palabras
        if(index < identidades.length)
            return identidades[index++];
        else
            return "##";
    }
}

class G1Parser {
    private ArgsTokenMgr tm; 
    private Stack<Character> stk; 
    private char currentToken; 
    private String currentToken2;

    public G1Parser (ArgsTokenMgr tm) {
        this.tm = tm;
        avance();
        stk = new Stack<Character>();
        stk.push('$');  
        stk.push('E');
    }

    private void avance(){
        currentToken = tm.getNextToken();
        currentToken2 = tm.getNextToken2();
        
    }

    public void parse(){
        int [] numero = {0,1,2,3,4,5,6,7,8,9};
        boolean done = false;

        while(!done){
            switch(stk.peek()){
                case 'E':
                    for (int i = 0; i < numero.length; i++) {
                        if (currentToken == numero[i] || currentToken2 == "sin(" || currentToken2 == "cos(" || currentToken2 == "tan(" || currentToken == '('){
                        stk.push('E'); 
                        stk.push('T');
                    }
                    else
                        done = true;
                    }
                    
                    break;

                case 'Z': //Z = E prima
                    if (currentToken == '+' || currentToken == '-'){
                        stk.push('E'); //Reemplace
                        stk.push('T');
                        avance();
                    }
                    else if(currentToken == '#'){
                        stk.pop(); 
                    }
                    else
                        done = true;
                    break;
                    
                case 'T':
                    for (int i = 0; i < numero.length; i++) {
                        if (currentToken == numero[i] || currentToken == 'x' || currentToken2 == "sin(" || currentToken2 == "cos(" || currentToken2 == "tan(" || currentToken == '('){
                            stk.push('Z'); // G= T prima
                            stk.push('P');
                        }
                        else
                            done = true;
                }
                break;
                    
                case 'G':  // G = T prima
                    if (currentToken == '*' || currentToken == '/'){
                        stk.push('Z'); 
                        stk.push('P');
                        avance();
                    }
                    else if(currentToken == '#'){
                        stk.pop(); 
                    }
                    else
                        done = true;
                    break;
                    
                case 'P':
                    for (int i = 0; i < numero.length; i++) {
                        if (currentToken == numero[i] || currentToken == 'x' || currentToken2 == "sin(" || currentToken2 == "cos(" || currentToken2 == "tan(" || currentToken == '('){
                        stk.push('C'); // C = P prima
                        stk.push('F');
                        }
                        else
                            done = true;
                }
                break;
                    
                case 'C': // C = P prima
                    if (currentToken == '^'){
                        stk.push('C'); 
                        stk.push('F');
                        avance();
                    }
                    else if(currentToken == '#'|| currentToken2 == "##"){
                        stk.pop(); 
                    }
                    else
                        done = true;
                    break;
                    
                case 'F':
                for (int i = 0; i < numero.length; i++) {
                    if (currentToken == numero[i] || currentToken == 'x'){
                        stk.pop();
                        avance();
                    }else{
                        for (int k = 0; k < numero.length; k++) {
                            if (currentToken == numero[k] || currentToken == 'x' || currentToken2 == "sin(" || currentToken2 == "cos(" || currentToken2 == "tan(" || currentToken == '('){
                                stk.push(')'); 
                                stk.push('E');
                                avance();
                        }else
                            done = true;}
                    }
                }
                    
                    break;
                    
                case ')':
                    if (stk.peek().charValue()==currentToken){
                        stk.pop();
                        avance();
                    }
                    else
                        done = true;
                    break;

                case '$':
                    done = true;
                    break;
            }
            done = true;
        }

        if (currentToken=='#' && stk.peek()=='$'&& currentToken2 == "##" )
            System.out.println("Acepte");
        else
            System.out.println("Rechace");
    }
}