/**
 * \file CAquariumTest.cpp
 *
 * \author kunyu chen
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishAngel.h"
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include<memory>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	
		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring &filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		/**
	* Test to ensure an aquarium .aqua file is empty
	*/
		void TestEmpty(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

		}

	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}
		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;
		
			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish1);
			aquarium.Add(fish2);
			///If two images are on top of each other
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2,
				L"Testing fish at 100, 200");
			Assert::IsFalse(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");
			Assert::IsTrue(aquarium.HitTest(200, 100) == nullptr,
				L"Testing empty aquarium");
		}
		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			//TestEmpty(file1);
		}
	};
}