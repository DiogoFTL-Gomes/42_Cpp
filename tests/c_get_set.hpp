#ifndef C_GET_SET_H
# define C_GET_SET_H

class get_set
{
	public:

		get_set(void);
		~get_set(void);

		int		getval(void) const;
		void	setval(int v);

	private:

		int		_val;
};

#endif