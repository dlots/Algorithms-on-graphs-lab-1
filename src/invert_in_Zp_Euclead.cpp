#include <iostream>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Wrong parameters" << std::endl;
        return -1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);  

    if ((a == 0) || (b == 0))
    {
        std::cout << 0;
        return 0;
    }
    
    if (a < b)
    {
        swap(a,b);
    }
    int p = a;
    
    int j1 = 1;
    int j2 = 0;
    int x1 = 0;
    int x2 = 1;
    
    while (true)
    {
        int new_b = a % b;
        if (new_b == 0)
            break;
        
        int integer_divisor = a / b;
        
        int new_j2 = j1 - j2 * integer_divisor;
        j1 = j2;
        j2 = new_j2;
        
        int new_x2 = x1 - x2 * integer_divisor;
        x1 = x2;
        x2 = new_x2;
        
        a = b;
        b = new_b;
        //std::cout << a << " " << b << " "  << j1 << " "  << j2 << " "  << x1 << " "  << x2  << " " << integer_divisor << std::endl;
    }
    
    if (b == 1)
    {
        if (x2 < 0)
        {
            x2 = p + x2;
        }
        std::cout << x2;
    }
    else
    {
        std::cout << 0;
    }
    return 0;
}
