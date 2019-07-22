//头文件
class Singleton
{
	public:
		static Singleton& Instance()                  //Instance()作为静态成员函数提供里全局访问点
		{
			static Singleton instance;
			return instance;
		}
 
	private:
		Singleton();                                  //这里将构造，析构，拷贝构造，赋值函数设为私有，杜绝了生成新例
		~Singleton();
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);		
};

//头文件
class Singleton
{
	public:
		static Singleton& Instance()        //Instance()作为静态成员函数提供里全局访问点
		{
			if(ps == NULL)
			{	
				Lock();				        //上锁
				if(ps == NULL)			    //如果还未实例化，即可实例话，反之提供实例的引用
					ps = new Singleton;
				Unlock();			//解锁
			}
			return *ps;                         	//返回指针的话可能会误被 delete，返回引用安全一点
		}	
 
	private:
		Singleton();                                  	//这里将构造，析构，拷贝构造，赋值函数设为私有，杜绝了生成新例
		~Singleton();
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
 
		static Singleton* ps;
};