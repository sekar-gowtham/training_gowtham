#include "WriteDb.h"
WriteDb::WriteDb()
{
	 SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);
	 SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	 SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);
	 SQLDriverConnect(sqlConnHandle,NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE5\\SQLEXPRESS, 49400;DATABASE=Mydata;UID=sa;PWD=abc123$%^;",
        SQL_NTS,retconstring,1024,NULL,SQL_DRIVER_NOPROMPT);
}
void WriteDb::insertSong()
{
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLCHAR album_id[SQL_RESULT_LEN];
	SQLCHAR artist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	SQLINTEGER ptr_album_id = SQL_NTS;
	SQLINTEGER ptr_artist_id = SQL_NTS;
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLINTEGER ptr_album_name = SQL_NTS;
	SQLINTEGER ptr_artist_name = SQL_NTS;
	string songName;
	string albumName;
	string artistName;
	cout << "\nenter the song name ";
	cin.ignore();
	getline(cin,songName);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into Song_Table(song_name) values (?)",
		SQL_NTS);
	strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
	SQLExecute(sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
	SQLExecute(sqlStmtHandle);
	SQLFetch(sqlStmtHandle);
	SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
	while (1)
	{
		cout << "\nenter album name which is present in database ";
		getline(cin, albumName);
		strcpy_s((char*)album_name, SQL_RESULT_LEN, (char*)albumName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select album_id from Album_Table where album_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, album_id, SQL_RESULT_LEN, &ptr_album_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong album name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_album(song_id,album_id) values (?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_id, 0, &ptr_album_id);
	SQLExecute(sqlStmtHandle);
	while (1)
	{
		cout << "\nenter artist name which is present in database ";
		getline(cin, artistName);
		strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)artistName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select artist_id from Artist_Table where artist_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, artist_id, SQL_RESULT_LEN, &ptr_artist_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong artist name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_artist(song_id,artist_id) values (?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_id, 0, &ptr_artist_id);
	SQLExecute(sqlStmtHandle);

	cout << "\nsong added";
}
void WriteDb::createAlbum()
{
	string albumName;
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_name = SQL_NTS;
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	SQLCHAR album_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_id = SQL_NTS;
	cout << "\nenter the album name ";
	cin.ignore();
	getline(cin, albumName);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into Album_Table(album_name) values (?)",
		SQL_NTS);
	strcpy_s((char*)album_name, SQL_RESULT_LEN, (char*)albumName.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select album_id from Album_Table where album_name=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
	SQLExecute(sqlStmtHandle);
	SQLFetch(sqlStmtHandle);
	SQLGetData(sqlStmtHandle, 1, SQL_CHAR, album_id, SQL_RESULT_LEN, &ptr_album_id);
	while (1)
	{
		cout << "\nenter the song name which is present in database";
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_album(song_id,album_id) values(?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_id, 0, &ptr_album_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nAlbum created";
}
void WriteDb::createArtist()
{
	string artistName;
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name = SQL_NTS;
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	SQLCHAR artist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_id = SQL_NTS;
	cout << "\nenter the artist name ";
	cin.ignore();
	getline(cin, artistName);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into Artist_Table(artist_name) values (?)",
		SQL_NTS);
	strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)artistName.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select artist_id from Artist_Table where artist_name=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
	SQLExecute(sqlStmtHandle);
	SQLFetch(sqlStmtHandle);
	SQLGetData(sqlStmtHandle, 1, SQL_CHAR, artist_id, SQL_RESULT_LEN, &ptr_artist_id);
	while (1)
	{
		cout << "\nenter the song name which is present in database ";
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_artist(song_id,artist_id) values(?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_id, 0, &ptr_artist_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nartist created";
}
void WriteDb::createPlaylist()
{
	string playlistName;
	SQLCHAR playlist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_name = SQL_NTS;
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	SQLCHAR playlist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_id = SQL_NTS;
	cout << "\nenter the playlist name ";
	cin.ignore();
	getline(cin, playlistName);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into Playlist_Table(playlist_name) values (?)",
		SQL_NTS);
	strcpy_s((char*)playlist_name, SQL_RESULT_LEN, (char*)playlistName.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_name, 0, &ptr_playlist_name);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select playlist_id from Playlist_Table where playlist_name=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_name, 0, &ptr_playlist_name);
	SQLExecute(sqlStmtHandle);
	SQLFetch(sqlStmtHandle);
	SQLGetData(sqlStmtHandle, 1, SQL_CHAR, playlist_id, SQL_RESULT_LEN, &ptr_playlist_id);
	while (1)
	{
		cout << "\nenter the song name which is present in database ";
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_playlist(song_id,playlist_id) values(?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_id, 0, &ptr_playlist_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nplaylist created";
}

void WriteDb::insertSongInArtist()
{
	string artistName;
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name = SQL_NTS;
	SQLCHAR artist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_id = SQL_NTS;
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the song name which is present in database ";
		cin.ignore();
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	while (1)
	{
		cout << "\nenter the artist name which is present in database ";
		getline(cin, artistName);
		strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)artistName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select artist_id from Artist_Table where artist_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, artist_id, SQL_RESULT_LEN, &ptr_artist_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong artist name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_artist(song_id,artist_id) values (?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_id, 0, &ptr_artist_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nsong added to the artist";
}
void WriteDb::insertSongInPlaylist()
{
	string playlistName;
	SQLCHAR playlist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_name = SQL_NTS;
	SQLCHAR playlist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_id = SQL_NTS;
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the song name which is present in database ";
		cin.ignore();
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	while (1)
	{
		cout << "\nenter the playlist name which is present in database ";
		getline(cin, playlistName);
		strcpy_s((char*)playlist_name, SQL_RESULT_LEN, (char*)playlistName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select playlist_id from Playlist_Table where playlist_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_name, 0, &ptr_playlist_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, playlist_id, SQL_RESULT_LEN, &ptr_playlist_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong playlist name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"insert into song_playlist(song_id,playlist_id) values (?,?)",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_id, 0, &ptr_playlist_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nsong added to the playlist";
}
void WriteDb::updateSongName()
{
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the old song name which is present in database ";
		cin.ignore();
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	cout << "Enter new song name";
	getline(cin, songName);
	strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update Song_Table set song_name=? where song_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLExecute(sqlStmtHandle);
	cout << "updated successfully ";
}
void WriteDb::updateArtistName()
{
	string artistName;
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name = SQL_NTS;
	SQLCHAR artist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the old artist name which is present in database ";
		cin.ignore();
		getline(cin, artistName);
		strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)artistName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select artist_id from Artist_Table where artist_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, artist_id, SQL_RESULT_LEN, &ptr_artist_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong artist name";
		}
	}
	cout << "Enter new artist name ";
	getline(cin, artistName);
	strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)artistName.c_str());
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update artist_Table set artist_name=? where artist_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_id, 0, &ptr_artist_id);
	SQLExecute(sqlStmtHandle);
	cout << "updated successfully ";
}
void WriteDb::updateAlbumName()
{
	string albumName;
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_name = SQL_NTS;
	SQLCHAR album_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the old album name which is present in database ";
		cin.ignore();
		getline(cin, albumName);
		strcpy_s((char*)album_name, SQL_RESULT_LEN, (char*)albumName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select album_id from Album_Table where album_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, album_id, SQL_RESULT_LEN, &ptr_album_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong album name";
		}
	}
	cout << "Enter new album name ";
	getline(cin, albumName);
	strcpy_s((char*)album_name, SQL_RESULT_LEN, (char*)albumName.c_str());
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update Album_Table set album_name=? where album_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_id, 0, &ptr_album_id);
	SQLExecute(sqlStmtHandle);
	cout << "updated successfully ";
}
void WriteDb::updatePlaylistName()
{
	string playlistName;
	SQLCHAR playlist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_name = SQL_NTS;
	SQLCHAR playlist_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the old playlist name which is present in database ";
		cin.ignore();
		getline(cin, playlistName);
		strcpy_s((char*)playlist_name, SQL_RESULT_LEN, (char*)playlistName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select playlist_id from Playlist_Table where playlist_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_name, 0, &ptr_playlist_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, playlist_id, SQL_RESULT_LEN, &ptr_playlist_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong album name";
		}
	}
	cout << "Enter new playlist name ";
	getline(cin, playlistName);
	strcpy_s((char*)playlist_name, SQL_RESULT_LEN, (char*)playlistName.c_str());
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update Playlist_Table set playlist_name=? where playlist_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_name, 0, &ptr_playlist_name);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, playlist_id, 0, &ptr_playlist_id);
	SQLExecute(sqlStmtHandle);
	cout << "updated successfully ";
}
void WriteDb::deleteSong()
{
	string songName;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR song_id[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_id = SQL_NTS;
	while (1)
	{
		cout << "\nenter the song name which is present in database ";
		cin.ignore();
		getline(cin, songName);
		strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)songName.c_str());
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_id from Song_Table where Song_Table.song_name=?",
			SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
		SQLExecute(sqlStmtHandle);
		if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_id, SQL_RESULT_LEN, &ptr_song_id);
			break;
		}
		else
		{
			cout << "\nyou entered wrong song name";
		}
	}
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from Song_Table where song_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from song_album where song_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from song_artist where song_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLExecute(sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from song_playlist where song_id=?",
		SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_id, 0, &ptr_song_id);
	SQLExecute(sqlStmtHandle);
	cout << "\nsong deleted successfully";
}
WriteDb::~WriteDb()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

