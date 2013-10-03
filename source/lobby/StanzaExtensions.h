/* Copyright (C) 2013 Wildfire Games.
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
#ifndef STANZAEXTENSIONS_H
#define STANZAEXTENSIONS_H

#include <gloox/client.h>

/// Global Gamelist Extension
#define ExtGameListQuery 1403
const std::string XMLNS_GAMELIST = "jabber:iq:gamelist";

/// Global Boardlist Extension
#define ExtBoardListQuery 1404
const std::string XMLNS_BOARDLIST = "jabber:iq:boardlist";

/// Global Boardlist Extension
#define ExtGameReport 1405
const std::string XMLNS_GAMEREPORT = "jabber:iq:gamereport";

typedef gloox::Tag PlayerData;
typedef gloox::Tag GameData;
typedef gloox::Tag GameReportData;

class GameReport : public gloox::StanzaExtension
{
public:
	GameReport(const gloox::Tag* tag = 0);

	// Following four methods are all required by gloox
	virtual StanzaExtension* newInstance(const gloox::Tag* tag) const
	{
		return new GameReport(tag);
	}
	virtual const std::string& filterString() const;
	virtual gloox::Tag* tag() const;
	virtual gloox::StanzaExtension* clone() const;

	std::list<const GameReportData*> m_GameReport;
};

class GameListQuery : public gloox::StanzaExtension
{
public:
	GameListQuery(const gloox::Tag* tag = 0);

	// Following four methods are all required by gloox
	virtual StanzaExtension* newInstance(const gloox::Tag* tag) const
	{
		return new GameListQuery(tag);
	}
	virtual const std::string& filterString() const;
	virtual gloox::Tag* tag() const;
	virtual gloox::StanzaExtension* clone() const;

	~GameListQuery();

	std::string m_Command;
	std::list<const GameData*> m_GameList;
};

class BoardListQuery : public gloox::StanzaExtension
{
public:
	BoardListQuery(const gloox::Tag* tag = 0);

	// Following four methods are all required by gloox
	virtual StanzaExtension* newInstance(const gloox::Tag* tag) const
	{
		return new BoardListQuery(tag);
	}
	virtual const std::string& filterString() const;
	virtual gloox::Tag* tag() const;
	virtual gloox::StanzaExtension* clone() const;

	~BoardListQuery();

	std::list<const PlayerData*> m_BoardList;
};
#endif
