#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int A[100][100],B[100][100],C[100][100],i,j,k,s;

  cout<<"Podaj dane dla macierzy A"<<endl;

  for(i = 0; i < 100; i++)
    for(j = 0; j < 100; j ++) A[i][j]=i;

  cout<<"Podaj dane dla macierzy B"<<endl;

  for(i = 0; i < 100; i++)
    for(j = 0; j < 100; j++) B[i][j]=i;

  cout << endl;

  for(k = 0; k < 100; k++)
    for(i = 0; i < 100; i++)
    {
      s = 0;
      for(j = 0; j < 100; j++) s += A[i][k] * B[k][j];
      C[i][j] = s;
    }

  cout <<  "C = A x B:\n";
  
  for(i = 0; i < 100; i++)
  {
    for(j = 0; j < 100; j++) cout << setw(6) << C[i][j];
    cout << endl;
  }

  return 0;
}
