// Copyright (c) 2012  Tel-Aviv University (Israel).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
// Author(s)     : Alex Tsui <alextsui05@gmail.com>

#include "ArrangementDemoWindow.h"
#include <QApplication>

int main( int argc, char* argv[] )
{
  QApplication app( argc, argv );

  // Forcing the menu bar to be platform independent 
  // app.setAttribute(Qt::AA_DontUseNativeMenuBar);

  ArrangementDemoWindow *demoWindow = ArrangementDemoWindow::getInstance();
  demoWindow->show( );

  return app.exec( );
}
