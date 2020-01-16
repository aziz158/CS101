//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa3

import java.util.*;
import java.lang.*;

public class List<T>{
	
	private class Node
	{
		T data;
		Node next;
		Node prev;
		
		boolean equals(Node N)
		{
			if(this.data.equals(N.data)){ return true;}
			else{ return false; }
		}
		
		Node(T data) 
		{
			this.data = data; 
			this.next = null; 
			this.prev = null;
		}
		public String toString()
		{
			return String.valueOf(data);
		}
	}
	
	
	private Node head;
	private Node tail;
	private Node cursor;
	private int length;
	private int index;
		
	List() {
		this.head = null;
		this.tail = null;
		this.length = 0;
		this.cursor = null;
		this.index = -1;
	}
	
	int index(){ return this.index; }
	T get() 
	{	
		if(this.isEmpty() || this.index < 0)
		{
			throw new RuntimeException("List Error: get() called on empty List");
		}
		return this.cursor.data;
	}
	
	int length(){ return this.length;}
	T front() 
	{ 
		if(this.isEmpty())
		{
			throw new RuntimeException("List Error: front() called on empty List");
		}
		return this.head.data;
	}
	
	T back() 
	{
		if(this.isEmpty())
		{
			throw new RuntimeException("List Error: back() called on empty List");
		}
		return this.tail.data;
	}
	
	boolean isEmpty() 
	{
		return this.length <= 0;
	}
	
	boolean CursorIsEmpty() { return this.index == -1;}
	
	void append(T data)
	{
		Node newNode = new Node(data);
		
		if(this.isEmpty())
		{
			this.head = newNode;
			this.tail = newNode;
			newNode.next = null;
			newNode.prev = null;
		}
		else
		{
			newNode.prev = this.tail;
			newNode.next = null;
			this.tail.next = newNode;
			this.tail = newNode;
		}
		this.length += 1;
	}
	
	void prepend(T data)
	{
		Node newNode = new Node(data);
		if(this.isEmpty())
		{
			this.head = newNode;
			this.tail = newNode;
			newNode.next = null;
			newNode.prev = null;
		}
		else
		{
			newNode.next = this.head;
			newNode.prev = null;
			this.head.prev = newNode;
			this.head = newNode;
		}
		if(!this.CursorIsEmpty()) {this.index += 1; }
		this.length += 1;
	}
	//If there is nothing print nothing
	public String toString()
	{
		Node temp = this.head;
		String output = "";
		
		if(this.isEmpty())
		{
			return output;
		}
		else
		{
			for(int i = 0; i < this.length; i++)
			{
				output += temp.toString() + " ";
				temp = temp.next;
			}		
			return output;
		}
	}
	
	void moveFront()
	{
		if (!this.isEmpty())
		{
			this.cursor = this.head;
			this.index = 0;
		}
	}
	
	void moveBack()
	{
		if (!this.isEmpty())
		{
			this.cursor = this.tail;
			this.index = length - 1;
		}
	}
	
	
	void movePrev()
	{
		if(this.index != -1)
		{	
			if(this.cursor == this.head)
			{
				this.index = -1;
				this.cursor = null;
			}
			else
			{
				this.cursor = this.cursor.prev;
				this.index = this.index - 1;
			}
		}
	}
	
	void moveNext()
	{
		if(this.index != -1)
		{
			if(this.cursor == this.tail)
			{
				this.index = -1;
				this.cursor = null;
			}
			else
			{
				this.cursor = this.cursor.next;
				this.index = this.index + 1;
			}
		}
	}
	
	
	 public boolean equals(Object x){
	      boolean eq  = false;
	      List L;
	      Node N, M;

	      if(x instanceof List){
	         L = (List)x;
	         N = this.head;
	         M = L.head;
	         eq = (this.length==L.length);
	         while( eq && N!=null ){
	            eq = N.equals(M);
	            N = N.next;
	            M = M.next;
	         }
	      }
	      return eq;
	   }
	
	void insertBefore(T data)
	{
		if(this.isEmpty() || this.index < 0)
		{
			throw new RuntimeException("List Error: insertBefore() called on empty List");
		}
		
		Node newNode = new Node(data);
		this.length += 1;
		
		if(this.cursor == this.head)
		{
			newNode.next = this.cursor;
			newNode.prev = null;
			this.cursor.prev = newNode;
			this.head = newNode;
			this.index +=1;
		}
		else
		{
			newNode.next = this.cursor;
			newNode.prev = this.cursor.prev;
			this.cursor.prev.next = newNode;
			this.cursor.prev = newNode;
			if(this.cursor == this.tail)
			{this.index = this.length - 1; }	
			else {this.index += 1;}
		}
		
		
	}
	
	void insertAfter(T data)
	{
		if(this.isEmpty() || this.index < 0)
		{
			throw new RuntimeException("List Error: insertAfter() called on empty List");
		}
		
		Node newNode = new Node(data);
		if(this.cursor == this.tail)
		{
			newNode.prev = this.cursor;
			newNode.next = null;
			this.cursor.next = newNode;
			this.tail = newNode;
		}
		else
		{
			newNode.prev = this.cursor;
			newNode.next = this.cursor.next;
			this.cursor.next.prev = newNode;
			this.cursor.next = newNode;
			if(this.cursor == this.head)
			{ this.index = 0;}
		}
		this.length += 1;
		
	}
	
	void deleteFront()
	{
		if(this.isEmpty())
		{
			throw new RuntimeException("List Error: deleteFront() called on empty List");
		}
		
		if(this.length == 1)
		{
			this.clear();
		}
		else if(this.cursor == this.head)
		{ 
			this.delete();
		} 
		else
		{
			this.head = this.head.next;
			this.head.prev.next = null;
			this.head.prev = null;
			this.length -= 1;
			if(!this.CursorIsEmpty()) {this.index -= 1;}
		}
	}
	
	void deleteBack()
	{
		if(this.isEmpty())
		{
			throw new RuntimeException("List Error: deleteBack() called on empty List");
		}
		
		if(this.length == 1)
		{
			this.clear();
		}
		else if(this.tail == this.cursor)
		{
			this.delete();
		}
		else
		{
			this.tail = this.tail.prev;
			this.tail.next.prev = null;
			this.tail.next = null;
			this.length -= 1;
		}
	}
	
	void delete()
	{
		if(this.isEmpty() || this.index < 0)
		{
			throw new RuntimeException("List Error: delete() called on empty List");
		}
		
		if(this.length() == 1)
		{
			this.clear();
		}else if(this.cursor == this.head)
		{
			this.cursor.next.prev = null;
			this.head = this.cursor.next;
			this.cursor.next = null;
			this.cursor.prev = null;
			this.length -= 1;
			this.index = -1;
		} else if(this.cursor == this.tail)
		{
			this.cursor.prev.next = null;
			this.tail = this.cursor.prev;
			this.cursor.next = null;
			this.cursor.prev = null;
			this.length -= 1;
			this.index = -1;
		} else 
		{	
			this.cursor.next.prev = this.cursor.prev;
			this.cursor.prev.next = this.cursor.next;
			this.cursor.next = null;
			this.cursor.prev = null;
			this.length -= 1;
			this.index = -1;
		}
	}
	
	void clear()
	{
		this.head = null;
		this.tail = null;
		this.length = 0;
		this.cursor = null;
		this.index = -1;
	}
	
}
