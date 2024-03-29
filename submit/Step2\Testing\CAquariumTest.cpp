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
#include"FishStar.h"
#include"CFishCarp.h"
#include"DecorCastle.h"
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
	
		const unsigned int RandomSeed = 1238197374;
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
			Assert::IsTrue(regex_search(xml, wregex(L"<\?xml.*\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));
		}

		/**
		 *  Populate an aquarium with three Beta fish
		 */
		void PopulateThreeBetas(CAquarium *aquarium)
		{
			srand(RandomSeed);
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);
		}

		void TestThreeBetas(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
		}

		/**
		 *  Populate an aquarium with 
		 */
		void PopulateAllTypes(CAquarium *aquarium)
		{
			srand(RandomSeed);
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(200, 300);
			aquarium->Add(fish1);

			shared_ptr<CDecorCastle> fish2 = make_shared<CDecorCastle>(aquarium);
			fish2->SetLocation(300, 300);
			aquarium->Add(fish2);

			shared_ptr<CFishStar> fish3 = make_shared<CFishStar>(aquarium);
			fish3->SetLocation(600, 200);
			aquarium->Add(fish3);

			shared_ptr<CFishCarp> fish4 = make_shared<CFishCarp>(aquarium);
			fish4->SetLocation(600, 100);
			aquarium->Add(fish4);

			shared_ptr<CFishAngel> fish5 = make_shared<CFishAngel>(aquarium);
			fish5->SetLocation(300, 200);
			aquarium->Add(fish5);
		}

		void TestAllTypes(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"200\" y=\"300\" speedx=\"37.0754112369152\" speedy=\"25.4814294869839\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"300\" y=\"300\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"200\" speedx=\"5.91601306192206\" speedy=\"11.1438337351604\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedx=\"2.29346598712119\" speedy=\"36.3811151463362\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"300\" y=\"200\" speedx=\"42.7915280617695\" speedy=\"7.22373119296854\"")));
			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"castle\"/><item.* type=\"star\"/><item.* type=\"carp\"/><item.* type=\"angel\"/></aqua>")));
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

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);

			TestThreeBetas(file2);
		}

		TEST_METHOD(TestCAquariumLoad)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);

			aquarium2.Load(file3);
			aquarium2.Save(file3);
			TestAllTypes(file3);
		}
		
		TEST_METHOD(TestClear)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(200, 300);
			aquarium.Add(fish1);

			shared_ptr<CDecorCastle> fish2 = make_shared<CDecorCastle>(&aquarium);
			fish2->SetLocation(300, 300);
			aquarium.Add(fish2);

			aquarium.Clear();
			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);
		}
		
	};
}