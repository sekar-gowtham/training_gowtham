#pragma once
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
#include <iostream>
#include <string>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
using namespace std;
class WriteDb
{
private:
	SQLHANDLE sqlConnHandle = NULL;
	SQLHANDLE sqlStmtHandle = NULL;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	WriteDb();
	~WriteDb();
	void insertSong();
	void createAlbum();
	void createArtist();
	void createPlaylist();
	void insertSongInArtist();
	void insertSongInPlaylist();
	void updateSongName();
	void updateArtistName();
	void updateAlbumName();
	void updatePlaylistName();
	void deleteSong();
};

