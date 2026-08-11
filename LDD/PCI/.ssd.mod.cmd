savedcmd_ssd.mod := printf '%s\n'   ssd.o | awk '!x[$$0]++ { print("./"$$0) }' > ssd.mod
