/* Copyright (C) 2012 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_CBUFFERITEM_H
#define INCLUDED_CBUFFERITEM_H

#include "lib/config2.h"

#if CONFIG2_AUDIO

#include "CSoundBase.h"

class CBufferItem : public CSoundBase
{
public:
	CBufferItem(CSoundData* sndData);
	virtual ~CBufferItem();
	
	virtual void SetLooping(bool loops);
	virtual bool IdleTask();
	
protected:	
	virtual void Attach(CSoundData* itemData);

	
};

#endif // CONFIG2_AUDIO

#endif // INCLUDED_CBUFFERITEM_H

