#include "ReadDb.h"


ReadDb::ReadDb()
{
	SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);

	SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	
	SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);
		
	SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE5\\SQLEXPRESS, 49400;DATABASE=Mydata;UID=sa;PWD=abc123$%^;",
		//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE5\\SQLEXPRESS, 49400;DATABASE=Mydata;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT);



}

void ReadDb::displayAllSongs()
{
	int i = 1;
	SQLCHAR sqlVersion1[40];
	SQLINTEGER ptrSqlVersion1;
	string query1 = "SELECT song_name FROM Song_Table WHERE song_id= " + i;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT song_name FROM Song_Table WHERE song_id=2", SQL_NTS);
	
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion1, 40, &ptrSqlVersion1);
		cout << sqlVersion1 << endl;
	}
}
void ReadDb::displayAllArtist()
{
	SQLCHAR sqlVersion1[40];
	SQLINTEGER ptrSqlVersion1;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM Artist_Table", SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion1, 40, &ptrSqlVersion1);
		cout << sqlVersion1 << endl;
	}
}

ReadDb::~ReadDb()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}
