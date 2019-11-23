/** \brief recorta los espacios a la izquierda y
 *         a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 *        ni finales
 * \return cadena devuelta sin espacios iniciales ni finales
 *
 */
void validateString(const char arrayIn[], char arrayOut[]);

/** \brief verifica si una cadena de caracteres recibio solo letras
 *
 * \param str[] char cadena a validar
 * \return int 1 si solo son letras -1 si no lo son
 *
 */
int esSoloLetras(char str[]);

/** \brief menu especifico de la aplicacion
 *
 * \param void
 * \return int opcion de menu seleccionado
 *
 */
int menuPrincipal(void);

/** \brief encabezado de una pantalla
 *
 * \param titulo[] char titulo de la pantalla
 * \param CANT int cantidad de filas que ocupa el encabezado
 * \param LENMENU int cantidad de columnas
 * \return void
 *
 */
void getChoiceForm(char titulo[],int CANT,int LENMENU);

/** \brief input de numeros enteros
 *
 * \param numero int* puntero del numero que se desea validar
 * \param mensaje1[] char inscripcion orientativa de la carga
 * \param mensajeError1[] char mensaje de error si se produciera
 * \param minimo int valor minimo del numero ingresado
 * \param maximo int valor minimo del numero ingresado
 * \return int 1 si la operacion fue exitosa -1 si no lo fue
 *
 */
int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);


/** \brief imprime un determinado caracter en n filas y n columnas
 *
 * \param caracter ej: '*'
 * \param can_col cantidad columnas
 * \param can_fila cantidad de filas
 * \return void
 *
 */
void crearEspacio(char caracter,int can_col,int can_fila);

/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar2(char mensaje[]);

/** \brief ingreso de cadena de caracteres controla el tamaño
 *         ingresado y facilita un mensaje orientado
 * \param char mensaje mensaje a mostrar
 * \param char input variable donde guarda el valor a su salida
 * \param tamano es el tamaño maximo para la cadena
 * \return char input
 *
 */

void getString(char mensaje[],char input[],int tamano);

/** \brief es una herramienta de validacion numerica
 *
 * \param char str[] char a controlar como numerico
 * \param
 * \return -1 si no es numerico 0 si es numerico
 *
 */
int esNumerico(char str[]);

/** \brief validacion de char verifica que se hayan ingresado
 *         datos alfanumericos
 * \param char str[] dato a controlar
 * \param
 * \return -1 si existen valores no alfanumericos 0 si es asi
 *
 */

int esAlfaNumerico(char str[]);

/** \brief recorre el numero ingresado y verifica que sea realmente
 *         un numero pero ademas controla q solo haya un '.'
 * \param cha[] albrega el dato ingresado a controlar
 * \param
 * \return -1 si no es flotante 0 si es asi
 *
 */

/** \brief verifica si una cadena de caracteres es convertible a un float
 *
 * \param str[] char
 * \return int 1 si lo es -1 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/** \brief Una pausa en el sistema
 *
 * \param mensaje[] char
 * \return void
 *
 */
void takeBreak(char mensaje[]);


/** \brief Input para una Cadena de caracteres
 *
 * \param array[] char se pasa un array vacio y se llena
 * \param cantidad int longitud del array
 * \return void
 *
 */
void myFgets(char array[], int cantidad);

/** \brief Busca y devuelve el proximo Id para una carga secuencial
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve un proximo Id
 *
 */
int nextIdLinkedList(LinkedList* pArrayListEmployee);

/** \brief A partir de un Id busca y devuelve el indice donde esta ese Id
 *
 * \param pArrayListEmployee LinkedList*
 * \param idLinkedlist int
 * \return int un indice buscado
 *
 */
int indexLinkedList(LinkedList* pArrayListEmployee,int idLinkedlist);

/** \brief un menu donde devuelve el orden a listar u ordenar
 *
 * \param void
 * \return int 1 Descendente 0 ascendente
 *
 */
int opcionOrden(void);

/** \brief Menu donde se pide que se elija por que campo se va a ordenar la lista
 *
 * \param void
 * \return char opcion
 *
 */
char menuOrdenamiento(void);

/** \brief
 *
 * \param titulo[] char
 * \param canFila int
 * \param canCol int
 * \return void
 *
 */
void encabezadoListados(char titulo[],int canFila, int canCol);
