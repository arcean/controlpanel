isEmpty(HOST_ARCH) {

HOST_ARCH=$$system(dpkg-architecture -qDEB_HOST_GNU_TYPE || echo meego)

!silent {
    message("arch $$HOST_ARCH")
}

contains(HOST_ARCH,meego){
  !silent {
    message("preparing for MEEGO")
  }
  CONFIG += meego
  DEFINES += MEEGO
}

!silent {
  meego {
    message("MEEGO")
  } else {
    message("NON-MEEGO")
  }
}

}

