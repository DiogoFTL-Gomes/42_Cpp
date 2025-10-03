#ifndef C_CONST_HPP
# define C_CONST_HPP

class C_const {
	public:
		float const	pi;
		int			qf;

		C_const(float const f);
		~C_const(void);

		void	bar(void) const;
};

#endif
