#include "source.h"

int main(int argc, char const *argv[])
{

	if(argc != 3)
	{
		cout << "Usage:" << argv[0] << " filename option" << endl;
		return -1;
	}
	
	RunCPU(argv[1], CustomAtoi(argv[2]));
	
	return 0;
}


