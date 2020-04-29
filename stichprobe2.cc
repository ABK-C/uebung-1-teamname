#include <cmath>
#include <fstream>
#include <iostream>

int main() {

  std::ifstream dataIn("datensumme.txt");
  std::ofstream dataMit("mittelwert.txt");
  std::ofstream dataVar("varianz.txt");

  while (!dataIn.eof()) {

    int wertemenge[9];
    double mittelwert = 0;
    for (int i = 0; i < 9; ++i) {
      int a = 0;
      dataIn >> a;
      wertemenge[i] = a;
      mittelwert = mittelwert + a;
    }
    mittelwert = mittelwert / 9;

    double varianz = 0;
    for (int i = 0; i < 9; ++i) {
      varianz = varianz + pow((wertemenge[i] - mittelwert), 2);
    }
    varianz = varianz / 9;

    dataMit << mittelwert << "\n";
    dataVar << varianz << "\n";
  }
  dataIn.close();
  dataMit.close();
  dataVar.close();

  std::ifstream dataMit2("mittelwert.txt");
  std::ifstream dataVar2("varianz.txt");

  double mittelmittel = 0;
  double mittelvar = 0;

  for (int i = 0; i<26; ++i)
  {
    double a = 0;
    double b = 0;
    dataMit2 >> a;
    dataVar2 >> b;
    mittelmittel = mittelmittel + a;
    mittelvar = mittelvar + b;
  }
  mittelmittel = mittelmittel / 26;
  mittelvar = mittelvar / 9;

  std::cout << mittelmittel << "\n";
  std::cout << mittelvar << "\n";
}
