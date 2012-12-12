
#ifndef BED_OVERLAPS_GARD
#define BED_OVERLAPS_GARD

#include<string>
#include<sstream>
#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>
#include<set>
#include <stdio.h>
#include <time.h>

//std::vector<unsigned int> get_coverage(std::string file_name);
std::vector<unsigned int> *get_coverage(const std::string file_name);
void write_overalps_into_a_file(std::string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a);
double get_chr_coverage (unsigned int set_size, unsigned int chr_size);
bool myComparison (unsigned int i, unsigned int j);



#endif
