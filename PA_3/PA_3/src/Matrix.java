//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa3

public class Matrix {
	private class Entry
	{	
		int column;
		double data;
		
		Entry(int col, double dat)
		{
			column = col;
			data = dat;
		}
		
		public String toString()
		{
			return "(" + String.valueOf(column) + ", " + String.valueOf(data)+ ")";
		}
		
		public boolean equals(Object x)
		{
		    boolean eq  = false;
		    Entry E;
		    if(x instanceof Entry)
		    {
		        E = (Entry)x;
		        eq = (this.column ==E.column && this.data == E.data);
		    }
		    return eq;
		}
		
	}
	
	private int size;
	private int NZNumbers;
	private List[] row;

	Matrix(int n)
	{
		row = new List[n];
		for(int i=0; i<n; i++)
		{
			row[i] = new List();
		}

		this.size = n;
	}
	
	int getSize()
	{
		return this.size;
	}
	
	int getNNZ()
	{
		return this.NZNumbers;
	}
	
	void changeEntry(int i, int j, double x)
	{
		Entry E = new Entry(j, x);
		
		if(x != 0)
		{	
			if(this.row[i-1].isEmpty() || this.row[i-1].length() < j)
			{ this.row[i-1].append(E); this.NZNumbers++;}
			else
			{
				this.row[i-1].moveFront();
				while(this.row[i-1].index() >= 0 )
				{
					Entry temp = (Entry)this.row[i-1].get();
					if(temp.column < E.column)
					{
						this.row[i-1].moveNext();
					}
					else
					{
						if(E.column == temp.column)
						{
							this.row[i-1].insertBefore(E);
							this.row[i-1].delete();
						}
						else
						{ this.row[i-1].insertBefore(E); this.NZNumbers++;}
						break;
					}
				}
			}
		}
		else
		{
			this.row[i-1].moveFront();
			while(this.row[i-1].index() >= 0 )
			{
				Entry temp = (Entry)this.row[i-1].get();
				if(temp.column < E.column)
				{
					this.row[i-1].moveNext();
				}
				else
				{
					if(temp.column == E.column)
					{
						this.row[i-1].delete();
						this.NZNumbers--;
					}
					break;
				}
			}
		}
	}
	
	public String toString()
	{
		String temp = "";
		for(int i = 0; i < this.size; i++)
		{
			if(this.row[i].isEmpty()) break;
			temp += String.valueOf(i+1) + ": " + this.row[i].toString() + "\n"; 
		}
		
		return temp;
	}
	
	Matrix clear()
	{
		for(int i = 0; i < this.size; i++)
		{
			this.row[i].clear();
		}
		this.NZNumbers = 0;
		
		return this;
	}
	

	
	Matrix scalarMult(double x)
	{
		Matrix N = new Matrix(this.size);
		if(x == 0)
		{ return N = this.clear();}
		else
		{
			for(int i = 0; i < this.size; i++)
			{
				this.row[i].moveFront();
				for(int j = 0; j < this.row[i].length(); j++)
				{
					
					Entry e =(Entry)(this.row[i].get());
					N.changeEntry(i+1, j+1, e.data * x);
					this.row[i].moveNext();
				}
			}
			return N;
		}
	}
	
	Matrix copy()
	{
		Matrix N = new Matrix(this.size);
		int column; 
		double data;
		
		for(int i = 0; i < this.size; i++)
		{
			this.row[i].moveFront();
			for(int j = 0; j < this.row[i].length(); j++)
			{
				Entry e = (Entry) this.row[i].get();
				data = e.data;
				column = e.column;
				N.changeEntry(i+1, column, data);
				this.row[i].moveNext();
			}
		}
		return N;
	}
	
	Matrix transpose()
	{
		Matrix N = new Matrix(this.size);
		int column; 
		double data;
		
		for(int i = 0; i < this.size; i++)
		{
			this.row[i].moveFront();
			for(int j = 0; j < this.row[i].length(); j++)
			{
				Entry e = (Entry) this.row[i].get();
				data = e.data;
				column = e.column;
				N.changeEntry(column, i+1, data);
				this.row[i].moveNext();
			}
		}
		return N;
	}
	
	/*List listAdd(List L, List M)
	{
		List N = new List();
		List L1 = L;
		List L2 = M;
		L.moveFront();
		Entry e1, e2, e3 = null, back;
		while(L1.index() >= 0 || L2.index() >= 0)
		{
			e1 = (Entry) L1.get();
			L2.moveFront();
			
			e2 = (Entry) L2.get();
			back = (Entry) M.back();
				
			if(e1.column >= back.column)
			{N.append(e1); break;}
				
			if(e1.column == e2.column)
			{
				e3.column = e1.column;
				e3.data = e1.data + e2.data;
				N.append(e3);
				break;
					
			}
			if((e1.column < e2.column && e2 != null) || e1 == null)
			{
				N.append(e1);
				L1.moveNext();
			}
			
			if((e2.column < e1.column && e1 != null) || e2 == null)
			{
				N.append(e2);
				L2.moveNext();
			}
			
				
			
		}
		
	
		return N;
	}*/
	
	Matrix add(Matrix M)
	{
		Matrix N = new Matrix(this.size);
		/*Entry e1, e2, e3 = null;
		List L1;
		List L2;
		
		if(this.equals(M))
		{
			N = M.scalarMult(2);
			return N;
		}
		else
		{
			for (int i = 0; i < this.size; i++)
			{
			/*   if(this.row[i].isEmpty())break;
				N.row[i] = this.listAdd(this.row[i], M.row[i]); }
				
				L1 = this.row[i];
				L2 = M.row[i];
				L1.moveFront();
				L2.moveFront();
				while(L1.index() >= 0 || L2.index() >= 0)
				{
					/*
					if(L1.index() == -1) e1 = null;
					else e1 = (Entry) L1.get();

					if(L2.index() == -1) e2 = null;
					else e2 = (Entry) L2.get();
					
					e1 = (Entry) L1.get();
					e2 = (Entry) L2.get();
					System.out.println(i);
					if(e1.column == e2.column && e1 != null && e2 != null)
					{
						N.changeEntry(i+1, e1.column, e1.data + e2.data);
						L1.moveNext();
						L2.moveNext();
					}
					
					if(e1.column < e2.column || e1 == null)
					{
						N.changeEntry(i+1, e1.column, e1.data);
						L1.moveNext();
					}
					
					if(e2.column < e1.column || e2 == null)
					{
						N.changeEntry(i+1, e2.column, e2.data);
						L2.moveNext();
					}
					
				}
				
			
			}
			
			/*for(int i = 0; i < this.size; i++)
			{
				this.row[i].moveFront();
				while(this.row[i].index() >= 0)
				{
					e1 = (Entry) this.row[i].get();
					M.row[i].moveFront();
					while(M.row[i].index() >= 0)
					{
						e2 = (Entry) this.row[i].get();
						if(e1.column == e2.column)
						{
							e3.column = e1.column;
							e3.data = e1.data + e2.data;
							M.row[i].delete();
						}
					}
				}
			}*/
		return N;
	}
	
	
	Matrix sub(Matrix M)
	{
		Matrix N = new Matrix(this.size);
		return N;
	}
	
	public boolean equals(Object x){
	      boolean eq  = false;
	      Matrix M;
	      Entry e1, e2;

	      if(x instanceof Matrix)
	      {
	         M = (Matrix)x; 
	         eq = (this.size==M.size);
	         if(eq == false)
	         {
	        	 return eq;
	         }
	         
	         for(int i = 0; i < this.size; i++)
	         {
	        	 if(!(this.row[i].equals(M.row[i]))) {return false;}
	         }
	      }
	      return eq;
	   }
	
	Matrix mult(Matrix M)
	{
		Matrix N = new Matrix(this.size);
		Matrix T = M.transpose();
		double dotProduct;
		
		for(int i = 0; i < this.size; i++)
		{
			for(int j = 0; j < this.row[i].length(); j++)
			{
				dotProduct = dot(this.row[i], T.row[i]); 
				N.changeEntry(i+1, j+1, dotProduct);
			}
		}
		return N;
	}
	
	double dot(List L1, List L2)
	{	
		double d = 0, p = 0;
		Entry e1, e2;
		
		L1.moveFront();
		
		while(L1.index() >= 0)
		{
			e1 = (Entry) L1.get();
			L2.moveFront();
			while(L2.index() >= 0)
			{
				e2 = (Entry) L2.get();
				if(e1.column == e2.column)
				{
					p = e1.data * e2.data;
					d += p;
					L2.moveNext();
				}
				else L2.moveNext();
			}
			L1.moveNext();
		}
		return d;
	}
	
	void makeZero()
	{
		for(int i = 0; i < this.size; i++)
		{
			this.row[i].clear();
		}
		this.NZNumbers = 0;
	}
	
}
