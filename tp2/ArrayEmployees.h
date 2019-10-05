struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

/** \brief Para indicar que todas las posicciones de el array estan vacias
* \param list Employee* puntero de el array empleados
* \param len int longitud de el array
* \return int Return (0) si esta Ok
*
*/

int initEmployees(Employee* list, int len);

/** \brief adhiere en una lista existente de empleados los valores recividos como parametros en la primer posicion que esta vacia
* \param list employee*
* \param len int
* \return int retorna (-1) si no hay espacio- (0) si Ok
*
*/

int addEmployee(Employee* list, int len);

/** \brief Encuentra un empleado por id para poder modificarlo
* \param list Employee*
* \param len int
* \return int Retorna (-1) si no hubo cambios o no pudo encontrar el empleado y (0) si modifico algo
*
*/

int findEmployeeById(Employee* list, int len);

/** \brief Realiza una baja logica, coloca isEmpty en 0
*
* \param list Employee*
* \param len int
* \return int  retrona (-1) si no encontro el registro o (0) si Ok
*
*/

int removeEmployee(Employee* list, int len);


/** \brief Imprime los empleados cargados
*
* \param list Employee*
* \param len int
* \return int
*
*/

int printEmployees(Employee* list, int len);
