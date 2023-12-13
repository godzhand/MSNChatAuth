#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdio>
#include "MD5X.h"

using namespace std;

/***
 *    ███####███#███████#███####██#
 *    ████##████#██######████###██#     credits to all the legends of MSNChat
 *    ██#████#██#███████#██#██##██#
 *    ██##██##██######██#██##██#██# cyborg, ryLan, aaronluke, Nathan, zmic, JD, Luke, Sky, Tewl, sn0wX, thugownsyou, ziggy, kinetix, Arrow, Sky, aborted, err0r, neox
 *    ██######██#███████#██###████#  ver|zon, eXonyte, Liam, Nicholas, Th|ef, chaos, cid, and to anyone else I did not mention, you know who you are <3
 *    #############################   this code is extremely sloppy
 *    #############################
 */

int instr(string istring, string tofind) {
	if (istring.find(tofind) != istring.npos) {
		return istring.find(tofind) + 1;
	}
	else {
		return 0;
	}
}

string hexToASCII(string hex)
{
	// initialize the ASCII code string as empty.
	string ascii = "";
	for (size_t i = 0; i < hex.length(); i += 2)
	{
		// extract two characters from hex string
		string part = hex.substr(i, 2);

		// change it into base 16 and
		// typecast as the character
		char ch = stoul(part, nullptr, 16);

		// add this char to final ASCII string
		ascii += ch;
	}
	return ascii;
}
void convertToASCII(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << (int)s[i]<< endl;
    }
}

static void removeTrailingCharacters(std::string& str, const char charToRemove) {
	str.erase(str.find_last_not_of(charToRemove) + 1, std::string::npos);
}
int main(int argc, char* argv[]) {
	 // Set console code page to UTF-8 so console known how to interpret string data
   // SetConsoleOutputCP(8859-15);
    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    //setvbuf(stdout, nullptr, _IOFBF, 1000);
 std::string current_exec_name = argv[0]; // Name of the current exec program
 std::vector<std::string> allArgs(argv, argv + argc);
 std::string AUTH = allArgs[1].c_str();
  std::string AUTH_TYPE = allArgs[2].c_str();
   std::string AUTH_SEQUENCE = allArgs[3].c_str();
    std::string AUTH_CHALLENGE = allArgs[4].c_str();
   if (AUTH == "AUTH") {
	   string SingleLine = allArgs[1] + allArgs[2] + allArgs[3] + allArgs[4];
	   if (AUTH_SEQUENCE == "S") {
				if (!SingleLine.empty()) {
					removeTrailingCharacters(SingleLine, '\n');
					removeTrailingCharacters(SingleLine, '\r');
					removeTrailingCharacters(SingleLine, '\t');
						  std::string currentPath = std::filesystem::current_path().string();
						  std::string dir = current_exec_name.substr(0, current_exec_name.size()-8);
						cout << dir << "\r\n";
						std::string filename = dir + "auth.gk";
						ofstream myfile;
						myfile.open(filename, fstream::in | fstream::out | fstream::trunc);
							    MD5 md5;
								string ChOK = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x02\\0\\0\\0\x03\\0\\0\\0";
								string findstringx = "\x03\\0\\0\\0\x02\\0\\0\\0";
								int findstringn = instr(SingleLine, findstringx);
								int math = findstringn + findstringx.size();
								string ChOK3 = SingleLine.substr(math - 1) + "irc.irc7.com";
								string ChallengeCode = "edp{}e|wxrdse}}u666666666666666666666666666666666666666666666666" + ChOK3;
								char* cz = const_cast<char*>(ChallengeCode.c_str());
								string g1 = md5.digestString(cz);
								string a1 = hexToASCII(g1);
								int n = 48;
								char cx = '\\';
								string c2 = hexToASCII("0f0e1a11170f161d12180e190f17171f") + std::string(n, cx) + a1;
								char* c = const_cast<char*>(c2.c_str());
								string a2 = md5.digestString(c);
								string a3 = hexToASCII(a2);
								//int gate = rand() % ((1111111111111111 - 9999999999999999) + 1) + 1111111111111111;
								string ChOK4 = "AUTH GateKeeper S :GKSSP\\0\\0\\0\x03\\0\\0\\0\x03\\0\\0\\0" + a3;
								//<.>JD> :GKSSP\\0\\0\\0\x03\\0\\0\\0\x03\\0\\0\\0
								//<.>JD> Then you add the hostname (in this case irc.irc7.com or whatever) to the challenge string before you calculate the hash
								//ChOK4 += xuidgkI64u;
								ChOK4 += "\r\n";
								const char* cstr = ChOK4.c_str();
								//NetDll_send(XNCALLER_SYSAPP, IRC7Sock, ChOK4.c_str(), ChOK4.length(), 0);
    //convertToASCII(ChOK4);
 myfile << ChOK4;
  myfile.close();

							}
							}
							}
							return 0;
							}