
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QTextStream>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtConcurrent/qtconcurrentmap.h>

using namespace QtConcurrent;

QStringList findFiles(const QString& startDir, QStringList filters)
{
	QStringList names;
	QDir dir(startDir);

	foreach(QString file, dir.entryList(filters, QDir::Files))
	{
		names += startDir + "/" + file;
	}

	foreach(QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
	{
		names += findFiles(startDir + "/" + subdir, filters);
	}
	return names;
}

typedef QMap<QString, int> WordCount;

WordCount singleThreadWordCount(QStringList files)
{
	WordCount wordCount;
	foreach(QString file, files)
	{
		QFile f(file);
		f.open(QIODevice::ReadOnly);
		QTextStream textStream(&f);
		while(textStream.atEnd() == false)
		{
			foreach(QString word, textStream.readLine().split(" "))
			{
				wordCount[word] += 1;
			}
		}
	}
	return wordCount;
}

WordCount countWords(const QString& file)
{
	QFile f(file);
	f.open(QIODevice::ReadOnly);
	QTextStream textStream(&f);
	WordCount wordCount;

	while(textStream.atEnd() == false)
	{
		foreach(QString word, textStream.readLine().split(" "))
		{
			wordCount[word] += 1;
		}
	}
	return wordCount;
}

void reduce(WordCount& result, const WordCount& w)
{
	QMapIterator<QString, int> i(w);
	while(i.hasNext())
	{
		i.next();
		result[i.key()] += i.value();
	}
}

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	qDebug() << "finding files...";
	QStringList files = findFiles("../../", QStringList() << "*.cpp" << "*.h");
	qDebug() << files.count() << "files";

	qDebug() << "warmup";
	{
		QTime time;
		time.start();
		WordCount total = singleThreadWordCount(files);
	}
	qDebug() << "warmup done";

	int singleThreadTime = 0;
	{
		QTime time;
		time.start();
		WordCount total = singleThreadWordCount(files);
		singleThreadTime = time.elapsed();
		qDebug() << "single thread" << singleThreadTime;
	}

	int mapReduceTime = 0;
	{
		QTime time;
		time.start();
		WordCount total = mappedReduced(files, countWords, reduce);
		mapReduceTime = time.elapsed();
		qDebug() << "MapReduced" << mapReduceTime;
	}
	qDebug() << "MapReduce speedup x" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;
}