#include <iostream>
#include <sys/time.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stddef.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <fstream>

/*http://edu.i-lo.tarnow.pl/inf/alg/003_sort/0024.php  -  sortowanie pozycyjne */

using namespace std;

/*!
 * \brief Funkcja zapelniajaca tablice losowymi liczbami, ktorych ilosc jest zadana na wejsciu
 */
template <typename T>
void Zapelnij_Vector(std::vector<T> & V, const int ilosc_elementow){
  srand(time(NULL));
  for( int i=1; i<=ilosc_elementow; i++)
    V.push_back(rand()% 100 + 1);
}
template <typename T>
void Wyswietl_Vector(std::vector<T> & V){
  for(unsigned int i=0; i<V.size(); i++)
    cout << V[i] << endl;
}

template <typename T>
void Sortowanie_Babelkowe(std::vector<T> & V, int n) {
  bool swapped; // Czy zamieniono w ostatnim obrocie?

  do {
    swapped = false;
    for (int i = 0; i < n - 1; ++i) {
      if (V[i] > V[i + 1]) {
	swap(V[i], V[i + 1]);
	swapped = true;
      }
    }
  } while (swapped);
}



template <typename T>
void Sortowanie_Szybkie(std::vector<T> & V, int x, int y)
{
  long i, j, mid;
  i=x;
  j=y;
  mid=V[(x+y)/2];
  do
    {
      while(V[i]<mid)
	i++;
      while(mid<V[j])
	j--;
      if(i<=j)
        {
	  swap(V[i], V[j]);
	  i++;
	  j--;
        }
    }
  while(i<=j);
  if(x<j) Sortowanie_Szybkie(V, x, j);
  if(i<y) Sortowanie_Szybkie(V, i, y);
}


template <typename T>
void Sortowanie_Scalanie(std::vector<T> & V, int pocz, int kon)
{
  long i, j, k, srodek;
      std::vector < int > wektor2;
    srodek=(pocz+kon+1)/2;
    if(srodek-pocz > 1)
        Sortowanie_Scalanie(V, pocz, srodek-1);
    if(kon-srodek > 0)
        Sortowanie_Scalanie(V, srodek, kon);
    j=pocz;
    k=srodek;
    for(i=pocz; i<=kon; i++)
        wektor2[i]=(j==srodek || (k<=kon && V[j]>V[k])) ? V[k++] : V[j++];
    for(i=pocz; i<=kon; i++)
        V[i]=wektor2[i];
    //~wektor2();
}





/*
RadixSort{ 		
	 for k := 1 to d do 		
	      for j := 1 to n do 		
	             x := k-ta cyfra od końca liczby e[j]; 		//  rozrzuć wszystkie liczby do kubełków
	           włóż e[j] do kolejki q[x]; 		 //o numerach 0,...9 ze względu na k-tą od końca cyfrę
	       od; 		 
	      for j := 0  to 9 do             		//połącz kolejki w jeden ciąg
	      przepisz zawartość kolejki q[j]
      na kolejne pozycje tablicy e ;     		//z zachowaniem kolejności elementów w kolejkach
	     od; 		
	 od;        		               
     } 	 
*/






int main(){ 
  cout << "##################"<< endl;

std::vector < int > wektor;

  double difference; 
  timeval start, stop;
  int ilosc_powtorzen;
  int ilosc_elementow;

  cout << "Ile razy ma powtorzyc algorytm?" << endl;
  cout << "-> ";
  cin >> ilosc_powtorzen;
  cout << endl;

  cout << "Ile elementow ma miec wektor?" << endl;
  cout << "-> ";
  cin >> ilosc_elementow;
  cout << endl;

  gettimeofday(&start,NULL);

  Zapelnij_Vector(wektor, ilosc_elementow);
  // Wyswietl_Vector(wektor);
  cout << "#################" << endl;
  int rozmiar=wektor.size();
  for(int i=0;i<ilosc_powtorzen;i++)
    // Sortowanie_Babelkowe(wektor, rozmiar);
    Sortowanie_Scalanie(wektor, 0, rozmiar);
  //Sortowanie_Szybkie(wektor, 0, rozmiar);

  //Wyswietl_Vector(wektor);

  gettimeofday(&stop,NULL);
  cout << "zakonczono prace" << endl;

  difference = (stop.tv_sec - start.tv_sec)*1000.0;
  difference += (stop.tv_usec - start.tv_usec) / 1000.0;
  //difference = (end - start) / (double)CLOCKS_PER_SEC;
  cout << "czas pracy programu: " << difference << "ms" << endl;
  cout << "##################"<< endl;

  /*
    fstream plik1;
    plik1.open("csv.txt");   //otwarcie pliku zrodlowego
    if ( !plik1.is_open() ) {
    cerr << "Blad otwarcia pliku do zapisu wynikow koncowych" << endl;
    }
    else{
    // plik1 << "ilosc elementow" <<"  "<< "ilosc powtorzen" <<"  "<< "czas pracy [ms]" << endl;
    plik1 << ilosc_elementow <<"                 "<< ilosc_powtorzen <<"                 "<< difference << endl;
    }
  */

  cout << "ilosc elementow" <<"  "<< "ilosc powtorzen" <<"  "<< "czas pracy [ms]" << endl;
  cout << ilosc_elementow <<"                 "<< ilosc_powtorzen <<"                 "<< difference << endl;
  cout << "##################"<< endl;
  return 0;
}
