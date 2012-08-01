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
  string first_bed     = argv[1];
  string second_bed    = argv[2];
  string output_file   = argv[3];
  vector<unsigned int> first_coverage = get_coverage(first_bed);
  vector<unsigned int> second_coverage = get_coverage(second_bed);
  int first_coverage_size    = first_coverage.size();
  int second_coverage_size    = second_coverage.size();
  if(!is_sorted(first_coverage.begin(), first_coverage.end())){
    sort(first_coverage.begin(), first_coverage.end());
  }
  if(!is_sorted(second_coverage.begin(), second_coverage.end())){
    sort(second_coverage.begin(), second_coverage.end());
  }

 
  //get common elements
 vector<unsigned int> intersection;
  set_intersection(first_coverage.begin(), first_coverage.end(),
		   second_coverage.begin(), second_coverage.end(),
		   back_inserter(intersection));
  unsigned int inter_size = intersection.size();
  cout<<"intetsection is: "<< inter_size<<"bps"<<endl;
 
  //get unions
  vector<unsigned int> union_of_sets;
  set_union(first_coverage.begin(), first_coverage.end(),
	    second_coverage.begin(), second_coverage.end(),
	    back_inserter(union_of_sets));
  unsigned int union_size = union_of_sets.size();  
  cout<<"union is: "<<union_size<<"bps"<<endl;

  //get difference
  vector<unsigned int> first_minus_second;
  set_difference(first_coverage.begin(), first_coverage.end(),
	    second_coverage.begin(), second_coverage.end(),
	    back_inserter(first_minus_second));
  unsigned int first_minus_second_size = first_minus_second.size();
  cout<<"number of bps in uw but not in rg is: "<<first_minus_second_size<<endl;


  //get difference
  vector<unsigned int> second_minus_first;
    set_difference(second_coverage.begin(), second_coverage.end(),
		   first_coverage.begin(), first_coverage.end(),
		   back_inserter(second_minus_first));
  unsigned int second_minus_first_size = second_minus_first.size();
  cout<<"number of bps in rg but in uw is: "<<second_minus_first_size<<endl;

  //write result int the ouput file
  write_overalps_into_a_file(output_file, inter_size,union_size, first_minus_second_size, second_minus_first_size);

  return 0;
}/*main*/


//////////////////////////////// functions //////////////////////////

vector<unsigned int> get_coverage(std::string file_name){
  vector<unsigned int> coverage;
  ifstream infile(file_name.c_str());
  string chr;
  int start, end;
  while(infile>>chr>>start>>end){
    for(int i = start; i<end+1;i++){
      coverage.push_back(i);
    }
  }
  return coverage;
}/*get_coverage*/

void write_overalps_into_a_file(string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a){
  ofstream myfile;
  myfile.open(output_file);
  
  myfile<<intersection<<"\t"<<a_minus_b<<"\t"<<b_minus_a<<"\t"<<uni<<endl;
  myfile.close();
}/*write_overalps_into_a_file*/




