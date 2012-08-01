#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <time.h>



using namespace std;

int main(int argc, char *argv[]){
  time_t s_time, e_time;
  time(&s_time);
  ifstream f(argv[1]);
  if (! f.good()){
    cerr << "couldn't open file\n";
    //::exit(1);
  }/*if*/
  
  ofstream out(argv[2]);
  if (! out.good()){
    cerr<< "coudln't open output file!"<<endl;
  }/*if*/
  
  std::string chr_name1, chr_name2, trash;
  unsigned a1, b1, a2, b2;
  unsigned merged_start, merged_end;
  
  //ignore first line if it srtarts with #:
  while (f.peek() == '#'){
    std::getline(f, trash);
  }/*while*/
  
  //get the first line which doesn't start with #
  f >> chr_name1 >> a1 >> b1;
  std::getline(f, trash);
  merged_start = a1;
  merged_end   = b1;
  
  unsigned counter(0);
  unsigned counter1(0);
  
  // ignore next line if starts with #
  while (f.peek() == '#'){
    std::getline(f, trash);
  }/*while*/
  
  //get next lines
  while(f >> chr_name2 >> a2 >> b2){
    std::getline(f, trash);
    
    // check if two lines are adjacent
    if (b1 != a2){
      //std::cout << chr_name1 << ' ' << a1 << ' ' << b1 << '\n';
      //std::cout << chr_name2 << ' ' << a2 << ' ' << b2 << '\n';
      // get the end of merged feature
      merged_end = b1;
      //forget about mitocondria:
      if (chr_name1 != "chrM"){
	out << chr_name1 << "\t"<< merged_start << "\t" <<merged_end<<endl;
      }
      
      //update start and ends
      merged_start = a2;
      merged_end   = b2;
	
      counter1++;
    }/*if*/
    chr_name1 = chr_name2;
    a1 = a2;
    b1 = b2;
    while (f.peek() == '#'){
      std::getline(f, trash);
      //std::cout << trash << '\n';
    }
    counter++;
  }/*while*/
  std::cout << "read " << (counter+1) << " lines\n";
  std::cout << "read " << counter1 << " non adjacent lines\n";
  f.close();
  out.close();
  time(&e_time);

  double diff = difftime(e_time, s_time);
 
  cout<< "execution time in seconds is equal to: "<< diff <<endl;
  return 0;
}/*main*/
