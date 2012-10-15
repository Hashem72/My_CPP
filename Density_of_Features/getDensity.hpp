#ifndef CORRELATION_GARD
#define CORRELATION_GARD




// std::vector<unsigned int> *get_coverage(const std::string file_name);
// void write_overalps_into_a_file(std::string output_file, unsigned int intersection, unsigned int uni,  unsigned int a_minus_b, unsigned int b_minus_a);


std::vector<unsigned int> *get_start_positions(const std::string a_bed_file);
std::vector<unsigned int> *get_density(unsigned int segment_start, unsigned int segment_end, unsigned int window_length, unsigned int step_width, std::string bed_file);
std::string convert_int(unsigned int number);
std::string make_output_file_name(std::string path, unsigned int window_length, unsigned int step_size );
void print_out_densities(std::string output_file, std::vector<unsigned int> *densites_A, std::vector<unsigned int> *densities_B, std::vector<unsigned int> *densities_C);
void print_outdensities_v2(std::string output_file, std::vector<std::vector<unsigned int> > *densities);
#endif
