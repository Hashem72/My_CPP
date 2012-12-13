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

  if(argc <3){
    cout<<"required 2 files as arguments (first_bed, second_bed and output file) but you passed only "<<argc<<endl;
    exit(0);  
  }
  //cout<<"Output format is: First(bp)\t Second(bp)\t Overlap\t acc= Overlap/Second\t ppv= Overlap/First\t mean(acc,ppv) "<<endl;
  string first_bed_file     = argv[1];
  string second_bed_file    = argv[2];
  

  unsigned int chr_length = (51000000-16000000);

  vector<unsigned int> *first_mappable = new vector<unsigned int>;
  first_mappable = get_coverage(first_bed_file);
  unsigned int size_of_first_mapple = first_mappable->size();
  //cout<<"Coverage of first set is : "<<size_of_first_mapple<<endl;
  double coverage_percent = get_chr_coverage(size_of_first_mapple, chr_length);//(size_of_first_mapple/(double)chr_length)*100;
  
  //printf( "size of first set is: %.3f\n", coverage_percent);
  


  vector<unsigned int> *second_mappable = new vector<unsigned int>;
  second_mappable = get_coverage(second_bed_file);
  unsigned int size_of_second_mappable = second_mappable->size();
  //cout<< "Coverage of second set is : "<< size_of_second_mappable<< endl;
  double coverage_for_second = get_chr_coverage(size_of_second_mappable, chr_length);
  //printf( "size of second set is: %.3f\n", coverage_for_second);

  //get common elements
  vector<unsigned int> *inter = new vector<unsigned int>;
  set_intersection(   first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *inter));
  unsigned int inter_size = inter->size();
  //cout<<"inter size is: "<< inter_size<<endl;
  delete inter;
  double intersection_coverage = get_chr_coverage(inter_size,chr_length);
  //printf(" size of intersection %.3f\n", intersection_coverage);

  // printing 
  //std::string header = "First_F(bp)\tSecond_F(bp)\tCoverage(bp)\tPPV\tmean";
  //cout<<header<<endl;
  double PPV = (double)inter_size/(double)size_of_first_mapple;
  double coverage = (double)inter_size/(double)size_of_second_mappable;
  cout<<size_of_first_mapple<<"\t"<<size_of_second_mappable<<"\t"<<inter_size<<"\t"<<coverage<<"\t"<<PPV<<endl;



  // get difference AnotB (A\B)
  vector<unsigned int> *AnotB = new vector<unsigned int>;
  set_difference(  first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *AnotB)  );
  unsigned int size_of_AnotB = AnotB->size();
  //cout<<"size of AnotB is: "<< size_of_AnotB<<endl;
  delete AnotB;
  double coverage_of_A_not_B = get_chr_coverage(size_of_AnotB,chr_length);
  //printf("size of A not B is:  %.3f\n", coverage_of_A_not_B);

  //get difference BnotA (B\A)
  vector<unsigned int > *BnotA = new vector<unsigned int>;
  set_difference( second_mappable->begin(), second_mappable->end(),
  		  first_mappable->begin(), first_mappable->end(),
  		  back_inserter( *BnotA)  );

  unsigned int size_of_BnotA = BnotA->size();
  // cout<< "size of BnotA is: "<< size_of_BnotA<<endl;
  delete BnotA;
  double coverage_of_B_not_A = get_chr_coverage(size_of_BnotA,chr_length);
  //printf(" size of B not A is : %.3f\n", coverage_of_B_not_A );

  // //get union
  vector<unsigned int> *union_of_sets = new vector<unsigned int>;
  set_union(  first_mappable->begin(), first_mappable->end(),
  		      second_mappable->begin(), second_mappable->end(),
  		      back_inserter( *union_of_sets)  );

  unsigned int size_of_union = union_of_sets->size();
  // cout<< "size of union is: "<< size_of_union<<endl;
  //double coverage_of_union = get_chr_coverage(size_of_union,chr_length);
  //printf("size of union is:  %.3f\n", coverage_of_union);
  delete union_of_sets;
  delete first_mappable;
  delete second_mappable;
 



  //write result int the ouput file
  //write_overalps_into_a_file(output_file, inter_size,size_of_union, size_of_AnotB, size_of_BnotA);

  return 0;
}/*main*/


//////////////////////////////// functions //////////////////////////

double get_chr_coverage (unsigned int set_size, unsigned int chr_size){
  double coverage_percent = ( set_size/(double)chr_size)*100;
  return coverage_percent;
}/*get_coverageg*/

vector<unsigned int> *get_coverage(const string file_name){
  vector<unsigned int> *pCoverage = new vector<unsigned int>;
  ifstream input_f(file_name.c_str());
  if (! input_f.good())
    {
      cerr<<"couldnt open  the file"<<endl;
    }

 std::string chr_name, name, strand;
 unsigned int feature_start, feature_end, score, peak;
 double s_value, p_value, q_value;
 while(input_f >> chr_name >> feature_start >> feature_end >> name >> score >> strand >> s_value >> p_value >> q_value >>peak ){
   for(unsigned int i = feature_start; i< feature_end+1; i++){
     pCoverage->push_back(i);
   }
 }
   input_f.close();
   if( ! is_sorted( pCoverage->begin(), pCoverage->end()  )){
     sort(pCoverage->begin(), pCoverage->end());
   }
   std:: vector<unsigned int>::iterator it;
   it = std::unique(pCoverage->begin(), pCoverage->end());
   pCoverage->resize( it - pCoverage->begin() );
   return pCoverage;
}/*get_coverage*/



std::vector<pair<unsigned int, unsigned int> > *get_starts_and_end_of_features(std::string input_file){
  vector< pair< unsigned int, unsigned int>> *result = new vector<pair<unsigned int, unsigned int>>;
//open check if the input file is good!
ifstream input_f(input_file);
if (! input_f.good())
  {
    cerr<<"couldn't open the file"<<endl;
  }
 std::string chr_name, name, strand;
 unsigned int feature_start, feature_end, score, peak;
 double s_value, p_value, q_value;
 while(input_f >> chr_name >> feature_start >> feature_end >> name >> score >> strand >> s_value >> p_value >> q_value >>peak ){
      pair<unsigned int, unsigned int> one_pair;
   one_pair.first  = feature_start;
   one_pair.second = feature_end;
   result->push_back(one_pair);
 }
  return result;
}/*get_starts_and_end_of_features*/





void write_overalps_into_a_file(string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a){
  ofstream myfile;
  myfile.open(output_file);
  
  myfile<<intersection<<"\t"<<a_minus_b<<"\t"<<b_minus_a<<"\t"<<uni<<endl;
  myfile.close();
}/*write_overalps_into_a_file*/




