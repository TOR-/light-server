#include "light-server.h"

int parse_request(char buf[])
{
  // request type : only GET supported for now
  switch(buf[0])
  {
    case 'G':
    // 012345
    // GET /file
      if(buf[4]!='/')
      {
        return ERR_INVALID_FILE_PATH;
      }
      else
      {
        int i = 4;
        char path[256];
        for(;buf[i]!=' ';i++)
        {
          path[i-4] = buf[i];
        }
        if(path)
        {
          n = write(acceptsockfd,path,strlen(path));
        }
      }
  }
  return 0;
}
