/* Copyright 2019, OpenSoft Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials provided
 * with the distribution.
 *     * Neither the name of OpenSoft Inc. nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include "proofnetwork/xjdf/data/abstractnode.h"

#include "proofnetwork/xjdf/data/abstractnode_p.h"

using namespace Proof;
using namespace Proof::XJdf;

NetworkDataEntityQmlWrapper *AbstractNode::toQmlWrapper(QObject *parent) const
{
    Q_UNUSED(parent)
    Q_ASSERT(false);
    return nullptr;
}

bool AbstractNode::readFieldsFromXJdf(QXmlStreamReader &)
{
    return false;
}

AbstractNode::AbstractNode(AbstractNodePrivate &dd) : NetworkDataEntity(dd)
{}

void AbstractNode::updateSelf(const Proof::NetworkDataEntitySP &other)
{
    AbstractNodeSP castedOther = qSharedPointerCast<AbstractNode>(other);

    NetworkDataEntity::updateSelf(other);
}

NodeWriterGuard::NodeWriterGuard(QXmlStreamWriter *writer) : writer(writer)
{
    Q_ASSERT(writer);
}

NodeWriterGuard::~NodeWriterGuard()
{
    if (writer)
        writer->writeEndElement();
}

void AbstractNodePrivate::updateDocument(const DocumentSP &newDocument)
{
    document = newDocument;
}
