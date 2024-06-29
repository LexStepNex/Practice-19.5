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

void dateControl(std::string date) {
  int sizeMoneyStr = date.length();
  int countDots = 0;
  std::string day = "", month = "", year = "";

  bool control = true;

  for (int i = 0; i < sizeMoneyStr && control; i++) {
    if (date[i] == '.') {
      countDots++;
    }

    if (!isdigit(date[i]) && date[i] != '.') {
      control = false;
      break;
    }

    if (countDots == 0 && isdigit(date[i])) {
      day += date[i];  
    }
    if (countDots == 1 && isdigit(date[i])) {
      month += date[i];
    } 
    if (countDots == 2 && isdigit(date[i])) {
      year += date[i];
    }
  }
  
  if (countDots != 2) control = false;
  int dd = stoi(day);
  int mm = stoi(month);
  int yyyy = stoi(year);

  if (1 > mm || mm > 12) {
    control = false;
  } else if (1 > dd || dd > 31) {
    control = false;
  } else if (yyyy < 0) {
    control = false;
  } else if (mm == 2) {
    if ((yyyy % 400 == 0) ||
        (yyyy % 4 == 0 && yyyy % 100 != 0)) {
      if (dd > 29) control = false;
    } else {
      if (dd > 28) control = false;
    }
  } else if (mm == 4 || mm == 6 || mm == 9 ||
             mm == 11) {
    if (dd > 30) control = false;
  } else {
    if (dd > 31) control = false;
  }

  if (!control) std::cerr << "Error in date\n";
}


std::string outputAlignment(std::string str) {
  std::string alignment = "";
  if (str.length() < 10) {
    for (int count = 0; count < 10 - str.length(); count++) alignment += " ";
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
    dateControl(date);

    if (maxMoney < money) {
      maxMoney = money;
      maxNameSurname = name + " " + surname;
    }
    if (money > -1) sum += money;
  }

  std::cout << "\nTotal payment amount: " << sum << "\n\n";
  std::cout << maxNameSurname << "'s with max payments " << maxMoney << "\n";
}