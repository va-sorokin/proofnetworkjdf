#include "medialink.h"
#include "proofnetwork/jdf/data/abstractphysicalresourcelink_p.h"

namespace Proof {
namespace Jdf {

class MediaLinkPrivate : public AbstractPhysicalResourceLinkPrivate
{
    Q_DECLARE_PUBLIC(MediaLink)
};

MediaLinkQmlWrapper *MediaLink::toQmlWrapper(QObject *parent) const
{
    Q_D(const MediaLink);
    MediaLinkSP castedSelf = qSharedPointerCast<MediaLink>(d->weakSelf);
    Q_ASSERT(castedSelf);
    return new MediaLinkQmlWrapper(castedSelf, parent);

}

MediaLinkSP MediaLink::create()
{
    MediaLinkSP result(new MediaLink());
    result->d_func()->weakSelf = result.toWeakRef();
    return result;
}

MediaLinkSP MediaLink::fromJdf(const QXmlStreamReader &xmlReader)
{
    MediaLinkSP media = create();
    AbstractPhysicalResourceLink::fromJdf(xmlReader, media);
    return media;
}

MediaLinkSP MediaLink::defaultObject()
{
    static MediaLinkSP entity = create();
    return entity;
}

MediaLink::MediaLink(QObject *parent) :
    AbstractPhysicalResourceLink(*new MediaLinkPrivate, parent)
{
}

}
}
