#include "include/solver.h"
#include <iostream>

int main() {
    try {
        while (true) {
            std::string input1, input2;
            std::cout << "\nВведите первое число в семеричной системе (или 'exit' для выхода): ";
            std::cin >> input1;
            if (input1 == "exit") break;
            std::cout << "Введите второе число в семеричной системе: ";
            std::cin >> input2;

            try {
                Seven seven1(input1);
                Seven seven2(input2);

                std::cout << "\nВыберите операцию:\n"
                          << "1. Сложение (Seven1 + Seven2)\n"
                          << "2. Вычитание (Seven1 - Seven2)\n"
                          << "3. Проверка на равенство (Seven1 == Seven2)\n"
                          << "4. Проверка на неравенство (Seven1 != Seven2)\n"
                          << "5. Сравнение (Seven1 < Seven2)\n"
                          << "6. Сравнение (Seven1 > Seven2)\n"
                          << "0. Выход\n"
                          << "Ваш выбор: ";

                int choice;
                std::cin >> choice;
                std::cin.ignore();

                std::cout << "\nРезультат: ";
                switch (choice) {
                    case 1: {
                        Seven result = seven1;
                        result += seven2;
                        std::cout << result.toString() << std::endl;
                        break;
                    }
                    case 2: {
                        Seven result = seven1;
                        try {
                            result -= seven2;
                            std::cout << result.toString() << std::endl;
                        } catch (const std::exception& e) {
                            std::cerr << "Ошибка при вычитании: " << e.what() << std::endl;
                        }
                        break;
                    }
                    case 3:
                        std::cout << (seven1 == seven2 ? "Да" : "Нет") << std::endl;
                        break;
                    case 4:
                        std::cout << (seven1 != seven2 ? "Да" : "Нет") << std::endl;
                        break;
                    case 5:
                        std::cout << (seven1 < seven2 ? "Да" : "Нет") << std::endl;
                        break;
                    case 6:
                        std::cout << (seven1 > seven2 ? "Да" : "Нет") << std::endl;
                        break;
                    case 0:
                        std::cout << "Выход из программы." << std::endl;
                        return 0;
                    default:
                        std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
                }

                std::cout << "\n-----\n" << std::endl;

            } catch (const std::exception& e) {
                std::cerr << "Ошибка: некорректный ввод чисел. " << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
