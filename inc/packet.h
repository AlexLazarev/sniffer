//
// Created by Alex on 2019-04-17.
//

#ifndef SNIFF_PACKET_H
#define SNIFF_PACKET_H

#define SIZE_ETHERNET 14

typedef struct  sniff_ip {
    u_char ip_vhl;		/* version << 4 | header length >> 2 */
    u_char ip_tos;		/* type of service */
    u_short ip_len;		/* total length */
    u_short ip_id;		/* identification */
    u_short ip_off;		/* fragment offset field */
    u_char ip_ttl;		/* time to live */
    u_char ip_p;		/* protocol */
    u_short ip_sum;		/* checksum */
    struct in_addr ip_src,ip_dst; /* source and dest address */
}               t_ip;

#endif //SNIFF_PACKET_H
