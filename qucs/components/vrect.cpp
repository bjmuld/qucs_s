/***************************************************************************
                         vrect.cpp  -  description
                             -------------------
    begin                : Sat Sep 18 2004
    copyright            : (C) 2004 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "vrect.h"


vRect::vRect()
{
  Description = QObject::tr("ideal rectangle voltage source");

  Arcs.append(new Arc(-12,-12, 25, 25,     0, 16*360,QPen(QPen::darkBlue,2)));
  Lines.append(new Line(-30,  0,-12,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( 30,  0, 12,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( 18,  5, 18, 11,QPen(QPen::red,1)));
  Lines.append(new Line( 21,  8, 15,  8,QPen(QPen::red,1)));
  Lines.append(new Line(-18,  5,-18, 11,QPen(QPen::black,1)));

  Lines.append(new Line( -5, -7, -5, -5,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -5, -5,  5, -5,QPen(QPen::darkBlue,2)));
  Lines.append(new Line(  5, -5,  6,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -5,  0,  6,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -5,  0, -5,  5,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -5,  5,  5,  5,QPen(QPen::darkBlue,2)));
  Lines.append(new Line(  5,  5,  5,  7,QPen(QPen::darkBlue,2)));

  Ports.append(new Port( 30,  0));
  Ports.append(new Port(-30,  0));

  x1 = -30; y1 = -14;
  x2 =  30; y2 =  14;

  tx = x1+4;
  ty = y2+4;
  Model = "Vrect";
  Name  = "V";

  Props.append(new Property("U", "1 V", true,
		QObject::tr("voltage of high signal")));
  Props.append(new Property("TH", "1 ms", true,
		QObject::tr("duration of high pulses")));
  Props.append(new Property("TL", "1 ms", true,
		QObject::tr("duration of low pulses")));
}

vRect::~vRect()
{
}

Component* vRect::newOne()
{
  return new vRect();
}

Component* vRect::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Rectangle Voltage");
  BitmapFile = "vrect";

  if(getNewOne)  return new vRect();
  return 0;
}
