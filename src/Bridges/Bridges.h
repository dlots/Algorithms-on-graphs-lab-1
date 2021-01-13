#ifndef _BRIDGES_H_
#define _BRIDGES_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

enum color
{
    white = 0,
    gray,
    black
};

enum sort_method
{
    radix = 0,
    bucket = 1,
    quick = 2
};

////////////////////////////////////////////////////////////////////////////////
// DATA
////////////////////////////////////////////////////////////////////////////////

map<uint64_t, vector<uint64_t>> adj_map;  // parsed adjacency list
size_t timer;
vector<color> colors;  // vertex state
vector<size_t> M;  // M-statistic ( min{ entry(backward), M(children) } )
vector<size_t> entry;  // entry time
vector<uint64_t> history;  // "gray path"
stringstream bridges_output;   // result string builder
map<uint64_t, map<uint64_t, uint64_t>> samples;   //random samples for randomized algorithms
mt19937_64 mersenne;   //random engine
uniform_int_distribution<uint64_t> random_number;

////////////////////////////////////////////////////////////////////////////////

void parse_adj_list(char* adj_list, uint64_t len);
const char* get_result_pointer(string& result_string);

void bridges_determ_dfs(uint64_t vertex);
const char* cpp_compute_bridges_determ(char* adj_list, uint64_t len);

void sampling_dfs(uint64_t vertex);
void launch_sampling();
const char* cpp_compute_bridges_rand(char* adj_list, uint64_t len);
const char* cpp_compute_2bridges_rand(char* adj_list, uint64_t len, int sort);

////////////////////////////////////////////////////////////////////////////////
// С99 functions to call from Python using CTypes
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

const char* compute_bridges_determ(char* adj_list, uint64_t len);
const char* compute_bridges_rand(char* adj_list, uint64_t len);
const char* compute_2bridges_rand(char* adj_list, uint64_t len, int sort);

#ifdef __cplusplus
}
#endif

#endif // _BRIDGES_H_
