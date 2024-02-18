

package gramatica.trigonometrica;

import java.util.Stack;

public class Evaluador {
    private final Tokens tokenV;
    private Tokens tokenE;
    private String currentToken;
    private String expresion;
    private Stack<String> op;
    private Stack<String> salida;
    private Stack<String> solucion;
    private String[] O;
    private String[] F;
    
    
    public Evaluador(Tokens token)
    {
        this.tokenV = token;
        this.expresion = "";
        this.op = new Stack<>();
        this.salida = new Stack<>();
        this.solucion = new Stack<>();
        this.O = new String[]{"+","-","*","/","^"};
        this.F = new String[]{"Sen","Cos","Tan","Csc","Sec","Cot"};
        
        avance(false);
    }
    
    private void avance(boolean type)
    {
        if(type == false)
        {
            currentToken = tokenV.obtenerSigToken(true, true);
        }
        else 
        {
            currentToken = tokenE.obtenerSigToken(true, false);
        }
    }
    
    private void setToken(String expresion)
    {
        tokenE = new Tokens(expresion, true);
    }
    
    private boolean perteneceA(String[] O)
    {
        for (String O1 : O)
        {
            if(currentToken.equals(O1))
            {
                return true;
            }
        }
        return false;
    }
    
    private boolean value(Double argumento)
    {
        int i = 1;
        while(argumento / i > 90 && argumento / i != 90)
        {
            i = i + 2;
        }
        if(argumento / i == 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public void conversión()
    {
        boolean done = true;
        while(done)
        {
            switch(currentToken)
            {
                case "(":
                    while(!op.peek().equals(")"))
                    {
                        salida.push(op.pop());
                    }
                    op.pop();
                    avance(false);
                break;

                case ")":
                    op.push(currentToken);
                    avance(false);
                break;
                
                case "┤":
                    while(!op.empty())
                    {
                        salida.push(op.pop());
                    }
                    done = false;
                break;
                
                default:
                    if(perteneceA(O))
                    {
                        if(op.empty())
                        {
                            op.push(currentToken);
                            avance(false);
                        }
                        else if((currentToken.equals("+") || currentToken.equals("-")) && (op.peek().equals("*") || op.peek().equals("/") || op.peek().equals("^")))
                        {
                            salida.push(op.pop());
                            op.push(currentToken);
                            avance(false);
                        }
                        else if((currentToken.equals("*") || currentToken.equals("/")) && op.peek().equals("^"))
                        {
                            salida.push(op.pop());
                            op.push(currentToken);
                            avance(false);
                        }
                        else
                        {
                            op.push(currentToken);
                            avance(false);
                        }
                    }
                    else
                    {
                        salida.push(currentToken);
                        avance(false);
                    }
                break;
            }
        }
        
        while(!salida.empty())
        {
            expresion = expresion + salida.pop();
        }
        setToken(expresion);
        avance(true);
    }
    
    public void evaluacion()
    {
        boolean done = true;
        while(done)
        {
            if(perteneceA(O))
            {
                switch(currentToken)
                {
                    case "+":
                        solucion.push(String.valueOf(Double.parseDouble(solucion.pop()) + Double.parseDouble(solucion.pop())));
                    break;
                    case "-":
                        solucion.push(String.valueOf(Double.parseDouble(solucion.pop()) - Double.parseDouble(solucion.pop())));
                    break;
                    case "*":
                        solucion.push(String.valueOf(Double.parseDouble(solucion.pop()) * Double.parseDouble(solucion.pop())));
                    break;
                    case "/":
                        solucion.push(String.valueOf(Double.parseDouble(solucion.pop()) / Double.parseDouble(solucion.pop())));
                    break;
                    default:
                        solucion.push(String.valueOf(Math.pow(Double.parseDouble(solucion.pop()), Double.parseDouble(solucion.pop()))));
                    break;
                }
                avance(true);
            }
            else if(perteneceA(F))
            {
                double resultado = 0;
                double argumento = Double.parseDouble(solucion.pop());
                double rad;
                        
                switch(currentToken)
                {
                    case "Sen":
                        rad = Math.toRadians(argumento);
                        resultado = Math.sin(rad);
                        solucion.push(String.valueOf(resultado));
                    break;
                    
                    case "Cos":
                        rad = Math.toRadians(argumento);
                        resultado = Math.cos(rad);
                        solucion.push(String.valueOf(resultado));
                    break;
                    
                    case "Tan":
                        if(value(argumento) == false)
                        {
                            if(argumento % 180 != 0)
                            {
                                rad = Math.toRadians(argumento);
                                resultado = Math.tan(rad);
                                solucion.push(String.valueOf(resultado));
                            }
                            else
                            {
                                solucion.push("0");
                            }
                        }
                        else
                        {
                            System.out.println("ERROR: Valor indefinido.");
                            done = false;
                        }
                    break;
                    
                    case "Csc":
                        if(argumento % 180 != 0)
                        {
                            rad = Math.toRadians(argumento);
                            resultado = 1/Math.sin(rad);
                            solucion.push(String.valueOf(resultado));
                        }
                        else
                        {
                            System.out.println("ERROR: Valor indefinido.");
                            done = false;
                        }
                    break;
                    
                    case "Sec":
                        if(value(argumento) == false)
                        {
                            rad = Math.toRadians(argumento);
                            resultado = 1/Math.cos(rad);
                            solucion.push(String.valueOf(resultado));
                        }
                        else
                        {
                            System.out.println("ERROR: Valor indefinido.");
                            done = false;
                        }
                    break;
                    
                    case "Cot":
                        if(argumento % 180 != 0)
                        {
                            if(value(argumento) == false)
                            {
                                rad = Math.toRadians(argumento);
                                resultado = Math.cos(rad)/Math.sin(rad);
                                solucion.push(String.valueOf(resultado));
                            }
                            else
                            {
                                solucion.push("0");
                            }
                        }
                        else
                        {
                            System.out.println("ERROR: Valor indefinido.");
                            done = false;
                        }
                    break;
                }
                avance(true);
            }
            else if(currentToken.equals("┤"))
            {
                System.out.println("El valor que surge de evaluar la expresión es: " + Double.parseDouble(solucion.pop()));
                done = false;
            }
            else if(currentToken.equals("."))
            {
                System.out.println("Se encontró (.)");
                avance(true);
            }
            else
            {
                solucion.push(currentToken);
                avance(true);
            }
        }
    }
}




