#ifndef C_VISIBILITY_H
# define C_VISIBILITY_H

class C_visibility {

	public:

		int		publicint;

		C_visibility(void);
		~C_visibility(void);

		void	publicft(void) const;
	
	private:

		int		_privateint;

		void	_privateft(void) const;

};

#endif