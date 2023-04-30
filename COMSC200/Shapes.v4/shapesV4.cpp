#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

#include <stdlib.h> 
#include <cmath>

class Square
{
  const double side;

  public :
  Square(const vector<string>&tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};
  Square& operator=(const Square&);
  void outputSquare(ostream&)const;
};

class Rectangle 
{
  const double length;
  const double width;

  public:
  Rectangle(const vector <string> &tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
  width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};

  Rectangle& operator = (const Rectangle&);
  void outputRectangle(ostream&)const;
};

class Triangle 
{
  const double side;

  public:
  Triangle(const vector <string> &tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0){};
  Triangle& operator = (const Triangle&);
  void outputTriangle(ostream&)const;
};

class Circle
{
  const double radius;

  public:
  Circle(const vector <string> &tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};
  Circle& operator = (const Circle&);
  void outputCircle(ostream&)const;
};

class Cube 
{
  const double side;

  public:
  Cube(const vector<string>&tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {};

  Cube& operator=(const Cube&);
  void outputCube(ostream&)const;
};

class Prism
{
  const double side;
  const double height;

  public:
  Prism(const vector <string> &tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
  height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};

  Prism& operator = (const Prism&);
  void outputPrism(ostream&)const;
};

class Cylinder
{
  const double radius;
  const double height;

  public:
  Cylinder(const vector <string> &tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
  height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};

  Cylinder& operator = (const Cylinder&);
  void outputCylinder(ostream&)const;
};

class Box 
{
  const double length;
  const double width;
  const double height;

  public:
  Box(const vector <string> &tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
  width(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
  height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};

  Box& operator = (const Box&);
  void outputBox(ostream&)const;
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
      const Square* const pSquare = reinterpret_cast<const Square*>(bag[i]); 
      const Square& rSquare = const_cast<Square&>(*pSquare); 
      rSquare.outputSquare(cout);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(bag[i]); 
      const Rectangle& rRectangle = const_cast<Rectangle&>(*pRectangle); 
      rRectangle.outputRectangle(cout);
    }

    else if(bagType[i] == 3)// Circle
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(bag[i]); 
      const Circle& rCircle = const_cast<Circle&>(*pCircle); 
      rCircle.outputCircle(cout);
    }

    else if(bagType[i] == 4)// Triangle
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(bag[i]); 
      const Triangle& rTriangle = const_cast<Triangle&>(*pTriangle); 
      rTriangle.outputTriangle(cout);
    }

    else if(bagType[i] == 5)// Cube
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(bag[i]); 
      const Cube& rCube = const_cast<Cube&>(*pCube); 
      rCube.outputCube(cout);
    }

    else if(bagType[i] == 6)// Box
    {
      const Box* const pBox = reinterpret_cast<const Box*>(bag[i]); 
      const Box& rBox = const_cast<Box&>(*pBox); 
      rBox.outputBox(cout);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(bag[i]); 
      const Cylinder& rCylinder = const_cast<Cylinder&>(*pCylinder); 
      rCylinder.outputCylinder(cout);
    }

    else if(bagType[i] == 8)// Prism
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(bag[i]); 
      const Prism& rPrism = const_cast<Prism&>(*pPrism); 
      rPrism.outputPrism(cout);
    }
  }

  out.open("Shapes.output.txt");

  for(int i = 0;i < bag.size();i++)// TXT output loop
  {
    if(bagType[i] == 1)// Square
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(bag[i]); 
      const Square& rSquare = const_cast<Square&>(*pSquare); 
      rSquare.outputSquare(out);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(bag[i]); 
      const Rectangle& rRectangle = const_cast<Rectangle&>(*pRectangle); 
      rRectangle.outputRectangle(out);
    }

    else if(bagType[i] == 3)// Circle
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(bag[i]); 
      const Circle& rCircle = const_cast<Circle&>(*pCircle); 
      rCircle.outputCircle(out);
    }

    else if(bagType[i] == 4)// Triangle
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(bag[i]); 
      const Triangle& rTriangle = const_cast<Triangle&>(*pTriangle); 
       rTriangle.outputTriangle(out);
    }

    else if(bagType[i] == 5)// Cube
    {
      const Cube* const pCube = reinterpret_cast<const Cube*>(bag[i]); 
      const Cube& rCube = const_cast<Cube&>(*pCube); 
      rCube.outputCube(out);
    }

    else if(bagType[i] == 6)// Box
    {
      const Box* const pBox = reinterpret_cast<const Box*>(bag[i]); 
      const Box& rBox = const_cast<Box&>(*pBox); 
      rBox.outputBox(out);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(bag[i]); 
      const Cylinder& rCylinder = const_cast<Cylinder&>(*pCylinder); 
      rCylinder.outputCylinder(out);
    }

    else if(bagType[i] == 8)// Prism
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(bag[i]); 
      const Prism& rPrism = const_cast<Prism&>(*pPrism); 
      rPrism.outputPrism(out);
    }
  }

  out << "\nEND";
  out.close();

  for(int i = 0;i < bag.size();i++)// deallocating loop
  {
    if(bagType[i] == 1)// Square
    {
      const Square* const s = reinterpret_cast<const Square*>(bag[i]); 
      delete s;
    }
    else if(bagType[i] == 2)// Rectangle
    {
      const Rectangle* const r = reinterpret_cast<const Rectangle*>(bag[i]); 
      delete r;
    }
    else if(bagType[i] == 3)// Circle
    {
      const Circle* const c = reinterpret_cast<const Circle*>(bag[i]); 
      delete c;
    }
    else if(bagType[i] == 4)// Triangle
    {
      const Triangle* const t = reinterpret_cast<const Triangle*>(bag[i]); 
      delete t;
    }
    else if(bagType[i] == 5)// Cube
    {
      const Cube* const cb = reinterpret_cast<const Cube*>(bag[i]); 
      delete cb;
    }
    else if(bagType[i] == 6)// Box
    {
      const Box* const b = reinterpret_cast<const Box*>(bag[i]); 
      delete b;
    }
    else if(bagType[i] == 7)// Cylinder
    {
      const Cylinder* const cy = reinterpret_cast<const Cylinder*>(bag[i]); 
      delete cy;
    }
    else if(bagType[i] == 8)// Prism
    {
      const Prism* const p = reinterpret_cast<const Prism*>(bag[i]); 
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
      Square* s = new Square(tokens);
      bag.push_back(s);
      bagType.push_back(1);
  }

  else if (tokens[0] == "RECTANGLE")  
  { 
    Rectangle* r = new Rectangle(tokens);
    bag.push_back(r);
    bagType.push_back(2);
  }

  else if (tokens[0] == "CIRCLE")
  {
    Circle* c = new Circle(tokens);
    bag.push_back(c);
    bagType.push_back(3);
  }

  else if (tokens[0] == "TRIANGLE")
  {
    Triangle* t = new Triangle(tokens);
    bag.push_back(t);
    bagType.push_back(4);
  }

  else if (tokens[0] == "CUBE")
  {
    Triangle* t = new Triangle(tokens);
    bag.push_back(t);
    bagType.push_back(4);
  }

  else if (tokens[0] == "BOX")
  {
    Box* b = new Box(tokens);
    bag.push_back(b);
    bagType.push_back(6);
  }

  else if (tokens[0] == "CYLINDER")
  {
    Cylinder* c = new Cylinder(tokens);
    bag.push_back(c);
    bagType.push_back(7);
  }

  else if (tokens[0] == "PRISM")
  {
    Prism* p = new Prism(tokens);
    bag.push_back(p);
    bagType.push_back(8);
  }

  else
  {
    cout << tokens[0] << " Invalid Shape" << endl;
  }
  
  for (int i = 0; i <= bag.size(); i++)
  {
    for (int j = i + 1; j < bag.size(); j++)
    {
      if (bagType[j] < bagType[i])
      {
        swap(bagType[i], bagType[j]);
        swap(bag[i], bag[j]);
      }
    }
  }
  
}

void Square::outputSquare(ostream& out) const
{
  double area = pow(this->side, 2);
  double perimeter = this->side *  4; 

  out << roundingOff << "Square: side = " << this->side;
  out << roundingTwo << " area = " << area << " Perimeter = " << perimeter << endl;
}

void Rectangle::outputRectangle(ostream& out) const
{
  double area = this->length * this->width;
  double perimeter = 2 * (this->length + this->width);

  out << roundingOff << "Rectangle: length = " << this->length << " width = " << this->width;
  out << roundingTwo <<" area = " << area << " perimeter = " << perimeter << endl;
}

void Circle::outputCircle(ostream& out) const
{
  double area = M_PI * pow(this->radius, 2);
  double perimeter = M_PI * 2 * this->radius;

  out << roundingOff << "Circle: radius = " << this->radius;
  out << roundingTwo << " area = " << area << " perimeter = " << perimeter << endl;
}

void Triangle::outputTriangle(ostream& out) const
{
  double area = 0.5 * pow(this->side, 2);
  double perimeter = 3 * this->side;

  out << roundingOff <<"Triangle: base = " << this->side;
  out << roundingTwo << " area = " << area << " perimeter = " << perimeter << endl;
}

void Cube::outputCube(ostream& out) const
{
  double volume = pow(this->side, 3);
  double surArea = 6 * pow(this->side, 2);

  out << roundingOff <<"Cube: side = " << this->side;
  out <<  roundingTwo << " volume = " << volume << "surface area = " << surArea << endl;
}

void Box::outputBox(ostream& out) const
{
  double volume = this->length * this->width * this->height;
  double surArea = (2 * this->length * this->width) + (2 * this->width * this->height) + (2 * this->length * this->height);

  out << roundingOff <<  "Box: length = "<< this->length << setw(10) << "width = "  << this->width << setw(10) << "height = " << this->height;
  out << roundingTwo << setw(10) << "volume = " << volume << setw(16) << "surface area = " << surArea << endl;
}

void Cylinder::outputCylinder(ostream& out) const
{
  double volume = M_PI * pow(this->radius, 2) * this->height;
  double surArea = (2 * M_PI * pow(this->radius, 2)) + (2 * M_PI * this->radius * this->height);

  out << roundingOff << "Cylinder: radius = " << this->radius << " height = " << this->height;
  out << roundingTwo << " volume = " << volume << " surface area = " << surArea << endl;
}

void Prism::outputPrism(ostream& out) const
{
  double area = 0.5 * this->side * this->height;
  double perimeter = 3 * this->side;

  out << roundingOff << "Prism:  side = " << this->side << " height = " << this->height;
  out <<  roundingTwo << " area = " <<  area;
  out <<  roundingTwo << " Perimeter = " << perimeter << endl;
}

//OVERLOAD FUNCTIONS
Square& Square::operator=(const Square& copyThis)
{
  Square& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
    const_cast<double&>(host.side) = copyThis.side;
  return host; //returns a "self-reference"
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
  Rectangle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host; //returns a "self-reference"
}

Circle& Circle::operator=(const Circle& copyThis)
{
  Circle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host; //returns a "self-reference"
}

Triangle& Triangle::operator=(const Triangle& copyThis)
{
  Triangle& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host; //returns a "self-reference"
}

Cube& Cube::operator=(const Cube& copyThis)
{
  Cube& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
    const_cast<double&>(host.side) = copyThis.side;
  return host; //returns a "self-reference"
}

Box& Box::operator=(const Box& copyThis)
{
  Box& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host; //returns a "self-reference"
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
  Cylinder& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.height) = copyThis.height;
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host; //returns a "self-reference"
}

Prism& Prism::operator=(const Prism& copyThis)
{
  Prism& host = *this; // a reference to the host object
  if (this != &copyThis) // skips self-copy if host and parameter are same object
  {
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host; //returns a "self-reference"
}

// ROUNDING FUNCTIONS
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

