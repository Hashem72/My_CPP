// set_intersection example
#include<string>
#include<sstream>
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
    cout<<"required 3 files as arguments (first_bed, second_bed and output file) but you passed only "<<argc<<endl;
    exit(0);  
  }
  cout<<"Output format is: intersection\t first_bed minus second_bed\t second_bed minus first_bed\t union"<<endl;
  string first_bed_file     = argv[1];
  string second_bed_file    = argv[2];
  string output_file        = argv[3];

  unsigned int chr_length = (51000000-16000000);

  vector<unsigned int> *first_mappable = new vector<unsigned int>;
  first_mappable = get_coverage(first_bed_file);
  if (! is_sorted( first_mappable->begin(), first_mappable->end() ) ){
    sort( first_mappable->begin(), first_mappable->end()  );
  }
  unsigned int size_of_first_mapple = first_mappable->size();
  double coverage_percent = get_chr_coverage(size_of_first_mapple, chr_length);//(size_of_first_mapple/(double)chr_length)*100;
  
  printf( "size of first set is: %.3f\n", coverage_percent);
  


  vector<unsigned int> *second_mappable = new vector<unsigned int>;
  second_mappable = get_coverage(second_bed_file);
  if(! is_sorted(  second_mappable->begin(), second_mappable->end()  ) ){
    sort( second_mappable->begin(), second_mappable->end());
  }
  unsigned int size_of_second_mappable = second_mappable->size();
  //cout<< "size of second set  is: "<< size_of_second_mappable<< endl;
  double coverage_for_second = get_chr_coverage(size_of_second_mappable, chr_length);
  printf( "size of second set is: %.3f\n", coverage_for_second);

  //get common elements
  vector<unsigned int> *inter = new vector<unsigned int>;
  set_intersection(   first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *inter));
  unsigned int inter_size = inter->size();
  // cout<<"inter size is: "<< inter_size<<endl;
  delete inter;
  double intersection_coverage = get_chr_coverage(inter_size,chr_length);
  printf(" size of intersection %.3f\n", intersection_coverage);

  // get difference AnotB (A\B)
  vector<unsigned int> *AnotB = new vector<unsigned int>;
  set_difference(  first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *AnotB)  );
  unsigned int size_of_AnotB = AnotB->size();
  //cout<<"size of AnotB is: "<< size_of_AnotB<<endl;
  delete AnotB;
  double coverage_of_A_not_B = get_chr_coverage(size_of_AnotB,chr_length);
  printf("size of A not B is:  %.3f\n", coverage_of_A_not_B);

  //get difference BnotA (B\A)
  vector<unsigned int > *BnotA = new vector<unsigned int>;
  set_difference( second_mappable->begin(), second_mappable->end(),
  		  first_mappable->begin(), first_mappable->end(),
  		  back_inserter( *BnotA)  );

  unsigned int size_of_BnotA = BnotA->size();
  // cout<< "size of BnotA is: "<< size_of_BnotA<<endl;
  delete BnotA;
  double coverage_of_B_not_A = get_chr_coverage(size_of_BnotA,chr_length);
  printf(" size of B not A is : %.3f\n", coverage_of_B_not_A );

  // //get union
  vector<unsigned int> *union_of_sets = new vector<unsigned int>;
  set_union(  first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *union_of_sets)  );

  unsigned int size_of_union = union_of_sets->size();
  // cout<< "size of union is: "<< size_of_union<<endl;
  double coverage_of_union = get_chr_coverage(size_of_union,chr_length);
  printf("size of union is:  %.3f\n", coverage_of_union);
  delete union_of_sets;
  delete first_mappable;
  delete second_mappable;
 



  //write result int the ouput file
  write_overalps_into_a_file(output_file, inter_size,size_of_union, size_of_AnotB, size_of_BnotA);

  return 0;
}/*main*/


//////////////////////////////// functions //////////////////////////

double get_chr_coverage (unsigned int set_size, unsigned int chr_size){
  double coverage_percent = ( set_size/(double)chr_size)*100;
  return coverage_percent;
}/*get_coverage*/

vector<unsigned int> *get_coverage(const string file_name){
  vector<unsigned int> *pCoverage = new vector<unsigned int>;
  ifstream infile(file_name.c_str());
  string one_line;
  if (infile.is_open())
    {
      while( infile.good()){
	getline(infile, one_line);
	
	istringstream iss(one_line);
	
	string chr = "dummy";
	iss >> chr;
	string start = "dummy";
	iss >> start;
	string end    = "dummy";
	iss >> end;
	if(chr != "dummy" && start != "dummy" && end != "dummy"){
	  int  start_int = atoi(start.c_str());
	  int end_int  = atoi(end.c_str());
	  //cout<<"chr= "<<chr<< " start = "<< start_int << " end "<< end_int<<endl;
	  for(unsigned int i = start_int; i <  end_int+1; i++){
	    pCoverage->push_back(i);
	  }
	}
	
      }
      
    }
  else
    {
      cerr<<"couldn't open file "<< file_name<<endl;
    }
  infile.close();
  return pCoverage;
}/*get_coverage*/



// vector<unsigned int> *get_coverage(const string file_name){
//   vector<unsigned int> *pCoverage = new vector<unsigned int>;
//   ifstream infile(file_name.c_str());
//   if (! infile.good())
//     {
//       cerr<<"couldn't open file: "<< file_name.c_str()<<endl;
//       exit(0);
//     }
//   string chr;
//   unsigned int start, end;
//   while(infile>>chr>>start>>end){
//     cout<<"chr= "<<chr<< " start = "<< start << " end "<< end<<endl;
//     for(unsigned int i = start; i<end+1; i++){
//       pCoverage->push_back(i);
//     }
//   }
//   infile.close();
//   return pCoverage;
// }/*get_coverage*/





void write_overalps_into_a_file(string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a){
  ofstream myfile;
  myfile.open(output_file);
  
  myfile<<intersection<<"\t"<<a_minus_b<<"\t"<<b_minus_a<<"\t"<<uni<<endl;
  myfile.close();
}/*write_overalps_into_a_file*/




