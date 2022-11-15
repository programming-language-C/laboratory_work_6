//Определить математическое ожидание и моду для элементов целочисленной матрицы,
//попавших в заданный интервал. Размерность матрицы не более, чем 15 * 20. Формат числа ц.

#include <iostream>
#include <tuple>
using namespace std;

//tuple<int, int> enterSizeOfMatrix();
tuple<int, int> enterInterval();
void createMatrix(int matrix);

const int ROWS = 5;
const int COLUMNS = 7;

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
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			matrix[row][column] = rand() % 10;
		}
	}
}

int getSumMatrix(int (*matrix)[COLUMNS], int startInterval, int endInterval)
{
	bool isIncludedInInterval;
	int sumMatrix = 0;
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			isIncludedInInterval = startInterval <= matrix[row][column] <= endInterval;
			if (isIncludedInInterval)
				sumMatrix += matrix[row][column];
		}
	}
	return sumMatrix;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int matrix[ROWS][COLUMNS],
	    startInterval,
	    endInterval,
	    sumMatrix;
	createMatrx(matrix);
	tie(startInterval, endInterval) = enterInterval();



	//Проверить результат!!!
	sumMatrix = getSumMatrix(matrix, startInterval, endInterval);
	printf("Sum: %d \n", sumMatrix);

	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			printf("%d, ", matrix[row][column]);
		}
	}
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

void createMatrix(int matrix[ROWS][COLUMNS], int ROWS, int COLUMNS)
{
	srand(time(NULL)); //рандомизация - инициализация ДСЧ

	int BORDER_RANDOMAZER = 9, randomNumber;
	for (int row = 0; row < ROWS; row++)
	{
		for (int column = 0; column < COLUMNS; column++)
		{
			matrix[row][column] = 10;
			//matrix[row] = new int[rows];
			//randomNumber = (rand() / RAND_MAX) * BORDER_RANDOMAZER;
			//matrix[row][column] = randomNumber;
			//cout << matrix[row][column];
		}
	}
}
