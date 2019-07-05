#include <vector>
#include <iostream>

class Object
{
	public:
		Object(std::string& name):name_(name){}
		std::string& get_name(){return name_;}

	private:
		std::string name_;
};

void remove_name_by_iter(const std::string& name, std::vector<Object*>& vec)
{
	for (std::vector<Object*>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		Object* po = *it;
		if (po && po->get_name() == name)
		{
			vec.erase(it);
			break;
		}
	}
}

void remove_name_by_replace(const std::string& name, std::vector<Object*>& vec)
{
	std::vector<Object*> new_vec;
	for (int i = 0; i < vec.size(); ++i)
	{
		Object* po = vec[i];
		if (po && po->get_name() == name)
		{
			continue;
		}
		new_vec.push_back(po);
	}
	vec = new_vec;
}

//#define test_iter_ma 1

void test_iter()
{
	std::string name1 = "katqweqwesdcscde";
	Object* o1 = new Object(name1);
	if (NULL == o1)
	{
		return;
	}
	
	std::string name2 = "jisdfcdcvwefwevthyjyukjm";
	Object* o2 = new Object(name2);
	if (NULL == o2)
	{
		return;
	}
	
	std::vector<Object*> vec;
    vec.push_back(o1);
    vec.push_back(o2);
    
    #if test_iter_ma
    //remove_name_by_iter(name1, vec);
    remove_name_by_iter(name2, vec);
    #else
    //remove_name_by_replace(name1, vec);
    remove_name_by_replace(name2, vec);
    #endif
    
    delete o1;
    delete o2;
}

int main()
{
	int loop_num = 1000000;
	while (loop_num > 0)
	{
		test_iter();
		--loop_num;
	}
}
