#include <iostream>

#include "myDynLib.h"



int main(int argc, char** argv)
{
	std::cout<<"Hello, World! (ver."<< version() <<")\n";
  std::cout<<fDyn();
  std::cout<<std::endl;
	return 0;
}
