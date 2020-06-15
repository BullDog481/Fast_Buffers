//Copyright 2020 BullDog481, MIT License
#include <string>
#include "parse.h"


using namespace std;

int main(unsigned int argc, char *argv[]) {
	string filename = argv[1];
	string outfile = argv[2];
	int err_code = parse_c(outfile, filename);
	return err_code;	
}