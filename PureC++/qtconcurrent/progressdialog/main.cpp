
#include <QtWidgets/QtWidgets>
#include <QtConcurrent/QtConcurrent>

using namespace QtConcurrent;

const int iterations = 200;

void spin(int& iteration)
{
	const int work = 1000 * 1000 * 40;
	volatile int v = 0;
	for (int j = 0; j < work; ++j)
	{
		++v;
	}

	qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QVector<int> vector;
	for (int i = 0; i < iterations; ++i)
	{
		vector.append(i);
	}

	QProgressDialog dialog;
	dialog.setLabelText(QString("Progressing using %1 threads...").arg(QThread::idealThreadCount()));

	QFutureWatcher<void> futureWatcher;
	QObject::connect(&futureWatcher, SIGNAL(finished()), &dialog, SLOT(reset()));
	QObject::connect(&dialog, SIGNAL(canceled()), &futureWatcher, SLOT(cancel()));
	QObject::connect(&futureWatcher, SIGNAL(progressRangeChanged(int, int)), &dialog, SLOT(setRange(int, int)));
	QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)), &dialog, SLOT(setValue(int)));

	futureWatcher.setFuture(QtConcurrent::map(vector, spin));

	dialog.exec();

	futureWatcher.waitForFinished();

	qDebug() << "Cancled?" << futureWatcher.future().isCanceled();
}
