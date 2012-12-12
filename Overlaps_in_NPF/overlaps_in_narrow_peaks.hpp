
#ifndef NPF_OVERLAPS_GARD
#define NPF_OVERLAPS_GARD

#include<string>
#include<sstream>
#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>
#include<set>
#include <stdio.h>
#include <time.h>

std::vector<std::pair<unsigned int, unsigned int> > *get_starts_and_end_of_features(std::string input_file);
void get_tp_tn_fp_fn(std::vector<std::pair<unsigned int, unsigned int>> *first_file_features, 
		     std::vector<std::pair<unsigned int, unsigned int>> *second_file_features, 
		     const double overlap_threshold);
std::vector<unsigned int> *get_intersection(std::vector<unsigned int> *first_vector, std::vector<unsigned int> *second_vector);
std::vector<unsigned int> *get_helper_vetor(unsigned int from, unsigned int to);

#endif
