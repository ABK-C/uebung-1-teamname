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
  return summe / (werte.size() - 1);
}

int main() {
  // Datei laden
  std::ifstream dataMit("mittelwerte.txt");
  std::ifstream dataVar("varianzen.txt");

  // Vektor füllen
  vector<double> mittel;
  while (!dataMit.eof()) {
    double a = 0;
    dataMit >> a;
    mittel.push_back(a);
  }
  vector<double> varianzen;
  while (!dataVar.eof()) {
    double a = 0;
    dataVar >> a;
    varianzen.push_back(a);
  }

  // Berechnung & Ausgabe
  cout << "Mittelwert: " << calculateAverage(mittel) << "\n";
  cout << "Varianz: " << calculateAverage(varianzen) << "\n";

  // Dateien schließen
  dataMit.close();
  dataVar.close();
}