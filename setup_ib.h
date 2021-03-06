#ifndef SETUP_IB_H
#define SETUP_IB_H

#include <infiniband/verbs.h>

struct IBResource {
    struct ibv_context      *ctx;
    struct ibv_pd           *pd;
    struct ibv_mr           *mr;
    struct ibv_cq           *cq;
    struct ibv_qp           *qp;
    struct ibv_port_attr    port_attr;
    struct ibv_device_attr  dev_attr;

    char    *ib_buf;
    size_t  ib_buf_size;

    uint32_t rkey;
    uint64_t raddr;
};

extern struct IBResource ib_res;

int setup_ib();
void close_ib_connection();

int connect_qp_server();
int connect_qp_client();

#endif /* SETUP_IB.H */
