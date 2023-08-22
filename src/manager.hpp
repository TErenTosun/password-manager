#pragma once
#ifndef manager

#include <iostream>
#include <fstream>
#include <string>

void databaseCheck(std::string);

//Enter username and password you use on a site
//Save them on a database (or a text file)
void manager_prompt();
int saveCredentials();

//Retrive username and password based on the domain name
int getCredentials();

#endif