//Определить математическое ожидание и моду для элементов целочисленной матрицы,
//попавших в заданный интервал. Размерность матрицы не более, чем 15 * 20. Формат числа ц.

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

const int ROWS = 4,
          COLUMNS = 4,
          NUMBEROFNUMBERS = 9;

tuple<int, int> enterInterval();
void createMatrx(int (*matrix)[COLUMNS]);
vector<int> getVectorOfNumbersInRange(int (*matrix)[COLUMNS], int startInterval, int endInterval);
float getMathExpectation(vector<int> vectorOfNumbersInRange);
int getSumVectorOfNumbersInRange(vector<int> vectorOfNumbersInRange);
int getFashion(vector<int> vectorOfNumbersInRange);

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

	printf("Математическое ожидание = %.2f\n", mathExpectation);
	printf("Мода = %d\n", fashion);
	printf("Матрица %d x %d\n", ROWS, COLUMNS);
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			printf("%d ", matrix[row][column]);
		}
		printf("\n");
	}
}

tuple<int, int> enterInterval()
{
	int startInterval, endInterval;
	printf("Введите интервал в котором должен производится поиск математического ожидания и моды\n");
	printf("Начальный интервал: ");
	scanf_s("%d", &startInterval);
	printf("Конечный интервал: ");
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

float getMathExpectation(vector<int> vectorOfNumbersInRange)
{
	int sum = getSumVectorOfNumbersInRange(vectorOfNumbersInRange),
	    vectorSize = vectorOfNumbersInRange.size();
	float mathExpectation = (float)sum / (float)vectorSize;
	return mathExpectation;
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

int getFashion(vector<int> vectorOfNumbersInRange)
{
	int sizeVectorOfNumbersInRange = vectorOfNumbersInRange.size(),
	    j,
	    fashion;
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
	auto vectorBegin = vectorCountNumberOfDuplicateNumbers.begin(),
	     vectorEnd = vectorCountNumberOfDuplicateNumbers.end();
	int maxNumberOfRepeatingNumbers = *std::max_element(vectorBegin, vectorEnd);
	vector<int>::iterator itr = find(vectorBegin, vectorEnd, maxNumberOfRepeatingNumbers);

	if (itr != vectorEnd)
	{
		fashion = distance(vectorBegin, itr);
	}
	return fashion;
}
