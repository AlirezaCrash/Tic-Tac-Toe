#include "mainwindow.h"
#include "ui_mainwindow.h"
char currentPlayerSymbol = 'X';
int player1Score=0 , player2Score=0;
bool won = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playerLine->setText(QString(currentPlayerSymbol));
    ui->player1_Score->setText(QString::number(player1Score));
    ui->player2_Score->setText(QString::number(player2Score));
    for (int i = 0; i < 9; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("pushButton_%1").arg(i + 1));
        if (button) {
            connect(button, &QPushButton::clicked, this, &MainWindow::onAnyButtonClicked);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::disableAllButtons()
{
    for (int i = 0; i < 9; ++i) {
        QPushButton* button = findChild<QPushButton*>(QString("pushButton_%1").arg(i + 1));
        if (button) {
            button->setEnabled(false);
        }
    }
}
bool MainWindow::checkIfWinner()
{
    if( !ui->pushButton_1->text().isEmpty()  && ui->pushButton_1->text()  == ui->pushButton_2->text() && ui->pushButton_2->text()== ui->pushButton_3->text())
        return true;
    if( !ui->pushButton_4->text().isEmpty()  && ui->pushButton_4->text()  == ui->pushButton_5->text() && ui->pushButton_5->text()== ui->pushButton_6->text())
        return true;
    if( !ui->pushButton_7->text().isEmpty()  && ui->pushButton_7->text()  == ui->pushButton_8->text() && ui->pushButton_8->text()== ui->pushButton_9->text())
        return true;
    if( !ui->pushButton_1->text().isEmpty()  && ui->pushButton_1->text()  == ui->pushButton_4->text() && ui->pushButton_4->text()== ui->pushButton_7->text())
        return true;
    if( !ui->pushButton_2->text().isEmpty()  && ui->pushButton_2->text()  == ui->pushButton_5->text() && ui->pushButton_5->text()== ui->pushButton_8->text())
        return true;
    if( !ui->pushButton_3->text().isEmpty()  && ui->pushButton_3->text()  == ui->pushButton_6->text() && ui->pushButton_6->text()== ui->pushButton_9->text())
        return true;
    if( !ui->pushButton_1->text().isEmpty()  && ui->pushButton_1->text()  == ui->pushButton_5->text() && ui->pushButton_5->text()== ui->pushButton_9->text())
        return true;
    if( !ui->pushButton_3->text().isEmpty()  && ui->pushButton_3->text()  == ui->pushButton_5->text() && ui->pushButton_5->text()== ui->pushButton_7->text())
        return true;

    return false;
}
void MainWindow::onAnyButtonClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        clickedButton->setText(QString(currentPlayerSymbol));
        clickedButton->setEnabled(false);
        won = checkIfWinner();
        if(won)
        {
            ui->winnerLine->setText("Player " + QString(currentPlayerSymbol) +  " Won!");
            if(currentPlayerSymbol == 'X')
            {
                ui->player1_Score->setText(QString::number(++player1Score));
            }
            else
            {
                ui->player2_Score->setText(QString::number(++player2Score));
            }
            disableAllButtons();
            return;
        }
        else
        {
            currentPlayerSymbol = (currentPlayerSymbol == 'X') ? 'O' : 'X';
            ui->playerLine->setText(QString(currentPlayerSymbol));
        }
    }
}
void MainWindow::on_nextButton_clicked()
{
    won = false;
    ui->winnerLine->setText("");
    currentPlayerSymbol = (currentPlayerSymbol == 'X') ? 'O' : 'X';
    ui->playerLine->setText(QString(currentPlayerSymbol));
    for (int i = 0; i < 9; ++i)
    {
        QPushButton* button = findChild<QPushButton*>(QString("pushButton_%1").arg(i + 1));
        if (button)
        {
            button->setText("");
            button->setEnabled(true);
        }
    }
}



void MainWindow::on_resetButton_clicked()
{
    won = false;
    currentPlayerSymbol = 'X';
    player1Score = 0 ;
    player2Score = 0 ;
    ui->player1_Score->setText(QString::number(player1Score));
    ui->player2_Score->setText(QString::number(player2Score));
    ui->playerLine->setText(QString(currentPlayerSymbol));
    ui->winnerLine->setText("");
    for (int i = 0; i < 9; ++i)
    {
        QPushButton* button = findChild<QPushButton*>(QString("pushButton_%1").arg(i + 1));
        if (button)
        {
            button->setText("");
            button->setEnabled(true);
        }
    }
}


void MainWindow::on_quit_clicked()
{
    MainWindow::~MainWindow();
}

