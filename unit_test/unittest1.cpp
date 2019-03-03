#include "stdafx.h"
#include "CppUnitTest.h"
#include "../algorithm/utils/string.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{		
	TEST_CLASS(test_string)
	{
	public:
		
		TEST_METHOD(test_check_circular_shift)
		{
			string a = "ACTGACG";
			string b = "TGACGAC";

			Assert::IsTrue(check_circular_shift(a, b));
		}

	};
}