/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 23 17:07:45 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalendar;
    QAction *actionTo_do_List;
    QAction *actionMemo_Pad;
    QAction *actionEvent_List;
    QAction *actionAlarm_List;
    QWidget *centralWidget;
    QPushButton *calendarButton;
    QLabel *label;
    QPushButton *todolistButton;
    QPushButton *MemopadButton;
    QPushButton *eventlistButton;
    QPushButton *alarmlistButton;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QWidget *Calendar;
    QCalendarWidget *calendarWidget;
    QLabel *label_2;
    QLabel *label_7;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;
    QWidget *TodoList;
    QLabel *label_3;
    QWidget *Memopad;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *Event;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QListWidget *listWidget_4;
    QGroupBox *groupBox;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_5;
    QLabel *label_18;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *Alarm;
    QLabel *label_6;
    QPushButton *addalarmButton;
    QPushButton *deletealarmButton;
    QGroupBox *AlarmTab_groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *alarmEnabled_label;
    QCheckBox *alarmEnabled_checkbox;
    QLabel *alarmName_label;
    QLineEdit *alarmName_textbox;
    QLabel *alarmRepeating_label;
    QRadioButton *alarm_yes_radiobutton;
    QLabel *alarmBlank_label;
    QRadioButton *alarm_no_radiobutton;
    QStackedWidget *alarm_Repating_stackedwidget;
    QWidget *repeatingNo;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QDateTimeEdit *alarm_datetime_editor;
    QLabel *label_11;
    QWidget *repeatingYes;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_14;
    QTimeEdit *alarm_time_editor;
    QLabel *label_15;
    QComboBox *alarm_frequency_comboBox;
    QLabel *alarm_customday_label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *alarmList_mon_checkbox;
    QCheckBox *alarmList_tue_checkbox;
    QCheckBox *alarmList_wed_checkbox;
    QCheckBox *alarmList_thu_checkbox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *alarmList_fri_checkbox;
    QCheckBox *alarmList_sat_checkbox;
    QCheckBox *alarmList_sun_checkbox;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_10;
    QLineEdit *alarm_audiofilepath_textbox;
    QLabel *label_9;
    QSlider *alarm_volume_slider;
    QPushButton *editalarmButton;
    QFrame *line_2;
    QFrame *line_3;
    QListWidget *AlarmListWidget;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuC7;
    QMenu *menuWindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        actionCalendar = new QAction(MainWindow);
        actionCalendar->setObjectName(QString::fromUtf8("actionCalendar"));
        actionTo_do_List = new QAction(MainWindow);
        actionTo_do_List->setObjectName(QString::fromUtf8("actionTo_do_List"));
        actionMemo_Pad = new QAction(MainWindow);
        actionMemo_Pad->setObjectName(QString::fromUtf8("actionMemo_Pad"));
        actionEvent_List = new QAction(MainWindow);
        actionEvent_List->setObjectName(QString::fromUtf8("actionEvent_List"));
        actionAlarm_List = new QAction(MainWindow);
        actionAlarm_List->setObjectName(QString::fromUtf8("actionAlarm_List"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        calendarButton = new QPushButton(centralWidget);
        calendarButton->setObjectName(QString::fromUtf8("calendarButton"));
        calendarButton->setGeometry(QRect(10, 30, 71, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 46, 13));
        todolistButton = new QPushButton(centralWidget);
        todolistButton->setObjectName(QString::fromUtf8("todolistButton"));
        todolistButton->setGeometry(QRect(10, 60, 75, 23));
        MemopadButton = new QPushButton(centralWidget);
        MemopadButton->setObjectName(QString::fromUtf8("MemopadButton"));
        MemopadButton->setGeometry(QRect(10, 90, 75, 23));
        eventlistButton = new QPushButton(centralWidget);
        eventlistButton->setObjectName(QString::fromUtf8("eventlistButton"));
        eventlistButton->setGeometry(QRect(10, 120, 75, 23));
        alarmlistButton = new QPushButton(centralWidget);
        alarmlistButton->setObjectName(QString::fromUtf8("alarmlistButton"));
        alarmlistButton->setGeometry(QRect(10, 150, 75, 23));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(100, 0, 531, 421));
        Home = new QWidget();
        Home->setObjectName(QString::fromUtf8("Home"));
        stackedWidget->addWidget(Home);
        Calendar = new QWidget();
        Calendar->setObjectName(QString::fromUtf8("Calendar"));
        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 391, 271));
        label_2 = new QLabel(Calendar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 10, 41, 16));
        label_7 = new QLabel(Calendar);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 260, 46, 13));
        listWidget_2 = new QListWidget(Calendar);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(400, 280, 131, 141));
        listWidget_3 = new QListWidget(Calendar);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(400, 30, 131, 221));
        stackedWidget->addWidget(Calendar);
        TodoList = new QWidget();
        TodoList->setObjectName(QString::fromUtf8("TodoList"));
        label_3 = new QLabel(TodoList);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 46, 13));
        stackedWidget->addWidget(TodoList);
        Memopad = new QWidget();
        Memopad->setObjectName(QString::fromUtf8("Memopad"));
        label_4 = new QLabel(Memopad);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 46, 13));
        lineEdit = new QLineEdit(Memopad);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 401, 281));
        listWidget = new QListWidget(Memopad);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(430, 20, 91, 361));
        pushButton = new QPushButton(Memopad);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 310, 75, 23));
        pushButton_2 = new QPushButton(Memopad);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 310, 75, 23));
        pushButton_3 = new QPushButton(Memopad);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 310, 75, 23));
        pushButton_4 = new QPushButton(Memopad);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(440, 390, 75, 23));
        stackedWidget->addWidget(Memopad);
        Event = new QWidget();
        Event->setObjectName(QString::fromUtf8("Event"));
        label_5 = new QLabel(Event);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 0, 46, 13));
        label_12 = new QLabel(Event);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(300, 80, 46, 13));
        label_13 = new QLabel(Event);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(300, 120, 46, 13));
        lineEdit_2 = new QLineEdit(Event);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 40, 113, 20));
        lineEdit_3 = new QLineEdit(Event);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(370, 80, 113, 20));
        lineEdit_4 = new QLineEdit(Event);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(380, 130, 113, 20));
        listWidget_4 = new QListWidget(Event);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        listWidget_4->setGeometry(QRect(10, 20, 91, 401));
        groupBox = new QGroupBox(Event);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(110, 40, 111, 131));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 46, 13));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 20, 69, 22));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 50, 46, 13));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 80, 46, 13));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 100, 75, 23));
        label_18 = new QLabel(Event);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(260, 50, 46, 13));
        pushButton_6 = new QPushButton(Event);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(320, 390, 75, 23));
        pushButton_7 = new QPushButton(Event);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(110, 190, 75, 23));
        stackedWidget->addWidget(Event);
        Alarm = new QWidget();
        Alarm->setObjectName(QString::fromUtf8("Alarm"));
        label_6 = new QLabel(Alarm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 46, 13));
        addalarmButton = new QPushButton(Alarm);
        addalarmButton->setObjectName(QString::fromUtf8("addalarmButton"));
        addalarmButton->setGeometry(QRect(60, 390, 75, 23));
        deletealarmButton = new QPushButton(Alarm);
        deletealarmButton->setObjectName(QString::fromUtf8("deletealarmButton"));
        deletealarmButton->setGeometry(QRect(140, 390, 75, 23));
        AlarmTab_groupBox = new QGroupBox(Alarm);
        AlarmTab_groupBox->setObjectName(QString::fromUtf8("AlarmTab_groupBox"));
        AlarmTab_groupBox->setGeometry(QRect(270, 10, 251, 401));
        formLayoutWidget = new QWidget(AlarmTab_groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 231, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        alarmEnabled_label = new QLabel(formLayoutWidget);
        alarmEnabled_label->setObjectName(QString::fromUtf8("alarmEnabled_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, alarmEnabled_label);

        alarmEnabled_checkbox = new QCheckBox(formLayoutWidget);
        alarmEnabled_checkbox->setObjectName(QString::fromUtf8("alarmEnabled_checkbox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, alarmEnabled_checkbox);

        alarmName_label = new QLabel(formLayoutWidget);
        alarmName_label->setObjectName(QString::fromUtf8("alarmName_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, alarmName_label);

        alarmName_textbox = new QLineEdit(formLayoutWidget);
        alarmName_textbox->setObjectName(QString::fromUtf8("alarmName_textbox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, alarmName_textbox);

        alarmRepeating_label = new QLabel(formLayoutWidget);
        alarmRepeating_label->setObjectName(QString::fromUtf8("alarmRepeating_label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, alarmRepeating_label);

        alarm_yes_radiobutton = new QRadioButton(formLayoutWidget);
        alarm_yes_radiobutton->setObjectName(QString::fromUtf8("alarm_yes_radiobutton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, alarm_yes_radiobutton);

        alarmBlank_label = new QLabel(formLayoutWidget);
        alarmBlank_label->setObjectName(QString::fromUtf8("alarmBlank_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, alarmBlank_label);

        alarm_no_radiobutton = new QRadioButton(formLayoutWidget);
        alarm_no_radiobutton->setObjectName(QString::fromUtf8("alarm_no_radiobutton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, alarm_no_radiobutton);

        alarm_Repating_stackedwidget = new QStackedWidget(AlarmTab_groupBox);
        alarm_Repating_stackedwidget->setObjectName(QString::fromUtf8("alarm_Repating_stackedwidget"));
        alarm_Repating_stackedwidget->setGeometry(QRect(10, 120, 231, 141));
        repeatingNo = new QWidget();
        repeatingNo->setObjectName(QString::fromUtf8("repeatingNo"));
        formLayoutWidget_2 = new QWidget(repeatingNo);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 0, 231, 101));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        alarm_datetime_editor = new QDateTimeEdit(formLayoutWidget_2);
        alarm_datetime_editor->setObjectName(QString::fromUtf8("alarm_datetime_editor"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, alarm_datetime_editor);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_11);

        alarm_Repating_stackedwidget->addWidget(repeatingNo);
        repeatingYes = new QWidget();
        repeatingYes->setObjectName(QString::fromUtf8("repeatingYes"));
        formLayoutWidget_3 = new QWidget(repeatingYes);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(0, 0, 231, 51));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_14);

        alarm_time_editor = new QTimeEdit(formLayoutWidget_3);
        alarm_time_editor->setObjectName(QString::fromUtf8("alarm_time_editor"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, alarm_time_editor);

        label_15 = new QLabel(formLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_15);

        alarm_frequency_comboBox = new QComboBox(formLayoutWidget_3);
        alarm_frequency_comboBox->setObjectName(QString::fromUtf8("alarm_frequency_comboBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, alarm_frequency_comboBox);

        alarm_customday_label = new QLabel(repeatingYes);
        alarm_customday_label->setObjectName(QString::fromUtf8("alarm_customday_label"));
        alarm_customday_label->setGeometry(QRect(0, 60, 63, 31));
        verticalLayoutWidget = new QWidget(repeatingYes);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 50, 82, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        alarmList_mon_checkbox = new QCheckBox(verticalLayoutWidget);
        alarmList_mon_checkbox->setObjectName(QString::fromUtf8("alarmList_mon_checkbox"));
        alarmList_mon_checkbox->setChecked(false);

        verticalLayout->addWidget(alarmList_mon_checkbox);

        alarmList_tue_checkbox = new QCheckBox(verticalLayoutWidget);
        alarmList_tue_checkbox->setObjectName(QString::fromUtf8("alarmList_tue_checkbox"));

        verticalLayout->addWidget(alarmList_tue_checkbox);

        alarmList_wed_checkbox = new QCheckBox(verticalLayoutWidget);
        alarmList_wed_checkbox->setObjectName(QString::fromUtf8("alarmList_wed_checkbox"));

        verticalLayout->addWidget(alarmList_wed_checkbox);

        alarmList_thu_checkbox = new QCheckBox(verticalLayoutWidget);
        alarmList_thu_checkbox->setObjectName(QString::fromUtf8("alarmList_thu_checkbox"));

        verticalLayout->addWidget(alarmList_thu_checkbox);

        verticalLayoutWidget_2 = new QWidget(repeatingYes);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(140, 50, 91, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        alarmList_fri_checkbox = new QCheckBox(verticalLayoutWidget_2);
        alarmList_fri_checkbox->setObjectName(QString::fromUtf8("alarmList_fri_checkbox"));

        verticalLayout_2->addWidget(alarmList_fri_checkbox);

        alarmList_sat_checkbox = new QCheckBox(verticalLayoutWidget_2);
        alarmList_sat_checkbox->setObjectName(QString::fromUtf8("alarmList_sat_checkbox"));

        verticalLayout_2->addWidget(alarmList_sat_checkbox);

        alarmList_sun_checkbox = new QCheckBox(verticalLayoutWidget_2);
        alarmList_sun_checkbox->setObjectName(QString::fromUtf8("alarmList_sun_checkbox"));

        verticalLayout_2->addWidget(alarmList_sun_checkbox);

        alarm_Repating_stackedwidget->addWidget(repeatingYes);
        formLayoutWidget_4 = new QWidget(AlarmTab_groupBox);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(9, 270, 231, 91));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(formLayoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_10);

        alarm_audiofilepath_textbox = new QLineEdit(formLayoutWidget_4);
        alarm_audiofilepath_textbox->setObjectName(QString::fromUtf8("alarm_audiofilepath_textbox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, alarm_audiofilepath_textbox);

        label_9 = new QLabel(formLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_9);

        alarm_volume_slider = new QSlider(formLayoutWidget_4);
        alarm_volume_slider->setObjectName(QString::fromUtf8("alarm_volume_slider"));
        alarm_volume_slider->setOrientation(Qt::Horizontal);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, alarm_volume_slider);

        editalarmButton = new QPushButton(AlarmTab_groupBox);
        editalarmButton->setObjectName(QString::fromUtf8("editalarmButton"));
        editalarmButton->setGeometry(QRect(170, 370, 75, 23));
        line_2 = new QFrame(AlarmTab_groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-3, 110, 251, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(AlarmTab_groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 260, 251, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        AlarmListWidget = new QListWidget(Alarm);
        AlarmListWidget->setObjectName(QString::fromUtf8("AlarmListWidget"));
        AlarmListWidget->setGeometry(QRect(10, 20, 251, 361));
        AlarmListWidget->setSelectionRectVisible(true);
        stackedWidget->addWidget(Alarm);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(80, 0, 20, 441));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuC7 = new QMenu(menuBar);
        menuC7->setObjectName(QString::fromUtf8("menuC7"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuC7->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuWindow->addAction(actionCalendar);
        menuWindow->addAction(actionTo_do_List);
        menuWindow->addAction(actionMemo_Pad);
        menuWindow->addAction(actionEvent_List);
        menuWindow->addAction(actionAlarm_List);

        retranslateUi(MainWindow);
        QObject::connect(calendarWidget, SIGNAL(selectionChanged()), MainWindow, SLOT(changeddate_Slot()));
        QObject::connect(calendarButton, SIGNAL(clicked()), MainWindow, SLOT(change2calendar_Slot()));
        QObject::connect(todolistButton, SIGNAL(clicked()), MainWindow, SLOT(change2todolist_Slot()));
        QObject::connect(MemopadButton, SIGNAL(clicked()), MainWindow, SLOT(change2memopad_Slot()));
        QObject::connect(eventlistButton, SIGNAL(clicked()), MainWindow, SLOT(change2eventlist_Slot()));
        QObject::connect(alarmlistButton, SIGNAL(clicked()), MainWindow, SLOT(change2alarmlist_Slot()));
        QObject::connect(AlarmListWidget, SIGNAL(itemSelectionChanged()), MainWindow, SLOT(alarmList_changed_slot()));
        QObject::connect(alarm_yes_radiobutton, SIGNAL(clicked()), MainWindow, SLOT(alarmList_repeatingYes_slot()));
        QObject::connect(alarm_no_radiobutton, SIGNAL(clicked()), MainWindow, SLOT(alarmList_repeatingNo_slot()));
        QObject::connect(alarm_frequency_comboBox, SIGNAL(currentIndexChanged(QString)), MainWindow, SLOT(alarmList_newFrequency_slot(QString)));
        QObject::connect(addalarmButton, SIGNAL(clicked()), MainWindow, SLOT(alarmList_addalarm_slot()));
        QObject::connect(deletealarmButton, SIGNAL(clicked()), MainWindow, SLOT(alarmList_deletealarm_slot()));
        QObject::connect(editalarmButton, SIGNAL(clicked()), MainWindow, SLOT(alarmList_editalarm_slot()));

        stackedWidget->setCurrentIndex(4);
        alarm_Repating_stackedwidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCalendar->setText(QApplication::translate("MainWindow", "Calendar", 0, QApplication::UnicodeUTF8));
        actionTo_do_List->setText(QApplication::translate("MainWindow", "To-do List", 0, QApplication::UnicodeUTF8));
        actionMemo_Pad->setText(QApplication::translate("MainWindow", "Memo Pad", 0, QApplication::UnicodeUTF8));
        actionEvent_List->setText(QApplication::translate("MainWindow", "Event List", 0, QApplication::UnicodeUTF8));
        actionAlarm_List->setText(QApplication::translate("MainWindow", "Alarm List", 0, QApplication::UnicodeUTF8));
        calendarButton->setText(QApplication::translate("MainWindow", "Calendar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Goto...", 0, QApplication::UnicodeUTF8));
        todolistButton->setText(QApplication::translate("MainWindow", "To-do List", 0, QApplication::UnicodeUTF8));
        MemopadButton->setText(QApplication::translate("MainWindow", "Memo Pad", 0, QApplication::UnicodeUTF8));
        eventlistButton->setText(QApplication::translate("MainWindow", "Event List", 0, QApplication::UnicodeUTF8));
        alarmlistButton->setText(QApplication::translate("MainWindow", "Alarm List", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Events", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Alarms", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Todo List", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Memopad", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Rename", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Event List", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sort By", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Class", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Appointment", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8)
        );
        label_16->setText(QApplication::translate("MainWindow", "Date:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Sort", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Alarm List", 0, QApplication::UnicodeUTF8));
        addalarmButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        deletealarmButton->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        AlarmTab_groupBox->setTitle(QApplication::translate("MainWindow", "Alarm Information", 0, QApplication::UnicodeUTF8));
        alarmEnabled_label->setText(QApplication::translate("MainWindow", "Enabled:", 0, QApplication::UnicodeUTF8));
        alarmEnabled_checkbox->setText(QString());
        alarmName_label->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        alarmName_textbox->setText(QString());
        alarmRepeating_label->setText(QApplication::translate("MainWindow", "Repeating:", 0, QApplication::UnicodeUTF8));
        alarm_yes_radiobutton->setText(QApplication::translate("MainWindow", "Yes", 0, QApplication::UnicodeUTF8));
        alarmBlank_label->setText(QString());
        alarm_no_radiobutton->setText(QApplication::translate("MainWindow", "No", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Time & Date:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Time:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Frequency:", 0, QApplication::UnicodeUTF8));
        alarm_frequency_comboBox->clear();
        alarm_frequency_comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Everyday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Monday-Wednesday-Friday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Tuesday-Thursday", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Weekdays Only", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Weekends Only", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Custom", 0, QApplication::UnicodeUTF8)
        );
        alarm_customday_label->setText(QApplication::translate("MainWindow", "Custom \n"
"Days", 0, QApplication::UnicodeUTF8));
        alarmList_mon_checkbox->setText(QApplication::translate("MainWindow", "Monday", 0, QApplication::UnicodeUTF8));
        alarmList_tue_checkbox->setText(QApplication::translate("MainWindow", "Tuesday", 0, QApplication::UnicodeUTF8));
        alarmList_wed_checkbox->setText(QApplication::translate("MainWindow", "Wednesday", 0, QApplication::UnicodeUTF8));
        alarmList_thu_checkbox->setText(QApplication::translate("MainWindow", "Thursday", 0, QApplication::UnicodeUTF8));
        alarmList_fri_checkbox->setText(QApplication::translate("MainWindow", "Friday", 0, QApplication::UnicodeUTF8));
        alarmList_sat_checkbox->setText(QApplication::translate("MainWindow", "Saturday", 0, QApplication::UnicodeUTF8));
        alarmList_sun_checkbox->setText(QApplication::translate("MainWindow", "Sunday", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Audio:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Volume:", 0, QApplication::UnicodeUTF8));
        editalarmButton->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        menuC7->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
