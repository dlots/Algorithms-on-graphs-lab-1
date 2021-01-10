#include "BridgesDeterm.h"

void parse_adj_list(char* adj_list, uint64_t len, std::map<uint64_t, std::vector<uint64_t>>& adj_map)
{
    int64_t vertex = -1;
    std::string number("");
    for (size_t i = 0; i < len; ++i)
    {
        char next_char = adj_list[i];
        if (next_char == '(')
        {
            ++vertex;
        }
        else if ((next_char == ',') || (next_char == ')'))
        {
            adj_map[vertex].push_back(std::stoi(number));
            number.clear();
        }
        else if (next_char == '\0')
        {
        }
        else
        {
            number.push_back(next_char);
        }
    }
}

void bridges_determ_dfs(uint64_t vertex)
{
    colors[vertex] = gray;
    history.push_back(vertex);
    entry[vertex] = ++timer;
    for (auto adjacent : adj_map[vertex])
    {
        bool not_parent = (history.size() < 2) || (history[history.size() - 2] != adjacent);
        if (colors[adjacent] == white)
        {
            bridges_determ_dfs(adjacent);
            M[vertex] = std::min(M[vertex], M[adjacent]);
            if (M[adjacent] >= entry[vertex])
            {
                bridges_output << "(" << vertex << "," << adjacent << "),";
            }
        }
        else if ((colors[adjacent] == gray) && not_parent)
        {
            M[vertex] = std::min(M[vertex], entry[adjacent]);
        }
    }
    colors[vertex] = black;
}

const char* cpp_compute_bridges_determ(char* adj_list, uint64_t len)
{

    parse_adj_list(adj_list, len, adj_map);

    colors = std::vector<color>(adj_map.size(), white);
    M = std::vector<size_t>(adj_map.size(), ULONG_MAX);
    entry = std::vector<size_t>(adj_map.size(), 0);

    bridges_output << "[";
    bridges_determ_dfs(0);
    std::string bridges_string(bridges_output.str());
    bridges_string.pop_back();
    bridges_string += "]";

    /*std::stringstream mapstream;
    for (size_t i = 0; i < adj_map.size(); ++i)
    {
        mapstream << i << ": ";
        for (auto num : adj_map[i])
        {
            mapstream << num << " ";
        }
        mapstream << std::endl;
    }

    std::string mapstring = mapstream.str();*/

    char* result = (char*)malloc(bridges_string.size() * sizeof(char));
    if (result == NULL)
    {
        exit(1);
    }
    memset(result, 0, bridges_string.size() * sizeof(char));

    strcpy(result, bridges_string.c_str());

    return result;
}

const char* compute_bridges_determ(char* adj_list, uint64_t len)
{
    return cpp_compute_bridges_determ(adj_list, len);
}

/*int main()
{
    char* test = "(1,2)(0)(3,0,4)(2)(5,2,6)(4)(7,4)(6)";

    const char* result = cpp_compute_bridges_determ(test, 36);

    std::cout << "\n res:" << test;

    return 0;
}
*/
