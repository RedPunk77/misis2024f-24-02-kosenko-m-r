#include <iostream>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>
#include <cmath>
#include <numeric>
#include <random>
#include <chrono>


class Rational {
private:
    double integer;
    double frac;

public:
    Rational(double r = 0.0, double i = 0.0) : integer(r), frac(i) {}

    double Getinteger() const { return integer; }
    double Getfrac() const { return frac; }

    Rational operator+(const Rational& vpriv) const {
        return Rational(vpriv.Getinteger() + integer, vpriv.Getfrac() + frac);
    }

    Rational operator-(const Rational& vpriv) const {
        return Rational(vpriv.Getinteger() - integer, vpriv.Getfrac() - frac);
    }

    Rational operator*(const Rational& vpriv) const {
        return Rational(vpriv.Getinteger() * integer - frac * vpriv.Getfrac(),
            vpriv.Getinteger() * frac + vpriv.Getfrac() * integer);
    }

    Rational operator/(const Rational& vpriv) const {
        double dop = (vpriv.Getinteger() * vpriv.Getinteger() + vpriv.Getfrac() * vpriv.Getfrac());
        if (dop == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Rational((integer * vpriv.Getinteger() - frac * vpriv.Getfrac()) / dop,
            (integer * vpriv.Getfrac() + frac * vpriv.Getinteger()) / dop);
    }

    void print() const {
        if (frac >= 0) {
            std::cout << integer << "." << frac;
        }
        else {
            std::cout << integer << "." << -frac;
        }
    }
};

//Функция получения правильно введенного целого числа
int getInteger(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input); //Чтение строки целиком

        //Удаление пробелов
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        //Проверка, содержит ли строка только цифры
        if (input.empty() or !std::all_of(input.begin(), input.end(), ::isdigit)) {
            std::cerr << "Ошибка: введено некорректное значение. Введите целое число" << std::endl;
            continue; //Запрашиваем ввод
        }

        //Преобразование строки в целое число
        try {
            return std::stoi(input); //Преобразование в целое число
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Ошибка: введено некорректное значение. Введите целое число" << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cerr << "Ошибка: переполнение целочисленного типа int" << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int integer1 = getInteger("Введите целую часть 1-ого числа: ");
    int frac1= getInteger("Введите дробную часть 1-ого числа: ");
    Rational number1(integer1, frac1);

    int integer2 = getInteger("Введите целую часть 2-ого числа: ");
    int frac2 = getInteger("Введите дробную часть 2-ого числа: ");
    Rational number2(integer2, frac2);

    Rational sum = number1 + number2;
    std::cout << "Сумма чисел: ";
    sum.print();
    std::cout << "\n";

    Rational diff = number1 - number2;
    std::cout << "Разность чисел: ";
    diff.print();
    std::cout << "\n";

    Rational mult = number1 + number2;
    std::cout << "Произведение чисел: ";
    mult.print();
    std::cout << std::endl;

    try {
        Rational Joy_Division = number1 / number2;
        std::cout << "Частное: ";
        Joy_Division.print();
        std::cout << std::endl;
    }
    catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}
