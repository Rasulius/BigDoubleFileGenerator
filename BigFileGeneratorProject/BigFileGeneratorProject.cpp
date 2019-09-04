// BigFileGeneratorProject.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <tchar.h>
#include <iostream>     
#include <fstream>
#include <limits>       
#include <random>
#include <chrono>
#include <string.h>
#include <stdexcept>


const int TIKCOUNT = 100000;

using namespace std;


// Вывод процента на экран
void showGenerateProcent(const int bigFileSize, int currentSize, int &tik){

	tik++;

	if (tik == TIKCOUNT){
		cout << currentSize / 1024 / 1024 << "Mb of " << bigFileSize / 1024 / 1024 / 1024 << " Gb \n";
		tik = 0;
	}


}
// Генерирует файл с данными типа double
// Автор Rasul. Генератор использует генератор Марсена, для создания случайных чисел.

void generateRandomDoubleFile(const string fileName){

	const int BIGFILESIZE = 1024 * 1024 * 1024; // размер файла 1 гб

	int tik = 0;

	int fileSize = 0;
	ofstream file;// Выходной поток

	random_device rd;
	mt19937_64 genMarsen(rd()); // Инициализируем генератор Марсена
	uniform_real_distribution <double> randomGenerator(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

	double randomNumber;

	// Обрабатываем исключение если была ошибка при открытии файла

	file.exceptions(ofstream::failbit | ofstream::badbit | ofstream::eofbit);
	try {
		file.open(fileName);

		while (fileSize  < BIGFILESIZE) {

			randomNumber = randomGenerator(genMarsen);

			file << randomNumber << '\n'; // выводим в файл
			fileSize = (int)file.tellp(); // Узнаем размер	
			showGenerateProcent(BIGFILESIZE, fileSize, tik);

		}

		file.close();

	}
	catch (const ifstream::failure& e) {
		cout << "Exception write file";
	}
}


int _tmain(int argc, _TCHAR* argv[]){
	generateRandomDoubleFile("generate_unsorted_double.txt");
	std::cout << "random file generated";
	return 0;
}


