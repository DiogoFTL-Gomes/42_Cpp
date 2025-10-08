#ifndef C_CLASS_STRUCT02_H
# define C_CLASS_STRUCT02_H


//structs e classes são iguais em c++
//qd não especificado, classes assumem-se privadas
class C_class_struct02{

	public://Se isto não estiver aqui, compilador assume privado

		int		val;

		C_class_struct02(void);
		~C_class_struct02(void);

		void	ft_example(void) const;
};

#endif