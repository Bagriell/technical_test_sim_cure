#ifndef DATA_H
#define DATA_H

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

extern const std::unordered_map<char, int> characterDict;
extern int computeScore(const std::string &word,
                        const std::unordered_map<char, int> &characterDict);
extern std::multimap<int, std::string> mapWords(std::ifstream &inputFile);
extern std::ifstream readFile(const char *fileNameArg);
extern void writeFile(const std::string &fileName,
                      const std::multimap<int, std::string> &content);

#endif  // DATA_H