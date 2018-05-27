
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

void writeCommandsOutputTo(std::string command, std::ofstream& outfile){
  FILE *pp;
  command += " 2>&1" ; 
  writeLine("---------------------------------------------------------\n", outfile); 
  writeLine("Executing command: ", outfile); 
  writeLine(command, outfile);
  writeLine("\n---------------------------------------------------------\n", outfile); 
  pp = popen(command.c_str(), "r");
  if (pp != NULL) {
    while (1) {
      char *line;
      char buf[1000];
      line = fgets(buf, sizeof buf, pp);
      if (line == NULL) break;
      // printf("%s", line); /* line includes '\n' */
      writeLine(line, outfile);
    }
    pclose(pp);
  }
  writeLine("---------------------------------------------------------\n\n\n", outfile); 
}

int main(void) {
  // Read and write to binary file
  std::string fileName = "hardwareInfo.txt" ; 
  std::ofstream outfile( fileName , std::ios::binary) ; 

  writeCommandsOutputTo("ifconfig", outfile) ; 
  writeCommandsOutputTo("/sbin/ifconfig", outfile) ; 
  writeCommandsOutputTo("more /proc/cpuinfo", outfile) ; 
  writeCommandsOutputTo("more /proc/meminfo", outfile) ; 
  writeCommandsOutputTo("df", outfile) ; 
  writeCommandsOutputTo("cat /etc/*-release", outfile) ; 
  writeCommandsOutputTo("lsb_release -a", outfile) ; 
  writeCommandsOutputTo("uname -a", outfile) ; 



  printf("Hardware information collected in ");
  printf("%s!\n", fileName.c_str());
  printf("Done!\n");
  outfile.flush() ;
  outfile.close() ;



  // // Read the binary file
  // readFile("binary.txt");


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

