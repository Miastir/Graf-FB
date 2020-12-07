#include "pch.h"
#include "CppUnitTest.h"
#include "../Graf-FB/floid.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)// проверка расчетов алгоритма Флойда
		{
			int ish[6][6] = { {0,3,10,6,6,13},//Матрица миним остов графа, не ориентированного
						{3,0,7,3,9,12},
						{10,7,0,4,12,5},
						{6,3,4,0,12,9},
						{6,9,12,12,0,7},
						{13,12,5,9,7,0}, };

			int matrix[6][6] = { {0,3,0,0,6,20},//Матрица весов ребер графа
							{3,0,8,3,0,0},
							{0,8,0,4,0,5},
							{0,3,4,0,0,0},
							{6,0,0,0,0,7},
							{20,0,5,0,7,0},};

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++) {
					if (matrix[i][j] == 0 && (i != j)) { matrix[i][j] = 1000; }
				}
			}

			for (int k = 0; k < 6; k++)
				for (int i = 0; i < 6; i++)
					for (int j = 0; j < 6; j++)
						if (matrix[i][j] > matrix[i][k] + matrix[k][j])
							matrix[i][j] = matrix[i][k] + matrix[k][j];

			
			int l=0;

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++) {
					if ((matrix[i][j]) != (ish[i][j])) {
						l = 1;
					}
				}
			}		

				Assert::AreEqual(0, l);// сравнение массивов

					
				}


		TEST_METHOD(Test2)// проверка расчетов алгоритма Флойда
		{
			int ish[6][6] = { {0,3,10,6,22,15},//Матрица миним остов графа,  ориентированного
						{25,0,7,3,19,12},
						{18,8,0,11,12,5},
						{22,12,4,0,16,9},
						{6,9,16,12,0,21},
						{13,16,23,19,7,0}, };

			int matrix[6][6] = { {0,3,0,0,0,20},//Матрица весов ребер графа,  ориентированного
							{0,0,0,3,0,0},
							{0,8,0,0,0,5},
							{0,0,4,0,0,0},
							{6,0,0,0,0,0},
							{0,0,0,0,7,0}, };

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++) {
					if (matrix[i][j] == 0 && (i != j)) { matrix[i][j] = 1000; }
				}
			}

			for (int k = 0; k < 6; k++)
				for (int i = 0; i < 6; i++)
					for (int j = 0; j < 6; j++)
						if (matrix[i][j] > matrix[i][k] + matrix[k][j])
							matrix[i][j] = matrix[i][k] + matrix[k][j];


			int l = 0;

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++) {
					if ((matrix[i][j]) != (ish[i][j])) {
						l = 1;
					}
				}
			}

			Assert::AreEqual(0, l);// сравнение массивов


		}


		TEST_METHOD(Test3)// проверка алгоритма ввода матрицы, блокировка букв
		{
			int flag = 3;

			char ch= 'а';
			                //проверка если введена буква вместо чила
			if (ch < '0' || ch > '9') {
				while (ch < '0' || ch > '9')
				{
					//ch = 1;
					//std::cout << "Некоректный ввод, введите заново \n";
					//std::cin >> ch;
					flag = 1;
					break;
				}
			}
			else {
				//matrix[i][j] = ch - '0';
				flag = 0;
			}
			Assert::AreEqual(1, flag);// буквы блокируются

		}

	

	};
}
