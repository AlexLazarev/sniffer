//
// Created by Alex on 2019-04-19.
//

#ifndef SNIFF_SNIFFER_H
#define SNIFF_SNIFFER_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

void create_demon();

#endif //SNIFF_SNIFFER_H