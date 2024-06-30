#include <fstream>
#include <iostream>
#include <string>

int question_int[13] = {0,   44,  99,  142, 167, 183, 216,
                        255, 296, 341, 390, 445, 499};
int answer_int[13] = {0, 4, 12, 19, 24, 29, 37, 46, 51, 56, 64, 71, 77};

void new_game_field(bool arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = false;
  }
}

bool control_free_question(bool arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == false) return true;
  }
  return false;
}

void print_field(bool arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
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

void print_question(int position) {
  std::ifstream game_questions;
  game_questions.open("9.5_questions.txt");

  game_questions.seekg(question_int[position]);
  std::string question_str = "", word;
  while (question_str[question_str.length() - 1] != '?') {
    game_questions >> word;
    if (question_str == "") {
      question_str += word;
    } else {
      question_str += " " + word;
    }
  }
  std::cout << "Question №" << question_str << "\n\n";
  game_questions.close();
}

std::string answer(int position) {
  std::ifstream game_answer;
  game_answer.open("9.5_answer.txt", std::ios::binary);

  game_answer.seekg(answer_int[position]);
  std::string answer_str;
  game_answer >> answer_str;

  game_answer.close();
  return answer_str;
}

std::string lower_case(std::string str) {
  int sizeStr = str.size();
  for (int i = 0; i < sizeStr; i++) {
    str[i] = std::tolower(str[i]);
  }
  return str;
}

int main() {
  std::cout << "Play in \"What? Where? When?\" \n";
  bool question_options[13];
  int score_player= 0, score_spectators = 0;
  bool win = false;
  int size_questions = std::size(question_options);
  new_game_field(question_options, size_questions);

  for (int count = 0; count < 13; count++) {
    int offset = 0;
    offset = offset_from_player(offset);

    while (control_free_question(question_options, size_questions)) {
      if (!question_options[offset]) {
        question_options[offset] = true;
        break;
      } else {
        offset++;
      }
      if (offset > 12) offset = 0;
    }
    print_question(offset);

    std::string answer_player;
    std::cout << "Input answer: ";
    std::cin >> answer_player;

    answer_player = lower_case(answer_player); 
   
    if(answer_player == answer(offset)) {
      std::cout << "You right\n";
    }

    print_field(question_options, size_questions);
  }
}