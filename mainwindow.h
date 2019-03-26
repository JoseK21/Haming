#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Convertir_clicked();

    void on_pushButton_Haming_clicked();

    void on_actionSalir_triggered();

    void on_actionLimpiar_Ventana_triggered();

    void on_pushButton_VerficarError_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    enum Columna{
        Empty,P1,P2,D1,P3,D2,D3,D4,P4,D5,D6,D7,D8,D9,D10,D11,P5,D12,PP,BP
    };
};

#endif // MAINWINDOW_H
