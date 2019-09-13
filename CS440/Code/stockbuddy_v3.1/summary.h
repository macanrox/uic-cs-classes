#ifndef SUMMARY_H
#define SUMMARY_H
#include "buy.h"
#include "sell.h"
#include "reciept.h"

#include <QDialog>

namespace Ui {
	class summary;
}

class summary : public QDialog
{
	Q_OBJECT

public:
	explicit summary(QWidget *parent = 0);
	~summary();

	private slots:

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_3_clicked();

private:
	Ui::summary *ui;
};

#endif // SUMMARY_H
