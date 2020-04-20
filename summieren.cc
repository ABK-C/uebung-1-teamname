#include <fstream>
#include <iostream>

int main() {
  std::ifstream dataIn("daten.txt");
  std::ofstream dataOut("datensumme.txt");
  
  for (int i; i < 234; ++i) {
    int x;
    int y;
    dataIn >> x;
    dataIn >> y;
    std ::cout << x << " " << y << std ::endl;
    int z = x + y;
    std ::cout << z << std::endl;
    dataOut << z << std::endl;
  }
  
  dataOut.close();
  dataIn.close();
}
