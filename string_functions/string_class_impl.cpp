CCMyString& CMyString::operator=(const CMyString &cMyString)
{
    if (this == &cMyString) {
        return *this;
    }
    delete []m_pData;
    m_pData = nullptr;
    
    m_pData = new char[strlen(str.m_pData) + 1;
    strcpy(m_pData, cMyString.m_pData);
    return *this;
}
