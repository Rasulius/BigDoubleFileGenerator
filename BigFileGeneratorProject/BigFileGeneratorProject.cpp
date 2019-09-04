// BigFileGeneratorProject.cpp: ���������� ����� ����� ��� ����������� ����������.
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


// ����� �������� �� �����
void showGenerateProcent(const int bigFileSize, int currentSize, int &tik){

	tik++;

	if (tik == TIKCOUNT){
		cout << currentSize / 1024 / 1024 << "Mb of " << bigFileSize / 1024 / 1024 / 1024 << " Gb \n";
		tik = 0;
	}


}
// ���������� ���� � ������� ���� double
// ����� Rasul. ��������� ���������� ��������� �������, ��� �������� ��������� �����.

void generateRandomDoubleFile(const string fileName){

	const int BIGFILESIZE = 1024 * 1024 * 1024; // ������ ����� 1 ��

	int tik = 0;

	int fileSize = 0;
	ofstream file;// �������� �����

	random_device rd;
	mt19937_64 genMarsen(rd()); // �������������� ��������� �������
	uniform_real_distribution <double> randomGenerator(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

	double randomNumber;

	// ������������ ���������� ���� ���� ������ ��� �������� �����

	file.exceptions(ofstream::failbit | ofstream::badbit | ofstream::eofbit);
	try {
		file.open(fileName);

		while (fileSize  < BIGFILESIZE) {

			randomNumber = randomGenerator(genMarsen);

			file << randomNumber << '\n'; // ������� � ����
			fileSize = (int)file.tellp(); // ������ ������	
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


