#include <stdio.h>
#include <bits/stdc++.h>
#include "qol_utils.hpp"
using namespace std;

string return_exit(bool allow_exit) {
  if (allow_exit) {
    return "(\"exit\" to exit)";
  } else {
    return "";
  }
}

vector<int> get_res(bool allow_exit = 0) {
  using namespace std;
  string horizontal, vertical;

  // TODO: Give an exit option.
  string exit_str = return_exit(allow_exit); // to use later
  horizontal = input("Horizontal resolution:\n> ");
  // if (allow_exit && horizontal == "exit") {exit(0);}
  
  vertical = input("Vertical resolution:\n> ");
  int horizontal_int = stoi(horizontal);
  int vertical_int = stoi(vertical);

  vector<int> resolution = {horizontal_int, vertical_int};
  return resolution;
}

double run_bench(vector<int> resolution = get_res(), bool debug = false) {
  int pixels = resolution[0] * resolution[1];
  double start = get_time_ms(); // this mf was a float and fucked over the whole program
  vector<vector<int>> buffer;
  
  for (int i = 0; i < pixels; i++) {
    vector<int> pixels(3, rand());
    buffer.push_back(pixels);
  }
  
  double end = get_time_ms();
  double duration_took = (end - start);
  double approx_fps = (1/(duration_took/1000));

  if (debug) {
    printf("%g ms\n", duration_took);
    printf("Approximately %f PB/s\n", approx_fps);
  }
  return approx_fps;
}

int print_key() {
  printf("Key:\n\tPB: push back(s)\n\tms: milliseconds\n");
  printf("\nShortcuts:\n\tctrl+c to exit.\n\n\n");
  return 0;
}

int main_loop(void) {
  bool debug = stob(input("Debug mode?\n> "));
  clear_terminal();
  print_key();
  printf("Average PB/s (0 tests): \n\n");
  
  vector<float> results;
  float avg;
  
  while (true) {
    vector<int> resolution = get_res(1);
    results = {};
    int n = 5;
    
    for (int i = 0; i < n; i++) {
      float data = run_bench(resolution, debug);
      results.push_back(data);
    }

    float sum = vector_sum(results);
    avg = sum / results.size();

    clear_terminal(debug);
    print_key();
    printf("Average PB/s (%i tests): %g \n\n", n, avg);
  }

  return 0;
}

int main() {
  while (true) {
    try {
      main_loop();
    } catch (...) {
      cout << "Encountered error. Resuming operations.\n\n";
      continue;
    }
  }
  
  return 0;
}