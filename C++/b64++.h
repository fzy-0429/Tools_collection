#ifndef BASE64_PLUS_PLUS_H
#define BASE64_PLUS_PLUS_H
#include <fstream>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <regex>
#include <cstring>
#include "base64.h"
#include "base64_file.h"

using namespace std;
/*
Credits to owners of base64 funtions, I just make them easier to use
*/

// base64 encode for file or char*
string b64_en(char *source, bool is_file = 1)
{
    if (is_file)
    {
        fstream file_stream;
        file_stream.open(source);

        if (!file_stream.is_open())
        {
            return base64_encode(string(source));
        }

        file_stream.close();

        return Base64::encodeFromFile(source);
    }
    else
    {
        return base64_encode(string(source));
    }
}

// decode file
void b64_de(string b64_data, string file_path)
{
    return Base64::decodeToFile(file_path, b64_data);
}

// decode string
string b64_de(string b64_data)
{
    return base64_decode(b64_data);
}

#endif