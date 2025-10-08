#ifndef C_CONST_H
# define C_CONST_H

class C_const {
	public:
		float const	pi;
		int			qf;

		C_const(float const f);
		~C_const(void);

		void	bar(void) const;
};

#endif
