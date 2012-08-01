#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>
#include <iomanip>


/*Note: bed files with biasness scores are build from six columns: chr, start, end, name, score and strand. The idea here is to add ninth colum that includes RGB color codes based on scores then Dalliance can display features colorfully. note that columns 7 and 8 are just dummy*/

using namespace std;

std::string get_color_code(double a_double);
std::string get_color_code_2(int interval_start, int interval_end, int green_integer , double score);


int main(int argc, char *argv[]) {

  // double x= 456.00017;
  // cout<< "precision 1 " <<setprecision(2)<<x<<endl;
  // cout<< "precision 2 " <<setprecision(2)<<x<<endl;
  // cout<< "precision 3 " <<setprecision(3)<<x<<endl;
  // exit(0);
  
  //some initials
  int interval_start = -2;
  int interval_end   = 2;
  int green_integer  = 128;
  double scale       = 0.01;
 
  
  bool change_score = true;
  
  ifstream fin(argv[1]);
  if (! fin.good())
    {
      cerr << "coudn't open file for reading!" << endl;
    }

  ofstream fout(argv[2]);
  if (! fout.good())
    {
      cerr << "coudn't open file for writing";
    }

  string chr_name, feature_name,strand,trash;
  double score;
  unsigned int start, stop;
  // start reading the bed file line by line
  while( fin >> chr_name >> start >> stop >> feature_name >> score >> strand){
    string one_code = get_color_code_2(interval_start, interval_end, green_integer, score);
    score = floor(score/scale + 0.5)*scale;

    //cout<< "score = "<< setprecision(2)<<score<< " col = "<< one_code<<endl;
    getline(fin, trash);
if (change_score)
  {
    fout << chr_name << "\t" << start << "\t" << stop << "\t" << score << "\t" << 25 << "\t" << strand << "\t0\t0\t" << one_code << endl;
  }
 else{
   fout << chr_name << "\t" << start << "\t" << stop << "\t" << feature_name << "\t" << score << "\t" << strand << "\t0\t0\t" << one_code << endl;
 }
    
  }/*while*/
  

  
  fin.close();
  fout.close();
  return 0;
}/*main*/

///////////////////// functions ////////////////

string get_color_code_2(int interval_start, int interval_end, int green_integer , double score){
  //this is to return  a string triple like (r,g,b). Howver it is assumed that g is fixed and given by user, the function 
  //will caluclate r and b values based on scores distribution in the given interval
  string code = "0,0,0";
  ostringstream convert;
  convert << green_integer;
  string green = convert.str();


  if (score <= interval_start){
    string red = "255";
    string blue = "0";
    code = red+","+green+","+blue;
  }
  else if(score >= interval_end){
    string red = "0";
    string blue = "255";
    code = red+","+green+","+blue;
  }
  else{//map scores into [0,1] interval
    int range = interval_end - interval_start;
    double new_score =  (score - (double) interval_start)/range;
    double red_as_double = 255*(1-new_score);
    red_as_double = floor(red_as_double + 0.5);
    double blue_as_double = 255*new_score;
    blue_as_double = floor(blue_as_double + 0.5);
    ostringstream red_convertor;
    red_convertor << red_as_double;
    string red = red_convertor.str();
    ostringstream blue_convertor;
    blue_convertor << blue_as_double;
    string blue = blue_convertor.str();
    code = red+","+green+","+blue;
  }
  
  //normlization: mappine the given interval into [0,1]
  return code;
}/*get_color_code_2*/

string get_color_code(double a_double){
  string code = "0,0,0";
  if (a_double<= -3)
    {
      code = "255,0,0";
    }
  else if (a_double <= -2)
    {
      code = "255,125,0";
    }
  else if (a_double <= -1)
    {
      code = "255,255,0";
      }
  else if (a_double <= 0)
    {
      code = "125,255,0";
    }
  else if (a_double <= 1)
    {
      code = "0,255,0";
    }
  else if (a_double <= 2)
    {
      code = "0,255,255";
    }
  else 
    {
      code = "0,0,255";
	}
  return code;
}/*get_color_code*/
