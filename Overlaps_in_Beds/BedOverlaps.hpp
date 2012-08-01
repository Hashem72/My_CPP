
#ifndef BED_OVERLAPS_GARD
#define BED_OVERLAPS_GARD

#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>

//std::vector<unsigned int> get_coverage(std::string file_name);
std::vector<unsigned int> *get_coverage(const std::string file_name);
void write_overalps_into_a_file(std::string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a);



#endif
