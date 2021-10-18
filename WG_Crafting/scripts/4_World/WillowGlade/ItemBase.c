modded class ItemBase
{
    bool HasQuantityBar()
    {
        return m_HasQuantityBar;
    }

    bool IsQuantityType()
    {
        return m_HasQuantityBar || m_VarQuantityMin > 0 || m_VarQuantityMax > 0;
    }
};