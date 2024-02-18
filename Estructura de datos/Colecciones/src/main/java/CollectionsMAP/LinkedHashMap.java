/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsMAP;
import java.util.LinkedHashMap;

/**
 *
 * @author JUAN PABLO
 */
class LinkedHashMap {
    public static void main(String[] args) {
        // create an instance of LinkedHashMap
        LinkedHashMap<String,String> lhm =new LinkedHashMap<>();  
  
        // Add mappings using put method
        lhm.put("one", "practice.geeksforgeeks.org");
        lhm.put("two", "code.geeksforgeeks.org");
        lhm.put("four", "quiz.geeksforgeeks.org");
  
        // It prints the elements in same order
        // as they were inserted
        System.out.println(lhm);
  
        System.out.println("Getting value for key 'one': " + lhm.get("one"));
  
        System.out.println("Size of the map: " + lhm.size());
  
        System.out.println("Is map empty? " + lhm.isEmpty());
  
        System.out.println("Contains key 'two'? " + lhm.containsKey("two"));
  
        System.out.println( "Contains value 'practice.geeks" + "forgeeks.org'? " + lhm.containsValue("practice"           + ".geeksforgeeks.org"));
  
        System.out.println("delete element 'one': " + lhm.remove("one"));
  
        // print mappings to the console
        System.out.println("Mappings of LinkedHashMap : "+ lhm);
        
        //Fetching key  
       System.out.println("Keys: "+lhm.keySet());  
       //Fetching value  
       System.out.println("Values: "+lhm.values());  
       //Fetching key-value pair  
       System.out.println("Key-Value pairs: "+lhm.entrySet());  
    }
            
}
