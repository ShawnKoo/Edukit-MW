
SRCDIR += links_c6xdsp/system links_c6xdsp/utils/src \
		links_c6xdsp/alg_link links_c6xdsp/alg_link/swosd links_c6xdsp/alg_link/scd

SRCS_UTILS = utils_dsp.c

SRCS_ALGLINK    = algLink_tsk.c algLink_priv.c

SRCS_OSDLINK    = osdLink_alg.c  

SRCS_SCDLINK    = scdLink_alg.c 

SRCS_SYSTEMDSP  = system_c6xdsp.c systemLink_tsk_c6xdsp.c 

SRCS_c6xdsp += $(SRCS_SYSTEMDSP) $(SRCS_UTILS) $(SRCS_ALGLINK) $(SRCS_OSDLINK) $(SRCS_SCDLINK)


