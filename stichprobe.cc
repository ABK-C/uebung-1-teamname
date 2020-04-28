#include <cmath>
#include <fstream>
#include <iostream>

int main() {
  // mittelwert
  std::ifstream dataIn("datensumme.txt");
  int summe = 0;
  int n = 0;
  while (!dataIn.eof()) {
    ++n;
    int a = 0;
    dataIn >> a;
    summe = summe + a;
  }
  dataIn.close();
  double mittelwert = summe / n;
  std::cout << mittelwert << "\n";

  // varianz
  std::ifstream dataIn2("datensumme.txt");
  int summe2 = 0;
  while (!dataIn2.eof()) {
    int a = 0;
    dataIn2 >> a;
    int b = (a - mittelwert) * (a - mittelwert);
    summe2 = summe2 + b;
  }
  dataIn2.close();
  double varianz = summe2 / n;
  std::cout << varianz << "\n";

  // abweichung
  std::cout << sqrt(varianz) << "\n";
}
