#include "word_mapping.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>." << std::endl;
    return EXIT_FAILURE;
  }

  std::ifstream inputFile;
  try {
    inputFile = readFile(argv[1]);
  } catch (std::exception &error) {
    std::cerr << "Error reading file: " << error.what() << "\n";
    return EXIT_FAILURE;
  }

  const std::multimap<int, std::string> wordsMap = mapWords(inputFile);
  try {
    writeFile(std::string(std::filesystem::path(argv[1]).stem()) + ".count.txt",
              wordsMap);

  } catch (std::exception &error) {
    std::cerr << "Error writing file: " << error.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
