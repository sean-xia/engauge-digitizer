#include "CurveConnectAs.h"
#include "Document.h"
#include "EngaugeAssert.h"
#include "ExportFileAbstractBase.h"
#include "Logger.h"
#include <QTextStream>
#include "SplinePair.h"
#include "Transformation.h"

using namespace std;

ExportFileAbstractBase::ExportFileAbstractBase()
{
}

QString ExportFileAbstractBase::curveSeparator (const QString &string) const
{
  if (string.trimmed().isEmpty()) {
    return "";
  } else {
    return "\n";
  }
}

QStringList ExportFileAbstractBase::curvesToInclude (const DocumentModelExport &modelExportOverride,
                                                     const Document &document,
                                                     const QStringList &curvesGraphsNames,
                                                     CurveConnectAs curveConnectAs1,
                                                     CurveConnectAs curveConnectAs2) const
{
  LOG4CPP_INFO_S ((*mainCat)) << "ExportFileAbstractBase::curvesToInclude";

  QStringList curvesToInclude;

  // Build a list of curves to include by subtracting the excluded curves from the the complete list.
  // Special case is to use only first included curve if appropriate flag is set
  QStringList::const_iterator itr;
  for (itr = curvesGraphsNames.begin(); itr != curvesGraphsNames.end(); itr++) {

    QString curvesGraphName = *itr;

    if (!modelExportOverride.curveNamesNotExported().contains (curvesGraphName)) {

      const Curve *curve = document.curveForCurveName(curvesGraphName);
      ENGAUGE_CHECK_PTR (curve);

      // Not excluded which means it gets included, but only if it is a function
      if (curve->curveStyle().lineStyle().curveConnectAs() == curveConnectAs1 ||
          curve->curveStyle().lineStyle().curveConnectAs() == curveConnectAs2) {

        curvesToInclude.push_back (curvesGraphName);
      }
    }
  }

  return curvesToInclude;
}

void ExportFileAbstractBase::destroy2DArray (QVector<QVector<QString*> > &array) const
{
  LOG4CPP_INFO_S ((*mainCat)) << "ExportFileAbstractBase::destroy2DArray";

  int colCount = array.count();
  int rowCount = array [0].count();
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      delete array [col] [row];
    }
  }
}

QString ExportFileAbstractBase::gnuplotComment() const
{
  return QString ("# ");
}

void ExportFileAbstractBase::insertLineSeparator (bool &isFirst,
                                                  ExportHeader exportHeader,
                                                  QTextStream &str) const
{
  // Insert line(s) between previous curve and this curve
  if (isFirst) {
    isFirst = false;
  } else {
    if (exportHeader == EXPORT_HEADER_GNUPLOT) {
      str << "\n\n"; // Gnuplot requires two blank lines between curves
    } else {
      str << "\n"; // Single blank line
    }
  }
}

void ExportFileAbstractBase::loadSplinePairsWithoutTransformation (const Points &points,
                                                                   vector<double> &t,
                                                                   vector<SplinePair> &xy) const
{
  Points::const_iterator itrP;
  for (itrP = points.begin(); itrP != points.end(); itrP++) {
    const Point &point = *itrP;
    QPointF posScreen = point.posScreen();

    t.push_back (point.ordinal ());
    xy.push_back (SplinePair (posScreen.x(),
                              posScreen.y()));
  }
}

void ExportFileAbstractBase::loadSplinePairsWithTransformation (const Points &points,
                                                                const Transformation &transformation,
                                                                vector<double> &t,
                                                                vector<SplinePair> &xy) const
{
  Points::const_iterator itrP;
  for (itrP = points.begin(); itrP != points.end(); itrP++) {
    const Point &point = *itrP;
    QPointF posScreen = point.posScreen();
    QPointF posGraph;
    transformation.transformScreenToRawGraph (posScreen,
                                              posGraph);

    t.push_back (point.ordinal ());
    xy.push_back (SplinePair (posGraph.x(),
                              posGraph.y()));
  }
}