#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <string>
#include <cstdlib>
#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <json-c/json.h>
#include <json-c/debug.h>
#include <json-c/json_object.h>
#include <QMessageBox>

#define PORT 3550
#define MAXDATASIZE 1000

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Table(int N, int At, int An, int T, int D, int L);
    string BMPtoBinaryData(string directory);
    string decimalToBinary(int d);

    int sendJSON(json_object *jObj);
    int sendJSON(string KEY, string data);

private slots:
    void on_BotonImg_clicked();

    void on_BotonGal_clicked();

private:
    Ui::MainWindow *ui;

    ///Cantidad de columnas
    int num,num2,col,fil;
    int Nombre,Autor,Year,Size,Descripcion,Link;

    ///Imagen
    QPixmap* Imag;

    ///QGraphicsView
    QGraphicsView * view;

    ///La ventana de la imagen
    QGraphicsScene* VentanaImagen;

    ///Instancia estática del contenedor del BinaryData
    string binaryData;

    //Objeto JSON para sendJSON()
    json_object *jObj = json_object_new_object();

    ///Keys SENDJSON
    QString NombreGaleria;
    QString newImage;


};

#endif // MAINWINDOW_H
