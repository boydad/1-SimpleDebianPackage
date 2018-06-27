#include <iostream>

#include "myDynLib.h"



int main(int argc, char** argv)
{
	std::cout<<"Hello, World!\n";
  std::cout<<"\tv"<<getVersion()<<"\n";
  std::cout<<fDyn();
  std::cout<<std::endl;
	return 0;
}
