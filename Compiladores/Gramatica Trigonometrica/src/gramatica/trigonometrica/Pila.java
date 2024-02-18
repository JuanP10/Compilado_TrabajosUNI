
package gramatica.trigonometrica;

import java.util.Stack;
import java.util.ArrayList;

public class Pila {
    private Tokens token;
    private Stack<String> stk;
    //
    private String[] N;
    private String[] L;
    private String[] F;
    private String currentToken;
    private ArrayList<Integer> identificadores;
    private int i;
    
    public Pila(Tokens token)
    {
        this.token = token;
        this.stk = new Stack<String>();
        this.N = new String[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        this.L = new String[]{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        this.F = new String[]{"Sen","Cos","Tan","Csc","Sec","Cot"};
        this.identificadores = new ArrayList<Integer>();
        this.i = 0;
        avance();
        stk.push("▼");
        stk.push("<S>");
    }
    
    private void avance()
    {
        currentToken = token.obtenerSigToken(false, false);
        token.incremento();
    }
    
    private boolean perteneceA(String currentToken, String[] v)
    {
        for (String v1 : v)
        {
            if (currentToken.equals(v1))
            {
                return true;
            }
        }
        return false;
    }
    
    public void introducirError(int id)
    {
        identificadores.add(id);
        i++;
    }
    
    public boolean parse()
    {
        boolean done = false;
        
        while(!done)
        {
            switch(stk.peek())
            {
                case "<S>":
                    if(currentToken.equals("(") || perteneceA(currentToken,N) || perteneceA(currentToken,L) || perteneceA(currentToken,F))
                    {
                        stk.pop();
                        stk.push("<S'>");
                        stk.push("<A>");
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(1);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<S'>":
                    if(currentToken.equals("+") || currentToken.equals("-"))
                    {
                        stk.pop();
                        stk.push("<S'>");
                        stk.push("<A>");
                        avance();
                    }
                    else if(currentToken.equals(")") || currentToken.equals("┤"))
                    {
                        stk.pop();
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/") || currentToken.equals("^"))//Error
                    {
                        stk.push("<A>");
                        identificadores.add(3);
                        //done = true;
                    }
                    else if(currentToken.equals("(") || perteneceA(currentToken, N) || perteneceA(currentToken, L) || perteneceA(currentToken,F))//Error
                    {
                        stk.push("<C>");
                        identificadores.add(4);
                    }
                break;
                
                case "<A>":
                    if(currentToken.equals("(") || perteneceA(currentToken,N) || perteneceA(currentToken,L) || perteneceA(currentToken,F))
                    {
                        stk.pop();
                        stk.push("<A'>");
                        stk.push("<B>");
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(1);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<A'>":
                    if(currentToken.equals("+") || currentToken.equals("-") || currentToken.equals(")") || currentToken.equals("┤"))
                    {
                        stk.pop();
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))
                    {
                        stk.pop();
                        stk.push("<A'>");
                        stk.push("<B>");
                        avance();
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(5);
                        //done = true;
                    }
                    else if(currentToken.equals("(") || perteneceA(currentToken, N) || perteneceA(currentToken, L) || perteneceA(currentToken,F))//Error
                    {
                        stk.push("<C>");
                        identificadores.add(4);
                    }
                break;
                
                case "<B>":
                    if(currentToken.equals("(") || perteneceA(currentToken,N) || perteneceA(currentToken,L) || perteneceA(currentToken,F))
                    {
                        stk.pop();
                        stk.push("<B'>");
                        stk.push("<C>");
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))//Error
                    {
                        stk.push(")");
                        identificadores.add(1);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<B'>":
                    if(currentToken.equals("+") || currentToken.equals("-") || currentToken.equals("*") || currentToken.equals("/") || currentToken.equals(")") || currentToken.equals("┤"))
                    {
                        stk.pop();
                    }
                    else if(currentToken.equals("^"))
                    {
                        stk.pop();
                        stk.push("<B'>");
                        stk.push("<C>");
                        avance();
                    }
                    else if(currentToken.equals("(") || perteneceA(currentToken, N) || perteneceA(currentToken, L) || perteneceA(currentToken,F))//Error
                    {
                        stk.push("<C>");
                        identificadores.add(4);
                    }
                break;
                
                case "<C>":
                    if(currentToken.equals("("))
                    {
                        stk.pop();
                        stk.push(")");
                        stk.push("<S>");
                        avance();
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.pop();
                        stk.push("<D>");
                        stk.push("<H>");
                    }
                    else if(perteneceA(currentToken,L))
                    {
                        stk.pop();
                        stk.push("<G>");
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.pop();
                        stk.push("<F>");
                        stk.push("<E>");
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))//Error
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<D>":
                    if(currentToken.equals("+") || currentToken.equals("-") || currentToken.equals("*") || currentToken.equals("/") || currentToken.equals("^") || currentToken.equals(")") || currentToken.equals("┤"))
                    {
                        stk.pop();
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.pop();
                        stk.push("<D>");
                        avance();
                    }
                    else if(currentToken.equals("("))//Error
                    {
                        stk.push("<C>");
                        identificadores.add(9);
                    }
                    else if(perteneceA(currentToken,L))
                    {
                        stk.push("<G>");
                        identificadores.add(10);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(10);
                    }
                break;
                
                case "<E>":
                    if(perteneceA(currentToken, F))
                    {
                        //System.out.println("Otra vez yo");
                        stk.pop();
                        avance();
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else if(perteneceA(currentToken,N))
                    {
                        stk.push("<D>");
                        identificadores.add(7);
                    }
                    else if(perteneceA(currentToken,L))
                    {
                        stk.push("<G>");
                        identificadores.add(7);
                    }
                    else if(currentToken.equals("("))
                    {
                        stk.push("<C>");
                        identificadores.add(7);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<F>":
                    if(currentToken.equals("("))
                    {
                        stk.pop();
                        stk.push(")");
                        stk.push("<S>");
                        avance();
                    }
                    else if(perteneceA(currentToken, L))
                    {
                        stk.pop();
                        stk.push("<G>");
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals(")"))//Error
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.push("<D>");
                        identificadores.add(11);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(11);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;

                case "<G>":
                    if(perteneceA(currentToken,L))
                    {
                        stk.pop();
                        avance();
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("("))
                    {
                        stk.push("<C>");
                        identificadores.add(12);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.push("<D>");
                        identificadores.add(12);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(12);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "<H>":
                    if(perteneceA(currentToken,N))
                    {
                        stk.pop();
                        avance();
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("("))
                    {
                        stk.push("<C>");
                        identificadores.add(10);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else if(perteneceA(currentToken, L))
                    {
                        stk.push("<G>");
                        identificadores.add(10);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(10);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case ")":
                    if(currentToken.equals(")"))
                    {
                        stk.pop();
                        avance();
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("("))
                    {
                        stk.push("<C>");
                        identificadores.add(10);
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.push("<D>");
                        identificadores.add(10);
                    }
                    else if(perteneceA(currentToken, L))
                    {
                        stk.push("<G>");
                        identificadores.add(12);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(13);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
                
                case "▼":
                    if(currentToken.equals("┤"))
                    {
                        done = true;
                    }
                    else if(currentToken.equals("+") || currentToken.equals("-"))//Error
                    {
                        stk.push("<S'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("*") || currentToken.equals("/"))//Error
                    {
                        stk.push("<A'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("^"))//Error
                    {
                        stk.push("<B'>");
                        identificadores.add(0);
                    }
                    else if(currentToken.equals("("))
                    {
                        stk.push("<C>");
                        identificadores.add(10);
                    }
                    else if(currentToken.equals(")"))
                    {
                        stk.push(")");
                        identificadores.add(8);
                    }
                    else if(perteneceA(currentToken, N))
                    {
                        stk.push("<D>");
                        identificadores.add(10);
                    }
                    else if(perteneceA(currentToken, L))
                    {
                        stk.push("<G>");
                        identificadores.add(12);
                    }
                    else if(perteneceA(currentToken,F))
                    {
                        stk.push("<E>");
                        identificadores.add(13);
                    }
                    else
                    {
                        done = true;
                        identificadores.add(2);
                    }
                break;
            }
        }
        
        if(!identificadores.isEmpty())
        {
            for (Integer identificadore : identificadores)
            {
                switch(identificadore)
                {
                    case 0:
                        System.out.println("Faltó un operando.");
                    break;
                    
                    case 1:
                        System.out.println("Se encontró un ) cuando se esperaba un operando.");
                    break;
                    
                    case 2:
                        System.out.println("Ocurrieron más o menos elementos de los esperados.");
                    break;
                    
                    case 3:
                        System.out.println("Se encontró un operador aritmético de orden 2 o 3 cuando se esperaba un +,- o la terminación de una operación ambigüa.");
                    break;
                    
                    case 4:
                        System.out.println("Faltó definir una operación de orden 1.");
                    break;
                    
                    case 5:
                        System.out.println("Se encontró ^ cuando se esperaba un operador de menor orden.");
                    break;
                    
                    case 6:
                        System.out.println("Faltó un operador, un ) o un número.");
                    break;
                    
                    case 7:
                        System.out.println("Se esperaba una función trigonométrica.");
                    break;
                    
                    case 8:
                        System.out.println("Se encontró ) cuando se esperaba definir un operando o un argumento.");
                    break;
                    
                    case 9:
                        System.out.println("Se esperaba definir una operación aritmética o un número.");
                    break;
                    
                    case 10:
                        System.out.println("Faltó un número.");
                    break;
                    
                    case 11:
                        System.out.println("Se esperaba definir una operación ambigüa o una letra.");
                    break;
                    
                    case 12:
                        System.out.println("Faltó definir una letra.");
                    break;
                    
                    case 13:
                        System.out.println("Se esperaba ).");
                    break;
                                 }
            }
            System.out.println("Compilación terminada. Corregir errores encontrados...");
            return false;
        }
        else
        {
            System.out.println("Acepte.");
            return true;
        }
    }
}




