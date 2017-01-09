#include "source.h"

Register MyRegisters[5];
Memory MyMemory[50];
string Lines[256];
string ParsedLine[3];
int DEBUG;
int RunCPU(string FileName, int Mode)
{
 	DEBUG = Mode;

	InitRegisters();
	InitMemory();
	int LineCount = ReadFile(FileName);
	
	//This loop using for walking through the line array. And instructions operations apply.
	for (int i = 0; i < LineCount; ++i)
	{
		int x = ParseString(Lines[i]);
		//int posnoktalicirgul = Lines[i].find(";");
		string TempString ;
		TempString += ParsedLine[0] + " " + ParsedLine[1] + " " + ParsedLine[2] + "\t";
		//If Parsed line has more than 3 value. Instructions argument
		if(x >= 3)
		{
			if(CustomToUpper(ParsedLine[0]).compare("MOV") == 0)
			{
				if(ParsedLine[1][0] == '#' && IsNumeric(ParsedLine[2]))
				{
					InstructionMov(ParsedLine[1], CustomAtoi(ParsedLine[2]));
					if(DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[1].substr(1, ParsedLine[1].size())));
						cout << endl;
					}
					//cout << "Adress + Int" << endl;
				}
				else if(ParsedLine[1][0] == '#')
				{
					InstructionMov(ParsedLine[1], FindRegisterByName(CustomToUpper(ParsedLine[2])));
					if(DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[1].substr(1, ParsedLine[1].size())));
						cout << endl;
					}
					//cout << "Adress + Reg" << endl;
				}
				else if(ParsedLine[2][0] == '#')
				{
					InstructionMov(FindRegisterByName(CustomToUpper(ParsedLine[1])), ParsedLine[2]);
					if(DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
					//cout << "REG + Adress" << endl;
				}
				else if(IsNumeric(ParsedLine[2]))
				{
					InstructionMov(FindRegisterByName(CustomToUpper(ParsedLine[1])), CustomAtoi(ParsedLine[2]));
					if(DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
					//cout << "REg + Int" << endl;
				}
				else
				{
					InstructionMov(FindRegisterByName(CustomToUpper(ParsedLine[1])), FindRegisterByName(CustomToUpper(ParsedLine[2])));
					if(DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[1].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
					//cout << "Reg+ reg" << endl;
				} 
			}
			else if(CustomToUpper(ParsedLine[0]).compare("ADD") == 0)
			{
				if(ParsedLine[2][0] == '#')
				{
					//cout << "Reg + adress" << endl;
					InstructionAdd(FindRegisterByName(CustomToUpper(ParsedLine[1])), ParsedLine[2]);
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
				}
				else if(IsNumeric(ParsedLine[2]))
				{
					InstructionAdd(FindRegisterByName(CustomToUpper(ParsedLine[1])), CustomAtoi(ParsedLine[2]));
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
					//cout << "Reg + int" << endl;
				}
				else
				{
					InstructionAdd(FindRegisterByName(CustomToUpper(ParsedLine[1])), FindRegisterByName(CustomToUpper(ParsedLine[2])));				
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
				} 
			}
			else if(CustomToUpper(ParsedLine[0]).compare("SUB") == 0)
			{
				if(ParsedLine[2][0] == '#')
				{
					//cout << "Reg + adress" << endl;
					InstructionSub(FindRegisterByName(CustomToUpper(ParsedLine[1])), ParsedLine[2]);
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
				}
				else if(IsNumeric(ParsedLine[2]))
				{
					InstructionSub(FindRegisterByName(CustomToUpper(ParsedLine[1])), CustomAtoi(ParsedLine[2]));
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
					//cout << "Reg + int" << endl;
				}
				else
				{
					InstructionSub(FindRegisterByName(CustomToUpper(ParsedLine[1])), FindRegisterByName(CustomToUpper(ParsedLine[2])));				
					if (DEBUG == 1)
					{
						Trace(TempString);
						cout << endl;
					}
					else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
						cout << endl;
					}
				} 
			}
			else if(CustomToUpper(ParsedLine[0]).compare("JMP") == 0)
			{

				if((IsNumeric(ParsedLine[2])))
				{
					if(FindRegisterByName(CustomToUpper(ParsedLine[1])).value == 0)
					{
						i = CustomAtoi(ParsedLine[2]) - 2;
						//cout << FindRegisterByName(ParsedLine[1]).value << endl;
						if (DEBUG == 1)
						{
							Trace(TempString);
							cout << endl;
						}
						else if(DEBUG == 2)
						{
							Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
							cout << endl;
						}
					}		
				}

			}
			else if(CustomToUpper(ParsedLine[0]).compare("JPN") == 0)
			{
				if(FindRegisterByName(CustomToUpper(ParsedLine[1])).value <= 0)
				i = CustomAtoi(ParsedLine[2]) - 2;
					//cout << FindRegisterByName(ParsedLine[1]).value << endl;
				if (DEBUG == 1)
				{
					Trace(TempString);
					cout << endl;
				}
				else if(DEBUG == 2)
				{
					Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
					cout << endl;
				}
			}
			else
			{
				cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine[0] << "\" on line " << i+1 << endl;
				return -1;
			}
		}
		else if(x == 2)
		{
			if(CustomToUpper(ParsedLine[0]).compare("JMP") == 0)
			{
				i = CustomAtoi(ParsedLine[1]) - 2;
				if (DEBUG == 1)
				{
					Trace(TempString);
					cout << endl;
				}
				else if(DEBUG == 2)
				{
					Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
					cout << endl;					
				}
			}
			else if(CustomToUpper(ParsedLine[0]).compare("PRN") == 0)
			{
				if(ParsedLine[1][0] == '#')
				{
					cout << "Memory Adress "  << FindMemoryAddress(CustomAtoi(ParsedLine[1].substr(1, ParsedLine[1].size()))).adress << " = " << FindMemoryAddress(CustomAtoi(ParsedLine[1].substr(1, ParsedLine[1].size()))).value << endl;	
				}
				else if(DEBUG == 2)
					{
						Trace2(TempString, CustomAtoi(ParsedLine[1].substr(1, ParsedLine[1].size())));
						cout << endl;
					}
				else
				{
					cout << FindRegisterByName(ParsedLine[1]).name << " = " << FindRegisterByName(ParsedLine[1]).value << endl;		
				}
			}
			else
			{
				cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine[0] << "\" on line " << i+1 << endl;
				return -1;
			}
		}
		else 
		{
			if(CustomToUpper(ParsedLine[0]).compare("HLT") == 0)
			{
				if (DEBUG == 1)
				{
					Trace(TempString);
					cout << endl;
				}
				else if(DEBUG == 2)
				{
					Trace2(TempString, CustomAtoi(ParsedLine[2].substr(1, ParsedLine[2].size())));
					cout << endl;
				}
				InstructionHlt();
			}
			else
			{
				cout << "There are some syntax errors. No such instruction that: \"" << ParsedLine[0] << "\" on line " << i+1 << endl;
				return -1;
			}
			
		}
	}
}
//Checks a string if is numeric.
bool IsNumeric(string str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if(isdigit(str.c_str()[i]))
		{
 			return true;
		}
		else if(str.c_str()[i] == '-')
		{
			if(isdigit(str.c_str()[i+1]))
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

void InstructionMov(Register& Register1, Register& Register2)
{
	Register2.value = Register1.value;
}
void InstructionMov(Register& Register1, int Constant)
{
	Register1.value = Constant;
}
void InstructionMov(Register& Register1, string adress)
{
	FindMemoryAddress(CustomAtoi(adress.substr(1, adress.size()))).value = Register1.value;
}
void InstructionMov(string adress, Register& Register1)
{
	Register1.value = FindMemoryAddress(CustomAtoi(adress.substr(1, adress.size()))).value;
}
void InstructionMov(string adress, int Constant)
{
	FindMemoryAddress(CustomAtoi(adress.substr(1, adress.size()))).value = Constant;
}
Register InstructionAdd(Register& Register1, Register& Register2)
{
	Register1.value += Register2.value;
	return Register1;
}
Register InstructionAdd(Register& Register1, int Constant)
{
	Register1.value += Constant;
	return Register1;
}
Register InstructionAdd(Register& Register1, string adress)
{
	Register1.value += FindMemoryAddress(CustomAtoi(adress.substr(1, adress.size()))).value;
	return Register1;
}
Register InstructionSub(Register& Register1, Register& Register2)
{
	Register1.value -= Register2.value;
	return Register1;
}
Register InstructionSub(Register& Register1, int Constant)
{
	Register1.value -= Constant;
	return Register1;
}
Register InstructionSub(Register& Register1, string adress)
{
	Register1.value -= FindMemoryAddress(CustomAtoi(adress.substr(1, adress.size()))).value;
	return Register1;
}
void InstructionJmp(Register Register1, int LineAdress)
{
	if(Register1.value == 0)
	{
		//Jump to Line Adress
	}
}
void InstructionJmp(int LineAdress)
{
	//Jump Line Adress
}
void InstructionPrn(Register Register1)
{
	cout << Register1.value << endl;
}
void InstructionPrn(int Constant)
{
	cout << Constant << endl;
}
int InstructionHlt()
{
	for (size_t i = 0; i < sizeof(MyRegisters)/sizeof(*MyRegisters); ++i)
	{
		cout << "Register " << MyRegisters[i].name << ": " << MyRegisters[i].value << endl; 
	}
	PrintMemory();
	return 0;
}
//INitialize registgers by default.
void InitRegisters()
{
	MyRegisters[0].name = "R1";
	MyRegisters[0].value = 0;
	MyRegisters[1].name = "R2";
	MyRegisters[1].value = 0;
	MyRegisters[2].name = "R3";
	MyRegisters[2].value  = 0;
	MyRegisters[3].name = "R4";
	MyRegisters[3].value = 0;
	MyRegisters[4].name = "R5";
	MyRegisters[4].value = 0;
}
void InitMemory()
{
	for (int i = 0; i < 50; ++i)
	{
		MyMemory[i].adress =  i;
		MyMemory[i].value = 0;
	}
}
//to find registers by names
Register& FindRegisterByName(string RegisterName)
{
	for (int i = 0; i < 5; ++i)
	{
		//cout  << MyRegisters[i].name << endl;
		if(RegisterName.compare(MyRegisters[i].name) == 0)
		{
			return MyRegisters[i];
		}
	}
}
Memory& FindMemoryAddress(int Adress)
{
	for (int i = 0; i < 50; ++i)
	{
		if(MyMemory[i].adress == Adress)
		{
			return MyMemory[i];
		}
	}
}
//Read file and returns line count.
int ReadFile(string FileName)
{
	string line;
	int i = 0;
  	ifstream MyFile(FileName.c_str());
  
  	if (MyFile.is_open())
  	{
    	while (getline (MyFile, line))
    	{
    		Lines[i] = line;
     		//cout << Lines[i] << endl;
     		++i;
    	}
    
    	MyFile.close();
    	return i;
  	}
  	else
  	{
  		cout << "Unable to open file"; 
  		return -1;
  	} 
}
//Parse string
int ParseString(string Line)
{
	string delimiter1 = ",";
	string strX = "";
	string a[3];
	int posnoktalicirgul = Line.find(";");
	string sX = Line.substr(0, posnoktalicirgul);
	size_t pos = 0;
	string token;

	while ((pos = sX.find(delimiter1)) != std::string::npos) 
	{
	    token = sX.substr(0, pos);
	    strX += token + " ";
	    sX.erase(0, pos + delimiter1.length());
	}

	strX += sX;
	//To skip whitespace.
	istringstream WhiteSpace(strX);
	int i = 0;
	do
    {
        string SubStr;
        WhiteSpace >> SubStr;
        if(SubStr != "")
        {
        	ParsedLine[i] = SubStr;
        	++i;
        }
    } while (WhiteSpace);

    return i;
}
//to make string integer
int CustomAtoi(string Str)
{
	//cout << Str << endl;
    int num = 0;
    int neg = 0;
    char* sX = (char*)Str.c_str();
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

//For DEBUG == 1 option 
void Trace(string Line)
{
	cout << Line << "\t - \t";
	for (int i = 0; i < 5; ++i)
	{
		cout << MyRegisters[i].name << " = " << MyRegisters[i].value << " ";
	}
}
//tracing address operations
void Trace2(string Line, int MemoryAdress)
{
	cout << Line << "\t - \t";
	for (int i = 0; i < 5; ++i)
	{
		cout << MyRegisters[i].name << " = " << MyRegisters[i].value << " ";
	}
	cout  << "\t - \t";
	cout << "Memory Adress " << FindMemoryAddress(MemoryAdress).adress << "= " << FindMemoryAddress(MemoryAdress).value;
}

string SkipWhiteSpace(string Str)
{
	size_t i = 0;

	string temStr = "";
	//cout << a[0] << endl;
	while(i < Str.length())
	{
		if(Str[i] != ' ')
		{
			temStr += Str[i];
			++i;
		}
		else
		{
			++i;
		}
	}
	return temStr;
}

string CustomToUpper(string Str)
{
	string TempString = "";
	for (size_t i = 0; i < Str.length(); ++i)
	{
		TempString += toupper(Str[i]);
	}
	return TempString;

}

string CustomItoa(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

void PrintMemory()
{
	for (int i = 0; i < 50; ++i)
	{
		cout << "Memory Adress " << MyMemory[i].adress << ": " <<  MyMemory[i].value << endl;
	}
}