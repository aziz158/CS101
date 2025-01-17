
import java.lang.*;
import java.util.*;
import java.io.*;

public class Lex {
	
	private String filename;
	private int numberofLines;
	private String[] stringArray;
	
	Lex()
	{this.filename = null;}
	
	Lex(String filename)
	{ this.filename = filename;}
	
	void ReadIn()
	{
		try{
    		File file = new File(this.filename);
    		if(file.exists())
    		{
    		    FileReader fileReader = new FileReader(file);
    		    LineNumberReader lineNumberReader = new LineNumberReader(fileReader);   
    		    int n = 0;
    	            while (lineNumberReader.readLine() != null){n++;}  	 
    	            System.out.println("Total number of lines : " + n);
    	            lineNumberReader.close();
    	            this.numberofLines = n;
    	        this.stringArray = new String[n];
    	        Scanner scan = new Scanner(new File(this.filename));
    	        int index = 0;
    	        while(scan.hasNext())
    	        {
    	        	this.stringArray[index] = scan.next();
    	        	index++;
    	        }
    		}
    		else
    		{System.out.println("File does not exists!");}	
    	}
		catch(IOException exception)
		{exception.printStackTrace();}
	}
	
	void Output()
	{
		List output = new List();
		output.append(0);
		output.moveFront();
		for(int i = 1; i < this.stringArray.length; i++)
		{
			
		}
	}
	
	
}	

	
	
