#include <fstream>
#include <iostream>
#include <string>

int moneyControl(std::string moneyStr) {
  int sizeMoneyStr = moneyStr.length();
  for (int i = 0; i < sizeMoneyStr; i++) {
    if (!std::isdigit(moneyStr[i])) {
      std::cerr << "Error entering monetary amount\n";
      return -1;
    }
  }
  return stoi(moneyStr);
}
std::string outputAlignment(std::string str) {
  std::string alignment = "";
  if (str.length() < 10) {  
    for (int count = 0; count < 10 - str.length(); count++)
      alignment += " ";
  }
  return alignment;  
}

int main() {
  std::cout << "Pay statement\n";
  std::ifstream notebook;
  notebook.open("C:\\develop\\practice\\practice-19.5\\Statement.txt");

  std::string name, surname, date, moneyStr, maxNameSurname;
  int money, maxMoney = -1, sum = 0;

  while (!notebook.eof()) {
    notebook >> name >> surname >> moneyStr >> date;

    std::cout << name << "\t" << surname << outputAlignment(surname) << "\t" 
              << moneyStr << "\t" << date << "\n";

    money = moneyControl(moneyStr);
    if (maxMoney < money) {
      maxMoney = money;
      maxNameSurname = name + " " + surname;
    }
    if (money > -1) sum += money;
  }

  std::cout << "\nTotal amount of payments: " << sum << "\n\n";
  std::cout << maxNameSurname << "'s with max payments " << maxMoney;
}