#include <fstream>
#include <complex>

#include <QFileDialog>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QTimer>

#include "maingui.h"
#include "ui_maingui.h"

#include "../RobotLib/Matrix.h"
#include "../RobotLib/Vector.h"
#include "../RobotLib/Text.h"
#include "../RobotLib/PlaneToCoordinateSystem.h"
#include "../RobotLib/Where.h"


mainGUI::mainGUI(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::mainGUI)
{
    ui->setupUi(this);
    ui->leBaseVectorX->setValidator(new QDoubleValidator(this));
    ui->leBaseVectorY->setValidator(new QDoubleValidator(this));
    ui->leBaseVectorZ->setValidator(new QDoubleValidator(this));
    ui->leXVectorX->setValidator(new QDoubleValidator(this));
    ui->leXVectorY->setValidator(new QDoubleValidator(this));
    ui->leXVectorZ->setValidator(new QDoubleValidator(this));
    ui->leYVectorX->setValidator(new QDoubleValidator(this));
    ui->leYVectorY->setValidator(new QDoubleValidator(this));
    ui->leYVectorZ->setValidator(new QDoubleValidator(this));
    ui->leAngleMarkerA->setValidator(new QDoubleValidator(this));
    ui->leAngleMarkerB->setValidator(new QDoubleValidator(this));
    ui->leAngleEraserA->setValidator(new QDoubleValidator(this));
    ui->leAngleEraserB->setValidator(new QDoubleValidator(this));

    this->robot = new Robot("/dev/ttyS0", 750000);
    this->robot->getPort()->setLiveCommandMode(false);
    this->automaticLastFilePrinted = QTime::currentTime();
}

mainGUI::~mainGUI()
{
    if (this->robot != NULL)
    {
        delete this->robot;
        this->robot = NULL;
    }

    delete ui;
}

void mainGUI::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void mainGUI::defineYVector()
{
    Where where = robot->whereIsRobot();
    ui->leYVectorX->setText(QString::number(where.x));
    ui->leYVectorY->setText(QString::number(where.y));
    ui->leYVectorZ->setText(QString::number(where.z));
}

void mainGUI::defineXVector()
{
    Where where = robot->whereIsRobot();
    ui->leXVectorX->setText(QString::number(where.x));
    ui->leXVectorY->setText(QString::number(where.y));
    ui->leXVectorZ->setText(QString::number(where.z));
}

void mainGUI::defineBaseVector()
{
    Where where = robot->whereIsRobot();
    ui->leBaseVectorX->setText(QString::number(where.x));
    ui->leBaseVectorY->setText(QString::number(where.y));
    ui->leBaseVectorZ->setText(QString::number(where.z));
}

void mainGUI::defineMarker()
{
    Where where = robot->whereIsRobot();
    ui->leAngleMarkerA->setText(QString::number(where.a));
    ui->leAngleMarkerB->setText(QString::number(where.b));
}


void mainGUI::defineEraser()
{
    Where where = robot->whereIsRobot();
    ui->leAngleEraserA->setText(QString::number(where.a));
    ui->leAngleEraserB->setText(QString::number(where.b));
}

void mainGUI::moveToBaseVector()
{
    //this->robot->goHome();
    this->robot->moveLinearTo(Vector(	ui->leBaseVectorX->text().toDouble(),
                                      ui->leBaseVectorY->text().toDouble(),
                                      ui->leBaseVectorZ->text().toDouble()),
                              ui->leAngleMarkerA->text().toDouble(),
                              ui->leAngleMarkerB->text().toDouble());
    this->robot->getPort()->executeQuedCommands();
}

void mainGUI::moveToXVector()
{
    //this->robot->goHome();
    this->robot->moveLinearTo(Vector(ui->leXVectorX->text().toDouble(),
                                     ui->leXVectorY->text().toDouble(),
                                     ui->leXVectorZ->text().toDouble()),
                              ui->leAngleMarkerA->text().toDouble(),
                              ui->leAngleMarkerB->text().toDouble());
    this->robot->getPort()->executeQuedCommands();
}


void mainGUI::moveToYVector()
{
    //this->robot->goHome();
    this->robot->moveLinearTo(Vector( ui->leYVectorX->text().toDouble(),
                                      ui->leYVectorY->text().toDouble(),
                                      ui->leYVectorZ->text().toDouble()),
                              ui->leAngleMarkerA->text().toDouble(),
                              ui->leAngleMarkerB->text().toDouble());
    this->robot->getPort()->executeQuedCommands();

}


void mainGUI::saveConfiguration()
{
    std::ofstream stream;
    stream.open("DrawTextToPlaneGUI.config");

    if ( stream )
    {
        stream  	      	 << ui->leYVectorX->text().toDouble()
        << std::endl << ui->leYVectorY->text().toDouble()
        << std::endl << ui->leYVectorZ->text().toDouble()
        << std::endl << ui->leBaseVectorX->text().toDouble()
        << std::endl << ui->leBaseVectorY->text().toDouble()
        << std::endl << ui->leBaseVectorZ->text().toDouble()
        << std::endl << ui->leXVectorX->text().toDouble()
        << std::endl << ui->leXVectorY->text().toDouble()
        << std::endl << ui->leXVectorZ->text().toDouble()
        << std::endl << ui->leAngleMarkerA->text().toDouble()
        << std::endl << ui->leAngleMarkerB->text().toDouble()
        << std::endl << ui->leAngleEraserA->text().toDouble()
        << std::endl << ui->leAngleEraserB->text().toDouble()
        << std::endl << ui->speedSpinBox->text().toStdString()
        << std::endl << ui->checkBoxInvertX->isChecked()
        << std::endl << ui->checkBoxInvertY->isChecked()
        << std::endl << ui->checkBoxInvertZ->isChecked();
    }

    stream.close();
}

void mainGUI::loadConfiguration()
{
    std::ifstream stream;
    stream.open("DrawTextToPlaneGUI.config");
    std::string value;

    stream >> value;
    ui->leYVectorX->setText(QString::fromStdString(value));
    stream >> value;
    ui->leYVectorY->setText(QString::fromStdString(value));
    stream >> value;
    ui->leYVectorZ->setText(QString::fromStdString(value));
    stream >> value;
    ui->leBaseVectorX->setText(QString::fromStdString(value));
    stream >> value;
    ui->leBaseVectorY->setText(QString::fromStdString(value));
    stream >> value;
    ui->leBaseVectorZ->setText(QString::fromStdString(value));
    stream >> value;
    ui->leXVectorX->setText(QString::fromStdString(value));
    stream >> value;
    ui->leXVectorY->setText(QString::fromStdString(value));
    stream >> value;
    ui->leXVectorZ->setText(QString::fromStdString(value));
    stream >> value;
    ui->leAngleMarkerA->setText(QString::fromStdString(value));
    stream >> value;
    ui->leAngleMarkerB->setText(QString::fromStdString(value));
    stream >> value;
    ui->leAngleEraserA->setText(QString::fromStdString(value));
    stream >> value;
    ui->leAngleEraserB->setText(QString::fromStdString(value));
    stream >> value;
    ui->speedSpinBox->setValue(stringToData<int32>(value));
    stream >> value;
    if (value == "1")
    {
        ui->checkBoxInvertX->setChecked( true );
    }
    else
    {
        ui->checkBoxInvertX->setChecked( false );
    }
    stream >> value;
    if (value == "1")
    {
        ui->checkBoxInvertY->setChecked( true );
    }
    else
    {
        ui->checkBoxInvertY->setChecked( false );
    }
    stream >> value;
    if (value == "1")
    {
        ui->checkBoxInvertZ->setChecked( true );
    }
    else
    {
        ui->checkBoxInvertZ->setChecked( false );
    }
}

void mainGUI::writeText()
{
    writeText(ui->txtEditTextToWrite->toPlainText());
    this->robot->goHome();
    this->robot->getPort()->executeQuedCommands();
}

void mainGUI::writeText(QString content)
{
    Vector yPoint	( ui->leYVectorX->text().toDouble(), 	ui->leYVectorY->text().toDouble(), 	ui->leYVectorZ->text().toDouble());
    Vector basePoint	( ui->leBaseVectorX->text().toDouble(), ui->leBaseVectorY->text().toDouble(), 	ui->leBaseVectorZ->text().toDouble());
    Vector xPoint	( ui->leXVectorX->text().toDouble(), 	ui->leXVectorY->text().toDouble(), 	ui->leXVectorZ->text().toDouble());

    Matrix coordinateSystem = PlaneToCoodinateSystem::toCoordinateSystem(xPoint-basePoint, yPoint-basePoint, ui->checkBoxInvertX->isChecked(), ui->checkBoxInvertY->isChecked(), ui->checkBoxInvertZ->isChecked());
    Vector target = coordinateSystem * Vector(1,0,0);

    Text::writeTextWithWordWrap(
        this->robot,
        std::string(content.toStdString()),
        coordinateSystem,
        yPoint,
        ui->leAngleMarkerA->text().toDouble(),
        ui->leAngleMarkerB->text().toDouble(),
        20.0,
        25
    );
}


void mainGUI::cleanBoard()
{
    cleanBoard(ui->txtEditTextToWrite->toPlainText());
    this->robot->goHome();
    this->robot->getPort()->executeQuedCommands();
}

void mainGUI::cleanBoard(QString content)
{
    Vector yPoint	( ui->leYVectorX   ->text().toDouble(), ui->leYVectorY   ->text().toDouble(), 	ui->leYVectorZ   ->text().toDouble());
    Vector basePoint	( ui->leBaseVectorX->text().toDouble(), ui->leBaseVectorY->text().toDouble(), 	ui->leBaseVectorZ->text().toDouble());
    Vector xPoint	( ui->leXVectorX   ->text().toDouble(), ui->leXVectorY   ->text().toDouble(), 	ui->leXVectorZ   ->text().toDouble());

    Matrix coordinateSystem = PlaneToCoodinateSystem::toCoordinateSystem(xPoint-basePoint, yPoint-basePoint, ui->checkBoxInvertX->isChecked(), ui->checkBoxInvertY->isChecked(), ui->checkBoxInvertZ->isChecked());
    Vector target = coordinateSystem * Vector(1,0,0);

    QStringList linesOfText = content.split("\n");
    uint64 longestLine = 0;
    QString currentLine;
    foreach( currentLine, linesOfText)
    {
        if ( currentLine.size() > longestLine )
        {
            longestLine = currentLine.size();
        }
    }

    Text::cleanBoard(
        this->robot,
        coordinateSystem,
        yPoint,
        //ui->leAngleEraserA->text().toDouble(),
        //ui->leAngleEraserB->text().toDouble(),
        20.0,
        60.0,
        60.0,
        60.0,
        20.0,
        25,
        linesOfText.size(),
        longestLine + 2
    );
}

void mainGUI::resetRobot()
{
    this->robot->reset();
}

void mainGUI::abortTransmission()
{
    this->robot->getPort()->abortDataTransmission();
}

void mainGUI::goHome()
{
    this->robot->goHome();
    this->robot->getPort()->executeQuedCommands();
}

void mainGUI::speedChanged(int newSpeed)
{
    this->robot->speed(newSpeed);
}

void mainGUI::selectScheduleDirectory()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setDirectory(this->ui->scheduleDirectoryLineEdit->text());

    if (dialog.exec())
    {
        this->ui->scheduleDirectoryLineEdit->setText(dialog.directory().path());
        scheduleDirectoryLineEditFinished();
    }
}

void mainGUI::scheduleDirectoryLineEditFinished()
{
    QFileSystemModel *model = new QFileSystemModel;
    model->setFilter(QDir::Files);
    model->setRootPath(this->ui->scheduleDirectoryLineEdit->text());
    QStringList filters;
    filters << "*.txt";
    model->setNameFilters ( filters );
    model->setNameFilterDisables(false);

    this->ui->scheduleFileListView->setModel(model);
    this->ui->scheduleFileListView->setRootIndex(model->index(this->ui->scheduleDirectoryLineEdit->text()));

//     int rowCount = model->rowCount();
//     if( rowCount > 0 )
//     {
//       this->ui->automaticStartPushButton->setEnabled(false);
//       this->ui->automaticStopPushButton->setEnabled(false);
//     }
}

void mainGUI::automaticStart()
{
    this->ui->automaticStartPushButton->setEnabled(false);
    this->ui->automaticStopPushButton->setEnabled(true);

    connect(&automaticTimer, SIGNAL(timeout()), this, SLOT(automaticTimerElapsed()));
    automaticTimer.start(1000);
}

void mainGUI::automaticStop()
{
    this->ui->automaticStartPushButton->setEnabled(true);
    this->ui->automaticStopPushButton->setEnabled(false);

    disconnect(&automaticTimer, SIGNAL(timeout()), this, SLOT(automaticTimerElapsed()));
}


void mainGUI::automaticTimerElapsed()
{
    //stop timer
    automaticTimer.stop();

    //if robot is in home position wait for completion
    if ( robotIsAtHomePossition(1) )
    {
        //Find next file
        QString nextFile = automaticFindAndSelectNextFileWhichShouldBePrinted(QTime::currentTime());

        //if we need an new file
        if ( nextFile != "" )
        {
	    this->robot->goHome();
	  
            //whipe old contend
            cleanBoard(this->ui->automaticTextEdit->toPlainText());

            //load  contend
            this->ui->automaticTextEdit->setText( loadFileContent(nextFile) );

            //draw contend
            writeText(this->ui->automaticTextEdit->toPlainText());
	    
	    this->robot->goHome();
            this->robot->getPort()->executeQuedCommands();
        }
    }

    //restart timer
    automaticTimer.start();
}

QString mainGUI::loadFileContent(QString currentFilePath)
{
    QFile file(currentFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Log Reader", "Cannot read file %1:\n%2"
                             ,currentFilePath
                             ,file.errorString());
        return "";
    }

    QTextStream textStream(&file);
    QString fileConntend = textStream.readAll();

    file.close();

    return fileConntend;
}

QString mainGUI::automaticFindAndSelectNextFileWhichShouldBePrinted(QTime currentTime)
{
    QFileSystemModel* model = dynamic_cast< QFileSystemModel* >(this->ui->scheduleFileListView->model());
    QModelIndex parentIndex = model->index(this->ui->scheduleDirectoryLineEdit->text());
    int rowCount = model->rowCount(parentIndex);
    for (int i=0; i < rowCount; i++)
    {
        QModelIndex modelIndex = model->index(i, 0, parentIndex);
        if ( modelIndex.isValid() )
        {

            QFileInfo fileInfo = model->fileInfo(modelIndex);
            QString currentFilePath = fileInfo.absoluteFilePath();
            QString currentFileBaseName = fileInfo.baseName();

            QTime fileTime = QTime::fromString(currentFileBaseName);
            if ( currentTime > fileTime )
            {
                if ( fileTime > automaticLastFilePrinted )
                {
                    this->ui->scheduleFileListView->selectionModel()->setCurrentIndex( modelIndex, QItemSelectionModel::ClearAndSelect );
                    automaticLastFilePrinted = fileTime;
                    return currentFilePath;
                }
            }
        }
    }

    return "";
}

bool mainGUI::robotIsAtHomePossition(float64 allowedDelta)
{
    Where currentLocation = robot->whereIsRobot();
    Where robotHome = robot->whereIsHome();

    float64 deltaX = std::abs(currentLocation.x - robotHome.x);
    float64 deltaY = std::abs(currentLocation.y - robotHome.y);
    float64 deltaZ = std::abs(currentLocation.z - robotHome.z);
    float64 deltaA = std::abs(currentLocation.a - robotHome.a);
    float64 deltaB = std::abs(currentLocation.b - robotHome.b);

    if ( deltaX <= allowedDelta &&
            deltaY <= allowedDelta &&
            deltaZ <= allowedDelta &&
            deltaA <= allowedDelta &&
            deltaB <= allowedDelta)
    {
        return true;
    }

    return false;
}

void mainGUI::automaticGroupToggled(bool checked)
{
  ui->groupBoxManual->setChecked( !checked );
}

void mainGUI::manualGroupToggled(bool checked)
{
  ui->groupBoxAutomatic->setChecked( !checked );
  if( checked )
  {
    //this->ui->automaticStartPushButton->setEnabled(false);
    //this->ui->automaticStopPushButton->setEnabled(false);

    disconnect(&automaticTimer, SIGNAL(timeout()), this, SLOT(automaticTimerElapsed()));
  }
}
