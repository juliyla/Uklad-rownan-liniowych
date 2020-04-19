#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main()
{
  
    ifstream plik;
    plik.open("plik"); 
    UkladRownanLiniowych   UklRown;
    plik >> UklRown;
    cout << UklRown << endl;
    plik.close();
    return 0;
  
  
}
