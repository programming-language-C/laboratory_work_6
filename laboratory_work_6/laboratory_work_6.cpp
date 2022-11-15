//Определить математическое ожидание и моду для элементов целочисленной матрицы,
//попавших в заданный интервал. Размерность матрицы не более, чем 15 * 20. Формат числа ц.

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

//tuple<int, int> enterSizeOfMatrix();
tuple<int, int> enterInterval();
void createMatrix(int matrix);

const int ROWS = 5,
          COLUMNS = 7,
          NUMBEROFNUMBERS = 9;

tuple<int, int> enterInterval()
{
	int startInterval, endInterval;
	printf("Введите интервал в котором должен производится поиск математического ожидания и моды\n");
	printf("a: ");
	scanf_s("%d", &startInterval);
	printf("b: ");
	scanf_s("%d", &endInterval);
	return make_tuple(startInterval, endInterval);
}

void createMatrx(int (*matrix)[COLUMNS])
{
	srand(time(NULL)); //рандомизация - инициализация ДСЧ
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			matrix[row][column] = rand() % 10;
		}
	}
}

vector<int> getVectorOfNumbersInRange(int (*matrix)[COLUMNS], int startInterval, int endInterval)
{
	bool isIncludedInInterval;
	vector<int> vectorOfNumbersInRange;
	int numberOfElementsInInterval = 0;
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			isIncludedInInterval = startInterval <= matrix[row][column] && matrix[row][column] <= endInterval;
			if (isIncludedInInterval)
			{
				vectorOfNumbersInRange.push_back(matrix[row][column]);
				numberOfElementsInInterval += 1;
			}
		}
	}
	//задаёт размерность вектора
	vectorOfNumbersInRange.reserve(numberOfElementsInInterval);
	return vectorOfNumbersInRange;
}


int getSumVectorOfNumbersInRange(vector<int> vectorOfNumbersInRange)
{
	int vectorSize = vectorOfNumbersInRange.size(),
	    sumVectorOfNumbersInRange = 0;
	for (int i = 0; i < vectorSize; i++)
	{
		sumVectorOfNumbersInRange += vectorOfNumbersInRange.at(i);
	}
	return sumVectorOfNumbersInRange;
}

float getMathExpectation(vector<int> vectorOfNumbersInRange)
{
	int sum = getSumVectorOfNumbersInRange(vectorOfNumbersInRange),
	    numberOfNumbers = ROWS * COLUMNS;
	double mathExpectation = (float)sum / (float)numberOfNumbers;
	return mathExpectation;
}

//void countNumberOfDuplicateNumbers(int arrOfNumberOfRepeatedNumbers)
//{
//	for (int i = 0; i <= NUMBEROFNUMBERS; i++)
//		arrOfNumberOfRepeatedNumbers;
//}

int getFashion(vector<int> vectorOfNumbersInRange)
{
	int sizeVectorOfNumbersInRange = vectorOfNumbersInRange.size(),
	    j;
	vector<int> vectorCountNumberOfDuplicateNumbers(NUMBEROFNUMBERS);
	for (int i = 0; i < sizeVectorOfNumbersInRange; i++)
	{
		for (int j = 1; j <= NUMBEROFNUMBERS; j++)
		{
			if (j == vectorOfNumbersInRange.at(i))
			{
				vectorCountNumberOfDuplicateNumbers[j] += 1;
				break;
			}
		}
	}
	int fashion = max_element(vectorCountNumberOfDuplicateNumbers.begin(), vectorCountNumberOfDuplicateNumbers.end());
	return fashion;
}

void main()
{
	setlocale(LC_ALL, "ru");

	int matrix[ROWS][COLUMNS],
	    arrOfNumberOfRepeatedNumbers[NUMBEROFNUMBERS],
	    startInterval,
	    endInterval,
	    sumMatrix,
	    fashion;
	vector<int> vectorOfNumbersInRange;
	float mathExpectation;

	createMatrx(matrix);
	tie(startInterval, endInterval) = enterInterval();
	vectorOfNumbersInRange = getVectorOfNumbersInRange(matrix, startInterval, endInterval);
	mathExpectation = getMathExpectation(vectorOfNumbersInRange);
	fashion = getFashion(vectorOfNumbersInRange);
	countNumberOfDuplicateNumbers();

	/*for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			printf("%d, ", matrix[row][column]);
		}
	}*/
}

//tuple<int, int> enterSizeOfMatrix()
//{
//	int rows, columns;
//
//	while (true)
//	{
//		cout << "Введите количество строк в матрице (не больше 15): ";
//		cin >> rows;
//
//		cout << "Введите количество столбцов в матрице (не больше 20): ";
//		cin >> columns;
//
//		bool isCorrectMatrix = rows <= 15 && columns <= 20;
//
//		if (isCorrectMatrix)
//			break;
//
//		cout << "Ошибка: количество строк в матрице не должно превышать 15 и количество столбцов не должно превышать 20"
//			<< endl;
//	}
//
//	return make_tuple(rows, columns);
//}
