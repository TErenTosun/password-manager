#pragma once
#ifndef generator
#include <iostream>
#include <ctime>

//Define usable characters in a string or an array (or map them)
const std::string specialCharacters = "!'^+%&/()=?-_>£#$½{[]}|";
const std::string lower_eng = "abcdefghijklmnopqrstuvwxyz";
const std::string upper_eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//More character support could be added if this was a professinonal app.


//Get user input.
void generator_prompt();

//Select random characters from the usable characters.

std::string level_one();
std::string level_two();
std::string level_three();

#endif