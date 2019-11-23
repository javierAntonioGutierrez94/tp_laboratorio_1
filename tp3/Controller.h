/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1 si la funcion falla, 0 si no existe el archivo, 1 si la carga se realizo de manera correctata.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1 si la funcion falla, 0 si no hay datos cargados, 1 si la carga se realizo de manera correctata.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna valor -1 si la funcion falla, 0 si el alta fue cancelada, 1 si la carga se realizo de manera correcta
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return devuelve valor -1 si la funcion fallo, 1 si la edicion se realizo de
 *         manera correcta, 0 si la edicion fue cancelada
 **/
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return devuelve valor -1 si la funcion fallo, 1 si la baja se realizo de
 *         manera correcta, 0 si la baja fue cancelada
 **/
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 por errores y 1 se realizo correctamente
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor 0 si no se pudo ordenar o 1 si se realizo de manera correcta el ordenamiento
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Escribe los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor -1 si hubo un error, valor 0 si no hay ningun para guardar o valor 1 si se guardo de manera correcta
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Escribe los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor -1 si hubo un error, valor 0 si no hay ningun para guardar o valor 1 si se guardo de manera correcta
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Valida las funciones y devuelve el mensaje correspondiente
 *
 * \param codigo int signed
 * \param codFun int
 * \return int devuelve el codigo ingresado
 *
 */
int validaciones(int signed codigo,int devolucion);
