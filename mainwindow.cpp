#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QCloseEvent>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "shutdown.h"
#include <QMediaPlayer>
#include <QSound>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //重置窗口大小
    resize(800,600);
    //固定窗口大小
    this->setFixedSize(800,600);
    //设置标题
  //  this->setWindowTitle("peppa");
    //设置窗口标题
    this->setWindowTitle(QString("peppa"));
    this->setWindowTitle("pappe");

    //初始化对象
    ShutDown *Msd = new ShutDown;

    //添加音乐
    QSound *bgm = new QSound("F:/C++Pritice/QThomework/05_File/cry/BGM~1.wav",this);
    bgm->setLoops(-1);
    bgm->play();


    ui->setupUi(this);



    //ui->centralWidget->setMouseTracking(true);
    this->setMouseTracking(true);
    count = 1;


    //创建一个按钮，功能为关闭窗口
    QPushButton *myBtn = new QPushButton;
    myBtn->show();
    myBtn->setParent(this);
    myBtn->setText("不是");
    myBtn->move(400,400);//设置按钮坐标
    //myBtn->setGeometry(60,60,50,50);
    connect(myBtn,&QPushButton::clicked,[=](){
        QMessageBox::critical(this,"错误","回答错误，请重新选择！");


    });


    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->show();
    btn->setParent(this);
    btn->setText("是");
    btn->move(100,400);
    connect(btn,&QPushButton::clicked,[=](){
        if(QMessageBox::critical(this,"恭喜","你选择了正确答案！")== QMessageBox::Ok)
        {
            if(QMessageBox::critical(this,"警告","你的电脑将于1分钟以后关机！请保存数据！")==QMessageBox::Ok)
            {
                Msd->MySystemShutdownOrRestart();
                qDebug()<<"调用成功！";
            }
        }


    });

   //给label_2添加动图
    QMovie * movie = new QMovie("F:/C++Pritice/QThomework/05_File/cry/timg.gif");
    ui->label_2->setMovie(movie);
    movie->start();
    ui->label_2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *p)
{
    qDebug()<<count++;
    qDebug()<<p;
    qDebug()<<p->pos().x()<<","<<p->pos().y();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //取消X的关闭功能
    if(QMessageBox::information(this,"略略略",QStringLiteral("关不掉我！"),QMessageBox::Ok,QMessageBox::NoButton)== QMessageBox::Ok)
    {
        event->ignore();
    }
    else
    {
        event->accept();
    }
}
