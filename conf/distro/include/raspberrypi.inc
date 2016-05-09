##############################################################################
##
## Copyright (C) 2016 The Qt Company Ltd.
## Contact: http://www.qt.io/licensing/
##
## This file is part of the Boot to Qt meta layer.
##
## $QT_BEGIN_LICENSE:COMM$
##
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see http://www.qt.io/terms-conditions. For further
## information use the contact form at http://www.qt.io/contact-us.
##
## $QT_END_LICENSE$
##
##############################################################################

IMAGE_FSTYPES += "ext3 rpi-sdimg"

BOOTFS_CONTENT = "\
    bcm2835-bootfiles/*: \
    ${KERNEL_IMAGETYPE}:kernel.img \
    "

BOOTFS_DEPENDS = "bcm2835-bootfiles:do_deploy virtual/kernel:do_deploy"

MACHINE_EXTRA_INSTALL_SDK = " \
        userland-dev \
        "

MACHINE_EXTRA_INSTALL = "\
        userland \
        omxplayer \
        "

KERNEL_MODULE_AUTOLOAD += "snd-bcm2835 bcm2835-v4l2"
KERNEL_MODULE_PROBECONF += "bcm2835-v4l2"
module_conf_bcm2835-v4l2 = "options bcm2835-v4l2 gst_v4l2src_is_broken=1"

# video camera support
VIDEO_CAMERA = "1"

RPI_FT5604 = "1"
KERNEL_DEVICETREE += "overlays/rpi-ft5406-overlay.dtb"
MACHINE_FEATURES += "pitft"
