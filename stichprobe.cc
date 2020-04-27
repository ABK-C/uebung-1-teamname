#include<fstream>
#include<iostream>
#include<cmath>

double mittelwert() {
  std::ifstream dataIn("datensumme.txt");

  int summe = 0;
  int n = 0;
  while (!dataIn.eof()) {
    ++n;
    int a = 0;
    dataIn >> a;
    summe = summe + a;
  }
  --n;

  dataIn.close();

  double result = summe / n;
  return result;
}

double varianz(double aritmittel) {
  std::ifstream dataIn("datensumme.txt");

  int summe = 0;
  int n = 0;
  while (!dataIn.eof()) {
    ++n;
    int a = 0;
    dataIn >> a;
    int b = (a - aritmittel) * (a - aritmittel);
    summe = summe + b;
  }
  --n;

  dataIn.close();

  double result = summe / n;
  return result;
}

int main() {
  std::cout << mittelwert() << "\n";
  std::cout << varianz(mittelwert()) << "\n";
  std::cout << sqrt(varianz(mittelwert())) << "\n";
}
