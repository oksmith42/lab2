#include "ReadFile.h"
#include <iostream>
#include <string>

ReadFile::ReadFile(const char* fn)
{
   input_file.open(fn);
   closed = false;
   _eof = false;
//rf->asodigja...
}

ReadFile::~ReadFile()
{
}

bool ReadFile::eof()
{
   return _eof;
}

void ReadFile::close()
{
   if (closed)
   {
      input_file.close();
      closed = true;
   }
}

String* ReadFile::readLine()
{
   if (closed) return NULL;
   if (_eof) return NULL;

   string text;
   _eof = !(getline(input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}
