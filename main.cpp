#include <stdio.h>
#include <bits/stdc++.h>
#include "qol_utils.hpp"
using namespace std;

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

int main_loop(void) {
  int n = 0;
  float avg = 0;

  clear_terminal();
  bool debug = stob(input("Debug mode?\n> "));
  clear_terminal();
  print_key(n, avg);
  
  vector<float> results;
  
  while (true) {
    vector<int> resolution = get_res(true, false, n, avg);
    results = {};
    int n = 5;
    
    for (int i = 0; i < n; i++) {
      float data = run_bench(resolution, debug);
      results.push_back(data);
    }

    float sum = vector_sum(results);
    avg = sum / results.size();

    clear_terminal(debug);
    print_key(n, avg);
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