//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa3

public class MatrixTest{
   public static void main(String[] args){
      int i, j, n=5;
      Matrix A = new Matrix(n);
      Matrix B = new Matrix(n);

      for(i = 0; i < n; i++)
      {
      	for(j = 1; j < n+1; j++)
      	{
      		double s = (double)(i+j); 
      		A.changeEntry(i+1, j, s);
      	}
      }
      
      System.out.println(A);
      A = A.scalarMult(0.5);
      System.out.println(A.getSize());
      System.out.println(A.getNNZ());

     System.out.println(A);

     B.changeEntry(1, 1, 5);
     B.changeEntry(1, 2, 7);
     B.changeEntry(1, 3, 0);
     B.changeEntry(1, 4, 3);
     B.changeEntry(1, 5, 3);
     B.changeEntry(2, 1, 1);
     B.changeEntry(2, 2, 2);
     B.changeEntry(2, 3, 9);
     B.changeEntry(2, 4, 0);
     B.changeEntry(2, 5, 4);
     B.changeEntry(3, 1, 1);
     B.changeEntry(3, 2, 12);
     B.changeEntry(3, 3, 8);
     B.changeEntry(3, 4, 8);
     B.changeEntry(3, 5, 9);
     B.changeEntry(4, 1, 7);
     B.changeEntry(4, 2, 0);
     B.changeEntry(4, 3, 1);
     B.changeEntry(4, 4, 3);
     B.changeEntry(4, 5, 0);
     B.changeEntry(5, 1, 5);
     B.changeEntry(5, 2, 6);
     B.changeEntry(5, 3, 1);
     B.changeEntry(5, 4, 6);
     B.changeEntry(5, 5, 1);

     System.out.println(B);

     Matrix C = B.transpose();

	 System.out.println(C);

	 Matrix D = C.copy();

	 System.out.println(D); 

	 System.out.println(C.equals(D));    

	 System.out.println(C.equals(A));   

	 System.out.println(A.mult(C)); 


   }
}