#include "myDynLib.h"

#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE testTestableFunc

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_testableFunc1)
{
	BOOST_CHECK( testableFunc() != 0 );
}

BOOST_AUTO_TEST_SUITE_END()
