/*
 *  Copyright © 2018-2020 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Crow Translate.
 *
 *  Crow Translate is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Crow Translate is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "retranslationtransition.h"

#include "qonlinetranslator.h"
#include "langbuttongroup.h"

RetranslationTransition::RetranslationTransition(QOnlineTranslator *translator, LangButtonGroup *group, QState *sourceState)
    : QAbstractTransition(sourceState)
    , m_translator(translator)
    , m_group(group)
{
}

bool RetranslationTransition::eventTest(QEvent *)
{
    return !m_translator->error() && m_group->isAutoButtonChecked() && m_translator->sourceLanguage() == m_translator->translationLanguage();
}

void RetranslationTransition::onTransition(QEvent *)
{
}
