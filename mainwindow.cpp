#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStuSql(nullptr)
{
    ui->setupUi(this);



    // QFile fread;
    // fread.setFileName(":/dlg.css");
    // fread.open(QIODevice::ReadOnly);
    // QString  strQss = fread.readAll();
    // m_dlgLogin.setStyleSheet(strQss);

    // fread.close();
    // fread.setFileName(":/main.css");
    // fread.open(QIODevice::ReadOnly);
    // strQss = fread.readAll();
    // this->setStyleSheet(strQss);





    m_dlgLogin.show();
    auto f = [&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);

    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"学生信息管理系统";

    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l<<"学生管理";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);

    // l.clear();
    // l<<"管理员管理";
    // QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    // pf->addChild(p2);

    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);


    m_ptrStuSql = stuSql::getinstance();
    m_ptrStuSql->init();

    m_lNames<<"宏箫笛";
    m_lNames<<"茹风";
    m_lNames<<"盛娴淑";
    m_lNames<<"秋觅双";
    m_lNames<<"裘志学";
    m_lNames<<"竹彦露";
    m_lNames<<"刁雪晴";
    m_lNames<<"图门素";
    m_lNames<<"宋心远";
    m_lNames<<"詹浩涆";
    m_lNames<<"稽芮丽";
    m_lNames<<"赵甘泽";
    m_lNames<<"刚仪";
    m_lNames<<"满胤";
    m_lNames<<"俎寻芳";
    m_lNames<<"董云韶";
    m_lNames<<"智乐成";
    m_lNames<<"经兰若";
    m_lNames<<"堵怀桃";
    m_lNames<<"北梦凡";
    m_lNames<<"束绣文";
    m_lNames<<"乐正珊";
    m_lNames<<"夏半青";
    m_lNames<<"曹欣笑";
    m_lNames<<"晋语彤";
    m_lNames<<"始小琴";
    m_lNames<<"琴鸿祯";
    m_lNames<<"藏乐人";
    m_lNames<<"虢岑";
    m_lNames<<"良濮存";
    m_lNames<<"枚曼安";
    m_lNames<<"公西成";
    m_lNames<<"操颖馨";
    m_lNames<<"席冷之";
    m_lNames<<"蹇偲";
    m_lNames<<"弥怀曼";
    m_lNames<<"通华奥";
    m_lNames<<"镇香天";
    m_lNames<<"郁星海";
    m_lNames<<"莱醉芙";
    m_lNames<<"龙和雅";
    m_lNames<<"红静秀";
    m_lNames<<"库可儿";
    m_lNames<<"冀尔烟";
    m_lNames<<"温平凡";
    m_lNames<<"袭秀慧";
    m_lNames<<"问斯文";
    m_lNames<<"杭鹤轩";
    m_lNames<<"呼延盼";
    m_lNames<<"那拉韶";
    m_lNames<<"善优悠";
    m_lNames<<"徭白云";
    m_lNames<<"俞知";
    m_lNames<<"越琬";
    m_lNames<<"斐运良";
    m_lNames<<"闾丘宛";
    m_lNames<<"解明凝";
    m_lNames<<"季洁玉";
    m_lNames<<"渠奕";
    m_lNames<<"依洋洋";
    m_lNames<<"琦芸溪";
    m_lNames<<"蔡霞辉";
    m_lNames<<"毕嫚";
    m_lNames<<"白冷珍";
    m_lNames<<"隆英奕";
    m_lNames<<"揭星光";
    m_lNames<<"撒康";
    m_lNames<<"潭慕山";
    m_lNames<<"镜雅逸";
    m_lNames<<"柯承福";
    m_lNames<<"简凌青";
    m_lNames<<"斋宜人";
    m_lNames<<"褒豪";
    m_lNames<<"愈依云";
    m_lNames<<"燕清舒";
    m_lNames<<"佘春琳";
    m_lNames<<"郜雅彤";
    m_lNames<<"伍翠柏";
    m_lNames<<"阮博耘";
    m_lNames<<"营修贤";
    m_lNames<<"赤怿";
    m_lNames<<"邛欣跃";
    m_lNames<<"东方永";
    m_lNames<<"冉幼";
    m_lNames<<"南漠";
    m_lNames<<"长孙晴";
    m_lNames<<"奈语蝶";
    m_lNames<<"俟烨烨";
    m_lNames<<"柳子悦";
    m_lNames<<"叔雁";
    m_lNames<<"滑彦珺";
    m_lNames<<"源芳润";
    m_lNames<<"淡和平";
    m_lNames<<"平丹彤";
    m_lNames<<"孟皓轩";
    m_lNames<<"嬴宛秋";
    m_lNames<<"闪巧曼";
    m_lNames<<"况瑰玮";
    m_lNames<<"逄业";
    m_lNames<<"喜清悦";
    m_lNames<<"栗永长";
    m_lNames<<"辉小凝";
    m_lNames<<"扈易巧";
    m_lNames<<"禚谷槐";
    m_lNames<<"贺儒";
    m_lNames<<"习波涛";
    m_lNames<<"农湛雨";
    m_lNames<<"昝晓兰";
    m_lNames<<"拓跋春";
    m_lNames<<"司徒易";
    m_lNames<<"司暮芸";
    m_lNames<<"昂临";
    m_lNames<<"严妙柏";
    m_lNames<<"纳喇安";
    m_lNames<<"仙胤雅";
    m_lNames<<"修承载";
    m_lNames<<"桂寻芳";
    m_lNames<<"江含海";
    m_lNames<<"山仪芳";
    m_lNames<<"湛小霜";
    m_lNames<<"开朝雨";
    m_lNames<<"张廖妙";
    m_lNames<<"缪德本";
    m_lNames<<"全音韵";
    m_lNames<<"乌孙多";
    m_lNames<<"衣静云";
    m_lNames<<"丑庄静";
    m_lNames<<"仝鹏池";
    m_lNames<<"剑晴照";
    m_lNames<<"松惜蕊";
    m_lNames<<"宦放";
    m_lNames<<"后喜悦";
    m_lNames<<"野芷荷";
    m_lNames<<"甲誉";
    m_lNames<<"过含雁";
    m_lNames<<"钦瑜蓓";
    m_lNames<<"京津";
    m_lNames<<"游晓兰";
    m_lNames<<"薄雯华";
    m_lNames<<"毛博裕";
    m_lNames<<"圭翠桃";
    m_lNames<<"闳畅";
    m_lNames<<"吕巧云";
    m_lNames<<"之金枝";
    m_lNames<<"皋和顺";
    m_lNames<<"保涉";
    m_lNames<<"壬戈";
    m_lNames<<"伊幻翠";
    m_lNames<<"哈问柳";
    m_lNames<<"嵇明";
    m_lNames<<"闻晴岚";
    m_lNames<<"常惜玉";
    m_lNames<<"泷怀山";
    m_lNames<<"戴罗绮";
    m_lNames<<"厍笑晴";
    m_lNames<<"戊俊英";
    m_lNames<<"包怜雪";
    m_lNames<<"庆浩宕";
    m_lNames<<"牟允";
    m_lNames<<"蓟子凡";
    m_lNames<<"桓安吉";
    m_lNames<<"蔺冠";
    m_lNames<<"乌雅尔";
    m_lNames<<"洪天菱";
    m_lNames<<"栾吉";
    m_lNames<<"齐巧兰";
    m_lNames<<"力曦之";
    m_lNames<<"回灵萱";
    m_lNames<<"宰父思";
    m_lNames<<"牛暖暖";
    m_lNames<<"相怀莲";
    m_lNames<<"水盼柳";
    m_lNames<<"洋雪萍";
    m_lNames<<"金书云";
    m_lNames<<"逯颜";
    m_lNames<<"单一南";
    m_lNames<<"臧以彤";
    m_lNames<<"元婉秀";
    m_lNames<<"潜妍歌";
    m_lNames<<"碧鲁飞";
    m_lNames<<"阎忆辰";
    m_lNames<<"福音悦";
    m_lNames<<"慕容嘉";
    m_lNames<<"竺英朗";
    m_lNames<<"孔刚捷";
    m_lNames<<"市曦晨";
    m_lNames<<"邵向雪";
    m_lNames<<"布鸿煊";
    m_lNames<<"刀修洁";
    m_lNames<<"帖书竹";
    m_lNames<<"达芳苓";
    m_lNames<<"舜寻桃";
    m_lNames<<"贝汉";
    m_lNames<<"汗修竹";
    m_lNames<<"幸承业";
    m_lNames<<"所德宇";
    m_lNames<<"荤凝竹";
    m_lNames<<"进芳泽";
    m_lNames<<"樊燕桦";
    m_lNames<<"完晗玥";
    m_lNames<<"缑慧秀";
    m_lNames<<"丛明辉";
    m_lNames<<"求坤";
    m_lNames<<"彭思嘉";
    m_lNames<<"汤水儿";
    m_lNames<<"鲁香之";
    m_lNames<<"青年";
    m_lNames<<"钊锐藻";
    m_lNames<<"劳余";
    m_lNames<<"尉痴梅";
    m_lNames<<"公羊学";
    m_lNames<<"尹雅辰";
    m_lNames<<"叶永思";
    m_lNames<<"友惜萱";
    m_lNames<<"以迎彤";
    m_lNames<<"巢浩博";
    m_lNames<<"虎怜双";
    m_lNames<<"板娅芳";
    m_lNames<<"东郭兆";
    m_lNames<<"书清韵";
    m_lNames<<"长情韵";
    m_lNames<<"佛书白";
    m_lNames<<"亥叶农";
    m_lNames<<"黄梓珊";
    m_lNames<<"益正平";
    m_lNames<<"宜依波";
    m_lNames<<"户秀慧";


    updateTable();


    //按比列拉伸表格的头部，而不是拉伸最后一列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F6)
    {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        this->setStyleSheet(strQss);
        m_dlgLogin.setStyleSheet(strQss);
    }
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}


void MainWindow::on_btn_simulation_clicked()
{


     //制作1000条员工数据
    QRandomGenerator  g,c;
    g.seed(0);
    c.seed(0);

    QList<StuInfo> l;
    for(int i =0;i<m_lNames.size();i++)
    {

        auto grade = g.bounded(7,10);
        auto uiclass = g.bounded(1,8);
        StuInfo info;
         info.name = m_lNames[i];
        if(i%3)
        {
          info.age = 16;
        }

        if(i%7)
        {
            info.age = 17;
        }

        if(i%2)
        {
           info.age = 18;
        }

        info.grade = grade;
        info.uiclass = uiclass;
        info.studentid = i;
        info.phone = "13812345678";
        info.wechat = "13812345678";
        l.append(info);
    }
    m_ptrStuSql->addStu(l);
    updateTable();
}


void MainWindow::on_btn_add_clicked()
{
    m_dlgAddStu.setType(true);
    m_dlgAddStu.exec();
    updateTable();
}


void MainWindow::on_btn_clear_clicked()
{
    m_ptrStuSql->clearStuTable();
    updateTable();
}


void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l ;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    //l<<"序号"<<"id"<<"姓名"<<"年龄"<<"部门id"<<"职级"<<"工号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrStuSql->getStuCnt();
    ui->lb_cnt->setText(QString("学生总数:%1").arg(cnt));
    QList<StuInfo>  lStudents = m_ptrStuSql->getPageStu(0,cnt);


    ui->tableWidget->setRowCount(cnt);
    for(int i =0;i<lStudents.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(lStudents[i].uiclass)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lStudents[i].wechat));

    }
}

void MainWindow::on_btn_del_clicked()
{
   int i = ui->tableWidget->currentRow();
   if(i>=0)
   {
      int id =  ui->tableWidget->item(i,1)->text().toUInt();
       m_ptrStuSql->delStu(id);
       updateTable();
       QMessageBox::information(nullptr,"信息","删除成功");
   }

}


void MainWindow::on_btn_update_clicked()
{
    StuInfo info;
    int i = ui->tableWidget->currentRow(); // 序号/行数


    if(i>=0)
{
        info.id =  ui->tableWidget->item(i,1)->text().toUInt();
        info.name =  ui->tableWidget->item(i,2)->text();
        info.age =  ui->tableWidget->item(i,3)->text().toUInt();
        info.grade =  ui->tableWidget->item(i,4)->text().toUInt();
        info.uiclass =  ui->tableWidget->item(i,5)->text().toUInt();
        info.studentid =  ui->tableWidget->item(i,6)->text().toUInt();
        info.phone =  ui->tableWidget->item(i,7)->text();
        info.wechat =  ui->tableWidget->item(i,8)->text();
       m_dlgAddStu.setType(false,info);
       m_dlgAddStu.exec();
    }

    qDebug() << "row =" << i
             << "id =" << info.id;


    updateTable();
}


void MainWindow::on_btn_search_clicked()
{


    QString strFilter= ui->le_search->text();
    if(strFilter.isEmpty())
    {
        QMessageBox::information(nullptr,"警告","名字筛选为空");
        updateTable();
        return;
    }


    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l ;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    //l<<"序号"<<"id"<<"姓名"<<"年龄"<<"部门id"<<"职级"<<"工号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    auto cnt = m_ptrStuSql->getStuCnt();
    ui->lb_cnt->setText(QString("员工总数:%1").arg(cnt));
    QList<StuInfo>  lStudents = m_ptrStuSql->getPageStu(0,cnt);



    int index = 0;
    for(int i =0;i<lStudents.size();i++)
    {
        if(!lStudents[i].name.contains(strFilter))
        {
            continue;
        }


        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index+1)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(QString::number(lStudents[i].uiclass)));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(index,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(index,8,new QTableWidgetItem(lStudents[i].wechat));
        index ++;

    }
    ui->tableWidget->setRowCount(index);

}

