
#include <QtCore/QCoreApplication>
#include <QtGui/QImage>
#include <QtCore/QList>
#include <QtCore/QThread>
#include <QtCore/QDebug>
#include <QtGui/QGuiApplication>
#include <QtConcurrent/qtconcurrentmap.h>

QImage scale(const QImage& image)
{
	qDebug() << "Scaling image in thread" << QThread::currentThreadId();
	return image.scaled(QSize(100, 100), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	const int imageCount = 20;

	QList<QImage> images;
	for (int i = 0; i < imageCount; ++i)
	{
		images.append(QImage(1600, 1200, QImage::Format_ARGB32_Premultiplied));
	}

	QList<QImage> thumbnails = QtConcurrent::blockingMapped<QList<QImage> >(images, scale);

	return 0;
}
