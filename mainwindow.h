/*!
  \file
  \brief Header file for MainWindow. Provides the work of the graphical shell. Responsible for the operability of buttons and windows.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Contractor.h>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

/*!
 * \brief The MainWindow class.
 *
 * The main window of application with table view and special buttons.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief MainWindow - constructor
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void convertIntoCSV();
    void convertIntoSql();

    void openDB();
    void openCSV();

    void slotFillBox(const QStringList& tables);
    void setModel(TableModel*);

signals:
    void sendCurrentTable(const QString& tableName);

private:
    Ui::MainWindow *ui;

    Contractor contractor;
};



#endif // MAINWINDOW_H
