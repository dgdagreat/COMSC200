#include <iostream> 
#include <set> 
#include <iterator> 

using namespace std; 

int main() 
{ 
  set <int> a;               
  a.insert(98); 
  a.insert(24); 
  a.insert(16); 
  
  set <int> :: iterator i; 
  
  i=a.begin();
    cout<<*i<<endl;
}