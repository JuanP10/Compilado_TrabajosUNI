/*
1.<S> -> a<A>c<B>
2.<S> -> <B>d<S>
3.<A> -> b<S>c<B>
4.<A> -> b
*/
import java.util.*;

public class G1 {
    public static void main (String args[]){

        ArgsTokenMgr tm = new ArgsTokenMgr(args);
        G1Parser parser = new G1Parser(tm);
        parser.parse();
    }
}

class ArgsTokenMgr{
    private int index;
    String input;

    public ArgsTokenMgr(String args[]){
        if(args.length > 0)
            input = args[0];
        else
            input = "";
        index = 0;
        System.out.println("input = " + input);
    }

    public char getNextToken(){
        if(index < input.length())
            return input.charAt(index++); //retorna el proximo caracter
        else
            return '#';  //Fin de cadena Alt+180
    }
}

class G1Parser {
    private ArgsTokenMgr tm;  //manejadore de Token
    private Stack<Character> stk; //pila para el parser
    private char currentToken; //token actual

    public G1Parser (ArgsTokenMgr tm) {
        this.tm = tm;
        avance();
        stk = new Stack<Character>();
        stk.push('$');  //Pila vacia Alt+31
        stk.push('S');
    }

    private void avance(){
        currentToken = tm.getNextToken();
    }

    public void parse(){
        boolean done = false;

        while(!done){
            switch(stk.peek()){
                case 'S':
                    if (currentToken == 'a'){
                        stk.pop();  //Aplicando la producción 1
                        stk.push('B');
                        stk.push('c');
                        stk.push('A');
                        avance();
                    }
                    else if(currentToken == 'd'){
                        stk.pop();  //Aplicando la producción 2
                        stk.push('d');
                        avance();
                    }
                    else
                        done = true;
                    break;

                case 'A':
                    if (currentToken == 'b'){
                        stk.push('B');  //Aplicando la producción 3
                        stk.push('c');
                        stk.push('S');
                        //stk.push('A');
                        avance();
                    }
                    else if(currentToken == 'c'){
                        stk.pop();  //Aplicando la producción 4
                        stk.push('d');
                        avance();
                    }
                    else
                        done = true;
                    break;

                case 'a':
                case 'b':
                case 'c':
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
        }

        if (currentToken=='#' && stk.peek()=='$')
            System.out.println("Acepte");
        else
            System.out.println("Rechace");
    }
}
