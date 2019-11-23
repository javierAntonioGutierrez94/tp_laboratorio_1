/** \brief Parsea los datos de un archivo de texto y antes de pasarlos a una lista enlazada
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se cargo la lista -1 no se posible
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de un archivo Binario y antes de pasarlos a una lista enlazada
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se cargo la lista -1 no se posible
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
