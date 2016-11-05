#!/bin/bash
rm interface_server.c interface_client.c interface_clnt.c interface.h interface_svc.c interface_xdr.c Makefile.interface *.o

rpcgen -C -a interface.x

make -f Makefile.interface
