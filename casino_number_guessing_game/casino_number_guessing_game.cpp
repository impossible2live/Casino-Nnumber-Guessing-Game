#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int user_money = 100;
    int random_chances = 6;
    int bet_amount;
    int user_bet;
    bool exit = false;
    srand(static_cast<unsigned>(time(0)));
    cout << "����� ���������� � ������!" << endl;
    while (!exit) {
        int what_to_do;
        cout << "\n��� �� ������ �������?" << endl;
        cout << "1: ���� � ������� ���������" << endl;
        cout << "2: ���������� ������" << endl;
        cout << "3: ����� �� ������" << endl;
        cin >> what_to_do;
        switch (what_to_do) {
        case 1:
            while (true) {
                cout << "������� ����� ������: $";
                cin >> bet_amount;
                if (bet_amount > user_money) {
                    cout << "������������ ������� ��� ����� ������." << endl;
                    break;
                }
                cout << "������� ����� �� 0 �� " << random_chances - 1 << ": ";
                cin >> user_bet;
                if (user_bet < 0 || user_bet >= random_chances) {
                    cout << "�������� �����. ���������� �����." << endl;
                    break;
                }
                int casino_result = rand() % random_chances;
                if (user_bet == casino_result) {
                    user_money += bet_amount;
                    cout << "�� ��������! ���� ����� ������� � " << casino_result << "." << endl;
                    break;
                }
                else {
                    user_money -= bet_amount;
                    cout << "��������� T_T ���� �����: " << user_bet << ", ��������� ������: " << casino_result << "." << endl;
                    if (user_money <= 0) {
                        cout << "� ��� ������ ��� ����� ��� ����." << endl;
                        exit = true;
                        break;
                    }
                    char play_again;
                    cout << "������ ������� ��� ���? (y/n): ";
                    cin >> play_again;
                    if (play_again == 'n' || play_again == 'N') {
                        break;
                    }
                }
            }
            break;
        case 2:
            cout << "��� ������: $" << user_money << endl;
            break;
        case 3:
            exit = true;
            break;
        default:
            cout << "�������� �������. ���������� �����." << endl;
            break;
        }
    }
    cout << "������� �� ����! ��� ��������� ������: $" << user_money << endl;
    return 0;
}