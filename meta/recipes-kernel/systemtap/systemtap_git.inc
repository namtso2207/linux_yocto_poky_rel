LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"
SRCREV = "0eba8a46bc99c66e5dd274a9a4d661fe08ac4b8a"
PV = "4.5"

SRC_URI = "git://sourceware.org/git/systemtap.git \
           file://0001-Do-not-let-configure-write-a-python-location-into-th.patch \
           file://0001-Install-python-modules-to-correct-library-dir.patch \
           file://0001-staprun-stapbpf-don-t-support-installing-a-non-root.patch \
           file://ef5a8b9eda402e4e96c4e3ce01e7ff95d3e10470.patch \
           "

COMPATIBLE_HOST = '(x86_64|i.86|powerpc|arm|aarch64|microblazeel|mips).*-linux'
COMPATIBLE_HOST_libc-musl = 'null'

S = "${WORKDIR}/git"

# systemtap can't be built without optimization, if someone tries to compile an
# entire image as -O0, break with fatal.
python () {
    if bb.utils.contains("SELECTED_OPTIMIZATION", "-O0", "x", "", d) == "x":
        bb.fatal("systemtap can't be built with -O0, using -O1 -Wno-error or -O1 instead.")
}