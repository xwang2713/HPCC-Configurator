#ifndef _SCHEMA_ATTRIBUTES_HPP_
#define _SCHEMA_ATTRIBUTES_HPP_

#include "jhash.hpp"
#include "jatomic.hpp"
#include "XMLTags.h"
#include "SchemaCommon.hpp"
#include "SchemaAnnotation.hpp"

class CSimpleTypeArray;
class CKeyRefArray;
class CKeyArray;

class CAttribute : public CXSDNodeWithType
{
public:

    CAttribute(CXSDNodeBase* pParentNode, const char* pName = NULL) : CXSDNodeWithType::CXSDNodeWithType(pParentNode, XSD_ATTRIBUTE), m_strName(pName),
            m_strDefault(""), m_strUse(""), m_pAnnotation(NULL), m_pSimpleTypeArray(NULL), m_pReverseKeyRefArray(NULL), m_pReverseKeyArray(NULL), m_bInstanceValueValid(false)
    {
    }

    CAttribute(CXSDNodeBase* pParentNode, const char* pName, const char* pType, const char* pDefault, const char* pUse) : CXSDNodeWithType::CXSDNodeWithType(pParentNode, XSD_ATTRIBUTE), m_strName(pName), m_pAnnotation(NULL),
            m_strDefault(pDefault), m_strUse(pUse), m_pSimpleTypeArray(NULL), m_pReverseKeyRefArray(NULL), m_bInstanceValueValid(false)
    {
    }

    virtual ~CAttribute();

    GETTERSETTER(Name)
    GETTERSETTER(Default)
    GETTERSETTER(Use)
    GETTERSETTER(InstanceValue)

    const CAnnotation* getAnnotation() const
    {
        return m_pAnnotation;
    }

    const char* getTitle() const;

    virtual const char* getXML(const char* pComponent);

    virtual void dump(std::ostream& cout, unsigned int offset = 0) const;

    virtual void getDocumentation(StringBuffer &strDoc) const;

    virtual void getDojoJS(StringBuffer &strJS) const;

    virtual void getQML(StringBuffer &strQML, int idx = -1) const;

    virtual void populateEnvXPath(StringBuffer strXPath, unsigned int index = 1);

    virtual void loadXMLFromEnvXml(const IPropertyTree *pEnvTree);

    virtual void traverseAndProcessNodes() const;

    static CAttribute* load(CXSDNodeBase* pParentNode, const IPropertyTree *pSchemaRoot, const char* xpath = NULL);

    bool isInstanceValueValid()
    {
        return m_bInstanceValueValid;
    }

    void setInstanceAsValid(bool bValid = true)
    {
        m_bInstanceValueValid = bValid;
    }

    virtual void setEnvValueFromXML(const char *p);

protected:

    void setAnnotation(CAnnotation *pAnnotation)
    {
        assert(pAnnotation != NULL);  // why would this ever be NULL?

        if (m_pAnnotation != NULL)
        {
            //m_pAnnotation->Release();
        }

        m_pAnnotation = pAnnotation;
    }

    void setSimpleTypeArray(CSimpleTypeArray *pSimpleTypeArray)
    {
        assert(pSimpleTypeArray != NULL);  // why would this ever be NULL?

        if (pSimpleTypeArray != NULL)
        {
            //pSimpleType->Release();
        }

        m_pSimpleTypeArray = pSimpleTypeArray;
    }

    CAnnotation *m_pAnnotation;
    CSimpleTypeArray *m_pSimpleTypeArray;
    CKeyRefArray *m_pReverseKeyRefArray;
    CKeyArray *m_pReverseKeyArray;
    bool m_bInstanceValueValid;

private:

};


class CAttributeArray : public CIArrayOf<CAttribute>, public InterfaceImpl, public CXSDNodeBase
{
public:

    CAttributeArray(CXSDNodeBase* pParentNode = NULL) : CXSDNodeBase::CXSDNodeBase(pParentNode, XSD_ATTRIBUTE_ARRAY)
    {
    }

    virtual ~CAttributeArray()
    {
    }

    virtual void dump(std::ostream& cout, unsigned int offset = 0) const;

    virtual void getDocumentation(StringBuffer &strDoc) const;

    virtual void getDojoJS(StringBuffer &strJS) const;

    virtual void getQML(StringBuffer &strQML, int idx = -1) const;

    virtual void populateEnvXPath(StringBuffer strXPath, unsigned int index = 1);

    virtual void loadXMLFromEnvXml(const IPropertyTree *pEnvTree);

    //virtual void traverseAndProcessNodes() const;

    virtual const char* getXML(const char* /*pComponent*/);

    const CAttribute* findAttributeWithName(const char *pName, bool bCaseInsensitive = true) const;

    static CAttributeArray* load(const char* pSchemaFile);
    static CAttributeArray* load(CXSDNodeBase* pParentNode, const IPropertyTree *pSchemaRoot, const char* xpath);

protected:

    bool getCountOfValueMatches(const char *pValue) const;

private:

};

#endif // _SCHEMA_ATTRIBUTES_HPP_
