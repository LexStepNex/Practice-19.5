#include <fstream>
#include <iostream>

bool substr(std::string str, std::string subStr) {
  int strLen = str.length();
  int subStrLen = subStr.length();
  if (strLen <= subStrLen) return false;

  for (int i = 0; i <= strLen - subStrLen; i++) {
    int j;

    for (j = 0; j < subStrLen; j++) {
      if (str[i + j] != subStr[j]) break;
    }

    if (j == subStrLen) return true;
  }
  return false;
}

int main() {
  std::cout << "Find you word in text\n";
  std::ifstream notebook; 
  notebook.open("C:\\develop\\practice\\practice-19.5\\words.txt");//открываем файл txt

  std::string word, searchWord;
  std::cout << "Input search word: ";
  std::cin >> searchWord;  // пример cat или catman
  int countSearchWord = 0, countSubWord = 0;

  while (!notebook.eof()) {
    notebook >> word;

    if (word == searchWord) countSearchWord++;
    if (substr(word, searchWord)) countSubWord++;
  }

  std::cout << "Your word appears in the text " << countSearchWord
            << " times\n";
  std::cout << "Your word is a subword in the text " << countSubWord
            << " times\n";
}