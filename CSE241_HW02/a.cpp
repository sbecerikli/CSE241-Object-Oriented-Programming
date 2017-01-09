#include <iostream>
#include <string>

int sad(std::string str)
{
    int num = 0;
    int neg = 0;
    char* sX = (char*)str.c_str();
    while (isspace(*sX))
    {
    	sX++;
    } 
    if (*sX == '-')
    {
        neg = 1;
        sX++;
    }
    while (isdigit(*sX))
    {
        num = 10 * num + (*sX - '0'); //to find digit ascii value
        sX++;
    }
    if (neg)
    {
        num = -num;
    }
    return num;
}
int main(int argc, char const *argv[])
{

	std::cout << sad("3222") << std::endl;
	
}

