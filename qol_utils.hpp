#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include "methods.hpp"
using namespace std::chrono;
using namespace std;

int contains_str(vector<string> v, string x) {
  if(find(v.begin(), v.end(), x) != v.end()) {
      return 1;
  } else {
      return 0;
  }
}

long get_time_ms() {
  auto now = std::chrono::system_clock::now();
  auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
  auto epoch = now_ms.time_since_epoch();
  auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

  return value.count();
}

float vector_sum(vector<float> arr) {
  float sum = 0;
  float n = arr.size();

  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}

string input(string to_print = "") {
  if (to_print != "") {cout << to_print;}

  string s;
  cin >> s;
  return s;
}

string return_exit(bool allow_exit, bool use_str = 1) {
  if (allow_exit && use_str) {
    return " (type \"exit\" to exit)";
  } else {
    return "";
  }
}

int clear_terminal(bool no_clear = 0) {
  if (no_clear) {return 0;}
  #if defined(__linux__)
    system("clear");
    return 0;
  #endif
  system("cls");
  return 0;
}

vector<int> get_res(bool allow_exit = 0, bool use_exit_str = 1, int tests = 0, float avg = 0) {
  string horizontal, vertical;
  string exit_str = return_exit(allow_exit, use_exit_str);
  string hin_output = "Horizontal resolution" + exit_str + ":\n> "; // (h)orizontal (in)put output

  horizontal = input(hin_output);
  if (horizontal != "exit") {
    clear_terminal();
    print_key(tests, avg);
    vertical = input("Vertical resolution:\n> ");
  }
  if (allow_exit && contains_str({horizontal, vertical}, "exit")) {
    clear_terminal();
    exit(0);
  }

  int horizontal_int = stoi(horizontal);
  int vertical_int = stoi(vertical);

  vector<int> resolution = {horizontal_int, vertical_int};
  return resolution;
}

string lower_string(string to_convert) {
  transform(to_convert.begin(), to_convert.end(), to_convert.begin(), ::tolower);
  return to_convert;
}

bool stob(string to_convert, bool bdefault = 1) {
  string lower_convert = lower_string(to_convert);
  vector<string> true_list = {"yes", "1", "true"};
  vector<string> false_list = {"no", "0", "false", "nuh uh"};
  
  if (lower_convert == "") {return bdefault;}
  if (contains_str(true_list, lower_convert)) {return 1;}
  if (contains_str(false_list, lower_convert)) {return 0;}

  throw "An unknown error has occurred. Ensure the data entered is correct.";
  return 2;
}