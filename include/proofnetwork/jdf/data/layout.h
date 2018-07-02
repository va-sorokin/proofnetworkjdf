#ifndef PROOF_JDF_LAYOUT_H
#define PROOF_JDF_LAYOUT_H

#include "proofnetwork/jdf/apihelper.h"
#include "proofnetwork/jdf/data/abstractresource.h"
#include "proofnetwork/jdf/data/qmlwrappers/layoutqmlwrapper.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"

#include <QXmlStreamReader>

namespace Proof {
namespace Jdf {

class LayoutPrivate;
class PROOF_NETWORK_JDF_EXPORT Layout : public AbstractResource
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Layout)
public:
    QVector<MediaSP> media() const;

    void setMedia(const QVector<MediaSP> &arg);
    void addMedia(const MediaSP &arg);

    LayoutQmlWrapper *toQmlWrapper(QObject *parent = nullptr) const override;

    static LayoutSP create();

    static LayoutSP fromJdf(QXmlStreamReader &xmlReader, const QString &jobId, bool sanitize = false);
    void toJdf(QXmlStreamWriter &jdfWriter) override;

signals:
    void mediaChanged();

protected:
    explicit Layout();
    void updateSelf(const Proof::NetworkDataEntitySP &other) override;
};

} // namespace Jdf
} // namespace Proof

#endif // PROOF_JDF_LAYOUT_H
