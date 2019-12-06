#ifndef _STATIC_REPO_STORE_HPP_
#define _STATIC_REPO_STORE_HPP_

#include <vector>
#include"boost/noncopyable.hpp"

const unsigned int DATA_CELL_SIZE = 500;
typedef std::pair<unsigned int, unsigned int> DATA_POSITION;
template <class T>
class CBlob :public boost::nocopybale
{
public:


public:
	CBlob()
	{
		m_datas.push_back(new T[DATA_CELL_SIZE]);
		m_current_position.first = 0;
		m_current_position.second = 0;
	}
	~CBlob()
	{
		eraseAllData();
	}

	DATA_POSITION addData(T* data)
	{
		DATA_POSITION position;
		//如果非空，则弹出一个空间用于插入数据
		if (!m_deleted_position.empty())
		{
			position = m_deleted_position.front();
			memcpy(m_datas[position.first][position.second], data, sizeof(T));
			m_deleted_position.pop();
			return position;
		}
		else
		{
			if (m_current_position.second%DATA_CELL_SIZE==0)  //如果达到了DATA_CELL_SIZE值，需要重要开辟一个空间
			{
				m_datas.push_back(new T[DATA_CELL_SIZE]);
				m_current_position.first++;
				m_current_position.second = 0;
				memcpy(m_datas[m_current_position.first][m_current_position.second], data, sizeof(T));

			}
			else
			{
				m_current_position.second++;
				memcpy(m_datas[m_current_position.first][m_current_position.second], data, sizeof(T));
			}
			return m_current_position;
		}
	}

	bool clearData(const DATA_POSITION& position)
	{

	}

	bool eraseData(const DATA_POSITION& position)
	{

	}

	bool eraseAllData()
	{
		std::vector<T*>::iterator it = m_datas.begin();
		try
		{
			for (; it != m_datas.end(); it++)
			{
				delete[](*it);
				*it = NULL;
			}

		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	std::queue<DATA_POSITION> getDeletedPosition() const
	{
		return m_deleted_position;
	}

private:
	std::vector<T*> m_datas;
	DATA_POSITION m_current_position; //first 是特征在vector中的位置，second是一大段T类型数据空间所在的位置
	std::queue<DATA_POSITION> m_deleted_position; //被删除的数据留出的空位
};



#endif
