# name of your application
APPLICATION = servo-mapper

# If no BOARD is found in the environment, use this default:
BOARD ?= samr21-xpro

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= ../../../../RIOT

# Include packages that pull up and auto-init the link layer.
# NOTE: 6LoWPAN will be included if IEEE802.15.4 devices are present
USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif
# Specify the mandatory networking modules for IPv6 and UDP
USEMODULE += gnrc_ipv6_router_default
USEMODULE += gnrc_udp
# Add a routing protocol
USEMODULE += gnrc_rpl
# Additional networking modules that can be dropped if not needed
USEMODULE += gnrc_icmpv6_echo
#
USEMODULE += gnrc_conn_udp

USEPKG += microcoap
CFLAGS += -DMICROCOAP_DEBUG

# include this for printing IP addresses
USEMODULE += shell_commands

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Features required
FEATURES_REQUIRED += cpp

# If you want to add some extra flags when compile c++ files, add these flags
# to CXXEXFLAGS variable
CXXEXFLAGS += -std=c++11

INCLUDES += -I${CURDIR}/../../lib
INCLUDES += -I${CURDIR}/../../lib/cereal/include
INCLUDES += -I${CURDIR}/../../lib/fakeros/include


include $(RIOTBASE)/Makefile.include
