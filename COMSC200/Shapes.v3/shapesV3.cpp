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

struct Square
{
  double side;
  void outputSquare(ostream&) const;
};

struct Rectangle
{
  double width;
  double length;
  void outputRectangle(ostream&) const;
};

struct Circle
{
  double radius;
  void outputCircle(ostream&) const;
};

struct Triangle
{
  double side;
  void outputTriangle(ostream&) const;
};

struct Cube
{
  double side;
  void outputCube(ostream&) const;
};

struct Box
{
  double width;
  double length;
  double height;
  void outputBox(ostream&) const;
};

struct Cylinder
{
  double side;
  double height;
  double radius;
  void outputCylinder(ostream&) const;
};

struct Prism
{
  double side;
  double height;
  double length;
  void outputPrism(ostream&) const;
};



vector<string> parseString(string); // prototype
ostream& roundingTwo(ostream&); // prototype
ostream& roundingOff(ostream&); // prototype 
void fullBag(vector<string>&, vector<void*>&, vector<int>&);

int main()
{

    // programmer identification
    cout << "Programmer: Dae'juan Graham\n";
    cout << "Programmmer's ID: 2015690\n";
    cout << "File: " << __FILE__ <<"\n"<< endl;

    ifstream fin;
    ofstream out;
    fin.open("Shapes.input.txt");

    string line; // to store a single line of input from file
    vector<string> tokens; // store tokens
    vector<void*> bag;
    vector<int> bagType;

    while(!fin.eof()) //fill bag loop
    {
      getline(fin, line);// get string from file
      tokens = parseString(line);// turn string into tokens
      if (tokens.empty()) continue;
      if (tokens[0] == "EOF") continue;
      fullBag(tokens, bag, bagType); // fill bag
    }

  fin.close();

  for(int i = 0;i < bag.size();i++)// CONSOLE output loop
  {
    if(bagType[i] == 1)// Square
    {
      Square* pSquare = reinterpret_cast<Square*>(bag[i]); 
      Square& rSquare = *pSquare; 
      rSquare.outputSquare(cout);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      rRectangle.outputRectangle(cout);
    }

    else if(bagType[i] == 3)// Circle
    {
      Circle* pCircle = reinterpret_cast<Circle*>(bag[i]); 
      Circle& rCircle = *pCircle; 
      rCircle.outputCircle(cout);
    }

    else if(bagType[i] == 4)// Triangle
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(bag[i]); 
      Triangle& rTriangle = *pTriangle; 
      rTriangle.outputTriangle(cout);
    }

    else if(bagType[i] == 5)// Cube
    {
      Cube* pCube = reinterpret_cast<Cube*>(bag[i]); 
      Cube& rCube = *pCube; 
      rCube.outputCube(cout);
    }

    else if(bagType[i] == 6)// Box
    {
      Box* pBox = reinterpret_cast<Box*>(bag[i]); 
      Box& rBox = *pBox; 
      rBox.outputBox(cout);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      rCylinder.outputCylinder(cout);
    }

    else if(bagType[i] == 8)// Prism
    {
      Prism* pPrism = reinterpret_cast<Prism*>(bag[i]); 
      Prism& rPrism = *pPrism; 
      rPrism.outputPrism(cout);
    }
  }

  out.open("Shapes.output.txt");

  for(int i = 0;i < bag.size();i++)// TXT output loop
  {
    if(bagType[i] == 1)// Square
    {
      Square* pSquare = reinterpret_cast<Square*>(bag[i]); 
      Square& rSquare = *pSquare; 
      rSquare.outputSquare(out);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      rRectangle.outputRectangle(out);
    }

    else if(bagType[i] == 3)// Circle
    {
      Circle* pCircle = reinterpret_cast<Circle*>(bag[i]); 
      Circle& rCircle = *pCircle; 
      rCircle.outputCircle(out);
    }

    else if(bagType[i] == 4)// Triangle
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(bag[i]); 
      Triangle& rTriangle = *pTriangle; 
       rTriangle.outputTriangle(out);
    }

    else if(bagType[i] == 5)// Cube
    {
      Cube* pCube = reinterpret_cast<Cube*>(bag[i]); 
      Cube& rCube = *pCube; 
      rCube.outputCube(out);
    }

    else if(bagType[i] == 6)// Box
    {
      Box* pBox = reinterpret_cast<Box*>(bag[i]); 
      Box& rBox = *pBox; 
      rBox.outputBox(out);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      rCylinder.outputCylinder(out);
    }

    else if(bagType[i] == 8)// Prism
    {
      Prism* pPrism = reinterpret_cast<Prism*>(bag[i]); 
      Prism& rPrism = *pPrism; 
      rPrism.outputPrism(out);
    }
  }

  out << "\nEND";
  out.close();

  for(int i = 0;i < bag.size();i++)// deallocating loop
  {
    if(bagType[i] == 1)// Square
    {
      Square* s = reinterpret_cast<Square*>(bag[i]); 
      delete s;
    }
    else if(bagType[i] == 2)// Rectangle
    {
      Rectangle* r = reinterpret_cast<Rectangle*>(bag[i]); 
      delete r;
    }
    else if(bagType[i] == 3)// Circle
    {
      Circle* c = reinterpret_cast<Circle*>(bag[i]); 
      delete c;
    }
    else if(bagType[i] == 4)// Triangle
    {
      Triangle* t = reinterpret_cast<Triangle*>(bag[i]); 
      delete t;
    }
    else if(bagType[i] == 5)// Cube
    {
      Cube* cb = reinterpret_cast<Cube*>(bag[i]); 
      delete cb;
    }
    else if(bagType[i] == 6)// Box
    {
      Box* b = reinterpret_cast<Box*>(bag[i]); 
      delete b;
    }
    else if(bagType[i] == 7)// Cylinder
    {
      Cylinder* cy = reinterpret_cast<Cylinder*>(bag[i]); 
      delete cy;
    }
    else if(bagType[i] == 8)// Prism
    {
      Prism* p = reinterpret_cast<Prism*>(bag[i]); 
      delete p;
    }

  }

}
vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

void fullBag(vector<string>& tokens, vector<void*>& bag, vector<int>& bagType)
{
  if (tokens[0] == "SQUARE")
  {
      Square* s = new Square;
      bag.push_back(s);
      bagType.push_back(1);
      s->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
  }

  else if (tokens[0] == "RECTANGLE")  
  { 
    Rectangle* r = new Rectangle;
    bag.push_back(r);
    bagType.push_back(2);
    r->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
    r->width = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
  }

  else if (tokens[0] == "CIRCLE")
  {
    Circle* c = new Circle;
    bag.push_back(c);
    bagType.push_back(3);
    c->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
  }

  else if (tokens[0] == "TRIANGLE")
  {
    Triangle* t = new Triangle;
    bag.push_back(t);
    bagType.push_back(4);
    t->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
  }

  else if (tokens[0] == "CUBE")
  {
    Triangle* t = new Triangle;
    bag.push_back(t);
    bagType.push_back(4);
    t->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
  }

  else if (tokens[0] == "BOX")
  {
    Box* b = new Box;
    bag.push_back(b);
    bagType.push_back(6);
    b->length = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
    b->width = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
    b->height = tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0;
  }

  else if (tokens[0] == "CYLINDER")
  {
    Cylinder* c = new Cylinder;
    bag.push_back(c);
    bagType.push_back(7);
    c->radius = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
    c->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
  }

  else if (tokens[0] == "PRISM")
  {
    Prism* p = new Prism;
    bag.push_back(p);
    bagType.push_back(8);
    p->side = tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0;
    p->height = tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0;
  }

  else
  {
    cout << tokens[0] << " Invalid Shape" << endl;
  }
}

void Square::outputSquare(ostream& out) const
{
  double area = pow(side, 2);
  double perimeter = side *  4; 

  out << roundingOff << "Square: side = " << side;
  out << roundingTwo << " area = " << area << " Perimeter = " << perimeter << endl;
}

void Rectangle::outputRectangle(ostream& out) const
{
  double area = length * width;
  double perimeter = 2 * (length + width);

  out << roundingOff << "Rectangle: length = " << length << " width = " << width;
  out << roundingTwo <<" area = " << area << " perimeter = " << perimeter << endl;
}

void Circle::outputCircle(ostream& out) const
{
  double area = M_PI * pow(radius, 2);
  double perimeter = M_PI * 2 * radius;

  out << roundingOff << "Circle: radius = " << radius;
  out << roundingTwo << " area = " << area << " perimeter = " << perimeter << endl;
}

void Triangle::outputTriangle(ostream& out) const
{
  double area = 0.5 * pow(side, 2);
  double perimeter = 3 * side;

  out << roundingOff <<"Triangle: base = " << side;
  out << roundingTwo << " area = " << area << " perimeter = " << perimeter << endl;
}

void Cube::outputCube(ostream& out) const
{
  double volume = pow(side, 3);
  double surArea = 6 * pow(side, 2);

  out << roundingOff <<"Cube: side = " << side;
  out <<  roundingTwo << " volume = " << volume << "surface area = " << surArea << endl;
}

void Box::outputBox(ostream& out) const
{
  double volume = length * width * height;
  double surArea = (2 * length * width) + (2 * width * height) + (2 * length * height);

  out << roundingOff <<  "Box: length = "<< length << setw(10) << "width = "  << width << setw(10) << "height = " << height;
  out << roundingTwo << setw(10) << "volume = " << volume << setw(16) << "surface area = " << surArea << endl;
}

void Cylinder::outputCylinder(ostream& out) const
{
  double volume = M_PI * pow(radius, 2) * height;
  double surArea = (2 * M_PI * pow(radius, 2)) + (2 * M_PI * radius * height);

  out << roundingOff << "Cylinder: radius = " << radius << " height = " << height;
  out << roundingTwo << " volume = " << volume << " surface area = " << surArea << endl;
}

void Prism::outputPrism(ostream& out) const
{
  double area = 0.5 * side * height;
  double perimeter = 3 * length;

  out << roundingOff << "Prism:  side = " << side << " height = " << height;
  out <<  roundingTwo << " area = " <<  area;
  out <<  roundingTwo << " Perimeter = " << perimeter << endl;
}

ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2); // 2 decimal digits
  return out;
}

ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed); 
  out.precision(6); // the C++ default 
  return out;
} 

