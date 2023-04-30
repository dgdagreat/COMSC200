#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

#include <stdlib.h> 
#include <cmath>

vector<string> parseString(string); // prototype
int main()
{

    // programmer identification
    cout << "Programmer: Dae'juan Graham\n";
    cout << "Programmmer's ID: 2015690\n";
    cout << "File: " << __FILE__ <<"\n"<< endl;
     
    cout << fixed << setprecision(2);

    double area;
    double perimeter;
    double volume;

    ifstream fin;
    fin.open("Shapes.input.txt");
    string line; // to store a single line of input from file
    vector<string> tokens; // store tokens
    while(!fin.eof())
  {
    getline(fin, line);// get string from file
    tokens = parseString(line);// turn string into tokens
    if (tokens.empty()) continue; // ignore empty line

      if (tokens[0] == "SQUARE")
      {
        double side = 0;
        if (tokens.size() >= 2)
          side = atof(tokens[1].c_str());

        area = side * side;
        perimeter = 4 * side;

        cout << "Square: ";
        cout << " Side = "  << side;
        cout << " Area = " << area;
        cout << " Perimeter = " << perimeter  << endl;
      }

      else if (tokens[0] == "RECTANGLE")  
      { 
        double length = 0, width = 0;
        if(tokens.size() >= 2)
          length = atof(tokens[1].c_str());
        
        if(tokens.size() >= 3)
          width = atof(tokens[2].c_str());

        area = length * width;
        perimeter = (2 * length) + (2 * width);

        cout << "Rectangle: ";
        cout << " length = "  << length << " width = "  << width;
        cout << " Area = "  << area;
        cout << " Perimeter = "  << perimeter << endl;
      }

      else if (tokens[0] == "CIRCLE")
      {
        double radius = 0;
        if(tokens.size() >= 2)
          radius = atof(tokens[1].c_str());
        
        area = 3.14 * (radius * radius);
        perimeter = 2 * 3.14 * radius;

        cout << "Circle: ";
        cout << " Radius = "  << radius;
        cout << " Area = "  << area;
        cout << " Circumference = "  << perimeter << endl;
      }

      else if (tokens[0] == "TRIANGLE")
      {
        double length = 0, width;
        if(tokens.size() >= 2)
          length = atof(tokens[1].c_str());

        if(tokens.size() >= 3)
          width = atof(tokens[2].c_str());
        
        area = 0.5 * length * width;
        perimeter = 3 * length;

        cout << "Triangle: ";
        cout << "side = "  << length;
        cout << " Area = "  << area;
        cout << " Perimeter = "  << perimeter << endl;
      }

      else if (tokens[0] == "CUBE")
      {
        double side  = 0;
        if(tokens.size() >= 2)
          side = atof(tokens[1].c_str());

        area = 6 * (side * side);
        perimeter = side * side * side;
        
        cout << "Cube: ";
        cout << " Side = "  << side;
        cout << "Surface Area = "  << area;
        cout << "Volume = "  << perimeter << endl;

      }

      else if (tokens[0] == "BOX")
      {
        double length = 0, width = 0, height = 0;
        if( tokens.size() >= 2)
            length = atof(tokens[1].c_str());
        
        if(tokens.size() >= 3)
            width = atof(tokens[2].c_str());
        
        if(tokens.size() >= 4)
            height = atof(tokens[3].c_str());
        
        area = (2 * length * width) + (2 * length * height) + 2 * (length * height);
        perimeter = length * width * height;
        
        cout << "Box: ";
        cout << "length = " << length << " width = " << width << " height = "  << height;
        cout << " Surface Area = " << area;
        cout << " Volume = "  << perimeter << endl;
      }

      else if (tokens[0] == "CYLINDER")
      {
        double radius = 0, height = 0;
        if(tokens.size() >= 2)
            radius = atof(tokens[1].c_str());
        
        if(tokens.size() >= 3)
            height = atof(tokens[2].c_str());

        perimeter = M_PI * (radius * radius) * height;
        area = 2 * M_PI * (radius * radius) + 2 * M_PI * radius * height;

        cout << "Cylinder: ";
        cout << "radius = " << radius << ", height = " << height;
        cout << " Surface Area = "  << area;
        cout << " Volume = "  << perimeter << endl;
      }

      else if (tokens[0] == "PRISM")
      {
        double length = 0, height = 0;
        if(tokens.size() >= 2)
            length = atof(tokens[1].c_str());

        if(tokens.size() >= 3)
            height = atof(tokens[2].c_str());

        area = 0.5 * length * height;
        perimeter = 3 * length;

        cout << "Prism: ";
        cout << "side = " << length;
        cout << " Area = " <<  area;
        cout << " Perimeter = " << perimeter << endl;
      }

      else if (tokens[0] == "EOF") continue;

      else
      {
        cout << tokens[0] << " Invalid Shape" << endl;
      }
  }
  
}
vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

