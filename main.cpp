#include "./src/generator.hpp"
#include "./src/manager.hpp"

//Password Manager Plus because it also generates passwords not just hold them.

/*
* TODOS:
* 
*	1- Enhance the password generation by randomly swapping characters.
* 
*	2- Implement credential deletion.
* 
*	3- Support for languages which use different letters/alphabets could be added.
*	i.e. Turkish (ş,ğ), German (ß, ö, ü), French (ç, é), Russian (Cyrillic Alphabet)
* 
*	4- Implement saving generated passwords into the database.
* 
*	5- If the same domain exists when saving a password, rather than only
*	printing "Domain already exists.", print out the username and password
*	of that domain.
* 
*/

void mainPrompt() {
	int opt;
	std::cout
		<< "1) Generator"
		<< std::endl
		<< "2) Manager"
		<< std::endl
		<< "> ";
	std::cin >> opt;
	switch (opt) {
	case 1:
		generator_prompt();
		break;
	case 2:
		manager_prompt();
		break;
	default:
		std::cout << "Invalid Input.";
		break;
	}
}

int main() {
	mainPrompt();
	return 0;
}