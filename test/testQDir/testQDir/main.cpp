
#include <QtCore/QtCore>

#include "gtest/gtest.h"

bool removeFiles(const QString& filePath)
{
	// 判断目录是否存在
	QDir dir(filePath);
	if (!dir.exists())
	{
		qDebug() << filePath << " is not exist";
		return false;
	}

	// 获取目录中所有的文件
	QFileInfoList fileInfos = dir.entryInfoList();
	Q_FOREACH(QFileInfo info, fileInfos)
	{
		QString path = info.filePath();
		if (info.isFile())
		{
			if (QFile::remove(path))
			{
				qDebug() << "remove file " << path << " successed";
			}
			else
			{
				qDebug() << "remove file " << path << " failed";
			}
		}
	}

	return true;
}

//int main(int argc, char *argv[])
//{
//	QCoreApplication a(argc, argv);
//
//	QString filePath = "./temp";
//	removeFiles(filePath);
//
//	return a.exec();
//}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::FLAGS_gtest_filter = "FactorialTest.*";
	return RUN_ALL_TESTS();
}
