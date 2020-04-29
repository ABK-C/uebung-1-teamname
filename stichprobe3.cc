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


int main() {
  // Datei laden
  ifstream dataIn("datensumme.txt");
  std::ofstream dataMit("mittelwert.txt");
  std::ofstream dataVar("varianz.txt");

  while (!dataIn.eof()) {
    // Vektor füllen
    vector<double> messdaten;
    for (int i = 0; i < 9; ++i) {
      double a = 0;
      dataIn >> a;
      messdaten.push_back(a);
    }

    // Berechnung & Speichern
    dataMit << calculateAverage(messdaten) << "\n";
    dataVar << calculateVar(messdaten) << "\n";
  }

  //Dateien schließen
  dataIn.close();
  dataMit.close();
  dataVar.close();
}