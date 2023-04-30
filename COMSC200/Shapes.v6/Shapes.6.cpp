#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "pShapes.h"

vector<string> parseString(string);

int main(){
  cout << "Programmer: Dae'juan Graham\n";
  cout << "Programmer's ID: 2015690\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  fin.open("Shapes.input.txt");
  vector<const Shape*> bag;

  while (fin.good()){
    string line;
    getline(fin, line);
    vector<string> lineElems = parseString(line);
    if(lineElems.size() != 0){
      checkShape(lineElems, bag);
    }
  }
  fin.close();

  for (unsigned int i = 0; i < bag.size(); i++){
    cout << *bag[i];
  }

  ofstream fout;
  fout.open("Shapes.output.txt");

  for (unsigned int i = 0; i < bag.size(); i++){
    fout << *bag[i];
  }

  fout.close();

  for (unsigned int i = 0; i < bag.size(); i++){
    delete bag[i];
  }
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}