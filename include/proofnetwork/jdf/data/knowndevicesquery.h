#ifndef PROOF_JDF_KNOWNDEVICESQUERY_H
#define PROOF_JDF_KNOWNDEVICESQUERY_H

#include "proofnetwork/jdf/data/query.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"

namespace Proof {
namespace Jdf {

class KnownDevicesQueryPrivate;
class PROOF_NETWORK_JDF_EXPORT KnownDevicesQuery : public Query
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(KnownDevicesQuery)

public:
    DeviceFilterSP deviceFilter() const;

    void setDeviceFilter(const DeviceFilterSP &arg);

    static KnownDevicesQuerySP create();

signals:
    void deviceFilterChanged(const Proof::Jdf::DeviceFilterSP &arg);

protected:
    KnownDevicesQuery();
    void updateSelf(const Proof::NetworkDataEntitySP &other) override;
};

} // namespace Jdf
} // namespace Proof

#endif // PROOF_JDF_KNOWNDEVICESQUERY_H
