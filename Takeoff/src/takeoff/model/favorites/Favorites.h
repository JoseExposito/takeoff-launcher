/**
 * @file /src/takeoff/model/Favorites.h
 *
 * This file is part of Takeoff.
 *
 * Takeoff is free software:  you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 3 of the License,  or (at your option)  any later
 * version.
 *
 * Takeoff is distributed in  the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Takeoff. If not, see <http://www.gnu.org/licenses/>.
 *
 * @author José Expósito <jose.exposito89@gmail.com> (C) 2011
 * @class  Favorites
 */
#ifndef MODEL_FAVORITES_H
#define MODEL_FAVORITES_H

#include <QtCore/QList>
#include "../../takeoff_widget/Launcher.h"

/**
 * Class to acces to the Kickoff favorites.
 */
class Favorites
{

public:

    /**
     * Returns the list of the favorite applications
     * @return The list.
     */
    static QList<Takeoff::Launcher*> favorites();

};

#endif // MODEL_FAVORITES_H
