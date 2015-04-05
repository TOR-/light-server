#ifndef _LIGHT_SERVER_H
#define _LIGHT_SERVER_H

#define ERR_INVALID_FILE_PATH 1

int acceptsockfd;
int parse_request(char buf[]);

#endif
