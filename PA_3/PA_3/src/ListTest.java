//Name: Azizkhuja Asomiddinov
//CruzID: aasomidd
//Assignment: pa3



public class ListTest{
   public static void main(String[] args){
      List A = new List();
      List B = new List();
      
      for(int i=1; i<=20; i++){
         A.append(i);
      }

      B.prepend(3.7);
      B.prepend(2.99);
      B.prepend(7.21);
      B.prepend(4.31);
      B.prepend(6.69);

      System.out.println(A);
      System.out.println(B);

      B.deleteFront();
      System.out.println(B);
      B.deleteBack();
      System.out.println(B);
      
      A.moveFront();
      A.moveNext();
      A.moveNext();
      A.delete();
      System.out.println(A);

      A.moveBack();
      A.movePrev();
      A.movePrev();
      A.delete();
      System.out.println(A);

      A.moveFront();
      A.moveNext();
      A.moveNext();
      A.insertBefore(999);
      System.out.println(A.index());
      System.out.println(A);

      A.moveBack();
      A.movePrev();
      A.movePrev();
      A.insertAfter(888);
      System.out.println(A.index());
      System.out.println(A);
      System.out.println(A.front());
      System.out.println(A.back());
      System.out.println(A.get());

      
      System.out.println(A.equals(B));
      System.out.println(A.equals(A));

      System.out.println(A.length());
      System.out.println(A.isEmpty());
      A.clear();
      System.out.println(A.length());
      System.out.println(A.isEmpty());
   }
}





