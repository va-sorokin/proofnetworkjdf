#include "jdfdocument.h"

#include "proofnetwork/networkdataentity_p.h"
#include "proofnetwork/jdf/data/resourcepool.h"
#include "proofnetwork/jdf/data/qmlwrappers/jdfdocumentqmlwrapper.h"

namespace Proof {
namespace Jdf {

class JdfDocumentPrivate : public NetworkDataEntityPrivate
{
    Q_DECLARE_PUBLIC(JdfDocument)

    void updateFrom(const Proof::NetworkDataEntitySP &other) override;

    QString id;
    QString jobId;
    QString jobPartId;
    ResourcePoolSP resourcePool = ResourcePool::defaultObject();
};

}
}

using namespace Proof::Jdf;

QString JdfDocument::id() const
{
    Q_D(const JdfDocument);
    return d->id;
}

QString JdfDocument::jobId() const
{
    Q_D(const JdfDocument);
    return d->jobId;
}

QString JdfDocument::jobPartId() const
{
    Q_D(const JdfDocument);
    return d->jobPartId;
}

ResourcePoolSP JdfDocument::resourcePool() const
{
    Q_D(const JdfDocument);
    return d->resourcePool;
}

void JdfDocument::setId(const QString &arg)
{
    Q_D(JdfDocument);
    if (d->id != arg) {
        d->id = arg;
        emit idChanged(d->id);
    }
}

void JdfDocument::setJobId(const QString &arg)
{
    Q_D(JdfDocument);
    if (d->jobId != arg) {
        d->jobId = arg;
        emit jobIdChanged(d->jobId);
    }
}

void JdfDocument::setJobPartId(const QString &arg)
{
    Q_D(JdfDocument);
    if (d->jobPartId != arg) {
        d->jobPartId = arg;
        emit jobPartIdChanged(d->jobPartId);
    }
}

void JdfDocument::setResourcePool(const ResourcePoolSP &arg)
{
    Q_D(JdfDocument);
    if (arg == nullptr)
        setResourcePool(ResourcePool::defaultObject());
    else if (d->resourcePool != arg) {
        d->resourcePool = arg;
        emit resourcePoolChanged(d->resourcePool);
    }
}

JdfDocumentQmlWrapper *JdfDocument::toQmlWrapper(QObject *parent) const
{
    Q_D(const JdfDocument);
    JdfDocumentSP castedSelf = qSharedPointerCast<JdfDocument>(d->weakSelf);
    Q_ASSERT(castedSelf);
    return new JdfDocumentQmlWrapper(castedSelf, parent);
}

JdfDocumentSP JdfDocument::create()
{
    JdfDocumentSP result(new JdfDocument());
    result->d_func()->weakSelf = result.toWeakRef();
    return result;
}

JdfDocumentSP JdfDocument::fromJdf(QXmlStreamReader &xmlReader)
{
    // TODO: Change parsing
    JdfDocumentSP document = create();
    document->setFetched(true);

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "JDF") {
                QXmlStreamAttributes attributes = xmlReader.attributes();
                if (attributes.value("Type").toString() == "Product") {
                    document->setId(attributes.value("ID").toString());
                    document->setJobId(attributes.value("JobID").toString());
                    document->setJobPartId(attributes.value("JobPartID").toString());
                }
            }

            if (xmlReader.name() == "ResourcePool")
                document->setResourcePool(ResourcePool::fromJdf(xmlReader, document->id()));
            // TODO: Add parsing ResourceLinkPool
        }
    }

    return document;
}

QString JdfDocument::toJdf()
{
    Q_D(JdfDocument);
    QString jdf;
    QXmlStreamWriter jdfWriter(&jdf);

    jdfWriter.setAutoFormatting(true);
    jdfWriter.writeStartDocument();

    jdfWriter.writeStartElement("JDF");
    {
        jdfWriter.writeDefaultNamespace("http://www.CIP4.org/JDFSchema_1_1");
        jdfWriter.writeAttribute("ID", d->id);
        jdfWriter.writeAttribute("JobID", d->jobId);
        jdfWriter.writeAttribute("JobPartID", d->jobPartId);
        jdfWriter.writeAttribute("Status", "Waiting");
        jdfWriter.writeAttribute("Type", "Product");
        jdfWriter.writeAttribute("Version", "1.4");
        d->resourcePool->toJdf(jdfWriter);
        d->resourcePool->toJdfLink(jdfWriter);
    }
    jdfWriter.writeEndElement();

    jdfWriter.writeEndDocument();

    return jdf;
}

JdfDocumentSP JdfDocument::defaultObject()
{
    static JdfDocumentSP entity = create();
    return entity;
}

JdfDocument::JdfDocument()
    : NetworkDataEntity(*new JdfDocumentPrivate)
{
}

void JdfDocumentPrivate::updateFrom(const NetworkDataEntitySP &other)
{
    Q_Q(JdfDocument);
    JdfDocumentSP castedOther = qSharedPointerCast<JdfDocument>(other);
    q->setId(castedOther->id());
    q->setJobId(castedOther->jobId());
    q->setJobPartId(castedOther->jobPartId());
    q->setResourcePool(castedOther->resourcePool());

    NetworkDataEntityPrivate::updateFrom(other);
}
