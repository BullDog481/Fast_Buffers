//Copyright 2020 BullDog481, MIT License
#include <iostream>
#include <string>
#include <fstream>



int parse_c(std::string outfile, std::string filename) {
    std::ifstream inf{ filename };
    // ofstream is used for writing files
    // We'll make a file called Sample.dat
    std::ofstream outf{ outfile };
    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << outfile << " could not be opened for writing" << std::endl;
        return 1;
    }

    // We'll write three lines into this file
    outf << "#include <vector>" << '\n' << '\n';
    outf << "int main(void){" << '\n';

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << filename << " could not be opened for reading" << std::endl;
        return 1;
    }
    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << " input string" << '\n';
        std::string delimiter = ";";
        std::string outString = "";
        unsigned int pos = 0;
        std::string token;
        unsigned int token_count = 0;
        while ((pos = strInput.find(delimiter)) != std::string::npos) {
            std::string value = "";
            token = strInput.substr(0, pos);
            std::cout << token << " token" <<  std::endl;
            
            if (token_count == 0) {
                if (token == "s") {
                    value = "std::string ";

                }
                else if (token[0] == 'i') {
                    if (token[1] == '2') {
                        value = "short int ";
                    }
                    else if (token[1] == '4') {
                        value = "int ";
                    }
                    else if (token[1] == '8') {
                        value = "long long int ";
                    }


                }
                else if (token == "c") {
                    value = "char ";

                }
                else if (token == "d") {
                    value = "double ";

                }
                else if (token == "f") {
                    value = "float ";
                }
                /*else if (token[0] == 'b') {
                    value = "char[";
                    std::string size(1, token[1]);
                    value.append(size);
                    value.append("] ");
                    return value;
                }*/
                /*else if (token == "e") {
                    value = "enum {";
                    token = token.erase(0, 1);
                    value = value.insert(4, token);
                    return value;
                }*/
                /*else if (token[0] == '/') {
                    value = token.erase(0, 1);
                    value = value.insert(0, "class ");
                    return value;
                }*/
            }
            else if (token_count == 1) {
                token.append(" = ");
                value = token;
            }
            else if (token_count == 2) {
                token.append(";");
                value = token;
            }
            outString.append(value);
            
            token_count++;
            strInput.erase(0, pos + delimiter.length());
        }
        std::cout << outString << " output string" << std::endl;
        outf << outString << '\n';
        
    }
    
    
   
        outf << "return 0;" << '\n';
        outf << '}' << '\n';
    

    // When outf goes out of scope, the ofstream
    // destructor will close the file
    return 0;
}