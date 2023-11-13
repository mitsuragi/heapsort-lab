#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <filesystem>

using namespace std;

vector<double> uploadFromFile(string fileName);
void saveArray(vector<double>& Array, string fileName);
bool getFilePath(string fileName);
vector<double> getRandomArray(int size);