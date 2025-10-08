#ifndef C_NON_MEMBER
# define C_NONMEMEBER

class c_non_member
{
	public:

		c_non_member(void);
		~c_non_member(void);

		static int	getnbrinst(void);
	
	private:

		static int	_nbinst;//declara que isto vai existir algures
};

#endif
