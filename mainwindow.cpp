#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string>

static int a[20],b[20],c1,c2,c3,c4,c5;
static QString r1 = "";
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->VerficarError_clicked->setVisible(false);
    QStringList titulos1,titulos2;
    ui->tableWidget_1->setColumnCount(18);
    ui->tableWidget_2->setColumnCount(20);
    titulos1<<"--"<<"P1"<<"P2"<<"D1"<<"P3"<<"D2"<<"D3"<<"D4"<<"P4"<<"D5"<<"D6"<<"D7"<<"D8"<<"D9"<<"D10"<<"D11"<<"P5"<<"D12";
    titulos2<<"--"<<"P1"<<"P2"<<"D1"<<"P3"<<"D2"<<"D3"<<"D4"<<"P4"<<"D5"<<"D6"<<"D7"<<"D8"<<"D9"<<"D10"<<"D11"<<"P5"<<"D12"<<"PP"<<"BP";
    ui->tableWidget_1->setHorizontalHeaderLabels(titulos1);
    ui->tableWidget_2->setHorizontalHeaderLabels(titulos2);

    ui->tableWidget_1->insertRow(0);
    ui->tableWidget_1->insertRow(1);
    ui->tableWidget_1->insertRow(2);
    ui->tableWidget_1->insertRow(3);
    ui->tableWidget_1->insertRow(4);
    ui->tableWidget_1->insertRow(5);
    ui->tableWidget_2->insertRow(0);
    ui->tableWidget_2->insertRow(1);
    ui->tableWidget_2->insertRow(2);
    ui->tableWidget_2->insertRow(3);
    ui->tableWidget_2->insertRow(4);
    ui->tableWidget_2->insertRow(5);


    ui->tableWidget_1->setItem(0,Empty,new QTableWidgetItem("00"));
    ui->tableWidget_1->setItem(1,Empty,new QTableWidgetItem("P1"));
    ui->tableWidget_1->setItem(2,Empty,new QTableWidgetItem("P2"));
    ui->tableWidget_1->setItem(3,Empty,new QTableWidgetItem("P3"));
    ui->tableWidget_1->setItem(4,Empty,new QTableWidgetItem("P4"));
    ui->tableWidget_1->setItem(5,Empty,new QTableWidgetItem("P5"));

    ui->tableWidget_2->setItem(0,Empty,new QTableWidgetItem("00"));
    ui->tableWidget_2->setItem(1,Empty,new QTableWidgetItem("P1"));
    ui->tableWidget_2->setItem(2,Empty,new QTableWidgetItem("P2"));
    ui->tableWidget_2->setItem(3,Empty,new QTableWidgetItem("P3"));
    ui->tableWidget_2->setItem(4,Empty,new QTableWidgetItem("P4"));
    ui->tableWidget_2->setItem(5,Empty,new QTableWidgetItem("P5"));

    ui->tableWidget_1->verticalHeader()->setVisible(false);
    ui->tableWidget_2->verticalHeader()->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Conversion de Numeros a sus bases
int validarBinario(string str)
{
    char ch;
    int l = str.length();
    if(l==12){
        for (int i = 0; i < l; i++) {
            ch = str.at(i);
            if (ch == '1' || ch == '0') {
            }
            else {
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}
int validarBinario17(string str){

    int l = str.length();
    char ch;
    if(l==17){
        for (int i = 0; i < l; i++) {
            ch = str.at(i);
            if (ch == '1' || ch == '0') {
            }
            else {
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }

}
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}


int digitos(int digNum)
{
    if (digNum == 12) {
        return 1;
    }
    return 0;
}
int convertBinaryToDecimal(string str, int indiceMax)
{
    char ch;
    int result = 0;
    int numPosBinary = 0;
    for (int pos = 0; pos < str.length(); pos++) {
        ch = str.at(pos);
        numPosBinary = pow(2, indiceMax - pos); //11-pos = n
        if (ch == '1') {
            result += numPosBinary;
        }
    }

    return result;
}
string convertBinaryToHex(string str)
{
    string vector[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "A", "B", "C", "D", "E", "F" };
    string result;
    int pos4 = 3;
    string str4Dig;
    int ind_1 = 0;
    int ind_2 = 4;

    while (pos4 > 0) {
        str4Dig = str.substr(ind_1, ind_2);
        ind_1 += 4;
        ind_2 = ind_1;
        pos4--;
        int numVec = convertBinaryToDecimal(str4Dig, 3);
        if (numVec > 9) {
            result += vector[numVec];
        }
        else {
            result += to_string(numVec);
        }
    }
    return result;
}

string convertBinaryToBCD(string str)
{
    string vector[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001"};
    string result;
    int pos4 = 3;
    string str4Dig;
    int ind_1 = 0;
    int ind_2 = 4;

    while (pos4 > 0) {
        str4Dig = str.substr(ind_1, ind_2);
        ind_1 += 4;
        ind_2 = ind_1;
        pos4--;
        int numVec = convertBinaryToDecimal(str4Dig, 3);
        if (numVec > 9) {
            result = "ERROR";
            return result;
        }
        else {
            result += to_string(numVec);
        }
    }
    return result;

}

// Haming
void agregarDigVector_a(string num){
    int cont =0;
    for(int i=3;i<18;i++){
        if((i==4)||(i==8)||(i==16)){
            //No hacer nada
        }else{
            char binary = num.at(cont);
            int b = binary - '0'; // i is now equal to 1, not '1'
            a[i]=b;
            cont++;
        }
    }
    a[1]=a[3]^a[5]^a[7]^a[9]^a[11]^a[13]^a[15]^a[17];
    a[2]=a[3]^a[6]^a[7]^a[10]^a[11]^a[14]^a[15];
    a[4]=a[5]^a[6]^a[7]^a[12]^a[13]^a[14]^a[15];
    a[8]=a[9]^a[10]^a[11]^a[12]^a[13]^a[14]^a[15];
    a[16]=a[17];
    //show();
}
void agregarDigVector_b(string num){
    if(num.length()!=17){

    }
    else{
        for(int i=0;i<17;i++){
        char binary = num.at(i);
        int bi = binary - '0'; // i is now equal to 1, not '1'
        b[i+1]=bi;
    }
}
    c1=b[1]+b[3]+b[5]+b[7]+b[9]+b[11]+b[13]+b[15]+b[17];

    c2=b[2]+b[3]+b[6]+b[7]+b[10]+b[11]+b[14]+b[15];

    c3=b[4]+b[5]+b[6]+b[7]+b[12]+b[13]+b[14]+b[15];

    c4= b[8]+b[9]+b[10]+b[11]+b[12]+b[13]+b[14]+b[15];

    c5= b[16]+b[17];
}


int Paridad(int p){
    int aux;
    aux=p;

    if(aux == 1){
        return 1;   //Par
    }
    if(aux ==2){
        return 2;   //Impar
    }
}


void Hamming(string numHaming,int paridad){
    int aux;
    agregarDigVector_a(numHaming);
    aux = Paridad(paridad);

    string res = "";
    a[1]=a[3]^a[5]^a[7]^a[9]^a[11]^a[13]^a[15]^a[17];
    a[2]=a[3]^a[6]^a[7]^a[10]^a[11]^a[14]^a[15];
    a[4]=a[5]^a[6]^a[7]^a[12]^a[13]^a[14]^a[15];
    a[8]=a[9]^a[10]^a[11]^a[12]^a[13]^a[14]^a[15];
    a[16]=a[17];

    if(aux==2){                   ///////Aqui se hace el cambio de los valores en caso de ser paridad impar
        if(a[1] == 0){
            a[1] = 1;
        }
        else{
            a[1] =0;
        }
        if(a[2] == 0){
            a[2] =1;
        }
        else{
            a[2]=0;
        }
        if(a[4] == 0){
            a[4] =1;
        }
        else{
            a[4]=0;
        }
        if(a[8] == 0){
            a[8] =1;
        }
        else{
            a[8]=0;
        }
        if(a[16] == 0){
            a[16] =1;
        }
        else{
            a[16]=0;
        }
    }
    for(int i=1;i<18;i++){
        res+=to_string(a[i]);
    }
    r1=QString::fromStdString(res);

}

void MainWindow::on_pushButton_Convertir_clicked()
{
    string numeroEntrada = ui->lineEdit_Numero->text().toStdString();
    int vB = validarBinario(numeroEntrada);
    if(vB==1){
        string num = numeroEntrada;
            string aq = to_string(convertBinaryToDecimal(num, 11));
            ui->lineEdit_Decimal->setText(QString::fromStdString(aq));
            ui->lineEdit_Hexadecimal->setText(QString::fromStdString(convertBinaryToHex(num)));
            ui->lineEdit_BCD->setText(QString::fromStdString(convertBinaryToBCD(numeroEntrada)));
    }else{
        QMessageBox::warning(this,"Error Conversión","Numero incorrecto\nEntrada: "+QString::fromStdString(numeroEntrada)
                                 +"\nIngrese un <Numero Binario de 12 digitos>"
                                 +"\nEjemplo: 111001111010");
    }
}

void MainWindow::on_pushButton_Haming_clicked()
{
    string numeroEntrada = ui->lineEdit_Numero->text().toStdString();
    int vB = validarBinario(numeroEntrada);
    if(vB==1){
        if(ui->radioButton_Par->isChecked() || ui->radioButton_Impar->isChecked()){
            ui->tableWidget_1->clearContents();
            ui->tableWidget_1->setItem(0,Empty,new QTableWidgetItem("00"));
            ui->tableWidget_1->setItem(1,Empty,new QTableWidgetItem("P1"));
            ui->tableWidget_1->setItem(2,Empty,new QTableWidgetItem("P2"));
            ui->tableWidget_1->setItem(3,Empty,new QTableWidgetItem("P3"));
            ui->tableWidget_1->setItem(4,Empty,new QTableWidgetItem("P4"));
            ui->tableWidget_1->setItem(5,Empty,new QTableWidgetItem("P5"));
            ui->tableWidget_2->clearContents();
            ui->tableWidget_2->setItem(0,Empty,new QTableWidgetItem("00"));
            ui->tableWidget_2->setItem(1,Empty,new QTableWidgetItem("P1"));
            ui->tableWidget_2->setItem(2,Empty,new QTableWidgetItem("P2"));
            ui->tableWidget_2->setItem(3,Empty,new QTableWidgetItem("P3"));
            ui->tableWidget_2->setItem(4,Empty,new QTableWidgetItem("P4"));
            ui->tableWidget_2->setItem(5,Empty,new QTableWidgetItem("P5"));

            if(ui->radioButton_Par->isChecked()){
                Hamming(numeroEntrada,1);
            }else{
                Hamming(numeroEntrada,2);
            }

            for (int filaX=0;filaX<6;filaX++) { // lOGICA DE LA TABLA 1
               if(filaX==0){
                   ui->tableWidget_1->setItem(filaX,D1,new QTableWidgetItem(QString::number(a[3])));
                   ui->tableWidget_1->setItem(filaX,D2,new QTableWidgetItem(QString::number(a[5])));
                   ui->tableWidget_1->setItem(filaX,D3,new QTableWidgetItem(QString::number(a[6])));
                   ui->tableWidget_1->setItem(filaX,D4,new QTableWidgetItem(QString::number(a[7])));
                   ui->tableWidget_1->setItem(filaX,D5,new QTableWidgetItem(QString::number(a[8])));
                   ui->tableWidget_1->setItem(filaX,D6,new QTableWidgetItem(QString::number(a[9])));
                   ui->tableWidget_1->setItem(filaX,D7,new QTableWidgetItem(QString::number(a[10])));
                   ui->tableWidget_1->setItem(filaX,D8,new QTableWidgetItem(QString::number(a[11])));
                   ui->tableWidget_1->setItem(filaX,D9,new QTableWidgetItem(QString::number(a[12])));
                   ui->tableWidget_1->setItem(filaX,D10,new QTableWidgetItem(QString::number(a[13])));
                   ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[14])));
                   //ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[15])));
                   ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[17])));
               }else if (filaX==1) {
                   ui->tableWidget_1->setItem(filaX,P1,new QTableWidgetItem(QString::number(a[1])));
                   ui->tableWidget_1->setItem(filaX,D1,new QTableWidgetItem(QString::number(a[3])));
                   ui->tableWidget_1->setItem(filaX,D2,new QTableWidgetItem(QString::number(a[5])));
                   ui->tableWidget_1->setItem(filaX,D4,new QTableWidgetItem(QString::number(a[7])));
                   ui->tableWidget_1->setItem(filaX,D5,new QTableWidgetItem(QString::number(a[8])));
                   ui->tableWidget_1->setItem(filaX,D7,new QTableWidgetItem(QString::number(a[9])));
                   ui->tableWidget_1->setItem(filaX,D9,new QTableWidgetItem(QString::number(a[11])));
                  //ui->tableWidget_1->setItem(filaX,D10,new QTableWidgetItem(QString::number(a[13])));
                   //ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[15])));
                   ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[16])));
                   ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[17])));
               }else if (filaX==2) {
                   ui->tableWidget_1->setItem(filaX,P2,new QTableWidgetItem(QString::number(a[2])));
                   ui->tableWidget_1->setItem(filaX,D1,new QTableWidgetItem(QString::number(a[3])));
                   ui->tableWidget_1->setItem(filaX,D3,new QTableWidgetItem(QString::number(a[6])));
                   ui->tableWidget_1->setItem(filaX,D4,new QTableWidgetItem(QString::number(a[7])));
                   ui->tableWidget_1->setItem(filaX,D6,new QTableWidgetItem(QString::number(a[8])));
                   ui->tableWidget_1->setItem(filaX,D7,new QTableWidgetItem(QString::number(a[10])));
                   ui->tableWidget_1->setItem(filaX,D10,new QTableWidgetItem(QString::number(a[11])));
                   ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[14])));
                  // ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[15])));
                  // ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[16])));
               }else if (filaX==3) {
                   ui->tableWidget_1->setItem(filaX,P3,new QTableWidgetItem(QString::number(a[4])));
                   ui->tableWidget_1->setItem(filaX,D2,new QTableWidgetItem(QString::number(a[5])));
                   ui->tableWidget_1->setItem(filaX,D3,new QTableWidgetItem(QString::number(a[6])));
                   ui->tableWidget_1->setItem(filaX,D4,new QTableWidgetItem(QString::number(a[7])));
                   ui->tableWidget_1->setItem(filaX,D8,new QTableWidgetItem(QString::number(a[7])));
                   ui->tableWidget_1->setItem(filaX,D9,new QTableWidgetItem(QString::number(a[12])));
                   ui->tableWidget_1->setItem(filaX,D10,new QTableWidgetItem(QString::number(a[13])));
                   ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[14])));
                   //ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[15])));
                   //ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[16])));
               }else if (filaX==4) {
                   ui->tableWidget_1->setItem(filaX,P4,new QTableWidgetItem(QString::number(a[4])));
                   ui->tableWidget_1->setItem(filaX,D5,new QTableWidgetItem(QString::number(a[8])));
                   ui->tableWidget_1->setItem(filaX,D6,new QTableWidgetItem(QString::number(a[9])));
                   ui->tableWidget_1->setItem(filaX,D7,new QTableWidgetItem(QString::number(a[10])));
                   ui->tableWidget_1->setItem(filaX,D8,new QTableWidgetItem(QString::number(a[11])));
                   ui->tableWidget_1->setItem(filaX,D9,new QTableWidgetItem(QString::number(a[12])));
                   ui->tableWidget_1->setItem(filaX,D10,new QTableWidgetItem(QString::number(a[13])));
                   ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[14])));
                   //ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[15])));
                   //ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[16])));
               }
               else if (filaX==5) {
                  //ui->tableWidget_1->setItem(filaX,D11,new QTableWidgetItem(QString::number(a[15]))); // EL 16 DEBERIA SER 15
                  ui->tableWidget_1->setItem(filaX,P5,new QTableWidgetItem(QString::number(a[16])));
                  ui->tableWidget_1->setItem(filaX,D12,new QTableWidgetItem(QString::number(a[17])));
              }
           }
            QMessageBox::information(this,"Codigo ",r1);
            ui->lineEdit_CodigoHaming->setText(r1);
        }
        else {
            QMessageBox::information(this,"Error Paridad","Seleccione la paridad \n: Par o Impar");
        }

    }else{
        QMessageBox::warning(this,"Error Haming","Numero incorrecto\nEntrada: "+QString::fromStdString(numeroEntrada)
                                 +"\nIngrese un <Numero Binario de 12 digitos>"
                                 +"\nEjemplo: 111001111010");
    }
}

void MainWindow::on_actionSalir_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLimpiar_Ventana_triggered()
{
    ui->radioButton_Impar->setAutoExclusive(false);
    ui->radioButton_Impar->setChecked(false);
    ui->radioButton_Impar->setAutoExclusive(true);

    ui->radioButton_Par->setAutoExclusive(false);
    ui->radioButton_Par->setChecked(false);
    ui->radioButton_Par->setAutoExclusive(true);


    ui->lineEdit_BCD->setText("");
    ui->lineEdit_Numero->setText("");
    ui->lineEdit_Decimal->setText("");
    ui->lineEdit_Hexadecimal->setText("");
    ui->lineEdit_CodigoHaming->setText("");
    ui->tableWidget_1->clearContents();
    ui->tableWidget_1->setItem(0,Empty,new QTableWidgetItem("00"));
    ui->tableWidget_1->setItem(1,Empty,new QTableWidgetItem("P1"));
    ui->tableWidget_1->setItem(2,Empty,new QTableWidgetItem("P2"));
    ui->tableWidget_1->setItem(3,Empty,new QTableWidgetItem("P3"));
    ui->tableWidget_1->setItem(4,Empty,new QTableWidgetItem("P4"));
    ui->tableWidget_1->setItem(5,Empty,new QTableWidgetItem("P5"));
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setItem(0,Empty,new QTableWidgetItem("00"));
    ui->tableWidget_2->setItem(1,Empty,new QTableWidgetItem("P1"));
    ui->tableWidget_2->setItem(2,Empty,new QTableWidgetItem("P2"));
    ui->tableWidget_2->setItem(3,Empty,new QTableWidgetItem("P3"));
    ui->tableWidget_2->setItem(4,Empty,new QTableWidgetItem("P4"));
    ui->tableWidget_2->setItem(5,Empty,new QTableWidgetItem("P5"));
}

void MainWindow::on_pushButton_VerficarError_clicked()
{
    string strx=  ui->lineEdit_CodigoHaming->text().toStdString();
    ui->lineEdit_CodigoHaming->setText("HOLA");

    agregarDigVector_b(strx);

    if(validarBinario17(strx)==1){
        if(ui->radioButton_Par->isChecked()){
            if((c1%2==0) && (c2%2==0)&& (c3%2==0) && (c4%2 ==0)&&(c5%2==0)){    //LISTO
                for (int filaX=0;filaX<6;filaX++) {
                   if(filaX==0){    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                   }else if (filaX==1) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==2) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));

                   }else if (filaX==3) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==4) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }
                   else if (filaX==5) { //LISTO

                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                  }
               }
            }
            else{   // LISTO
                int filaX = 0;
                ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                //ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(""));
                //ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(""));
                if((c1%2) != 0){    //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c2%2) != 0){    //LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                    }
                else{//LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(1)));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c3%2) != 0){ // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c4%2) != 0){ // LISTO
                   int filaX = 4;
                   ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                   ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                   ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                   ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                   ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                   ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                   ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                   ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                   ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                   ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{//LISTO
                    int filaX = 4;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c5%2) != 0){//LISTO
                    int filaX = 5;

                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
            }

        }else{
            if((c1%2==1) && (c2%2==1)&& (c3%2==1) && (c4%2==1)&&(c5%2==1)){    //LISTO
                for (int filaX=0;filaX<6;filaX++) {
                   if(filaX==0){    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       //ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(""));
                       //ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(""));
                   }else if (filaX==1) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==2) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));

                   }else if (filaX==3) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==4) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }
                   else if (filaX==5) { //LISTO

                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                  }
               }
            }
            else{   // LISTO
                int filaX = 0;
                ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[16])));
                ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(QString::number(b[17])));

                if((c1%2) != 1){    //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
                else{   //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c2%2) != 1){    //LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                    }
                else{//LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c3%2) != 1){ // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c4%2) != 1){ // LISTO
                   int filaX = 4;
                   ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                   ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                   ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                   ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                   ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                   ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                   ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                   ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                   ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                   ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{//LISTO
                    int filaX = 4;
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
                if((c5%2) != 1){//LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

        }}

    }else{
        QMessageBox::warning(this,"Error Haming","Numero incorrecto\nEntrada: "+QString::fromStdString(strx)
                                 +"\nIngrese un <Numero Binario de 12 digitos>"
                                 +"\nEjemplo: 111001111010");
    }

}

void MainWindow::on_pushButton_clicked()
{
    string strx=  ui->lineEdit_CodigoHaming->text().toStdString();
    agregarDigVector_b(strx);


    if(validarBinario17(strx)==1){
        if(ui->radioButton_Par->isChecked()){
            if((c1%2==0) && (c2%2==0)&& (c3%2==0) && (c4%2 ==0)&&(c5%2==0)){    //LISTO
                for (int filaX=0;filaX<6;filaX++) {
                   if(filaX==0){    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                   }else if (filaX==1) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==2) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));

                   }else if (filaX==3) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==4) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }
                   else if (filaX==5) { //LISTO

                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                  }
               }
            }
            else{   // LISTO
                int filaX = 0;
                ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                //ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(""));
                //ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(""));
                if((c1%2) != 0){    //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c2%2) != 0){    //LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                    }
                else{//LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c3%2) != 0){ // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c4%2) != 0){ // LISTO
                   int filaX = 4;
                   ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                   ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                   ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                   ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                   ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                   ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                   ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                   ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                   ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                   ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{//LISTO
                    int filaX = 4;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c5%2) != 0){//LISTO
                    int filaX = 5;

                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
            }

        }else{
            if((c1%2==1) && (c2%2==1)&& (c3%2==1) && (c4%2==1)&&(c5%2==1)){    //LISTO
                for (int filaX=0;filaX<6;filaX++) {
                   if(filaX==0){    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       //ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(""));
                       //ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(""));
                   }else if (filaX==1) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==2) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                       ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));

                   }else if (filaX==3) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                       ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                       ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                       ui->tableWidget_2->setItem(filaX,D4,new QTableWidgetItem(QString::number(b[7])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }else if (filaX==4) {    //LISTO
                       ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[8])));
                       ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[9])));
                       ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[10])));
                       ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[11])));
                       ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[12])));
                       ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[13])));
                       ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[14])));
                       ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[15])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                   }
                   else if (filaX==5) { //LISTO

                       ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[16])));
                       ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                       ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                       ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                  }
               }
            }
            else{   // LISTO
                int filaX = 0;
                ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[16])));
                ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem(QString::number(b[17])));

                if((c1%2) != 1){    //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
                else{   //LISTO
                    int filaX = 1;
                    ui->tableWidget_2->setItem(filaX,P1,new QTableWidgetItem(QString::number(b[1])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,D12,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c2%2) != 1){    //LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                    }
                else{//LISTO
                    int filaX = 2;
                    ui->tableWidget_2->setItem(filaX,P2,new QTableWidgetItem(QString::number(b[2])));
                    ui->tableWidget_2->setItem(filaX,D1,new QTableWidgetItem(QString::number(b[3])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c3%2) != 1){ // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   // LISTO
                    int filaX = 3;
                    ui->tableWidget_2->setItem(filaX,P3,new QTableWidgetItem(QString::number(b[4])));
                    ui->tableWidget_2->setItem(filaX,D2,new QTableWidgetItem(QString::number(b[5])));
                    ui->tableWidget_2->setItem(filaX,D3,new QTableWidgetItem(QString::number(b[6])));
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[7])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

                if((c4%2) != 1){ // LISTO
                   int filaX = 4;
                   ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                   ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                   ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                   ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                   ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                   ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                   ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                   ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                   ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                   ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{//LISTO
                    int filaX = 4;
                    ui->tableWidget_2->setItem(filaX,D5,new QTableWidgetItem(QString::number(b[8])));
                    ui->tableWidget_2->setItem(filaX,D6,new QTableWidgetItem(QString::number(b[9])));
                    ui->tableWidget_2->setItem(filaX,D7,new QTableWidgetItem(QString::number(b[10])));
                    ui->tableWidget_2->setItem(filaX,D8,new QTableWidgetItem(QString::number(b[11])));
                    ui->tableWidget_2->setItem(filaX,D9,new QTableWidgetItem(QString::number(b[12])));
                    ui->tableWidget_2->setItem(filaX,D10,new QTableWidgetItem(QString::number(b[13])));
                    ui->tableWidget_2->setItem(filaX,D11,new QTableWidgetItem(QString::number(b[14])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[15])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }
                if((c5%2) != 1){//LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("E"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(1)));
                }
                else{   //LISTO
                    int filaX = 5;
                    ui->tableWidget_2->setItem(filaX,P4,new QTableWidgetItem(QString::number(b[16])));
                    ui->tableWidget_2->setItem(filaX,P5,new QTableWidgetItem(QString::number(b[17])));
                    ui->tableWidget_2->setItem(filaX,PP,new QTableWidgetItem("C"));
                    ui->tableWidget_2->setItem(filaX,BP,new QTableWidgetItem(QString::number(0)));
                }

        }}

    }else{
        QMessageBox::warning(this,"Error Haming","Numero incorrecto\nEntrada: "+QString::fromStdString(strx)
                                 +"\nIngrese un <Numero Binario de 12 digitos>"
                                 +"\nEjemplo: 111001111010");
    }

}
