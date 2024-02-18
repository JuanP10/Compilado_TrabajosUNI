
package gramatica.trigonometrica;

public class Tokens {
    private int index;
    private int n;
    private final String entrada;
    private String auxiliar;
    private String[] N;
    
    public Tokens(String secuencia, boolean tipo)//El atributo tipo indica el tipo de manejador (Parser/EvaluadorS)
    {
        if(tipo == false)//Para el parser
        {
            index = 0;
            n = 1;
            if(secuencia.length() > 0)
            {
                entrada = secuencia.substring(index);
            }
            else
            {
                entrada = "";
            }
        
            System.out.println("input = " + entrada);
        }
        else//Para el evaluador
        {
            index = secuencia.length();
            n = index - 1;
            entrada = secuencia.substring(0);
            
            System.out.println("input = " + entrada);
        }
        this.N = new String []{"0","1","2","3","4","5","6","7","8","9"};
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
    
    public String obtenerSigToken(boolean tipo, boolean truth)
    {
        if(tipo == false)//Para el parser
        {
            if(index < entrada.length())
            {
                if(entrada.substring(index, n).equals("S") || entrada.substring(index, n).equals("C") || entrada.substring(index, n).equals("T"))
                {
                    System.out.println("cadena: "+entrada.substring(index, index+3));
                    auxiliar = entrada.substring(index, index+3);
                    return auxiliar;
                }
                else
                {
                    System.out.println("cadena: "+entrada.substring(index, n));
                    auxiliar = entrada.substring(index, n);
                    return auxiliar;
                }
            }
            else
            {
                return "┤"; //fin de cadena/secuencia
            }
        }
        else//Para el evaluador. PD: Pendiente a los "index + 1"
        {
            if(index > 0)
            {
                if(entrada.substring(n - setI(2), index).equals("Sen") || entrada.substring(n - setI(2) , index).equals("Cos") || entrada.substring(n - setI(2), index).equals("Tan") || entrada.substring(n - setI(2), index).equals("Csc") || entrada.substring(n - setI(2), index).equals("Sec") || entrada.substring(n - setI(2), index).equals("Cot"))
                {
                    System.out.println("cadena: " + entrada.substring(n - 2, index));
                    auxiliar = entrada.substring(n - 2, index);
                    decremento(2);
                    return auxiliar;
                }
                else if(perteneceA(entrada.substring(n, index),N))
                {
                    int i = 0;
                    while(perteneceA(entrada.substring(setK(n - (i + 1)), index - (i + 1)),N))
                    {
                        i++;
                    }
                    //Es necesario manejar un carácter extra para saber identificar un número de otro.
                    System.out.println("cadena: " + entrada.substring(n - i, index));
                    if(truth == true)
                    {
                        auxiliar = "." + entrada.substring(n - i, index);
                    }
                    else
                    {
                        auxiliar = entrada.substring(n - i, index);
                    }
                    
                    decremento(i);//Es necesario llamar a decremento para luego no tener en cuenta valores evaluados                    
                    return auxiliar;
                }
                else if(entrada.substring(n, index).equals("."))
                {
                    System.out.println("cadena: " + entrada.substring(n, index));
                    decremento(0);
                    return ".";
                }
                else
                {
                    System.out.println("cadena: " + entrada.substring(n, index));
                    auxiliar = entrada.substring(n, index);
                    decremento(0);
                    return auxiliar;
                }
            }
            else
            {
                return "┤";
            }
        }
        
    }
    
    public void incremento()
    {
        if(auxiliar.equals("Sen") || auxiliar.equals("Cos") || auxiliar.equals("Tan") || auxiliar.equals("Csc") || auxiliar.equals("Sec") || auxiliar.equals("Cot"))
        {
            index = index + 2;
            n = n + 2;
        }
        index++;
        n++;
    }
    
    public void decremento(int i) //Para el evaluador
    {
        if(i > 0)
        {
            index = index - i;
            n = n - i;
        }
        index--;
        n--;
        System.out.println("n = " + n + " index = " + index);
    }
    
    public void setIndex()
    {
        index = entrada.length();
        n = index - 1;
    }
    
    private int setI(int i)
    {
        if(n - i >= 0)
        {
            return i;
        }
        else
        {
            return 0;
        }
    }
    
    private int setK(int i)
    {
        if(i == -1)
        {
            return 0;
        }
        else
        {
            return i;
        }
    }

}






