#ifndef _SCHEMA_MAX_INCLUSIVE_HPP_
#define _SCHEMA_MAX_INCLUSIVE_HPP_

#include "SchemaCommon.hpp"

class CMaxInclusive : public CXSDNode
{
public:

    virtual ~CMaxInclusive()
    {
    }

    static CMaxInclusive* load(CXSDNodeBase* pParentNode, const IPropertyTree *pSchemaRoot, const char* xpath);

    virtual void dump(std::ostream& cout, unsigned int offset = 0) const;

    virtual void getDocumentation(StringBuffer &strDoc) const
    {
        assert(!"Not Implemented");
    }

    virtual void getDojoJS(StringBuffer &strJS) const
    {
        assert(!"Not Implemented");
    }

    void getQML(StringBuffer &strQML, int idx = -1) const
    {
        assert(!"Not Implemented");
    }

    virtual const char* getXML(const char* /*pComponent*/)
    {
        assert(!"Not Implemented");
    }

    virtual void populateEnvXPath(StringBuffer strXPath, unsigned int index = 1)
    {
        assert(!"Not Implemented");
    }

    GETTERSETTER(Value)
    GETTERSETTERINT(MaxInclusive)

private:

    CMaxInclusive() : CXSDNode::CXSDNode(NULL, XSD_MAX_INCLUSIVE), m_MaxInclusive(-1)
    {
    }

    int m_nMaxInclusive;

};

#endif // _SCHEMA_MAX_INCLUSIVE_HPP_
