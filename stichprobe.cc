#include<fstream>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//Berechnung des Mittelwertes
double calculateAverage(vector<double> werte)
{
  double summe = 0;
  for (int i=0; i<werte.size(); ++i)
  {
    summe=summe+werte[i];
  }
  return summe/werte.size();
}

//Berechung der Varianz
double calculateVar(vector<double> werte)
{
  double mittel = calculateAverage(werte);
  double summe = 0;
  for (int i=0; i<werte.size(); ++i)
  {
    int a = pow(werte[i]-mittel,2);
    summe=summe+a;
  }
  return summe/werte.size();
  return 0;
}



int main() {
//Datei laden
ifstream dataIn("datensumme.txt");

//Vektor füllen
vector<double> messdaten;
while (!dataIn.eof())
{
double a=0;
dataIn>>a;
messdaten.push_back(a);
}

//Berechnung & Ausgabe
cout<<calculateAverage(messdaten)<<"\n";
cout<<calculateVar(messdaten)<<"\n";
cout<<sqrt(calculateVar(messdaten))<<"\n";

//Datei schließen
dataIn.close();
}