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
    cout << "Добро пожаловать в казино!" << endl;
    while (!exit) {
        int what_to_do;
        cout << "\nЧто вы хотите сделать?" << endl;
        cout << "1: Идти к игровым автоматам" << endl;
        cout << "2: Посмотреть баланс" << endl;
        cout << "3: Выйти из казино" << endl;
        cin >> what_to_do;
        switch (what_to_do) {
        case 1:
            while (true) {
                cout << "Введите сумму ставки: $";
                cin >> bet_amount;
                if (bet_amount > user_money) {
                    cout << "Недостаточно средств для такой ставки." << endl;
                    break;
                }
                cout << "Введите число от 0 до " << random_chances - 1 << ": ";
                cin >> user_bet;
                if (user_bet < 0 || user_bet >= random_chances) {
                    cout << "Неверное число. Попробуйте снова." << endl;
                    break;
                }
                int casino_result = rand() % random_chances;
                if (user_bet == casino_result) {
                    user_money += bet_amount;
                    cout << "Вы выиграли! Ваше число совпало с " << casino_result << "." << endl;
                    break;
                }
                else {
                    user_money -= bet_amount;
                    cout << "Неповезло T_T Ваше число: " << user_bet << ", результат казино: " << casino_result << "." << endl;
                    if (user_money <= 0) {
                        cout << "У вас больше нет денег для игры." << endl;
                        exit = true;
                        break;
                    }
                    char play_again;
                    cout << "Хотите сыграть еще раз? (y/n): ";
                    cin >> play_again;
                    if (play_again == 'n' || play_again == 'N') {
                        break;
                    }
                }
            }
            break;
        case 2:
            cout << "Ваш баланс: $" << user_money << endl;
            break;
        case 3:
            exit = true;
            break;
        default:
            cout << "Неверная команда. Попробуйте снова." << endl;
            break;
        }
    }
    cout << "Спасибо за игру! Ваш финальный баланс: $" << user_money << endl;
    return 0;
}