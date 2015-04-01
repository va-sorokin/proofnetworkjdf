#ifndef PROOF_JDF_COMPONENT_H
#define PROOF_JDF_COMPONENT_H

#include "proofnetwork/jdf/data/abstractphysicalresource.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/apihelper.h"
#include "proofnetwork/jdf/data/qmlwrappers/componentqmlwrapper.h"

#include <QXmlStreamReader>

namespace Proof {
namespace Jdf {

class ComponentPrivate;
class PROOF_NETWORK_JDF_EXPORT Component : public AbstractPhysicalResource
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Component)
public:
    ApiHelper::ComponentType componentType() const;
    double width() const;
    double height() const;
    double length() const;
    BundleSP bundle() const;
    QList<CutBlockSP> cutBlocks() const;

    void setComponentType(ApiHelper::ComponentType arg);
    void setWidth(double arg);
    void setHeight(double arg);
    void setLength(double arg);
    void setBundle(const BundleSP &arg);
    QList<CutBlockSP> updateCutBlocks(const QList<CutBlockSP> &arg);

    void updateFrom(const NetworkDataEntitySP &other) override;
    ComponentQmlWrapper *toQmlWrapper(QObject *parent = 0) const override;

    static ComponentSP create();

    static ComponentSP fromJdf(QXmlStreamReader &xmlReader, const QString &jdfId);
    void toJdf(QXmlStreamWriter &jdfWriter);
    static ComponentSP defaultObject();

signals:
    void componentTypeChanged(Proof::Jdf::ApiHelper::ComponentType arg);
    void widthChanged(double arg);
    void heightChanged(double arg);
    void lengthChanged(double arg);
    void bundleChanged(const Proof::Jdf::BundleSP &bundle);
    void cutBlocksChanged();

protected:
    explicit Component();

};

}
}

#endif // PROOF_JDF_COMPONENT_H
