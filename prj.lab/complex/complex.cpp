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


class Complex {
private:
    double real;
    double image;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), image(i) {}

    double GetReal() const { return real; }
    double GetImage() const { return image; }

    Complex operator+(const Complex& vpriv) const {
        return Complex(vpriv.GetReal() + real, vpriv.GetImage() + image);
    }

    Complex operator-(const Complex& vpriv) const {
        return Complex(vpriv.GetReal() - real, vpriv.GetImage() - image);
    }

    Complex operator*(const Complex& vpriv) const {
        return Complex(vpriv.GetReal() * real - image * vpriv.GetImage(),
            vpriv.GetReal() * image + vpriv.GetImage() * real);
    }

    Complex operator/(const Complex& vpriv) const {
        double dop = (vpriv.GetReal() * vpriv.GetReal() + vpriv.GetImage() * vpriv.GetImage());
        if (dop == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Complex((real * vpriv.GetReal() - image * vpriv.GetImage()) / dop,
            (real * vpriv.GetImage() + image * vpriv.GetReal()) / dop);
    }

    void print() const {
        if (image >= 0) {
            std::cout << real << " + " << image << "i";
        }
        else {
            std::cout << real << " - " << -image << "i";
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

    int real1 = getInteger("Введите действительную часть 1-ого числа: ");
    int imaginary1 = getInteger("Введите мнимую часть 1-ого числа: ");
    Complex number1(real1, imaginary1);

    int real2 = getInteger("Введите действительную часть 2-ого числа: ");
    int imaginary2 = getInteger("Введите мнимую часть 2-ого числа: ");
    Complex number2(real2, imaginary2);

    Complex sum = number1 + number2;
    std::cout << "Сумма чисел: ";
    sum.print();
    std::cout << "\n";

    Complex diff = number1 - number2;
    std::cout << "Разность чисел: ";
    diff.print();
    std::cout << "\n";

    Complex mult = number1 + number2;
    std::cout << "Произведение чисел: ";
    mult.print();
    std::cout << std::endl;

    try {
        Complex Joy_Division = number1/number2;
        std::cout << "Частное: ";
        Joy_Division.print();
        std::cout << std::endl;
    }
    catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}
