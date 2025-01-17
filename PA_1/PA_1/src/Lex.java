//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa1

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
    	            lineNumberReader.close();
    	            this.numberofLines = n;
    	        this.stringArray = new String[n];
    	        Scanner scan = new Scanner(new File(this.filename));
    	        int index = 0;
    	        while(scan.hasNext())
    	        {
    	        	this.stringArray[index] = scan.nextLine();
    	        	index++;
    	        }
    	        fileReader.close();
    	        scan.close();
    		}
    		else
    		{System.out.println("File does not exists!");}	
    	}
		catch(IOException exception)
		{exception.printStackTrace();}
	}
	
	void Output(String x)
	{
		List output = new List();
		output.append(0);
		for(int i = 1; i < this.stringArray.length; i++)
		{
			output.moveFront();
			int j = output.get();
			while(this.stringArray[i].compareTo(this.stringArray[j]) >= 0)
			{
				output.moveNext();
				if(output.index() == -1){output.append(i); break;}
				j = output.get();
			}
			
			if(output.index() >= 0) {output.insertBefore(i);}
		}
		try
		{
			PrintWriter Output = new PrintWriter(x, "UTF-8");
			output.moveFront();
			for(int i = 0; i < this.stringArray.length; i++)
			{
				Output.println(this.stringArray[output.get()]);
				output.moveNext();
			}
			Output.close();
		} catch(IOException exception)
		{ exception.printStackTrace(); }
	}
	
	public static void main(String[] args)
	{
		if(args.length != 2)
		{ 
			System.err.println("You should have exactly 2 arguments");
			System.exit(1);
		}
		
		String input = args[0];
		Lex lex = new Lex(input);
		lex.ReadIn();
		lex.Output(args[1]);
		
	}
	
	
}	

	
	
