#include <iostream>
#include <vector>
#include <deque>
#include <random>
#include <conio.h>
#include <windows.h>

using namespace std;

const int FIELD_SIZE = 15;
const char FIELD_CH = '.';

const char APPLE_CH = '@';

const char SNAKE_HEAD_CH = 'O';
const char SNAKE_TAIL_CH = 'o';
const deque<pair<int, int>> START_POS_SNAKE = { make_pair(1, 0),  make_pair(0, 0) }; //y - 1st, x - 2nd

const int SPEED = 400;
const bool START = false;

const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';

const string GAME_OVER_MESSAGE = "          GAME OVER\n";
const string GAME_WIN_MESSAGE = "            YOU WON\n";
const char SPACE = ' ';

void FillField(vector<vector<char>>& field)
{
	vector<char> lineField;
	for (int i = 0; i < FIELD_SIZE; i++)
		lineField.push_back(FIELD_CH);
	for (int i = 0; i < FIELD_SIZE; i++)
		field.push_back(lineField);

	/*vector<vector<char>> cleanField(FIELD_SIZE, vector<char>(FIELD_SIZE, FIELD_CH));
	field = cleanField;*/
}

void AddSnakeToField(vector<vector<char>>& field, deque<pair<int, int>>& snake)
{
	for (int i = 0; i < snake.size(); i++)
		if (i == 0)
			field[snake[i].first][snake[i].second] = SNAKE_HEAD_CH;
		else
			field[snake[i].first][snake[i].second] = SNAKE_TAIL_CH;
}

void AddAppleToField(vector<vector<char>>& field, pair<int,int>& apple)
{
	field[apple.first][apple.second] = APPLE_CH;
}

bool CheckInCorrectPos(pair<int, int>& apple, deque<pair<int, int>>& snake)
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (snake[i] == apple)
			return false;
	}
	return true;
}

void DefinePosApple(pair<int, int>& apple, deque<pair<int, int>>& snake)
{
	srand(time(0));
	apple = make_pair(rand() % FIELD_SIZE, rand() % FIELD_SIZE);
	while (!CheckInCorrectPos(apple, snake))
		apple = make_pair(rand() % FIELD_SIZE, rand() % FIELD_SIZE);
}

void EatApple(deque<pair<int, int>>& snake, pair<int, int>& apple)
{
	if (snake.front() == apple)
	{
		snake.push_back(snake.back());
		DefinePosApple(apple, snake);
	}
}

void PrintField(vector<vector<char>>& field)
{
	for (int i = 0; i < field.size(); i++) {
		copy(field[i].begin(), field[i].end(), ostream_iterator<char>(cout, " "));
		cout << "\n";
	}
}

void InputDir(char& direction)
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case UP:
				direction = ((direction != DOWN) ? (UP) : (DOWN));
				break;
			case DOWN:
				direction = ((direction != UP) ? (DOWN) : (UP));
				break;
			case LEFT:
				direction = ((direction != RIGHT) ? (LEFT) : (RIGHT));
				break;
			case RIGHT:
				direction = ((direction != LEFT) ? (RIGHT) : (LEFT));
				break;
		}
	}
}

bool CheckCrossSnake(deque<pair<int, int>> snake)
{
	for (int i = 1; i < snake.size(); i++)
		if (snake.front() == snake[i])
			return true;

	return false;
}

bool CheckCrossField(deque<pair<int, int>> snake)
{
	return ((snake.front().first > FIELD_SIZE - 1) ||
		(snake.front().first < 0) ||
		(snake.front().second > FIELD_SIZE - 1) ||
		(snake.front().second < 0));
}

void MoveSnake(deque<pair<int, int>>& snake, char direction, bool& gameOver)
{
	snake.pop_back();
	switch (direction)
	{
		case UP:
			snake.push_front(make_pair(snake.front().first - 1, snake.front().second));
			break;
		case DOWN:
			snake.push_front(make_pair(snake.front().first + 1, snake.front().second));
			break;
		case LEFT:
			snake.push_front(make_pair(snake.front().first, snake.front().second - 1));
			break;
		case RIGHT:
			snake.push_front(make_pair(snake.front().first, snake.front().second + 1));
			break;
	}
}

bool CheckGameOver(deque<pair<int, int>> snake)
{
	return (CheckCrossSnake(snake) || CheckCrossField(snake));
}

bool CheckWinner(vector<vector<char>> field)
{
	for (int i = 0; i < field.size(); i++)
		for (int j = 0; j < field.size(); j++)
			if ((field[i][j] != SNAKE_HEAD_CH) || (field[i][j] != SNAKE_TAIL_CH))
				return false;
	return true;
}

void PrintMessage(bool gameOver, bool gameWin)
{
	if (gameOver && !gameWin)
		cout << GAME_OVER_MESSAGE;
	else
		cout << GAME_WIN_MESSAGE;
}

int main()
{
	vector<vector<char>> field;
	deque<pair<int, int>> snake = START_POS_SNAKE;
	pair<int,int> apple;
	DefinePosApple(apple, snake);

	bool gameOver = START, gameWin = START;
	char direction = DOWN;

	while (!gameOver && !gameWin)
	{
		EatApple(snake, apple);
		system("cls");
		field.clear();

		FillField(field);
		AddAppleToField(field, apple);
		AddSnakeToField(field, snake);

		PrintField(field);
		Sleep(SPEED);

		InputDir(direction);
		MoveSnake(snake, direction, gameOver);
		gameOver = CheckGameOver(snake);
		gameWin = CheckWinner(field);
	}
	PrintMessage(gameOver, gameWin);
	return 0;
}