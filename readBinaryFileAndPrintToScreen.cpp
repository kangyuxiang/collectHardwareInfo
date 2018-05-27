
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>
#include <stdio.h>

// for g++
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <functional>
#include <vector>
#include <unordered_set>



#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <bitset>
#include <sstream>


void writeLine(std::string line, std::ofstream& outfile){
  for (auto it: line)  {
    outfile << std::bitset<8>( it )  ;
  }
  outfile << std::endl;
}

void readLine(std::string line, std::ifstream& infile){
  std::bitset<8> digit ; 
  std::stringstream lineSS(line) ; 
  while( lineSS >> digit ){
    std::cout << static_cast<char>( digit.to_ulong() )  ; 
  }
  // std::cout << std::endl; 
}

void readFile(std::string filename, int NumLine = 100 ){
  std::ifstream infile(filename, std::ios::binary) ; 
  std::string theLine ; 
  while(getline(infile, theLine)){
    readLine(theLine, infile) ; 
  }
  std::cout << std::endl;  
  infile.close();
}


int main(int argc, char const *argv[])
{
  if (argc < 2) {
    std::cerr << " Please give your binary filename! \n" ;
    return -1; 
  }
  std::string fileName = std::string(argv[1]) ; 
  
  // // Read the binary file
  readFile(fileName);


  return 0;
}


// #include <iostream>
// #include <fstream>
// #include <string>
 
// int main() {
//     std::string filename = "Test.b";
//     {
//         std::ofstream ostrm(filename, std::ios::binary);
//         double d = 3.14;
//         ostrm.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
//         ostrm << 123 << "abc" << '\n';                      // text output
//     }
//     // read back
//     std::ifstream istrm(filename, std::ios::binary);
//     double d;
//     istrm.read(reinterpret_cast<char*>(&d), sizeof d);
//     int n;
//     std::string s;
//     istrm >> n >> s;
//     std::cout << " read back: " << d << " " << n << " " << s << '\n';
// }

