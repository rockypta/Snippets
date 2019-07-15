#include <iostream>

class CIntSet
{
public:
	CIntSet()
	{
		m_iSize =0;
		m_paItems = nullptr;
	}
	~CIntSet()
	{
		delete[] m_paItems;
	}
	void AddItem(int iItem)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if(*(m_paItems+i) == iItem)
				return;
		}

		if (m_iSize != 0 )
			m_paItems = (int*)realloc(m_paItems, (m_iSize +1)*sizeof(int));
		else
			m_paItems = new int;

		int* pNewItem = m_paItems + m_iSize;
		*pNewItem = iItem;
		m_iSize++;	
	}

	int GetSize()
	{
		return m_iSize;
	}

	int GetItemAt(int iPos)
	{
		return *(m_paItems+iPos);
	}

protected:
	int* m_paItems;	
	int m_iSize;
};

void GetArray(CIntSet& rSet)
{
	rSet.AddItem(1);
	rSet.AddItem(100);
	rSet.AddItem(100);
}

bool IsDivisibleByPrimes(int iNumber, CIntSet& raPrimes)
{
	for (int i = 0; i < raPrimes.GetSize(); i++)
	{
		if (iNumber % raPrimes.GetItemAt(i) == 0)
			return true;
	}

	return false;	
}

void GetPrimesTill(int iTill, CIntSet& raPrimes)
{
	for (int i = 2; i < iTill; i++)
	{
		if (!IsDivisibleByPrimes(i, raPrimes))
		{	
			raPrimes.AddItem(i);		
			std::cout << i << std::endl;			
		}
	}
	
}

class CIntNode
{
public:
	int iLeft = INT32_MAX;
	int iRight = INT32_MAX;
	CIntNode* pParent = nullptr;
};

int main() 
{
	CIntSet vSet;
	GetPrimesTill(5000000, vSet);

	std::cout << vSet.GetItemAt(0) << std::endl;
	std::cout << vSet.GetItemAt(15) << std::endl;
	std::cout << vSet.GetSize() << std::endl;
	return 0;
}