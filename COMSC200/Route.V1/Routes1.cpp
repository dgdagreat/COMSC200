#include <iostream>
using namespace std;
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//leg class declaration
class Leg {
   const char* const startCity;
   const char* const endCity;
   const double distance;
   friend class Routes;
public:
   Leg(const char* const, const char* const, const double);
   Leg& operator= (const Leg&);
   double getDistance() const;
   void output(ostream&) const;
};
//routes class declaration
class Routes{
   vector<const Leg*> legs; // bag of legs
   const double dist;
public:
   Routes(const Leg&);
   Routes(const Routes&, const Leg&);
   Routes& operator=(const Routes&);
   double getDistance() const;
   void output(ostream&) const;
};
int main()
{
    // programmer identification
  cout << "Programmer: Dae'juan Graham\n";
  cout << "Programmmer's ID: 2015690\n";
  cout << "File: " << __FILE__ <<"\n"<< endl;
  
  Leg legs[] =
  {
    Leg("San Fransisco", "Danville", 30.4),
    Leg("San Fransisco", "Walnut Creek", 24.4),
    Leg("San Fransisco", "Pleasant Hill", 27.0),
    Leg("San Fransisco", "Concord", 29.8),
    Leg("San Fransisco", "Reno", 218.0),
    Leg("Danville", "San Diego", 478.0),
    Leg("Danville", "Los Angeles", 358.0),
    Leg("Danville", "Malibu", 372.0),
    Leg("Danville", "Las Vegas", 545.0),
    Leg("Danville", "Reno", 209.0),
    Leg("South Lake Tahoe", "Reno", 61.9),
    Leg("South Lake Tahoe", "Carson City", 27.7),
    Leg("South Lake Tahoe", "Virginia City", 42.8),
    Leg("South Lake Tahoe", "Sacramento", 104.0),
    Leg("South Lake Tahoe", "Vacaville", 134.0),
    Leg("San Jose", "Fresno", 150.0),
    Leg("San Jose", "Bakersfield", 241.0),
    Leg("San Jose", "Anaheim", 366.0),
    Leg("San Jose", "Sacramento", 120.0),
    Leg("San Jose", "Long Beach", 363.0),
    Leg("Boston", "Cambridge", 3.1),
    Leg("Boston", "Newton", 10.6),
    Leg("Boston", "Waltham", 12.1),
    Leg("Boston", "Frammingham", 22.8),
    Leg("Boston", "Dover", 71.4),
    Leg("San Antonio", "Austin", 79.7),
    Leg("San Antonio", "Dallas", 274.0),
    Leg("San Antonio", "Houston", 197.0),
    Leg("San Antonio", "El Paso", 552.0),
    Leg("San Antonio", "Waco", 180.0),
    Leg("Denver", "Danville", 1200.0),
    Leg("Denver", "Salt Lake City", 519.0),
    Leg("Denver", "Boston", 1972.0),
    Leg("Denver", "Sacramento", 1122.0),
    Leg("Denver", "Dover", 1744.0),
    Leg("Dover", "Sacramento", 2810.0),
    Leg("Albuquerque", "Dallas", 650.0),
    Leg("Waltham", "South Lake Tahoe", 2927.0),
    Leg("Boston", "Walnut Creek", 3078.0),
    Leg("Roundup", "Chicago", 1248.0),
  };
  //declaring routes object
  Routes r[] =
  {
    Routes(legs[0]),
    Routes(r[0], legs[4]),
    Routes(r[1], legs[12]),
    Routes(r[2], legs[13]),
    Routes(r[3], legs[17]),
    Routes(r[4], legs[5]),
    Routes(r[5], legs[19]),
    Routes(r[6], legs[14]),
    Routes(r[7], legs[7]),
    Routes(r[8], legs[20]),
    Routes(r[9], legs[1])
  };
  cout<<endl;
  //determining the size of legs
  const int legSize = sizeof(legs)/sizeof(Leg);
  const int routeSize = sizeof(r) / sizeof(Routes);
  for(int i = 0 ; i < routeSize; i++)
  {
  for(int j = i+1; j < routeSize ; j++)
  {
    if(r[i].getDistance() > r[j].getDistance())
    {
      swap(r[i], r[j]);
    }
  }
  }
  cout << "Routes: " << endl;
  for (int k = 0; k < routeSize; k++)
  {
    r[k].output(cout);
  }
  cout << endl << endl;
  //sorting function
  for (int i = 0; i < legSize; i++)
  {
  for (int j = i+1 ; j < legSize; j++)
  {
    if (legs[i].getDistance() > legs[j].getDistance())
    {
      swap(legs[i], legs[j]);
    }
  }
  }

  //output
  for (int k = 0; k < legSize; k++)
  {
    legs[k].output(cout);
  }
  return 0;
}
//constructor
Leg::Leg(const char* const start, const char* const end, const double distance)
:startCity(start), endCity(end), distance(distance)
{
}
//getter
void Leg::output(ostream& out) const
{
  out << "Leg: " << startCity << " to " << endCity << ", " << distance << " miles.\n";
}
//getter
double Leg::getDistance() const
{
  return distance;
}
//assignment operator
Leg& Leg::operator=(const Leg& Copy)
{
  Leg& host = *this;
  if (this != &Copy)
  {
    const_cast<const char*&>(host.startCity) = Copy.startCity;
    const_cast<const char*&>(host.endCity) = Copy.endCity;
    const_cast<double&>(host.distance) = Copy.distance;
  }
  return host;
}
Routes::Routes(const Leg& legObject)
: dist(legObject.distance)
{
  legs.push_back(&legObject);
}
Routes::Routes(const Routes& route, const Leg& legObject)
:legs(route.legs), dist(route.dist + legObject.distance)
{
  if(strcmp(legs.back()->endCity, legObject.startCity) != 0)
  {
    cout<<"Skipping....";
  }
  legs.push_back(&legObject);
}
double Routes::getDistance() const
{
  return dist;
}
void Routes::output(ostream& out) const
{
  out << endl << "Routes: " << legs[0]->startCity << " to ";
  for(int i = 0 ; i < legs.size() ; i++)
  {
    if (i < (legs.size() - 1)) out << legs[i]->endCity << " to ";
      else
        out << legs[i]->endCity << ", ";
  }
  out << dist << " miles.";
}
//assignment operator
Routes& Routes::operator=(const Routes& Copy)
{
  Routes& host = *this;
  if (this != &Copy)
  {
    host.legs = Copy.legs;
    const_cast<double&>(host.dist) = Copy.dist;
  }
  return host;
}
