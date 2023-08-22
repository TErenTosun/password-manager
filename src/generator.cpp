#include "generator.hpp"

//TODO: Try to swap the characters for more security.

char random_lower() {
	return lower_eng[rand() % 26];
}

char random_upper() {
	return upper_eng[rand() % 26];
}

char random_special() {
	return specialCharacters[rand() % 23];
}

void generator_prompt() {

	int opt;
	std::cout
		<< "1) Level 1 (8 characters, 1 uppercase, no special characters)"
		<< std::endl
		<< "2) Level 2 (10 characters, 2 uppercase, 1 special character)"
		<< std::endl
		<< "3) Level 3 (12 characters, 3 uppercase, 2 special characters)"
		<< std::endl
		<< "> ";

	std::cin >> opt;
	switch (opt) {
	case 1:
		level_one();
		break;
	case 2:
		level_two();
		break;
	case 3:
		level_three();
		break;
	default:
		std::cout << "Invalid input.";
		break;
	}
	std::cout << std::endl;
	system("pause");
}

std::string level_one() {

	srand(time(0));
	std::string password = "________";

	password[0] = random_upper();
	for (int i = 1; i < 8; i++) {
		password[i] = random_lower();
	}

	std::cout << std::endl << password;
	return password;
}

std::string level_two() {

	srand(time(0));
	std::string password = "__________";

	password[0] = random_upper();
	password[1] = random_upper();
	for (int i = 2; i < 9; i++) {
		password[i] = random_lower();
	}
	password[9] = random_special();

	std::cout << std::endl << password;
	return password;
}

std::string level_three() {

	srand(time(0));
	std::string password = "____________";

	for (int i = 0; i < 3; i++) {
		password[i] = random_upper();
	}
	for (int i = 3; i < 9; i++) {
		password[i] = random_lower();
	}
	for (int i = 9; i < 11; i++) {
		password[i] = random_special();
	}
	std::cout << std::endl << password;
	return password;
}

