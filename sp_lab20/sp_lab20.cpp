#include <iostream>
#include <string>
using namespace std;

typedef struct Struct {
    char fio[100];
    char gender;
    bool marry;
    bool knowledgeOfAForeignLanguage;
    union {
        int howManyLanguages;
        char whatLanguages[100];
        int date;
    } peoplefig;
} fig;

int main() {
    setlocale(LC_ALL, "Russian");
    Struct people[100];
    int count = 0;
    int yesno = 0;
    cout << "введите количество анкет: ";
    int total;
    cin >> total;
    if (total <= 0 || total > 100) {
        cout << "error" << endl;
        return 0;
    }
    for (int i = 0; i < total; i++) {
        cout << "анкета #" << i + 1 << ":\n";
        fig f;
        char F[50], I[50], O[50];
        cout << "фамилия: ";
        cin >> F;
        cout << "имя: ";
        cin >> I;
        cout << "отчество: ";
        cin >> O;
        int pos = 0;
        for (int i = 0; F[i] != '\0'; i++) {
            f.fio[pos++] = F[i];
        }
        f.fio[pos++] = ' ';
        for (int i = 0; I[i] != '\0'; i++) {
            f.fio[pos++] = I[i];
        }
        f.fio[pos++] = ' ';
        for (int i = 0; O[i] != '\0'; i++) {
            f.fio[pos++] = O[i];
        }
        f.fio[pos] = '\0';
        cout << "пол (m - мужчина, f - женщина): ";
        cin >> f.gender;
        if (f.gender != 'm' && f.gender != 'f') {
            cout << "error" << endl;
            return 0;
        }
        cout << "семейное положение (1 - женат/замужем, 2 - нет): ";
        cin >> yesno;
        f.marry = (yesno == 1);
        cout << "знание иностранных языков (1 - знаю, 2 - не знаю): ";
        cin >> yesno;
        f.knowledgeOfAForeignLanguage = (yesno == 1);
        if (f.knowledgeOfAForeignLanguage) {
            cout << "сколько иностранных языков вы знаете?: ";
            cin >> f.peoplefig.howManyLanguages;
            cout << "какие языки?(через запятую слитно): ";
            char language[100];
            cin >> language;
            int langPos = 0;
            for (int j = 0; language[j] != '\0'; j++) {
                f.peoplefig.whatLanguages[langPos++] = language[j];
            }
            f.peoplefig.whatLanguages[langPos] = '\0';
            f.peoplefig.date = 0;
        }
        else {
            cout << "ваш год рождения?: ";
            cin >> f.peoplefig.date;
            for (int k = 0; k < 100; k++) {
                f.peoplefig.whatLanguages[k] = 0;
            }
            f.peoplefig.howManyLanguages = 0;
        }
        people[count] = f;
        count++;
    }
    cout << "список холостых мужчин без знания иностранного языка:\n";
    for (int i = 0; i < count; i++) {
        if (people[i].gender == 'm' &&
            !people[i].marry &&
            !people[i].knowledgeOfAForeignLanguage) {
            cout << people[i].fio << endl;
        }
    }
    return 0;
}
