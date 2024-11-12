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

using namespace std;
using vll = vector <long long>;
using vll2 = vector <vll>;
using chv = vector <char>;
using chv2 = vector <chv>;
using ull = uint64_t;
using ll = int64_t;
using ui = uint32_t;
using ush = uint16_t;
const ll INF = 1e18;
const double EPS = 1e-12;

class Rational {
private:
    //ll integer;
    double frac;

public:
    Rational(double i = 0.0) : frac(i) {}

    //ll Getinteger() const { return integer; }
    double Getfrac() const { return frac; }

    Rational operator+(const Rational& vpriv) const {
        return Rational(vpriv.Getfrac() + frac);
    }

    Rational operator-(const Rational& vpriv) const {
        return Rational(vpriv.Getfrac() - frac);
    }

   /* Rational operator*(const Rational& vpriv) const {
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
    }*/

    void print() const {
        if (frac >= 0) {
            std::cout <<frac;
        }
        else {
            std::cout <<-frac;
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
        //if (input.empty() or !std::all_of(input.begin(), input.end(), ::isdigit)) {
        //    std::cerr << "Ошибка: введено некорректное значение. Введите целое число" << std::endl;
        //    continue; //Запрашиваем ввод
        //}

        //Преобразование строки в целое число
        try {
            return std::stod(input); //Преобразование в целое число
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

    ll frac1 = getInteger("Введите 1е число: ");
    Rational number1(frac1);
    ll frac2 = getInteger("Введите 2е число: ");
    Rational number2(frac2);

    Rational sum = number1 + number2;  
    std::cout << "Сумма чисел: ";
    sum.print();
    std::cout << "\n";

    Rational diff = number1 - number2;
    std::cout << "Разность чисел: ";
    diff.print();
    std::cout << "\n";

    /*Rational mult = number1 * number2;
    std::cout << "Произведение чисел: ";
    mult.print();
    std::cout << std::endl;*/

    /*try {
        Rational Joy_Division = number1 / number2;
        std::cout << "Частное: ";
        Joy_Division.print();
        std::cout << std::endl;
    }
    catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
    }*/

    return 0;
}
