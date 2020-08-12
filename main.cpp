#include <iostream>
#include <fstream>
void calcular(int TA , float Presio,char l);
void imprimir();
using namespace std;

int main() {
 //tipo de uva
 char TA;
 //tamaño de uva
 int T1; 
 //Presio
 float P;
 
 cout << "Ingrese el presio inicial: ";
 cin >> P;

 cout <<"\n___________________________________________\n";
  cout <<"Bienvenido\n";
  cout << "Que tipo de uva desea adquirir (A/B)?: ";
  cin >> TA;
  cout << "Tamaño de la Uva (1/2): ";
  
  do{cin >> T1;}while(T1>3);
  
  if(TA=='a'||TA=='A')
  {
    calcular(T1,P,'A');
  }
  else
  {
    calcular(T1,P,'B');
  }

  return 0;  
}

void calcular( int TA,float Presio,char l)
{
  ofstream Uvadatos;
  int k;
  float Ganancia;
  cout << "Ingrese los Kilogramos de Uvas: ";
  cin >> k;
   cout <<"\n___________________________________________\n";
  Uvadatos.open("Datos",ios::out);
  
  Uvadatos << "\nPresio inicial; " << Presio;
  
  Uvadatos << "\nKilogramos de uvas: " << k;
  if(l=='A')
  {
    if(TA==1)
    {
      Uvadatos << "\nTipo de Uva: A " << "\nTamaño de uva: 1";
      Presio=Presio+0.20;
      Uvadatos << "\nPresio Modificado: " << Presio;

    }
    else
    {
       Uvadatos << "\nTipo de Uva: A " << "\nTamaño de uva: 2";
      Presio=Presio+0.30;
      Uvadatos << "\nPresio Modificado: " << Presio;

    }
  }
  else
  {
    if(TA==1)
    {
      Uvadatos << "\nTipo de Uva: B " << "\nTamaño de uva: 1";
      Presio=Presio-0.30;
      Uvadatos << "\nPresio Modificado: " << Presio;

    }
    else
    {
       Uvadatos << "\nTipo de Uva: B " << "\nTamaño de uva: 2";
      Presio=Presio-0.50;
      Uvadatos << "\nPresio Modificado: " << Presio;

    }
     
  }
  Ganancia = Presio*k;
  Uvadatos <<"\nGanancia: " <<Ganancia; 
  Uvadatos.close();
  imprimir();
}
void imprimir()
{
  string texto;
  ifstream Uvasdatos;
  Uvasdatos.open("Datos",ios::in);
  while(!Uvasdatos.eof())
  {
    getline(Uvasdatos,texto);
    cout << texto << endl;
  }
  Uvasdatos.close();
}