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
};

struct Rectangle
{
  double width;
  double length;
};

struct Circle
{
  double radius;
};

struct Triangle
{
  double side;
};

struct Cube
{
  double side;
};

struct Box
{
  double width;
  double length;
  double height;
};

struct Cylinder
{
  double side;
  double height;
  double radius;
};

struct Prism
{
  double side;
  double height;
  double length;
};



vector<string> parseString(string); // prototype
void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputCube(ostream&, const Cube&);
void outputBox(ostream&, const Box&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);
void fullBag(vector<string>&, vector<void*>&, vector<int>&);

int main()
{

    // programmer identification
    cout << "Programmer: Dae'juan Graham\n";
    cout << "Programmmer's ID: 2015690\n";
    cout << "File: " << __FILE__ <<"\n"<< endl;
     
    cout << fixed << setprecision(2);

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
    if (tokens.size() != 0) // ignore empty line
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
      outputSquare(cout, rSquare);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      outputRectangle(cout, rRectangle);
    }

    else if(bagType[i] == 3)// Circle
    {
      Circle* pCircle = reinterpret_cast<Circle*>(bag[i]); 
      Circle& rCircle = *pCircle; 
      outputCircle(cout, rCircle);
    }

    else if(bagType[i] == 4)// Triangle
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(bag[i]); 
      Triangle& rTriangle = *pTriangle; 
      outputTriangle(cout, rTriangle);
    }

    else if(bagType[i] == 5)// Cube
    {
      Cube* pCube = reinterpret_cast<Cube*>(bag[i]); 
      Cube& rCube = *pCube; 
      outputCube(cout, rCube);
    }

    else if(bagType[i] == 6)// Box
    {
      Box* pBox = reinterpret_cast<Box*>(bag[i]); 
      Box& rBox = *pBox; 
      outputBox(cout, rBox);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      outputCylinder(cout, rCylinder);
    }

    else if(bagType[i] == 8)// Prism
    {
      Prism* pPrism = reinterpret_cast<Prism*>(bag[i]); 
      Prism& rPrism = *pPrism; 
      outputPrism(cout, rPrism);
    }
  }

  out.open("Shapes.output.txt");

  for(int i = 0;i < bag.size();i++)// TXT output loop
  {
    if(bagType[i] == 1)// Square
    {
      Square* pSquare = reinterpret_cast<Square*>(bag[i]); 
      Square& rSquare = *pSquare; 
      outputSquare(out, rSquare);
    }

    else if(bagType[i] == 2)// Rectangle
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(bag[i]); 
      Rectangle& rRectangle = *pRectangle; 
      outputRectangle(out, rRectangle);
    }

    else if(bagType[i] == 3)// Circle
    {
      Circle* pCircle = reinterpret_cast<Circle*>(bag[i]); 
      Circle& rCircle = *pCircle; 
      outputCircle(out, rCircle);
    }

    else if(bagType[i] == 4)// Triangle
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(bag[i]); 
      Triangle& rTriangle = *pTriangle; 
      outputTriangle(out, rTriangle);
    }

    else if(bagType[i] == 5)// Cube
    {
      Cube* pCube = reinterpret_cast<Cube*>(bag[i]); 
      Cube& rCube = *pCube; 
      outputCube(out, rCube);
    }

    else if(bagType[i] == 6)// Box
    {
      Box* pBox = reinterpret_cast<Box*>(bag[i]); 
      Box& rBox = *pBox; 
      outputBox(out, rBox);
    }

    else if(bagType[i] == 7)// Cylinder
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(bag[i]); 
      Cylinder& rCylinder = *pCylinder; 
      outputCylinder(out, rCylinder);
    }

    else if(bagType[i] == 8)// Prism
    {
      Prism* pPrism = reinterpret_cast<Prism*>(bag[i]); 
      Prism& rPrism = *pPrism; 
      outputPrism(out, rPrism);
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
    r->width = tokens.size() >= 3 ? atof(tokens[1].c_str()) : 0;
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

void outputSquare(ostream& out, const Square& s)
{
  out << fixed << setprecision(2);

  double area = pow(s.side, 2);
  double perimeter = s.side *  4; 

  out << "Square: side = " << s.side;
  out << " area = " << area << " Perimeter = " << perimeter << endl;
}

void outputRectangle(ostream& out, const Rectangle& r)
{
  out << fixed << setprecision(2);

  double area = r.length * r.width;
  double perimeter = 2 * (r.length + r.width);

  out << "Rectangle: length = " << r.length << "width = " << r.width;
  out << "area = " << area << " perimeter = " << perimeter << endl;
}

void outputCircle(ostream& out, const Circle& c)
{
  out << fixed << setprecision(2);

  double area = M_PI * pow(c.radius, 2);
  double perimeter = M_PI * 2 * c.radius;

  out << "Circle: radius = " << c.radius;
  out << " area = " << area << " perimeter = " << perimeter << endl;
}

void outputTriangle(ostream& out, const Triangle& t)
{
  out << fixed << setprecision(2);

  double area = 0.5 * pow(t.side, 2);
  double perimeter = 3 * t.side;

  out << "Triangle: base = " << t.side;
  out << " area = " << area << " perimeter = " << perimeter << endl;
}

void outputCube(ostream& out, const Cube& c)
{
  out << fixed << setprecision(2);

  double volume = pow(c.side, 3);
  double surArea = 6 * pow(c.side, 2);

  out << "Cube: side = " << c.side;
  out << " volume = " << volume << "surface area = " << surArea << endl;
}

void outputBox(ostream& out, const Box& b)
{
  out << fixed << setprecision(2);

  double volume = b.length * b.width * b.height;
  double surArea = (2 * b.length * b.width) + (2 * b.width * b.height) + (2 * b.length * b.height);

  out << "Box: width = " << b.width << " length = " << b.length << " height = " << b.height;
  out << " volume = " << volume << " surface area = " << surArea << endl;
}

void outputCylinder(ostream& out, const Cylinder& c)
{
  out << fixed << setprecision(2);

  double volume = M_PI * pow(c.radius, 2) * c.height;
  double surArea = (2 * M_PI * pow(c.radius, 2)) + (2 * M_PI * c.radius * c.height);

  out << "Cylinder: radius = " << c.radius << " height = " << c.height;
  out << " volume = " << volume << " surface area = " << surArea << endl;
}

void outputPrism(ostream& out, const Prism& p)
{
  out << fixed << setprecision(2);

  double area = 0.5 * p.side * p.height;
  double perimeter = 3 * p.length;

  out << "Prism:  side = " << p.side << " height = " << p.height;
  out << " area = " <<  area;
  out << " Perimeter = " << perimeter << endl;
}



