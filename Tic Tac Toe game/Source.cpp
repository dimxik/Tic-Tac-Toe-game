#include <iostream>
#include<conio.h>
#include <Windows.h>
using namespace std;

const int rows = 3;
const int cols = 3;
bool win = false;
char map[rows][cols] = { {'1', '2', '3'},
						{'4' ,'5' ,'6' },
						{'7' ,'8' ,'9' } };
bool isMoveValid(int move)
{
	int row = (move - 1) / cols;
	int col = (move - 1) % cols;
	return (map[row][col] != 'X' && map[row][col] != '0');
}
int draw = 0;  //������� ��� �����

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
void drawMap()
{
	system("cls");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "| " << map[i][j] << " |";
		}
		cout << endl;
		cout << "-------------";
		cout << endl;
	}
}

char checkWin()
{
	// �������� �� �����������
	for (int i = 0; i < rows; i++) {
		if (map[i][0] == map[i][1] && map[i][1] == map[i][2]) {
			return map[i][0];
		}
	}

	// �������� �� ���������
	for (int i = 0; i < cols; i++) {
		if (map[0][i] == map[1][i] && map[1][i] == map[2][i]) {
			return map[0][i];
		}
	}

	// �������� �� ���������
	if ((map[0][0] == map[1][1] && map[1][1] == map[2][2]) || (map[0][2] == map[1][1] && map[1][1] == map[2][0])) {
		return map[1][1];
	}

	// �����
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (map[i][j] != 'X' && map[i][j] != '0') {
				return ' ';
			}
		}
	}

	return 'D';
}

void makeMove(char symbol, int move)
{
	int row = (move - 1) / cols;
	int col = (move - 1) % cols;
	map[row][col] = symbol;
}

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	string playX = "�������";
	string play0 = "�����";
	bool move = true;
	int statisticsX = 0;
	int statistics0 = 0;
	while (true) {
	menu:
		system("cls");
		cout << "����� ���������� � ���� �������� � ������" << endl << endl;
		cout << "[ 1 ]������ ���� �� �����\n\n";
		cout << "[ 2 ]������ ���� ������ �����\n\n";
		cout << "[ 3 ]���������\n\n";
		cout << "[ 4 ]����������\n\n";
		cout << "[ 5 ]�����\n\n";
		string choice;

		cout << "����: ";
		cin >> choice;




		if (choice == "3") {
			system("cls");

			cout << "������� ������� ������� ������: ";
			cin >> playX;
			cout << "������� ������� ������� ������: ";
			cin >> play0;

			cout << "���� �������� - " << playX << " � " << play0;
			system("pause");
			goto menu;




		}
		else if (choice == "1") {
			while (true) {

				if (move == true) {
					move = false;
				}
				else {
					move = true;
				}

				system("cls");
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						if (map[i][j] == 'X') {
							SetColor(4, 0);
							cout << "| " << map[i][j] << " |";
							SetColor(15, 0);

						}
						else  if (map[i][j] == '0') {
							SetColor(2, 0);
							cout << "| " << map[i][j] << " |";
							SetColor(15, 0);
						}
						else {
							cout << "| " << map[i][j] << " |";
						}




					}
					cout << "\n";
					cout << "---------------";
					cout << "\n";
				}
				;
				if (move == true) {

					cout << "����� \x1b[92m0\x1b[0m\n";
				}
				else if (move == false) {
					cout << "����� \x1b[91mX\x1b[0m\n";
				}

				//�������� �� �������
				//���� �� �����

				if (map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X') {
					cout << "������� " << playX;								//������ ������� 1,2,3
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X') {
					cout << "������� " << playX;						//2 ������� 4,5,6
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X') {
					cout << "������� " << playX;						//3 ������� 7,8,9
					system("pause");
					statisticsX++;
					break;
				}

				else if (map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X') {
					cout << "������� " << playX;								//������ ������� 1,4,7
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X') {
					cout << "������� " << playX;								//2 ������� 2,5,8
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X') {
					cout << "������� " << playX;								//3 ������� 3,6,9
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X') {
					cout << "������� " << playX;								//��������� 1,5,9
					system("pause");
					statisticsX++;
					break;
				}
				else if (map[2][0] == 'X' && map[1][1] == 'X' && map[0][2] == 'X') {
					cout << "������� " << playX;								//��������� 3,5,7
					system("pause");
					statisticsX++;
					break;
				}





				else if (map[0][0] == '0' && map[0][1] == '0' && map[0][2] == '0') {
					cout << "������� " << play0;								//������ ������� 1,2,3
					system("pause");
					statistics0++;
					break;
				}
				else if (map[1][0] == '0' && map[1][1] == '0' && map[1][2] == '0') {
					cout << "������� " << play0;							//2 ������� 4,5,6
					system("pause");
					statistics0++;
					break;
				}
				else if (map[2][0] == '0' && map[2][1] == '0' && map[2][2] == '0') {
					cout << "������� " << play0;							//3 ������� 7,8,9
					system("pause");
					statistics0++;
					break;
				}


				else if (map[0][0] == '0' && map[1][0] == '0' && map[2][0] == '0') {
					cout << "������� " << play0;									//������ ������� 1,4,7
					system("pause");
					statistics0++;
					break;
				}
				else if (map[0][1] == '0' && map[1][1] == '0' && map[2][1] == '0') {
					cout << "������� " << play0;									//2 ������� 2,5,8
					system("pause");
					statistics0++;
					break;
				}
				else if (map[0][2] == '0' && map[1][2] == '0' && map[2][2] == '0') {
					cout << "������� " << play0;									//3 ������� 3,6,9
					system("pause");
					statistics0++;
					break;
				}
				else if (map[0][0] == '0' && map[1][1] == '0' && map[2][2] == '0') {
					cout << "������� " << play0;									//��������� 1,5,9
					system("pause");
					statistics0++;
					break;
				}
				else if (map[2][0] == '0' && map[1][1] == '0' && map[0][2] == '0') {
					cout << "������� " << play0;									//��������� 3,5,7
					system("pause");
					statistics0++;
					break;
				}

				else if (map[0][0] != '1' && map[0][1] != '2' && map[0][2] != '3' &&
					map[1][0] != '4' && map[1][1] != '5' && map[1][2] != '6' &&
					map[2][0] != '7' && map[2][1] != '8' && map[2][2] != '9') {
					cout << "�����\n";
					system("pause");
					break;

				}

				if (win == true)
				{
					goto menu;
				}
				char play = _getch();

				switch (play) {
				case '1':
					if (map[0][0] == 'X' || map[0][0] == '0') break;
					if (move == false) {
						map[0][0] = 'X';
					}
					else {
						map[0][0] = '0';
					}
					break;
				case '2':
					if (map[0][1] == 'X' || map[0][1] == '0') break;
					if (move == false) {
						map[0][1] = 'X';
					}
					else {
						map[0][1] = '0';
					}
					break;
				case '3':
					if (map[0][2] == 'X' || map[0][2] == '0') break;
					if (move == false) {
						map[0][2] = 'X';
					}
					else {
						map[0][2] = '0';
					}
					break;
				case '4':
					if (map[1][0] == 'X' || map[1][0] == '0') break;
					if (move == false) {
						map[1][0] = 'X';
					}
					else {
						map[1][0] = '0';
					}
					break;
				case '5':
					if (map[1][1] == 'X' || map[1][1] == '0') break;
					if (move == false) {
						map[1][1] = 'X';
					}
					else {
						map[1][1] = '0';
					}
					break;
				case '6':
					if (map[1][2] == 'X' || map[1][2] == '0') break;
					if (move == false) {
						map[1][2] = 'X';
					}
					else {
						map[1][2] = '0';
					}
					break;
				case '7':
					if (map[2][0] == 'X' || map[2][0] == '0') break;
					if (move == false) {
						map[2][0] = 'X';
					}
					else {
						map[2][0] = '0';
					}
					break;
				case '8':
					if (map[2][1] == 'X' || map[2][1] == '0') break;
					if (move == false) {
						map[2][1] = 'X';
					}
					else {
						map[2][1] = '0';
					}
					break;

				case '9':
					if (map[2][2] == 'X' || map[2][2] == '0') break;
					if (move == false) {
						map[2][2] = 'X';
					}
					else {
						map[2][2] = '0';
					}
					break;



				}

			}
		}
		else if (choice == "2") {
			srand(time(NULL));
			bool playerTurn = true;
			char playerSymbol = 'X';
			char computerSymbol = '0';

			while (true) {
				drawMap();

				if (playerTurn) {
					int move;
					cout << "��� ��� (1-9): ";
					cin >> move;

					if (!isMoveValid(move)) {
						cout << "�������� ���! ���������� �����." << endl;
						continue;
					}

					makeMove(playerSymbol, move);
				}
				else {
					// ��� ����������
					int availableMoves[rows * cols];
					int numAvailableMoves = 0;

					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if (map[i][j] != 'X' && map[i][j] != '0') {
								availableMoves[numAvailableMoves++] = i * cols + j + 1;
							}
						}
					}

					if (numAvailableMoves > 0) {
						int randomIndex = rand() % numAvailableMoves;
						makeMove(computerSymbol, availableMoves[randomIndex]);
					}
				}

				char result = checkWin();
				if (result == 'X') {
					drawMap();
					cout << "�� ��������!" << endl;
					break;
				}
				else if (result == '0') {
					drawMap();
					cout << "��������� �������!" << endl;
					break;
				}
				else if (result == 'D') {
					drawMap();
					cout << "�����!" << endl;
					break;
				}

				playerTurn = !playerTurn;
			}


		}

		else if (choice == "4") {
			system("cls");
			cout << "\x1b[91m���������� ����� ��������: \x1b[0m ";
			cout << statisticsX << endl;
			cout << "\x1b[92m���������� ����� ������: \x1b[0m ";
			cout << statistics0 << endl;
			system("pause");
			goto menu;

		}
		else if (choice == "5") {
			cout << "��� ��� �����!" << endl;
			return 0;

		}


	}

}
