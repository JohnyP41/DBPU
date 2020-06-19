#include <iostream>
#include <fstream>
using namespace std;

int main() {
 std::fstream fs;
  fs.open ("plik.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  fs.close();
  
  return 0;
}
