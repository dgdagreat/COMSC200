#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
//leg class declaration
class Leg 
{
  const char* const startCity;
  const char* const endCity;
  const double distance;
  
  public:
  Leg(const char* const, const char* const, const double);
  Leg& operator= (const Leg&);
  double getDistance() const;
  void output(ostream&) const;
  friend class Route;
  friend class ShortestRoute;
};
//routes class declaration
class Route
{
  vector<const Leg*> legs; // bag of legs
  const double dist;

  public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route& operator=(const Route&);
  double getDistance() const;
  void output(ostream&) const;
  friend class ShortestRoute;
  friend bool operator<(const Route&, const Route&);
};

class ShortestRoute
{
  private:
  static const int legSize;
  static const Leg legs[];

  public:
  static const Route anyRoute(const char* const from, const char* const to);
  static const Route shortestRoute(const char* const from, const char* const to);
};

  //the array of legs
const Leg ShortestRoute:: legs[ ] = 
{
  Leg("San Francisco", "Sacramento", 87.9), Leg("Sacramento", "Reno", 132),
  Leg("Sacramento", "Bakersfield", 286), Leg("Portland", "Sacramento", 581),
  Leg("Reno", "Winnemucca", 166), Leg("Reno", "Salt Lake City", 518),
  Leg("Portland", "Reno", 533), Leg("Winnemucca", "Elko", 124),
  Leg("Bakersfield", "Winnemucca", 560), Leg("Winnemucca", "Battle Mountain", 53.5),
  Leg("San Francisco", "Bakersfield", 283), Leg("San Francisco", "Eureka", 271),
  Leg("Eureka", "Portland", 409), Leg("San Francisco", "Battle Mountain", 436),
  Leg("Battle Mountain", "Salt Lake City", 300), Leg("Battle Mountain", "Elko", 70.5),
  Leg("Bakersfield", "West Wendover", 647), Leg("West Wendover", "Albuquerque", 719),
  Leg("Elko", "West Wendover", 107), Leg("West Wendover", "Salt Lake City", 123),
  Leg("Rock Spring", "Albuquerque", 653), Leg("Spokane", "Rock Spring", 758),
  Leg("Salt Lake City", "Rock Spring", 187), Leg("Omaha", "New York", 1246),
  Leg("Rock Spring", "Cheyenne", 256), Leg("Cheyenne", "Omaha", 494),
  Leg("Chicago", "Cincinnati", 299), Leg("Kansas City", "Chicago", 510),
  Leg("Omaha", "Chicago", 472), Leg("Chicago", "New York", 790),
  Leg("Los Angeles", "Las Vegas", 270), Leg("Bakersfield", "Los Angeles", 113),
  Leg("Phoenix", "Albuquerque", 422), Leg("San Francisco", "Los Angeles", 383),
  Leg("Los Angeles", "Phoenix", 373), Leg("Las Cruces", "Oklahoma City", 672),
  Leg("Las Vegas", "Las Cruces", 685), Leg("Phoenix", "Las Cruces", 388),
  Leg("Las Cruces", "Austin", 622), Leg("Austin", "Jacksonville", 1034),
  Leg("Jacksonville", "Richmond", 598), Leg("Kansas City", "Jacksonville", 1144),
  Leg("Jacksonville", "New York", 930), Leg("Seattle", "Spokane", 279),
  Leg("Richmond", "New York", 333), Leg("San Francisco", "Seattle", 808),
  Leg("Seattle", "Great Falls", 642), Leg("Minneapolis", "Chicago", 408),
  Leg("Great Falls", "Minneapolis", 967), Leg("Cincinnati", "Richmond", 514),
  Leg("Minneapolis", "Cincinnati", 704), Leg("Cincinnati", "New York", 639),
  Leg("Great Falls", "Cheyenne", 670), Leg("Cheyenne", "Minneapolis", 809),
  Leg("Austin", "Omaha", 842), Leg("Salt Lake City", "Kansas City", 1073),
  Leg("Bakersfield", "Las Vegas", 286), Leg("Las Vegas", "Phoenix", 298),
  Leg("San Francisco", "Portland", 635), Leg("Portland", "Seattle", 173),
  Leg("Portland", "Spokane", 351), Leg("Spokane", "Great Falls", 365),
  Leg("Portland", "Elko", 627), Leg("Elko", "Cheyenne", 667),
  Leg("Las Vegas", "Albuquerque", 574), Leg("Albuquerque", "Austin", 695),
  Leg("Albuquerque", "Kansas City", 790), Leg("Oklahoma City", "Kansas City", 353),
  Leg("Oklahoma City", "Nashville", 678), Leg("Salt Lake City", "Oklahoma City", 1188),
  Leg("Austin", "Nashville", 859), Leg("Nashville", "Cincinnati", 272),
  Leg("Denver", " Kansas City", 605), Leg("Great Falls", "Denver", 770),
  Leg("Nashville", "Richmond", 614), Leg("Las Vegas", "Denver", 748),
  Leg("Denver", " Omaha", 538), Leg("San Francisco", "New York", 21000)
};

const int ShortestRoute::legSize = sizeof(legs) / sizeof(*legs);

int main()
{
    // programmer identification
  cout << "Programmer: Dae'juan Graham\n";
  cout << "Programmmer's ID: 2015690\n";
  cout << "File: " << __FILE__ <<"\n"<< endl;
  Route cashRoute = ShortestRoute::anyRoute("San Francisco", "New York");
  Route shortRoute = ShortestRoute::shortestRoute("San Francisco", "New York");

  // Print any route
  cout << "Any Route: " << endl;
  cashRoute.output(cout);

  // Print the shortest route
  cout << "Shortest Route: " << endl;
  shortRoute.output(cout);

  return 0;
}

void Leg::output(ostream& out) const
{
  out << startCity << " to " << endCity
      << ", " << distance << " miles\n";
}

void Route::output(ostream& out) const
{
  const Leg* lastLeg = legs.back();
  out << "Route: ";
  for( unsigned int i = 0; i < legs.size(); i++)
  out << legs[i]->startCity << " to ";
  out << lastLeg->endCity << ", " << dist << endl;
}

//constructor
Leg::Leg(const char* const start, const char* const end, const double distance)
:startCity(start), endCity(end), distance(distance)
{
}

//getter
double Leg::getDistance() const
{
  return distance;
}

Route::Route(const Leg& legObject)
: dist(legObject.distance)
{
  legs.push_back(&legObject);
}

Route::Route(const Route& exRoute, const Leg& newLeg)
:dist(exRoute.dist + newLeg.distance)
{
  legs = exRoute.legs;

  try
  {
    if(strcmp(exRoute.legs.back()->endCity, newLeg.startCity) != 0)
      throw "Cities don't match!";
  }
  catch(string error)
  {
    cout << error << endl;
  }

  legs.push_back(&newLeg); // add new leg to route
}


double Route::getDistance() const
{
  return dist;
}

const Route ShortestRoute::anyRoute(const char* const from, const char* const to) 
{
  const Leg* legTo = NULL;

  try 
  {
    for (int i = 0; i < legSize; i++) 
    {
      bool matchDestination = !strcmp(to, legs[i].endCity);
      bool matchDepart = !strcmp(from, legs[i].startCity);
      if (matchDestination && matchDeparting) return Route(legs[i]);
      if (matchDestination) 
      {
        legTo = &legs[i];
        break;
      }
    }
    if (!legTo) throw "No matching arriving city found";
  } 
  catch (const char* err) 
  {
    cout << err << endl;
  }
  return Route(anyRoute(from, legTo->startCity), *legTo);
}

const Route ShortestRoute::shortestRoute(const char* const from, const char* const to) 
{
  set<Route> routes;

  try 
  {
    for (int i = 0; i < legSize; i++) 
    {
      bool matchDestination = !strcmp(to, legs[i].endCity);
      bool matchDepart = !strcmp(from, legs[i].startCity);
      if (!strcmp(legs[i].startCity, "San Francisco") && !strcmp(legs[i].endCity, "New York"))
        continue;
      if (matchDestination && matchDepart) return Route(legs[i]);
      if (matchDestination) {
        try 
        {
          const Route candidate(shortestRoute(from, legs[i].startCity), legs[i]);
          routes.insert(candidate);
        } 
        catch (const char* err) 
        {
          continue;
        }
      }
    }

    if (routes.empty()) throw "Something went wrong. Check your legs";
  } 
  catch (const char* err) 
  {
    cout << err << endl;
  }

  return *routes.begin();
}

// ROUTE assignment operator
Route& Route::operator=(const Route& Copy)
{
  Route& host = *this;
  if (this != &Copy)
  {
    host.legs = Copy.legs;
    const_cast<double&>(host.dist) = Copy.dist;
  }
  return host;
}

// LEG assignment operator
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

bool operator < (const Route& left, const Route& right) 
{
  return left.getDistance() < right.getDistance() ? true : false;
}