#include <fstream>
#include <iostream>

int main() {
  std::ifstream dataIn("daten.txt");
  std::ofstream dataOut("datensumme.txt");

  for (int i = 0; i < 234; ++i) {
    int x;
    int y;
    dataIn >> x;
    dataIn >> y;
    dataOut << x+y;

    if (i < 233) {
      dataOut << "\n";
    }
  }

  dataOut.close();
  dataIn.close();
}
