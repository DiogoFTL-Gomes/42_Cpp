#ifndef C_COMPARISON_H
# define C_COMPARISON_H

class C_comparison
{
	public:

		char	letter;

		C_comparison(int v, char x);
		~C_comparison(void);

		int	getval(void) const;
		int	compare(C_comparison *other) const;

	private:

		int		_val;
};

#endif
