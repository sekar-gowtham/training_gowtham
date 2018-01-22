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
class ReadDb
{
private:
	SQLHANDLE sqlConnHandle=NULL;
	SQLHANDLE sqlStmtHandle=NULL;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	SQLINTEGER sqlVersion;
	SQLINTEGER ptrSqlVersion;
public:
	ReadDb();
	~ReadDb();
	void displayAllSongs();
	void displayAllArtist();

};

