#include "pch.h"
#include "CppUnitTest.h"
#include "../CodeProject/array/BinaryArrSort.h"
#include "../CodeProject/string/ReverseWords.h"
#include "../CodeProject/array/ArrangePositiveNegativeNumbers.h"
#include "../CodeProject/careercup/LeastNumberOfPerfectSquaresToReachN.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace PracticeCodeTest
{
	TEST_CLASS(PracticeCodeTest)
	{
	public:
		TEST_METHOD(ArrangePositiveNegativeNumbersTest) {
			ArrangePositiveNegativeNumbers obj;
			vector<int> test = { 1, 2, 3, -23, -1, -1, -2, -3, -12, -24, -121,11, 12, 12, 1212 };
			vector<int> expected = { -23, -1, -1, -2, -3, -12, -24, -121, 1, 2, 3, 11, 12, 12, 1212 };
			cout << "Input: ";
			for (auto i : test) cout << i << " ";
			cout << "Output: ";
			obj.arrangeNumbersNormalSort(test);
			for (auto i : test) cout << i << " ";
			cout << endl;
			//Assert::AreEqual(expected, test);
			obj.arrangeNumbersMergeSort(test);
			//Assert::AreEqual(expected, test);
		}

		//TEST_METHOD(BinaryArraySortTest)
		//{
		//    BinaryArrSort obj;
		//    vector<pair<vector<int>, vector<int>>> arrs = {
		//        {{},{}},
		//        {{0},{0}},
		//        {{1},{1}},
		//        {{0,0},{0,0}},
		//        {{1,1},{1,1}},
		//        {{0,1},{0,1}},
		//        {{0,1,0},{0,0,1}},
		//        {{1,0,1},{0,1,1}},
		//        {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
		//        {{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
		//        {{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },{0, 0, 0, 0, 0, 0, 0, 0, 1, 1}},
		//        {{ 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 }, {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}}
		//    };
		//    for (auto& arr : arrs) {
		//        obj.sort1(arr.first);
		//        //Assert::IsTrue(arr.second == arr.first);
		//    }
		//    for (auto& arr : arrs) {
		//        obj.sort2(arr.first);
		//        //Assert::IsTrue(arr.second == arr.first);
		//    }
		//}

		TEST_METHOD(ReverseWordTest)
		{
			ReverseWords obj;
			{
				string s;
				obj.reverse(s);
				Assert::AreEqual(s, s);
			}
			{
				string s = "a";
				obj.reverse(s);
				Assert::AreEqual(s, s);
			}
			{
				string s = "abc";
				obj.reverse(s);
				Assert::AreEqual(s, s);
			}
			{
				string original = "abc def";
				string expected = "def abc";
				obj.reverse(original);
				Assert::AreEqual(expected, original);
			}
			{
				string original = "this is me";
				string expected = "me is this";
				obj.reverse(original);
				Assert::AreNotEqual(string("siht si em"), original);
				Assert::AreNotEqual(string("this is me"), original);
				Assert::AreNotEqual(string("siht is me"), original);
				Assert::AreEqual(expected, original);
			}
		}

		TEST_METHOD(LeastNumberOfPerfectSquaresToReachN)
		{
			LeastNumberOfPerfectSquaresToReachN::test();
		}
	};
}
