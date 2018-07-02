#ifndef PROOF_JDF_QUERY_H
#define PROOF_JDF_QUERY_H

#include "proofnetwork/jdf/data/message.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"

namespace Proof {
namespace Jdf {

class QueryPrivate;
class PROOF_NETWORK_JDF_EXPORT Query : public Message
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Query)

protected:
    explicit Query(QueryPrivate &dd);
};

} // namespace Jdf
} // namespace Proof

#endif // PROOF_JDF_QUERY_H
