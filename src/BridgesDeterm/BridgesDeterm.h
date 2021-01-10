#ifndef _BRIDGES_DETERM_H_
#define _BRIDGES_DETERM_H_

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

enum color
{
    white = 0,
    gray,
    black
};

std::map<uint64_t, std::vector<uint64_t>> adj_map;
size_t timer = 0;
std::vector<color> colors;
std::vector<size_t> M;
std::vector<size_t> entry;
std::vector<uint64_t> history;
std::stringstream bridges_output;

void parse_adj_list(char* adj_list, uint64_t len, std::map<uint64_t, std::vector<uint64_t>>& adj_map);

void bridges_determ_dfs(uint64_t vertex);

const char* cpp_compute_bridges_determ(char* adj_list, uint64_t len);

#ifdef __cplusplus
extern "C" {
#endif

const char* compute_bridges_determ(char* adj_list, uint64_t len);

#ifdef __cplusplus
}
#endif

#endif // _BRIDGES_DETERM_H_
