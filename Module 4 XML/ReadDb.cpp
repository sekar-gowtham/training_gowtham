#include "ReadDb.h"
ReadDb::ReadDb()
{
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);
	SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);
	SQLDriverConnect(sqlConnHandle,NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE5\\SQLEXPRESS, 49400;DATABASE=Mydata;UID=sa;PWD=abc123$%^;",
		SQL_NTS,retconstring,1024,NULL,SQL_DRIVER_NOPROMPT);
}
void ReadDb::displayAllSongs()
{
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name;
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_name;
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name;
	SQLCHAR temp[SQL_RESULT_LEN];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	 SQLExecDirect(sqlStmtHandle,
		(SQLWCHAR*)L"select Song_Table.song_name ,Album_Table.album_name,Artist_Table.artist_name from Song_Table join song_album on song_album.song_id = Song_Table.song_id join Album_Table on Album_Table.album_id = song_album.album_id join song_artist on song_artist.song_id = Song_Table.song_id join Artist_Table on Artist_Table.artist_id = song_artist.artist_id order by Song_Table.song_name",
		SQL_NTS);
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, song_name, SQL_RESULT_LEN, &ptr_song_name);
			if (_strcmpi((char*)song_name, (char*)temp) != 0)
			{
				cout << "\n\nSong name : ";
				cout << song_name;
				strcpy_s((char*)temp, SQL_RESULT_LEN, (char*)song_name);
				cout << "\nAlbum : ";
				SQLGetData(sqlStmtHandle, 2, SQL_CHAR, album_name, SQL_RESULT_LEN, &ptr_album_name);
				cout << album_name;
				cout << "\nArtists : ";
			}
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, artist_name, SQL_RESULT_LEN, &ptr_artist_name);
			cout << artist_name << endl;
		}	
}
void ReadDb::displayAllArtist()
{
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name;
	SQLCHAR temp[SQL_RESULT_LEN];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle,
		(SQLWCHAR*)L"select Artist_Table.artist_name,Song_Table.song_name from Song_Table join song_artist on song_artist.song_id = Song_Table.song_id join Artist_Table on Artist_Table.artist_id = song_artist.artist_id order by Artist_Table.artist_name,Song_Table.song_name",
		SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, artist_name, SQL_RESULT_LEN, &ptr_artist_name);
		if (_strcmpi((char*)artist_name, (char*)temp) != 0)
		{
			cout << "\nArtist name : ";
			cout << artist_name << endl;
			//SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVariable3, SQL_RESULT_LEN, &ptrSqlVariable3);
			strcpy_s((char*)temp, SQL_RESULT_LEN, (char*)artist_name);
			cout << "Song names : ";
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, song_name, SQL_RESULT_LEN, &ptr_song_name);
		cout << song_name << endl;
	}
}
void ReadDb::displayAllAlbum()
{
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_album_name;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name;
	SQLCHAR temp[SQL_RESULT_LEN];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle,
		(SQLWCHAR*)L"select Album_Table.album_name,Song_Table.song_name from Song_Table join song_album on song_album.song_id = Song_Table.song_id join Album_Table on Album_Table.album_id = song_album.album_id order by Album_Table.album_name, Song_Table.song_name",
		SQL_NTS);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, album_name, SQL_RESULT_LEN, &ptr_album_name);
		if (_strcmpi((char*)album_name, (char*)temp) != 0)
		{
			cout << "\nAlbum name : ";
			cout << album_name << endl;
			strcpy_s((char*)temp, SQL_RESULT_LEN, (char*)album_name);
			cout << "\nSong names : ";
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, song_name, SQL_RESULT_LEN, &ptr_song_name);
		cout << song_name << endl;
	}
}
void ReadDb::displayAllPlaylist()
{
	SQLCHAR playlist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_playlist_name;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name;
	SQLCHAR temp[SQL_RESULT_LEN];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle,
		(SQLWCHAR*)L"select Playlist_Table.playlist_name,Song_Table.song_name from Song_Table join song_playlist on song_playlist.song_id = Song_Table.song_id join Playlist_Table on Playlist_Table.playlist_id = song_playlist.playlist_id order by Playlist_Table.playlist_name, Song_Table.song_name",
		SQL_NTS);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, playlist_name, SQL_RESULT_LEN, &ptr_playlist_name);
		if (_strcmpi((char*)playlist_name, (char*)temp) != 0)
		{
			cout << "\nPlaylist name name : ";
			cout << playlist_name << endl;
			strcpy_s((char*)temp, SQL_RESULT_LEN, (char*)playlist_name);
			cout << "\nSong names : ";
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, song_name, SQL_RESULT_LEN, &ptr_song_name);
		cout << song_name << endl;
	}
}
void ReadDb::displaySongDetails()
{
	string name;
	SQLCHAR song_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_song_name = SQL_NTS;
	SQLCHAR sqlVariable[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVariable;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Song_Table.song_name ,Album_Table.album_name,Artist_Table.artist_name from Song_Table join song_album on song_album.song_id = Song_Table.song_id join Album_Table on Album_Table.album_id = song_album.album_id join song_artist on song_artist.song_id = Song_Table.song_id join Artist_Table on Artist_Table.artist_id = song_artist.artist_id where Song_Table.song_name = ? order by Song_Table.song_name",
		SQL_NTS);
	cout << "Enter song name ";
	cin.ignore();
	getline(cin, name);
	strcpy_s((char*)song_name, SQL_RESULT_LEN, (char*)name.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, song_name, 0, &ptr_song_name);
	SQLExecute(sqlStmtHandle);
	if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "song name : ";
		cout << sqlVariable << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "album name : ";
		cout << sqlVariable << endl;
		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "artist names : ";
		cout << sqlVariable << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
			cout << sqlVariable << endl;
		}
	}
	else
	{
		cout << "\nSong is not present in database ";
	}
}
void ReadDb::displayArtistDetails()
{
	string name;
	SQLCHAR artist_name[SQL_RESULT_LEN];
	SQLINTEGER ptr_artist_name = SQL_NTS;
	SQLCHAR sqlVariable[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVariable;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Artist_Table.artist_name , Song_Table.song_name from Song_Table join song_artist on song_artist.song_id = Song_Table.song_id join Artist_Table on Artist_Table.artist_id = song_artist.artist_id where Artist_Table.artist_name = ? order by Artist_Table.artist_name, Song_Table.song_name",
		SQL_NTS);
	cout << "Enter artist name ";
	cin.ignore();
	getline(cin, name);
	strcpy_s((char*)artist_name, SQL_RESULT_LEN, (char*)name.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, artist_name, 0, &ptr_artist_name);
	SQLExecute(sqlStmtHandle);
	if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "artist name : ";
		cout << sqlVariable << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "song names : ";
		cout << sqlVariable << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
			cout << sqlVariable << endl;
		}
	}
	else
	{
		cout << "\nSong is not present in database ";
	}
}
void ReadDb::displayAlbumDetails()
{
	SQLINTEGER ptr_album_name = SQL_NTS;
	string name;
	SQLCHAR album_name[SQL_RESULT_LEN];
	SQLCHAR sqlVariable[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVariable;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Album_Table.album_name,Song_Table.song_name from Song_Table join song_album on song_album.song_id = Song_Table.song_id join Album_Table on Album_Table.album_id = song_album.album_id where Album_Table.album_name = ? order by Album_Table.album_name, Song_Table.song_name",
		SQL_NTS);
	cout << "\nenter album name ";
	cin.ignore();
	getline(cin, name);
	strcpy_s((char*)album_name, SQL_RESULT_LEN, (char*)name.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0, album_name, 0, &ptr_album_name);
	SQLExecute(sqlStmtHandle);
	if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "album name : ";
		cout << sqlVariable << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "song names : ";
		cout << sqlVariable << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
			cout << sqlVariable << endl;
		}
	}
	else
	{
		cout << "\nSong is not present in database ";
	}
}
void ReadDb::displayPlaylistDetails()
{
	SQLINTEGER ptr = SQL_NTS;
	string name;
	SQLCHAR playlist[SQL_RESULT_LEN];
	SQLCHAR sqlVariable[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVariable;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"select Playlist_Table.playlist_name,Song_Table.song_name from Song_Table join song_playlist on song_playlist.song_id = Song_Table.song_id join Playlist_Table on Playlist_Table.playlist_id = song_playlist.playlist_id where Playlist_Table.playlist_name = ? order by Playlist_Table.playlist_name, Song_Table.song_name",
		SQL_NTS);
	cout << "\nenter playlist name ";
	cin.ignore();
	getline(cin, name);
	strcpy_s((char*)playlist, SQL_RESULT_LEN, (char*)name.c_str());
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, SQL_RESULT_LEN, 0,playlist, 0, &ptr);
	SQLExecute(sqlStmtHandle);
	if (SQL_SUCCESS == SQLFetch(sqlStmtHandle))
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "playlist name : ";
		cout << sqlVariable << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
		cout << "song names : ";
		cout << sqlVariable << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVariable, SQL_RESULT_LEN, &ptrSqlVariable);
			cout << sqlVariable << endl;
		}
	}
	else
	{
		cout << "\nSong is not present in database ";
	}
}
ReadDb::~ReadDb()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}
