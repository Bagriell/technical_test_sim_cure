#include "word_mapping.hpp"

// Character-to-Integer Dictionary.
const std::unordered_map<char, int> characterDict = {
    {'A', 32}, {'B', 36}, {'C', 33}, {'D', 40}, {'E', 41}, {'F', 47}, {'G', 31},
    {'H', 27}, {'I', 49}, {'J', 28}, {'K', 30}, {'L', 42}, {'M', 29}, {'N', 38},
    {'O', 51}, {'P', 43}, {'Q', 45}, {'R', 39}, {'S', 35}, {'T', 52}, {'U', 37},
    {'V', 46}, {'W', 34}, {'X', 48}, {'Y', 44}, {'Z', 50}, {'é', 60}, {'è', 61},
    {'ê', 62}, {'à', 63}, {'â', 64}, {'ë', 65}, {'û', 66}, {'ù', 67}, {'î', 68},
    {'ç', 69}, {'ô', 70}, {'ö', 71}, {'ü', 72}, {'a', 1},  {'b', 4},  {'c', 5},
    {'d', 8},  {'e', 10}, {'f', 11}, {'g', 13}, {'h', 16}, {'i', 18}, {'j', 19},
    {'k', 21}, {'l', 21}, {'m', 23}, {'n', 2},  {'o', 3},  {'p', 6},  {'q', 7},
    {'r', 9},  {'s', 12}, {'t', 14}, {'u', 15}, {'v', 17}, {'w', 20}, {'x', 24},
    {'y', 25}, {'z', 26}};

/**
 * Computes the score of a word based on characterDict mapped values.
 *
 * @param word The word for which the score is to be computed.
 * @return The computed score of the word.
 */
int computeScore(const std::string &word) {
  int score = 0;

  for (char letter : word) {
    auto elem = characterDict.find(letter);

    if (elem != characterDict.end()) {
      score += elem->second;
    }
  }

  return score;
}

/**
 * Replaces punctuation with space.
 *
 * @param character The character to be potentially replaced.
 * @return The character.
 */
char replacePunct(char &character) {
  return !std::ispunct(character) ? character : ' ';
}

/**
 * Map words from an input file to their scores.
 *
 * @param inputFile An input file stream from which words will be read.
 * @return A multimap containing words mapped to their scores.
 */
std::multimap<int, std::string> mapWords(std::ifstream &inputFile) {
  std::multimap<int, std::string> wordsMap;
  std::string fileWord;

  while (inputFile >> fileWord) {
    std::transform(fileWord.begin(), fileWord.end(), fileWord.begin(),
                   replacePunct);
    std::stringstream fileWorldStream(fileWord);
    std::string word;

    while (fileWorldStream >> word) {
      wordsMap.insert({computeScore(word), word});
    }
  }
  return wordsMap;
}

/**
 * Read file and return an input file stream.
 *
 * @param fileNameArg The name of the file to be opened.
 * @return An input file stream associated with the opened file.
 * @throws std::runtime_error if the file cannot be opened.
 */
std::ifstream readFile(const char *fileNameArg) {
  std::ifstream inputFile(fileNameArg);
  if (!inputFile.is_open()) {
    throw std::runtime_error("file cannot be opened.");
  }
  return inputFile;
}

/**
 * Write multimap content to a file.
 *
 * @param fileName The name of the file to write the content to.
 * @param content The multimap containing the content to be written to the file.
 * @throws std::runtime_error if the file cannot be opened.
 */
void writeFile(const std::string &fileName,
               const std::multimap<int, std::string> &content) {
  std::ofstream countFile(fileName);

  if (!countFile.is_open()) {
    throw std::runtime_error("file cannot be opened.");
  }

  for (const auto &[count, word] : content) {
    countFile << word << ", " << count << std::endl;
  }
}