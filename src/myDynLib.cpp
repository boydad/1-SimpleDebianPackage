#include "myDynLib.h"
#include "version.h"

const char* fDyn()
{
  return "Hello from Dynamic lib";
}

const std::string getVersion()
{
  return gGIT_VERSION_SHORT;
}

int testableFunc()
{
  return 1;
}

