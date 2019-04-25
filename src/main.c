#include "btree.h"
#include "packet.h"
#include "error.h"
#include "sniffer.h"
#include <pthread.h>

void get_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    t_ip        *ip;

    ip = (t_ip*)(packet + SIZE_ETHERNET);

    insert(inet_ntoa(ip->ip_src), (t_node**)args);
}

static void start(char *dev, int num_packets, char *filter_exp, t_node *root) {
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 mask;		/* The netmask of our sniffing device */
    bpf_u_int32 net;		/* The IP of our sniffing device */
    struct bpf_program fp;		/* The compiled filter expression */
    pcap_t *handle;

    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        error(ERROR_NETMASK, errbuf);
    }
    if ((handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf)) == NULL){
        error(ERROR_OPEN_DEVICE, errbuf);
    }
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        error(ERROR_PARSE_FILTER, pcap_geterr(handle));
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        error(ERROR_INSTALL_FILTER, pcap_geterr(handle));
    }
    pcap_loop(handle, num_packets, get_packet, (u_char*)&root);

    pcap_freecode(&fp);
    pcap_close(handle);
}

void *sniffer(void *arg) {
    int num_packets = 10;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        error(ERROR_NOT_FOUND_DEFAULT_DEVICE, errbuf);
    }
    start(dev, num_packets, "ip", (t_node*)arg);
    return NULL;
}

static void create_sniffer(t_node *root) {
    pthread_t handler;

    if (pthread_create(&handler, NULL, sniffer, root)) {
        error(ERROR_CREATE_THREAD, NULL);
    }
    if (pthread_join(handler, NULL)) {
        error(ERROR_JOIN_THREAD, NULL);
    }
}


int main(int argc, char **argv) {
    t_node          *root = NULL;

    create_demon();
    create_sniffer(root);
    create_server();
    preorder_print(root);
    printf("\nCapture complete.\n");
    return 0;
}
