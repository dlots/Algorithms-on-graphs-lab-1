#include <iostream>
#include <random>

long fast_pow(int a, int p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p == 1)
    {
        return a;
    }
    
    if (p % 2 == 0)
    {
        a = fast_pow(a, p/2);
        return a * a;
    }
    else
    {
        return fast_pow(a, p-1) * a;
    }
}

bool ferma_test(int p)
{
    std::random_device rd; 
    std::mt19937 mersenne(rd());
    for (size_t i = 0; i < 100; )
    {
        int random_number = mersenne();
        if (random_number % p == 0)
        {
            continue;
        }
        
        if (fast_pow(random_number, p-1) % p != 1)
        {
            return false;
        }
        
        ++i;
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Wrong parameters." << std::endl;
        return -1;
    }
    
    int p = atoi(argv[1]);
    int x = atoi(argv[2]);
    
    if (ferma_test(p))
    {
        std::cout << fast_pow(x, p-2) % p;
    }
    else
    {
        std::cout << 0;
    }
    
    return 0;
}