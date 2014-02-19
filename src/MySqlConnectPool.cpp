//============================================================================
// Name        : MySqlConnectPool.cpp
// Author      : chenhf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <my_global.h>
#include <mysql.h>

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	MYSQL * conn;
	int nRet = -1;


	conn = mysql_init(NULL);
	if (conn == NULL)
		std::cout << "init fail\n";


	MYSQL * p = NULL;
	p = mysql_real_connect(conn, "localhost", "webmall", "webmall", "webmall", 3306, "/var/lib/mysql/mysql.sock", 0);
	if (p == NULL)
	{
		std::cout << "connect fail " << mysql_error(conn) << std::endl;
		return 1;
	}


	char value = 1;
	mysql_options(conn, MYSQL_OPT_RECONNECT, &value);

	nRet = mysql_set_character_set(conn, "utf8");



	nRet = mysql_query(conn, "insert into users(realname) values('陈海峰')");
	if (nRet != 0)
	{
		std::cout << "insert into fail: " << mysql_error(conn) << std::endl;

	}
	else
	{
		std::cout << "mysql_query execute succesfully";
	}

	mysql_close(conn);

	return 0;
}
