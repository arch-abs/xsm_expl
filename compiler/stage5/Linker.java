import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.*;

public class Linker{
    public static void main(String args[]){
        try{
            File fl = new File("./a.xsm");
            Scanner s = new Scanner(fl);
            
            FileWriter writer = new FileWriter("./b.xsm");
            PrintWriter print_writer = new PrintWriter(writer);

            String str, found_str;
            int i, j;

            HashMap<String, Integer> map = new HashMap<String, Integer>();
            String pattern = "[L||F][0-9]+:";
            String pattern2 = "[L||F][0-9]+";
            java.util.regex.Pattern r = Pattern.compile(pattern);
            java.util.regex.Pattern r2 = Pattern.compile(pattern2);

            Matcher m;

            for(i=0; i<8; i++)      //to make scanner ptr skip the header part
                s.nextLine();


            i=0; j=0;    

            while(s.hasNext()){
                str = s.nextLine();
                m = r.matcher(str);
                if(m.matches()){
                    map.put(str, (2056 + 2*i - 2*j));
                    System.out.println("Matched "+str+" to addr "+(2056 + 2*i - 2*j) +" "+ map.get(str));
                    j++;
                }
                i++;
            }



            s = new Scanner(fl);
            while(s.hasNext()){
                str = s.nextLine();
                m = r.matcher(str);
                if(!m.matches()){
                    m = r2.matcher(str);
                    if(m.find()){
                        found_str = m.group();
                        // System.out.println(found_str+" "+map.get(found_str));
                        str = m.replaceAll(""+map.get(found_str+":"));
                    }
                    print_writer.println(str);
                    System.out.println(str);   
                }
            }
            print_writer.close();

        }catch(Exception e){
            System.out.println("File not found "+e);
        }
    }
}