#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAnyButtonClicked();
    bool checkIfWinner();
    void disableAllButtons();

    void on_nextButton_clicked();


    void on_resetButton_clicked();

    void on_quit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
