#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11_2/PR11_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            char inputFileName[] = "testInputFile.bin";
            char outputFileName[] = "testOutputFile.bin";
            std::ofstream inputFile(inputFileName, std::ios::binary);
            inputFile << "infohjy";
            inputFile.close();

            ProcessBIN(inputFileName, outputFileName);


            std::ifstream outputFile(outputFileName, std::ios::binary);
            std::stringstream buffer;
            buffer << outputFile.rdbuf();
            std::string result = buffer.str();

            Assert::AreEqual(std::string("info"), result);

		}
	};
}
