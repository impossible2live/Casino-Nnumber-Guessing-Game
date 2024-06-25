#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int user_money = 100;
    const int random_chances = 6;
    int bet_amount;
    int user_bet;
    bool exit = false;
    srand(static_cast<unsigned>(time(0)));
    cout << "Äîáðî ïîæàëîâàòü â êàçèíî!" << endl;
    while (!exit) {
        int what_to_do;
        cout << "\n×òî âû õîòèòå ñäåëàòü?" << endl;
        cout << "1: Èäòè ê èãðîâûì àâòîìàòàì" << endl;
        cout << "2: Ïîñìîòðåòü áàëàíñ" << endl;
        cout << "3: Âûéòè èç êàçèíî" << endl;
        cin >> what_to_do;
        switch (what_to_do) {
        case 1:
            while (true) {
                cout << "Ââåäèòå ñóììó ñòàâêè: $";
                cin >> bet_amount;
                if (bet_amount > user_money) {
                    cout << "Íåäîñòàòî÷íî ñðåäñòâ äëÿ òàêîé ñòàâêè." << endl;
                    break;
                }
                cout << "Ââåäèòå ÷èñëî îò 0 äî " << random_chances - 1 << ": ";
                cin >> user_bet;
                if (user_bet < 0 || user_bet >= random_chances) {
                    cout << "Íåâåðíîå ÷èñëî. Ïîïðîáóéòå ñíîâà." << endl;
                    break;
                }
                int casino_result = rand() % random_chances;
                if (user_bet == casino_result) {
                    user_money += bet_amount;
                    cout << "Âû âûèãðàëè! Âàøå ÷èñëî ñîâïàëî ñ " << casino_result << "." << endl;
                    break;
                }
                else {
                    user_money -= bet_amount;
                    cout << "Íåïîâåçëî T_T Âàøå ÷èñëî: " << user_bet << ", ðåçóëüòàò êàçèíî: " << casino_result << "." << endl;
                    if (user_money <= 0) {
                        cout << "Ó âàñ áîëüøå íåò äåíåã äëÿ èãðû." << endl;
                        exit = true;
                        break;
                    }
                    char play_again;
                    cout << "Õîòèòå ñûãðàòü åùå ðàç? (y/n): ";
                    cin >> play_again;
                    if (play_again == 'n' || play_again == 'N') {
                        break;
                    }
                }
            }
            break;
        case 2:
            cout << "Âàø áàëàíñ: $" << user_money << endl;
            break;
        case 3:
            exit = true;
            break;
        default:
            cout << "Íåâåðíàÿ êîìàíäà. Ïîïðîáóéòå ñíîâà." << endl;
            break;
        }
    }
    cout << "Ñïàñèáî çà èãðó! Âàø ôèíàëüíûé áàëàíñ: $" << user_money << endl;
    return 0;
}
