#!/bin/bash
# Usage $run.sh SuperUserPass

if [ ! $# -eq 1 ] ; then
    echo The script must receive the super user password
    exit
fi

cd plasmoid

# Delete the generated symbolic links
rm `find -type l`

# Rename the plasmoid library
orgName=`ls lib*`
plasmoidLib=${orgName%*.*.*.*}
plasmoidLib=${plasmoidLib:3:`echo -n $plasmoidLib | wc -c`}
mv $orgName $plasmoidLib

# Install the plasmoid
plasmoidDesktop=`ls *.desktop`

echo -n "Installing plasmoid"

echo $1 | sudo -S cp $plasmoidLib /usr/lib/kde4/$plasmoidLib
echo $1 | sudo -S cp $plasmoidDesktop /usr/share/kde4/services/$plasmoidDesktop

# Run the plasmoid
plasmoidName=`cat $plasmoidDesktop | grep X-KDE-PluginInfo-Name | cut -d = -f 2`
kbuildsycoca4 2> /dev/null

echo -n "Runing plasmoid"

plasmoidviewer $plasmoidName
