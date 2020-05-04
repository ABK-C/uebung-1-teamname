#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Berechnung des Mittelwertes
double calculateAverage(vector<double> werte) {
  double summe = 0;
  for (int i = 0; i < werte.size(); ++i) {
    summe = summe + werte[i];
  }
  return summe / werte.size();
}

// Berechung der Varianz
double calculateVar(vector<double> werte) {
  double mittel = calculateAverage(werte);
  double summe = 0;
  for (int i = 0; i < werte.size(); ++i) {
    summe = summe + (werte[i] - mittel) * (werte[i] - mittel);
  }
  return summe / werte.size();
}

int main() {
  // Datei laden
  ifstream dataIn("datensumme.txt");

  // Vektor füllen
  vector<double> messdaten;
  while (!dataIn.eof()) {
    double a = 0;
    dataIn >> a;
    messdaten.push_back(a);
  }

  // Berechnung & Ausgabe
  cout << "Mittelwert: " << calculateAverage(messdaten) << "\n";
  cout << "Varianz: " << calculateVar(messdaten) << "\n";
  cout << "Abweichung: " << sqrt(calculateVar(messdaten)) << "\n";

  // Datei schließen
  dataIn.close();
}