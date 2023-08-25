//chain.c implementation
matrix *create_matrix(int num_rows, int num_cols)
{

    // allocate the memory for the matrix
    matrix *mat = (matrix *)malloc(sizeof(matrix));

    // Check if memory allocation was successful
    if (mat == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }

    mat->num_rows = num_rows;
    mat->num_cols = num_cols;

    // Allocate memory for rows of the matrix
    mat->data = (int **)malloc(sizeof(int *) * num_rows);

    // Check if memory allocation was successful
    if (mat->data == NULL)
    {
        // Handle memory allocation failure
        free(mat);
        return NULL;
    }

    // Allocate memory for each row's columns
    for (int i = 0; i < num_rows; i++)
    {
        mat->data[i] = (int *)malloc(sizeof(int) * num_cols);
    }

    // Initialize matrix elements to 0
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            mat->data[i][j] = 0;
        }
    }

    return mat;
}
int calculatePower(int num, int power)
{

    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= num;
    }
    return result;
}

void add_row(matrix *mat, int *row)
{
    mat->data = realloc(mat->data, sizeof(int *) * (mat->num_rows + 1));
    int *new_row = (int *)malloc(sizeof(int *) * (mat->num_cols));
    for (int i = 0; i < mat->num_cols; i++)
    {
        new_row[i] = row[i];
    }
    mat->data[mat->num_rows] = new_row;

    (mat->num_rows) += 1;
}

void add_col(matrix *mat, int *col)
{
    for (int i = 0; i < mat->num_rows; i++)
    {
        mat->data[i] = (int *)realloc(mat->data[i], sizeof(int) * (mat->num_cols + 1));
        mat->data[i][mat->num_cols] = col[i];
    }
    mat->num_cols++;
}

void increment(matrix *mat, int num)
{
    for (int i = 0; i < (mat->num_rows); i++)
    {
        for (int j = 0; j < (mat->num_cols); j++)
        {
            mat->data[i][j] += num;
        }
    }
}

void scalar_multiply(matrix *mat, int num)
{
    for (int i = 0; i < (mat->num_rows); i++)
    {
        for (int j = 0; j < (mat->num_cols); j++)
        {
            mat->data[i][j] *= num;
        }
    }
}

void scalar_divide(matrix *mat, int num)
{
    if (num != 0)
    {
        for (int i = 0; i < (mat->num_rows); i++)
        {
            for (int j = 0; j < (mat->num_cols); j++)
            {
                mat->data[i][j] /= num;
            }
        }
    }
    else
    {
        printf("Error: Cannot divide by zero");
    }
}

void scalar_power(matrix *mat, int num)
{

    for (int i = 0; i < (mat->num_rows); i++)
    {
        for (int j = 0; j < (mat->num_cols); j++)
        {
            mat->data[i][j] = calculatePower(mat->data[i][j], num);
        }
    }
}

void delete_matrix(matrix *mat)
{

    for (int i = 0; i < mat->num_rows; i++)
    {
        free(mat->data[i]);
    }
    //  free(mat->data);
    free(mat);
}

/*
    DO NOT MODIFY BELOW
*/
// print out matrix in row-major order
// elements in the same row are space-separated
// each row starts in a new line
void print_matrix(matrix *mat) 
{
    int row_idx, col_idx;
    for(row_idx = 0; row_idx < mat->num_rows; ++row_idx) {
        for(col_idx = 0; col_idx < mat->num_cols; ++col_idx) {
            if (col_idx == mat->num_cols-1) {
                printf("%d\n", mat->data[row_idx][col_idx]);
            } else {
                printf("%d ", mat->data[row_idx][col_idx]);
            }
        }
    }
}

//Add the rest of the functions needed for the chain below
void insert_node_before(chain *chn, int index, matrix *mat)
{
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->mat = mat;

    if (chn->head == NULL)
    {

        newNode->prev = newNode;
        newNode->next = newNode;
        chn->head = newNode; // if the only node is head so, the previous and next also be itself.

        return;
    }

    else
    {

        // Find the node before which to insert the new node
        node *current = chn->head;

        if (index >= 0)
        {

            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
        }
        else
        {
            for (int i = 0; i < -index; i++)
            {
                current = current->prev;
            }
        }
        // Insert the new node before the current node
        current->prev->next = newNode;
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev = newNode;
    }
}
void insert_node_after(chain *chn, int index, matrix *mat)
{
    int afterIndex = index + 1;

    // Call the insert_node_before function with the adjusted index

    insert_node_before(chn, afterIndex, mat);
}
void delete_node(chain *chn, int index)
{
    node *current = chn->head;
    if (index >= 0)
    {
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
    }
    else
    {
        for (int i = 0; i < -index; i++)
        {
            current = current->prev;
        }
    }
    // Update the neighboring nodes to bypass the current node
    current->prev->next = current->next;

    current->next->prev = current->prev;

    // If the head is being deleted, update the head
    if (current == chn->head)
    {
        chn->head = current->next;
    }

    free(current);
}
void delete_list(chain *chn)
{

    node *current = chn->head;
    if (current != NULL)
    {
        while (1)
        {
            node *nextnode = current->next;
            free(current->mat);
            free(current);
            current = nextnode;
            if (current == chn->head)

            {

                free(current);
                break;
            }
        }
    }
    else
    {
        printf("%s\n", "The list is empty");
    }
}


//-----------------Implementation of Lab1-2-3.c file--------------

int main()
{
    chain * chn = (chain *) malloc(sizeof(chain));
    chn->head = NULL;
	run(chn);
    print_chain(chn);
    free(chn);
	return 0;
}
matrix *copy_matrix(matrix *mat)
{
    matrix *new_mat = create_matrix(mat->num_rows, mat->num_cols);
    for (int i = 0; i < mat->num_rows; i++)
    {
        for (int j = 0; j < mat->num_cols; j++)
        {
            new_mat->data[i][j] = mat->data[i][j];
        }
    }
    return new_mat;
}

// parse the input
void run(chain *chn)
{
    int row = 0;

    scanf("%d", &row);

    char *input = (char *)malloc(sizeof(char) * 100);
    getchar();


    fgets(input, 100, stdin);
    char *token = strtok(input, " ");

    int i = 0;
    int array[100];

    while (token != NULL)
    {

        array[i] = atoi(token);
        //  printf("%d\n", array[i]);
        i++;
        token = strtok(NULL, " ");
    }

    matrix *mat = create_matrix(row, i);
    for (int j = 0; j < i; j++)
    {
        mat->data[0][j] = array[j];
    }

    for (int k = 1; k < row; k++)
    {
        fgets(input, 100, stdin);
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL)
        {
            mat->data[k][i] = atoi(token);
            i += 1;
            token = strtok(NULL, " ");
        }
    }
    insert_node_before(chn, 0, copy_matrix(mat));
    int query = 0;
    scanf("%d", &query);
    while (query != 0)
    {
        switch (query)
        {

        case 2:
            int array1[100];
            for (int i = 0; i < mat->num_cols; i++)
            {
                scanf("%d", &array1[i]);
            }
            add_row(mat, array1);
            break;

        case 3:
            int array2[100];
            for (int i = 0; i < mat->num_rows; i++)
            {
                scanf("%d", &array2[i]);
            }
            add_col(mat, array2);
            break;

        case 4:
            int num = 0;
            scanf("%d", &num);
            increment(mat, num);
            break;
        case 5:
            int num2 = 0;
            scanf("%d", &num2);
            scalar_multiply(mat, num2);
            break;
        case 6:
            int num3 = 0;
            scanf("%d", &num3);
            scalar_divide(mat, num3);
            break;

        case 7:
            int num1 = 0;
            scanf("%d", &num1);
            scalar_power(mat, num1);
            break;
        }
        insert_node_after(chn, -1, copy_matrix(mat));
        scanf("%d", &query);
    }
}

//Print the chain
void print_chain(chain *chn)
{

    node *current = chn->head;
    if (current != NULL)
    {
        // print the list with space after each word
        do
        {
            
            print_matrix(current->mat);
            printf("\n");

            current = current->next;
        } while (current != chn->head);
    }

    else
    {
        printf("The list is empty.\n");
    }
}