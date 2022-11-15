//Определить математическое ожидание и моду для элементов целочисленной матрицы,
//попавших в заданный интервал. Размерность матрицы не более, чем 15 * 20. Формат числа ц.

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

//int getArrOfNumbersInRange(int (*matrix)[COLUMNS], int startInterval, int endInterval)
//{
//	bool isIncludedInInterval;
//	int arrOfNumbersInRange = new;
//	for (int row = 0; row < ROWS; row++)
//	{
//		for (int column = 0; column < COLUMNS; column++)
//		{
//			isIncludedInInterval = startInterval <= matrix[row][column] && matrix[row][column] <= endInterval;
//			if (isIncludedInInterval)
//				sumMatrix += matrix[row][column];
//		}
//	}
//}

int getSumMatrix(int (*matrix)[COLUMNS], int startInterval, int endInterval)
{
	bool isIncludedInInterval;
	int sumMatrix = 0;
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			isIncludedInInterval = startInterval <= matrix[row][column] && matrix[row][column] <= endInterval;
			if (isIncludedInInterval)
				sumMatrix += matrix[row][column];
		}
	}
	return sumMatrix;
}

float getMathExpectation(int sum)
{
	int numberOfNumbers = ROWS * COLUMNS,
	    mathExpectation = sum / numberOfNumbers;
	return mathExpectation;
}

//void createNumberRepetitionsNumbers(int arrOfNumberOfRepeatedNumbers)
//{
//	for (int i = 0; i <= NUMBEROFNUMBERS; i++)
//		arrOfNumberOfRepeatedNumbers;
//}

//int getFashion(int* matrix, int a, int b)
//{
//}

int main()
{
	setlocale(LC_ALL, "ru");

	vector<int> ivector;
	for (int i = 0; i < COLUMNS; i++)
	{
		ivector.push_back(i);
	}
	ivector.reserve(COLUMNS);

	ivector.push_back(12);
	/*int matrix[ROWS][COLUMNS],
	    arrOfNumberOfRepeatedNumbers[NUMBEROFNUMBERS],
	    startInterval,
	    endInterval,
	    sumMatrix;
	float mathExpectation;
	createMatrx(matrix);
	tie(startInterval, endInterval) = enterInterval();
	sumMatrix = getSumMatrix(matrix, startInterval, endInterval);
	mathExpectation = getMathExpectation(sumMatrix);*/
	//createNumberRepetitionsNumbers();

	//for (int row = 0; row < ROWS; row++)
	//{
	//	for (int column = 0; column < COLUMNS; column++)
	//	{
	//		printf("%d, ", matrix[row][column]);
	//	}
	//}
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
