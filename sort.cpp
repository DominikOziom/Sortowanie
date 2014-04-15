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
/*http://www.algorytm.edu.pl/algorytmy-maturalne/sortowanie-przez-scalanie.html   scalanie*/
using namespace std;


template <typename T>
class Sortowanie{
public:
  std::vector < int > V;
  int ilosc_elementow;


  /* Sortowania();
  Sortowania(int p);
  ~Sortowania();*/

  void Sortowanie_Babelkowe(int n);
  void Sortowanie_Szybkie(int x, int y);
  void SortOdwr(int pierwszy, int ostatni);
  void Sortowanie_Scalanie(int pierwszy1, int ostatni2);

  int CzyPosortowana(int kierunek);
  void Wyswietl_Vector();
  void Zapelnij_Vector(int ilosc_elementow);
};
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

/*!
 * \brief Funkcja zapelniajaca tablice losowymi liczbami, ktorych ilosc jest zadana na wejsciu
 */
template <typename T>
void Sortowanie<T>::Zapelnij_Vector(int ilosc_elementow){
  srand(time(NULL));
  for( int i=1; i<=ilosc_elementow; i++)
    V.push_back(rand());
}
template <typename T>
void Sortowanie<T>::Wyswietl_Vector(){
  for(unsigned int i=0; i<V.size(); i++)
    cout << V[i] << endl;
}

template <typename T>
int Sortowanie<T>::CzyPosortowana(int kierunek)
{
  int licznik=0;
  int rozmiar=V.size();
  int a, i=0;
  a=V[i];
  if(kierunek==1){
    for(i;i<rozmiar-1;i++){
      a=V[i];
      licznik++;
      if (V[i+1]<a) return false;
    }}
  if(kierunek==0){
    for(i;i<rozmiar-1;i++){
      a=V[i];
      if (V[i+1]>a) return false;
    }}
  return licznik;
}

template <typename T>
void Sortowanie<T>::Sortowanie_Babelkowe(int n) {
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
void Sortowanie<T>::Sortowanie_Szybkie(int x, int y)
{
  long i, j, mid;
  i=x;
  j=y;
  int a1 = V[x];
  int a2 = V[x+1];
  int a3 = V[x+2];
  if((a1<=a2&&a2<=a3)||(a3<=a2&&a2<=a1)) mid = a2;
  if((a2<=a1&&a1<=a3)||(a3<=a1&&a1<=a2)) mid = a1;
  if((a2<=a3&&a3<=a1)||(a1<=a3&&a3<=a2)) mid = a3;
  //mid=V[(x+y)/2];
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
  if(x<j) Sortowanie_Szybkie(x, j);
  if(i<y) Sortowanie_Szybkie(i, y);
}


template <typename T>
void Sortowanie<T>::Sortowanie_Scalanie(int pierwszy1, int ostatni2)
{
  int i2, i1=pierwszy1;
  int i=pierwszy1;
  T *Tpom=new int[V.size()];
  int pierwszy2=(pierwszy1+ostatni2+1)/2;
  i2=pierwszy2;
  if(pierwszy2-pierwszy1>1) Sortowanie_Scalanie(pierwszy1,pierwszy2-1);
  if(ostatni2-pierwszy2>0) Sortowanie_Scalanie(pierwszy2,ostatni2);

  for(i=pierwszy1;i<=ostatni2;i++){
    if((i1==pierwszy2)||((i2<=ostatni2)&&(V[i1]>V[i2]))){
      Tpom[i]=V[i2];
      i2+=1;}
    else{
      Tpom[i]=V[i1];
      i1+=1;}}
  for(i=pierwszy1;i<=ostatni2;i++)
    V[i]=Tpom[i];
  delete Tpom; Tpom=NULL;
}




template <typename T>
void Sortowanie<T>::SortOdwr(int pierwszy, int ostatni)
{
  int piwot, p, a;
  int i=((pierwszy+ostatni)/2);   //indeks wartosc piwota

  piwot=V[i];

    p=a=ostatni;
    swap(V[i],V[pierwszy]);
    for(a=ostatni;a>pierwszy;a--){      // POROWNYWANIE Z PIWOTEM
      if(piwot>(V[a])){
	swap(V[p],V[a]);
	p-=1;
      }}                                // DO TEGO MOMENTU
    swap(V[p],V[pierwszy]); //Koncowa zmiana piwota z elementem p
  

  if(pierwszy<p-1) SortOdwr(pierwszy,p-1); //sortowanie pierwszej polowy
  if(p+1<ostatni) SortOdwr(p+1,ostatni);   //sortowanie drugiej polowy
}



//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

int main(){ 
  cout << "##################"<< endl;

  Sortowanie<int> *S=new Sortowanie<int>;

  double difference;
  timeval start, stop;
  int licznik=0;
  //cout << "Ile elementow ma miec wektor?" << endl;
  //cout << "-> ";
  //cin >> S->ilosc_elementow;
  //cout << endl;
  int tab[5]={4096, 16384, 65536, 262144, 1048576};
  //int tab[5]={4, 16, 65, 262, 1048};

  S->ilosc_elementow = tab[1];
 

  S->Zapelnij_Vector(S->ilosc_elementow);
  int rozmiar = S->V.size();
  //S->Sortowanie_Szybkie(0, rozmiar);
  S->SortOdwr(0, rozmiar);
  //S->Wyswietl_Vector();
  cout << "#################" << endl;
  gettimeofday(&start,NULL);
  S->Sortowanie_Babelkowe(rozmiar);
  S->Sortowanie_Scalanie(0, rozmiar);
  S->Sortowanie_Szybkie(0, rozmiar);
  //S->Wyswietl_Vector();
  gettimeofday(&stop,NULL);
  licznik = S->CzyPosortowana(1);
  cout << licznik << endl;
  cout << "zakonczono prace" << endl;

  difference = (stop.tv_sec - start.tv_sec)*1000.0;
  difference += (stop.tv_usec - start.tv_usec) / 1000.0;
  //difference = (end - start) / (double)CLOCKS_PER_SEC;  

  cout << "ilosc elementow" <<"  "<< "czas pracy [ms]" << endl;
  cout << S->ilosc_elementow <<"                 "<< difference << endl;
  cout << "##################"<< endl;
  /////////////////////////////////////////////////////////////////////////////////////
 
  return 0;
}
