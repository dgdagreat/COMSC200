// Programmer: Dae'juan Graham
// Programmer's ID: 2015690

#include "iostream"
#include "fstream"
#include <string>
#include <vector>
using namespace std;

#include <cmath>

#include "pShapes.h"

const double PI = 3.14159;

ostream& roundingTwo(ostream& out){
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

ostream& roundingOff(ostream& out){
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

void checkShape(vector<string>& line, vector<const Shape*>& bag){
  string validShapes[] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};
  bool valShape = false;
  for(auto& i : validShapes){
    if(line.at(0) == i){
      valShape = true;
    }
  }
  cout.flush();
  if(valShape == true){
    calcShape(line, bag);
  }
  else{
    if(line.at(0)!="EOF"){
      cout << line.at(0) << " invalid shape" << endl;
    }
  }
}

void calcShape(vector<string>& line, vector<const Shape*>& bag){
  string shapeType = line.at(0);

  if (shapeType == "SQUARE"){
    const Square* const s = new Square(line);
    bag.push_back(s);
  }
  else if (shapeType=="RECTANGLE"){
    const Rectangle* const r = new Rectangle(line);
    bag.push_back(r);
  }
  else if (shapeType == "CIRCLE"){
    const Circle* const c = new Circle(line);
    bag.push_back(c);
  }
  else if (shapeType == "TRIANGLE"){
    const Triangle* const t = new Triangle(line);
    bag.push_back(t);
  }
  else if (shapeType == "CUBE"){
    const Cube* const c = new Cube(line);
    bag.push_back(c);
  }
  else if (shapeType == "BOX"){
    const Box* const b = new Box(line);
    bag.push_back(b);
  }
  else if (shapeType == "CYLINDER"){
    const Cylinder* const c = new Cylinder(line);
    bag.push_back(c);
  }
  else if (shapeType == "PRISM"){
    const Prism* const p = new Prism(line);
    bag.push_back(p);
  }
  else {
    //end of file, do nothing
  }
}

void Square::output(ostream& os) const{
  const double area = side * side;
  const double perim = side * 4.0;
  os << "SQUARE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Square::Square(const vector<string>& line)
        : side(line.size() >= 2 ? atof(line.at(1).c_str()) : 0){
}

Square& Square::operator=(const Square& copyThis){
  Square& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Rectangle::output(ostream& os) const{
  const double area = length * width;
  const double perim = (2.0 * length) + (2.0 * width);
  os << "RECTANGLE length=" << length << " width=" << width;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Rectangle::Rectangle(const vector<string>& line)
        : length(line.size() >= 2 ? atof(line.at(1).c_str()) : 0), width(line.size() >= 3 ? atof(line.at(2).c_str()) : 0){
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis){
  Rectangle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

void Circle::output(ostream& os) const{
  const double area = PI * radius * radius;
  const double perim = 2 * PI * radius;
  os << "CIRCLE radius=" << radius;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Circle::Circle(const vector<string>& line)
        : radius(line.size() >= 2 ? atof(line.at(1).c_str()) : 0){
}

Circle& Circle::operator=(const Circle& copyThis){
  Circle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

void Triangle::output(ostream& os) const{
  const double area = (pow(3.0, 0.5) / 4.0) * pow(side, 2.0);
  const double perim = side * 3.0;
  os << "TRIANGLE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Triangle::Triangle(const vector<string>& line)
        : side(line.size() >= 2 ? atof(line.at(1).c_str()) : 0){
}

Triangle& Triangle::operator=(const Triangle& copyThis){
  Triangle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Cube::output(ostream& os) const{
  const double surfaceArea = 6.0 * pow(side, 2.0);
  const double volume = pow(side, 3.0);
  os << "CUBE side=" << side;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cube& Cube::operator=(const Cube& copyThis){
  Cube& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Box::output(ostream& os) const{
  const double surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
  const double volume = length * width * height;
  os << "BOX length=" << length << " width=" << width << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Box& Box::operator=(const Box& copyThis){
  Box& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Cylinder::output(ostream& os) const{
  const double surfaceArea = (2.0 * (PI * pow(radius, 2.0))) + (2.0 * PI * radius * height);
  const double volume = PI * pow(radius, 2.0) * height;
  os << "CYLINDER radius=" << radius << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis){
  Cylinder& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Prism::output(ostream& os) const{
  const double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0))) + (3.0 * (side * height));
  const double volume = ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0)) * height;
  os << "PRISM side=" << side << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Prism& Prism::operator=(const Prism& copyThis){
  Prism& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

ostream& operator<<(ostream& out, const Shape& s){
  s.output(out);
  return out;
}