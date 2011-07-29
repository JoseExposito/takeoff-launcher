#!/bin/bash
# Usage $ _uninstall.sh SuperUserPass

if [ ! $# -eq 1 ] ; then
    echo The script must receive the super user password
    exit
fi

cd plasmoid

plasmoidLib=`ls *.so`
if [ $? != 0 ] ; then
    echo "Run install before uninstall"
    exit
fi

plasmoidDesktop=`ls *.desktop`
if [ $? != 0 ] ; then
    echo "Run install before uninstall"
    exit
fi

echo $1 | sudo -S rm /usr/lib/kde4/$plasmoidLib
echo $1 | sudo -S rm /usr/share/kde4/services/$plasmoidDesktop
kbuildsycoca4 2> /dev/null
