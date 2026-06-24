#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <string>

#include "DiskFiles.h"

using std::string;

string DiskFiles::strCFRDir = "";
string DiskFiles::strStaticDir = "";
const bool bIsLocal = true;

void DiskFiles::Init(void)
{
  char hostname_buf[500];
  gethostname(hostname_buf, sizeof(hostname_buf));

  strCFRDir = "/home/alex/code/dataT/cfr";
  strStaticDir = "/home/alex/code/dataT/static";
}

const char *DiskFiles::GetCFRDirPath(void)
{
  if (strCFRDir == "")
  {
    fprintf(stderr, "Should Init() First!\n");
    exit(-1);
  }
  return strCFRDir.c_str();
}

const char *DiskFiles::GetstaticDirPath(void)
{
  if (strStaticDir == "")
  {
    fprintf(stderr, "Should Init() First!\n");
    exit(-1);
  }
  return strStaticDir.c_str();
}
