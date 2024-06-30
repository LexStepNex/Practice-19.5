#include <fstream>
#include <iostream>


void new_game_field(bool arr[]) {
  for (int i = 0; i < 13; i++) {
    arr[i] = false;
  }
}

void print_field(bool arr[]) {
  for (int i = 0; i < 13; i++) {
    std::cout << arr[i] << " ";
  }
}

int offset_from_player(int offset) {
   do {
    std::cout << "Input drum offset: ";
    std::cin >> offset;
    if (offset < 1) {
      std::cerr << "The offset must be greater than or equal to 1.\n";
      continue;
    }
  } while (offset < 1);

  if (offset > 13) offset %= 13;
  offset--;
  return offset;
}

int main() {
  bool question_options[13];
  new_game_field(question_options);

  int offset = offset_from_player(offset);
 
  std::cout << "offset = " << offset << "\n";
  print_field(question_options);
}