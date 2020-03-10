#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<LINE> lines;
			LINE line1 = makeline(0, 0, 1, 1);
			lines.push_back(line1);
			Assert::AreEqual(calculateCrossPointsNum(lines), 0);
		}
		TEST_METHOD(TestMethod2)
		{
			vector<LINE> lines;
			LINE line1 = makeline(0, 0, 1, 1);
			LINE line2 = makeline(1, 0, 0, 1);
			LINE line3 = makeline(1, 2, 2, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(calculateCrossPointsNum(lines), 3);
		}
		TEST_METHOD(TestMethod3)
		{
			vector<LINE> lines;
			LINE line1 = makeline(0, 0, 1, 1);
			LINE line2 = makeline(0, 0, 0, 1);
			LINE line3 = makeline(0, 0, -1, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(calculateCrossPointsNum(lines), 1);
		}
		TEST_METHOD(TestMethod4)
		{
			vector<LINE> lines;
			LINE line1 = makeline(0, 0, 1, 1);
			LINE line2 = makeline(1, 0, 0, 1);
			LINE line3 = makeline(0, 0, -1, 1);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(calculateCrossPointsNum(lines), 2);
		}
	};
}
