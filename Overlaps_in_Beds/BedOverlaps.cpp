// set_intersection example
#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>
#include<set>
#include <stdio.h>
#include <time.h>


#include "BedOverlaps.hpp"

using namespace std;

int  main(int argc, char *argv[]){

  if(argc <4){
    cout<<"required 3 fies as arguments (first_bed, second_bed and output file) but you passed only "<<argc<<endl;
    exit(0);  
  }
  cout<<"Output format is: intersection\t first_bed minus second_bed\t second_bed minus first_bed\t union"<<endl;
  string first_bed_file     = argv[1];
  string second_bed_file    = argv[2];
  string output_file        = argv[3];



  vector<unsigned int> *first_mappable = new vector<unsigned int>;
  first_mappable = get_coverage(first_bed_file);
  if (! is_sorted( first_mappable->begin(), first_mappable->end() ) ){
    sort( first_mappable->begin(), first_mappable->end()  );
  }
  unsigned int size_of_first_mapple = first_mappable->size();
  cout<<"size of first mapple is: "<< first_mappable->size()<<endl;

  vector<unsigned int> *second_mappable = new vector<unsigned int>;
  second_mappable = get_coverage(second_bed_file);
  if(! is_sorted(  second_mappable->begin(), second_mappable->end()  ) ){
    sort( second_mappable->begin(), second_mappable->end());
  }
  unsigned int size_of_second_mappable = second_mappable->size();
  cout<< "size of second mappable is: "<< size_of_second_mappable<< endl;

  //get common elements
  vector<unsigned int> *inter = new vector<unsigned int>;
  set_intersection(   first_mappable->begin(), first_mappable->end(),
		      second_mappable->begin(), second_mappable->end(),
		      back_inserter( *inter));
  unsigned int inter_size = inter->size();
  cout<<"inter size is: "<< inter_size<<endl;
  delete inter;

  // get difference AnotB (A\B)
  vector<unsigned int> *AnotB = new vector<unsigned int>;
  set_difference(  first_mappable->begin(), first_mappable->end(),
		      second_mappable->begin(), second_mappable->end(),
		      back_inserter( *AnotB)  );
  unsigned int size_of_AnotB = AnotB->size();
  cout<<"size of AnotB is: "<< size_of_AnotB<<endl;
  delete AnotB;
  
  //get difference BnotA (B\A)
  vector<unsigned int > *BnotA = new vector<unsigned int>;
  set_difference( second_mappable->begin(), second_mappable->end(),
		  first_mappable->begin(), first_mappable->end(),
		  back_inserter( *BnotA)  );

  unsigned int size_of_BnotA = BnotA->size();
  cout<< "size of BnotA is: "<< size_of_BnotA<<endl;
  delete BnotA;

  // //get union
  vector<unsigned int> *union_of_sets = new vector<unsigned int>;
  set_union(  first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *union_of_sets)  );

  unsigned int size_of_union = union_of_sets->size();
  cout<< "size of union is: "<< size_of_union<<endl;
  delete union_of_sets;
  delete first_mappable;
  delete second_mappable;
 



  //write result int the ouput file
  write_overalps_into_a_file(output_file, inter_size,size_of_union, size_of_AnotB, size_of_BnotA);

  return 0;
}/*main*/


//////////////////////////////// functions //////////////////////////


vector<unsigned int> *get_coverage(const string file_name){
  vector<unsigned int> *pCoverage = new vector<unsigned int>;
  ifstream infile(file_name.c_str());
  string chr;
  unsigned int start, end;
  while(infile>>chr>>start>>end){
    for(unsigned int i = start; i<end+1; i++){
      pCoverage->push_back(i);
    }
  }
  infile.close();
  return pCoverage;
}/*get_coverage*/




// vector<unsigned int> get_coverage(std::string file_name){
//   vector<unsigned int> coverage;
//   ifstream infile(file_name.c_str());
//   string chr;
//   int start, end;
//   while(infile>>chr>>start>>end){
//     for(int i = start; i<end+1;i++){
//       coverage.push_back(i);
//     }
//   }
//   return coverage;
// }/*get_coverage*/

void write_overalps_into_a_file(string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a){
  ofstream myfile;
  myfile.open(output_file);
  
  myfile<<intersection<<"\t"<<a_minus_b<<"\t"<<b_minus_a<<"\t"<<uni<<endl;
  myfile.close();
}/*write_overalps_into_a_file*/




