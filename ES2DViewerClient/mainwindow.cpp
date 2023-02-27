#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ES2DViewerCommon.h"

using namespace es2d;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitializeUI();
    InitializeConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeUI()
{
    m_pViewerWidget = new CES2DViewer(this);

    if(m_pViewerWidget)
    {
        QString strAppPath = qApp->applicationDirPath();
        QString strSampleImage = "FeatureToastBulldogImg.png";

        QString strSamplePath = QString("%1\\%2").arg(strAppPath).arg(strSampleImage);
        //QString strSamplePath = "c:\\temp\\test.dcm";
        //QString strSamplePath = "c:\\temp\\sample\\test_1.jpg";

        if(false == QFile::exists(strSamplePath))
        {
            QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
            QString strSystemSamplePath = QString("%1\\sysnative\\%2").arg(env.value("systemroot")).arg(strSampleImage);

            QFile::copy(strSystemSamplePath, strSamplePath);
        }

        dynamic_cast<CES2DViewer *>(m_pViewerWidget)->SetImage(strSamplePath);
        dynamic_cast<CES2DViewer *>(m_pViewerWidget)->SetCurrentCommand(eSelect);

        setCentralWidget(m_pViewerWidget);
    }
}

void MainWindow::InitializeConnect()
{
    if(m_pViewerWidget)
    {
        connect(m_pViewerWidget, SIGNAL(SignalTagFileSaved(QString)), this, SLOT(SlotTagFileSaved(QString)));
    }
}

void MainWindow::SlotTagFileSaved(QString strTagFilename)
{
    qDebug() << Q_FUNC_INFO << ":" << strTagFilename;
}

