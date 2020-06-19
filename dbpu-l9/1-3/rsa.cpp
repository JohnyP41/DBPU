#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;


int nwd ( int a, int b )
{
  int t;

  while( b != 0 )
  {
    t = b;
    b = a % b;
    a = t;
  };
  return a;
}


int odwr_mod ( int a, int n )
{
  int a0, n0, p0, p1, q, r, t;

  p0 = 0; p1 = 1; a0 = a; n0 = n;
  q  = n0 / a0;
  r  = n0 % a0;
  while( r > 0 )
  {
    t = p0 - q * p1;
    if( t >= 0 )
      t = t % n;
    else
      t = n - ( ( -t ) % n );
    p0 = p1; p1 = t;
    n0 = a0; a0 = r;
    q  = n0 / a0;
    r  = n0 % a0;
  }
  return p1;
}

int pot_mod ( int a, int w, int n )
{
  int pot, wyn, q;

  pot = a; wyn = 1;
  for( q = w; q > 0; q /= 2 )
  {
    if( q % 2 ) wyn = ( wyn * pot ) % n;
    pot = ( pot * pot ) % n; 
  }
  return wyn;
}




int main( )
{
  //Generowanie klucza
  const int tp [ 10 ] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
  int p, q, phi, n, e, d;

  do
  {
    p = tp [ rand( ) % 10 ];
    q = tp [ rand( ) % 10 ];
  } while( p == q );

  phi = ( p - 1 ) * ( q - 1 );
  n   = p * q;


  for( e = 3; nwd ( e, phi ) != 1; e += 2 );
  d = odwr_mod ( e, phi );
  
  //szyfrowanie M=67
  cout<<"Szyfrowanie"<<endl;
  int M=67;
  int c;
  c=pot_mod ( M, e, n );
  cout << "Dla M=67 c = " <<c<< endl;
  
  //deszyfrowanie z CRT
  cout<<"Deszyfrowanie"<<endl;
  int m1,m2,dp,dq,qinv,h,m;
  dp=d % (p-1);
  dq=d % (q-1);
  qinv=odwr_mod(q,p);
  m1=pot_mod(c,dp,p);
  m2=pot_mod(c,dq,q);
  h=(qinv*(m1-m2)) % p;
  m=(m2+h*q) % (p*q);
  cout<<"M = "<<m<<endl;
  
  if(m==M){ 
	cout<<"Poprawnie zdeszyfrowano"<<endl;
  }else{
	  cout<<"Niepoprawnie zdeszyfrowano"<<endl;
  }
  

  return 0;
} 
