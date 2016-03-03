#include "ManagerSqlite.h"

static ManagerSqlite *_instance;

ManagerSqlite * ManagerSqlite::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ManagerSqlite();
	}
	return _instance;
}

void ManagerSqlite::destroyInstance()
{
	CC_SAFE_DELETE(_instance);
}

ManagerSqlite::ManagerSqlite() : _dataBase(nullptr)
{
}

ManagerSqlite::~ManagerSqlite()
{
}

void ManagerSqlite::dataBaseOpen()
{
	auto path = FileUtils::getInstance()->getWritablePath() + "dataBase.db";//ָ�����ݿ��·��

	auto result = sqlite3_open(path.c_str(), &_dataBase);//��һ�����ݿ⣬��������ݿⲻ���ڣ��򴴽�һ�����ݿ��ļ�
	if (result != SQLITE_OK)
	{
		log("ManagerSqlite::dataBaseOpen open database failed,  number%d", result);
	}
}

void ManagerSqlite::dataBaseClose()
{
	sqlite3_close(_dataBase);
}

void ManagerSqlite::tableCreate()
{
	std::string sql = "create table student(ID integer primary key autoincrement,name text,sex text)";//������

	auto result = sqlite3_exec(_dataBase, sql.c_str(), nullptr, nullptr, nullptr);
	if (result != SQLITE_OK)
	{
		log("ManagerSqlite::tableCreate create table failed, number%d", result);
	}
}

void ManagerSqlite::dataInsert()
{
	std::string sql = "insert into student values(1,'student1','male')";//����в���1������

	auto result = sqlite3_exec(_dataBase, sql.c_str(), nullptr, nullptr, nullptr);
	if (result != SQLITE_OK)
	{
		log("ManagerSqlite::dataInsert insert data failed, number%d", result);
	}
}

void ManagerSqlite::dataQuery()
{
	char **result;//��ѯ���
	int r, c;//�С���
	std::string sql = "select * from student";

	sqlite3_get_table(_dataBase, sql.c_str(), &result, &r, &c, nullptr);
	log("ManagerSqlite::dataQuery row is %d,column is %d", r, c);
	for (auto i = 1; i < r; i++)
	{
		for (auto j = 0; j < c; j++)
		{
			log("%s", result[i * c + j]);
		}
	}
	sqlite3_free_table(result);
}

void ManagerSqlite::dataDelete()
{
	std::string sql = "delete from student where ID=1"; //ɾ��ID = 1��ѧ��

	auto result = sqlite3_exec(_dataBase, sql.c_str(), nullptr, nullptr, nullptr);
	if (result != SQLITE_OK)
	{
		log("ManagerSqlite::dataDelete delete data failed, number%d", result);
	}
}
