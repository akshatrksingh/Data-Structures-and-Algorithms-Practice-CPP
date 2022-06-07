class Solution
{
  public:
      int inSequence(int A, int B, int C)
      {
          return (A==B || C==0)? A==B: ((C>0)? (B>A && (B-A)%C == 0): (B<A && (B-A)%C == 0));
      }
};
