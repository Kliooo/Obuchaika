#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>
#include <random>

namespace {
	static const char SPACE = ' ';

	bool example(int x, int y, int ans, char operation);
}

const VBek::MenuItem* VBek::show_menu(const MenuItem* current) {
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Обучайка > ";

	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;

	return current->children[user_input];
}

const VBek::MenuItem* VBek::exit(const MenuItem* current) {
	std::exit(0);
}

const VBek::MenuItem* VBek::go_back(const MenuItem* current) {
	return current->parent->parent;
}

const VBek::MenuItem* VBek::algebra_summ(const MenuItem* current) {
	std::mt19937 mt(time(nullptr));

	bool exit = 0;
	do {
		int first_number = mt() % 10;
		int second_number = mt() % 10;
		exit = example(first_number, second_number, first_number + second_number, '+');
	} while (!exit);
	return current->parent;
}

const VBek::MenuItem* VBek::algebra_substrect(const MenuItem* current) {
	std::mt19937 mt(time(nullptr));

	bool exit = 0;
	do {
		int first_number = mt() % 10;
		int second_number = mt() % 10;
		exit = example(first_number, second_number, first_number - second_number, '-');
	} while (!exit);
	return current->parent;
}

const VBek::MenuItem* VBek::algebra_multiply(const MenuItem* current) {
	std::mt19937 mt(time(nullptr));

	bool exit = 0;
	do {
		int first_number = mt() % 10;
		int second_number = mt() % 10;
		exit = example(first_number, second_number, first_number * second_number, '*');
	} while (!exit);
	return current->parent;
}

const VBek::MenuItem* VBek::algebra_divide(const MenuItem* current) {
	std::mt19937 mt(time(nullptr));

	bool exit = 0;
	do {
		int first_number = mt() % 100;
		int second_number = mt() % 10 + 1;
		exit = example(first_number, second_number, first_number / second_number, '/');
	} while (!exit);
	return current->parent;
}

const VBek::MenuItem* VBek::mathan_differentiation(const MenuItem* current) {
	//TODO
	return current->parent;
}

const VBek::MenuItem* VBek::mathan_integration(const MenuItem* current) {
	//TODO
	return current->parent;
}

namespace {
	bool example(int first_number, int second_number, int ans, char operation) {
		int user_input;
		do {
			std::cout << "Чтобы выйти введите Ъ" << std::endl;
			std::cout << "Реши данный пример: " << first_number << SPACE << operation << SPACE << second_number << " = ";

			std::cin >> user_input;
			std::cout << std::endl;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				return true;
			}

			if (user_input == ans) {
				std::cout << "Верно, го ещё" << std::endl;
			} else {
				std::cout << "Неверно, решай заново" << std::endl;
			}
		} while (user_input != ans);

		return false;
	}
}