#Make n-key-rollover possible
NKRO_ENABLE     = yes
FORCE_NKRO      = yes

#Enable control of the mouse
MOUSEKEY_ENABLE = yes

#Enable control of media keys
EXTRAKEY_ENABLE = yes

#Disable the command feature
COMMAND_ENABLE  = no

ifndef QUANTUM_DIR
    include ../../../../Makefile
endif
