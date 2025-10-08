#ifndef C_CLASS_STRUCT01_H
# define C_CLASS_STRUCT01_H

//structs e classes são iguais em c++
//qd não especificado, structs assumem-se publicas
struct C_class_struct01{

	int		val;

	C_class_struct01(void);
	~C_class_struct01(void);

	void	ft_example(void) const;
};

#endif