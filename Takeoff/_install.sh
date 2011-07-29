#!/bin/bash
# Usage $ _install.sh SuperUserPass

if [ ! $# -eq 1 ] ; then
    echo The script must receive the super user password
    exit
fi

qmake
make
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
echo $1 | sudo -S cp $plasmoidLib /usr/lib/kde4/$plasmoidLib
echo $1 | sudo -S cp $plasmoidDesktop /usr/share/kde4/services/$plasmoidDesktop
