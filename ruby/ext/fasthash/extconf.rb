require "mkmf"

have_library("fasthash", "fasthash_init")

create_makefile "fasthash/fasthash"
