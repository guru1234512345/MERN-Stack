// // reader writer mutex
// // 3
// // 1
// // 10

// #include<stdio.h>
// #include<stdlib.h>
// #include<semaphore.h>
// #include<pthread.h>

// int Data = 10;
// int ReadCount=0;

// pthread_mutex_t mutexEnter;
// pthread_mutex_t mutexDb;

// void* readDb(void* args)
// {
//     int id = *(int *)args;
//     pthread_mutex_lock(&mutexEnter);
//     ReadCount=ReadCount+1;
//     if(ReadCount==1)
//     {
//         pthread_mutex_lock(&mutexDb);
//     }
//     pthread_mutex_unlock(&mutexEnter);
    
//     pthread_mutex_lock(&mutexEnter);
//     printf("\nReader %d Entering in Critical Region",id);
//     ReadCount=ReadCount-1;
//     if(ReadCount==0)
//     {
//         pthread_mutex_unlock(&mutexDb);
//     }
//     printf("\nReader %d reading data %d",id,Data);
//     printf("\nReader %d Exiting Critical Region",id);
//     pthread_mutex_unlock(&mutexEnter);
    
// }

// void* writeDb(void* args)
// {
//     int id = *(int *)args;
//     int newData;
//     pthread_mutex_lock(&mutexDb);
//     printf("\nWriter %d Entering in Critical Region",id);
//     printf("\nEnter data which you wants to update : ");
//     scanf("%d",&newData);
//     Data = newData;
//     printf("\nWriter %d update the data to %d",id,Data);
//     printf("\nWriter %d Exiting Critical Region",id);
//     pthread_mutex_unlock(&mutexDb);
// }


// int main()
// {
//     // Producer Count
//     int readC = 0;
//     int writeC = 0;
//     printf("\nEnter the number of Readers : ");
//     scanf("%d",&readC);
//     printf("\nEnter the number of Writers : ");
//     scanf("%d",&writeC);
//     int read = 0;
//     int writer = 0;
    
    
//     // creating threads
//     pthread_t Reader[readC],Writer[writeC];
//     int readId[readC];
//     int writeId[writeC];
    
//     // initialising semaphores
//     pthread_mutex_init(&mutexEnter,NULL);
//     pthread_mutex_init(&mutexDb,NULL);
    
    
//     for(read;read<readC;read++)
//     {
//         readId[read] = read+1;
//         pthread_create(&Reader[read],NULL,readDb,&readId[read]);
//     }
//     for(writer;writer<writeC;writer++)
//     {
//         writeId[writer] = writer+1;
//         pthread_create(&Writer[writer],NULL,writeDb,&writeId[writer]);
        
//     }
//     // for(read;read<readC;read++)
//     // {
//     //     readId[read] = read+1;
//     //     pthread_create(&Reader[read],NULL,readDb,&readId[read]);
//     // }
//     // for(writer;writer<writeC;writer++)
//     // {
//     //     writeId[writer] = writer+1;
//     //     pthread_create(&Writer[writer],NULL,writeDb,&writeId[writer]);
        
//     // }
    
//     for(int i=0;i<readC;i++)
//     {
//         pthread_join(Reader[i], NULL);
//     }
//     for(int i=0;i<writeC;i++)
//     {
//         pthread_join(Writer[i], NULL);
//     }
    
//     return 0;
        
// }




//reader writer semaphore

// #include <stdio.h>
// #include <stdlib.h>
// #include <semaphore.h>
// #include <pthread.h>

// int Data = 10;
// int ReadCount = 0;

// sem_t enter, db;

// void *readDb(void *args)
// {
//     int id = *(int *)args;
//     sem_wait(&enter);
//     ReadCount = ReadCount + 1;
//     if (ReadCount == 1)
//     {
//         sem_wait(&db);
//     }
//     sem_post(&enter);
//     printf("\nReader %d Entering in Critical Region", id);
//     printf("\nReader %d reading data %d", id, Data);
//     printf("\nReader %d Exiting from Critical Region", id);
//     sem_wait(&enter);
//     ReadCount = ReadCount - 1;
//     if (ReadCount == 0)
//     {
//         sem_post(&db);
//     }
//     sem_post(&enter);
// }

// void *writeDb(void *args)
// {
//     int id = *(int *)args;
//     int newData;
//     sem_wait(&db);
//     printf("\nWriter %d Entering in Critical Region", id);
//     printf("\nEnter data which you wants to update : ");
//     scanf("%d", &newData);
//     Data = newData;
//     printf("\nWriter %d update the data to %d", id, Data);
//     printf("\nWriter %d Exiting from Critical Region", id);
//     sem_post(&db);
// }

// int main()
// {
//     // Producer Count
//     int readC = 0;
//     int writeC = 0;
//     printf("\nEnter the number of Readers : ");
//     scanf("%d", &readC);
//     printf("\nEnter the number of Writers : ");
//     scanf("%d", &writeC);
//     int read = 0;
//     int writer = 0;

//     // creating threads
//     pthread_t Reader[readC], Writer[writeC];
//     int readId[readC];
//     int writeId[writeC];

//     // initialising semaphores
//     sem_init(&enter, 0, 1);
//     sem_init(&db, 0, 1);

//     for (read; read < readC; read++)
//     {
//         readId[read] = read + 1;
//         pthread_create(&Reader[read], NULL, readDb, &readId[read]);
//     }
//     for (writer; writer < writeC; writer++)
//     {
//         writeId[writer] = writer + 1;
//         pthread_create(&Writer[writer], NULL, writeDb, &writeId[writer]);
//     }

//     for (int i = 0; i < readC; i++)
//     {
//         pthread_join(Reader[i], NULL);
//     }
//     for (int i = 0; i < writeC; i++)
//     {
//         pthread_join(Writer[i], NULL);
//     }

//     return 0;
// }






// // producer consumer mutex
// // 4
// // 3

// #include <stdio.h>
// #include <stdlib.h>
// #include <semaphore.h>
// #include <pthread.h>

// #define BUFFER_SIZE 5
// int buffer[BUFFER_SIZE];
// int count = 0;

// sem_t full, empty;
// pthread_mutex_t mutex;

// void *produce(void *args)
// {
//     int id = *((int *)args);

//     if (count == BUFFER_SIZE)
//     {
//         printf("\nProducer Cannot Produce Because Buffer is Full");
//     }
//     else
//     {
//         sem_wait(&empty);
//         pthread_mutex_lock(&mutex);
//         printf("\nProducer %d is Entered in Critical Region : ",id);
//         printf int newProduct = count + 1;
//         buffer[count] = newProduct;
//         printf("\nProducer %d produce new product %d", id, newProduct);
//         count = count + 1;
//         printf("\nBuffer Status : \n");
//         for (int i = 0; i < BUFFER_SIZE; i++)
//         {
//             printf("%d ", buffer[i]);
//         }
//         printf("\nProducer %d is Exit from Critical Region : ",id);
//         pthread_mutex_unlock(&mutex);
//         sem_post(&full);
//     }
// }   

// void *consume(void *args)
// {
//     int id = *((int *)args);

//     if (count == 0)
//     {
//         printf("\nConsumer Cannot Consume Because Buffer is Empty");
//     }
//     else
//     {
//         sem_wait(&full);
//         pthread_mutex_lock(&mutex);
//         printf("\nConsumer %d is Entered in Critical Region : ",id);
//         int consumeProduct = buffer[count - 1];
//         printf("\nConsumer %d consume product %d", id, consumeProduct);
//         count = count - 1;
//         buffer[count] = 0;
//         printf("\nBuffer Status : \n");
//         for (int i = 0; i < BUFFER_SIZE; i++)
//         {
//             printf("%d ", buffer[i]);
//         }
//         printf("\nConsumer %d is Exit from Critical Region : ",id);
//         pthread_mutex_unlock(&mutex);
//         sem_post(&empty);
//     }
// }

// int main()
// {
//     // Producer Count
//     int Prod = 0;
//     int Consu = 0;
//     printf("\nEnter the number of Producer : ");
//     scanf("%d", &Prod);
//     printf("\nEnter the number of Consumer : ");
//     scanf("%d", &Consu);
//     int pro = 0;
//     int con = 0;
//     int counter = 0;

//     for (int i = 0; i < BUFFER_SIZE; i++)
//     {
//         buffer[i] = 0;
//     }

//     // creating threads
//     pthread_t Producer[Prod], Consumer[Consu];
//     int ProdId[Prod], ConsuId[Consu];

//     // initialising semaphores
//     sem_init(&full, 0, 0);
//     sem_init(&empty, 0, BUFFER_SIZE);
//     pthread_mutex_init(&mutex, NULL);

//     for (pro; pro < Prod; pro++)
//     {
//         ProdId[pro] = pro + 1;
//         pthread_create(&Producer[pro], NULL, produce, &ProdId[pro]);
//     }
//     for (con; con < Consu; con++)
//     {
//         ConsuId[con] = con + 1;
//         pthread_create(&Consumer[con], NULL, consume, &ConsuId[con]);
//     }

//     for (int i = 0; i < Prod; i++)
//     {
//         pthread_join(Producer[i], NULL);
//     }
//     for (int i = 0; i < Consu; i++)
//     {
//         pthread_join(Consumer[i], NULL);
//     }

//     return 0;
// }





// // producer consumer semaphore
// // 7
// // 2

// #include <stdio.h>
// #include <stdlib.h>
// #include <semaphore.h>
// #include <pthread.h>

// #define BUFFER_SIZE 5
// int buffer[BUFFER_SIZE];
// int count = 0;

// sem_t full, empty;
// sem_t S;

// void *produce(void *args)
// {
//     int id = *((int *)args);

//     if (count == BUFFER_SIZE)
//     {
//         printf("\nProducer Cannot Produce Because Buffer is Full");
//         return;
//     }
//     else
//     {
//         sem_wait(&empty);
//         sem_wait(&S);
//         printf("\nProducer %d is Entered in Critical Region : ", id);
//         int newProduct = count + 1;
//         buffer[count] = newProduct;
//         printf("\nProducer %d produce new product %d", id, newProduct);
//         count = count + 1;
//         printf("\nBuffer Status : \n");
//         for (int i = 0; i < BUFFER_SIZE; i++)
//         {
//             printf("%d ", buffer[i]);
//         }
//         printf("\nProducer %d is Entered in Critical Region : ", id);
//         sem_post(&S);
//         sem_post(&full);
//     }
// }

// void *consume(void *args)
// {
//     int id = *((int *)args);

//     if (count == 0)
//     {
//         printf("\nConsumer Cannot Consume Because Buffer is Empty");
//         return;
//     }
//     else
//     {
//         sem_wait(&full);
//         sem_wait(&S);
//         printf("\nConsumer %d is Entered in Critical Region : ", id);
//         int consumeProduct = buffer[count - 1];
//         printf("\nConsumer %d consume product %d", id, consumeProduct);
//         count = count - 1;
//         buffer[count] = 0;
//         printf("\nBuffer Status : \n");
//         for (int i = 0; i < BUFFER_SIZE; i++)
//         {
//             printf("%d ", buffer[i]);
//         }
//         sem_post(&S);
//         sem_post(&empty);
//         printf("\nConsumer %d is Exit from Critical Region : ", id);
//     }
// }

// int main()
// {
//     // Producer Count
//     int Prod = 0;
//     int Consu = 0;
//     printf("\nEnter the number of Producer : ");
//     scanf("%d", &Prod);
//     printf("\nEnter the number of Consumer : ");
//     scanf("%d", &Consu);
//     int pro = 0;
//     int con = 0;
//     int counter = 0;

//     for (int i = 0; i < BUFFER_SIZE; i++)
//     {
//         buffer[i] = 0;
//     }

//     // creating threads
//     pthread_t Producer[Prod], Consumer[Consu];
//     int ProdId[Prod], ConsuId[Consu];

//     // initialising semaphores
//     sem_init(&full, 0, 0);
//     sem_init(&empty, 0, BUFFER_SIZE);
//     sem_init(&S, 0, 1);

//     for (pro; pro <Prod; pro++)
//     {
//         ProdId[pro] = pro + 1;
//         pthread_create(&Producer[pro], NULL, produce, &ProdId[pro]);
//     }
//     for (con; con < Consu; con++)
//     {
//         ConsuId[con] = con + 1;
//         pthread_create(&Consumer[con], NULL, consume, &ConsuId[con]);
//     }
//     for (pro; pro < Prod; pro++)
//     {
//         ProdId[pro] = pro + 1;
//         pthread_create(&Producer[pro], NULL, produce, &ProdId[pro]);
//     }

//     for (int i = 0; i < Consu; i++)
//     {
//         pthread_join(Consumer[i], NULL);
//     }

//     return 0;
// }





// //dinning philosopher

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>
// #include <unistd.h>

// #define NUM_PHILOSOPHERS 3
// #define MAX_MEALS 1 // Number of times each philosopher will eat

// sem_t forks[NUM_PHILOSOPHERS];
// pthread_mutex_t lock;
// int meal_count[NUM_PHILOSOPHERS] = {0}; // Tracks meals for each philosopher

// void *philosopher(void *arg)
// {
//     int id = *((int *)arg);
//     int left = id;
//     int right = (id + 1) % NUM_PHILOSOPHERS;

//     while (meal_count[id] < MAX_MEALS)
//     {
//         // Thinking
//         printf("Philosopher %d is thinking.\n", id);
//         sleep(1);

//         // Picking up forks
//         pthread_mutex_lock(&lock);
//         sem_wait(&forks[left]);
//         sem_wait(&forks[right]);
//         pthread_mutex_unlock(&lock);

//         // Eating
//         printf("Philosopher %d is eating.\n", id);
//         sleep(2); // Eating time
//         meal_count[id]++;
//         printf("Philosopher %d finished eating (%d/%d times).\n", id, meal_count[id], MAX_MEALS);

//         // Putting down forks
//         sem_post(&forks[left]);
//         sem_post(&forks[right]);
//     }

//     printf("Philosopher %d is done eating and leaving.\n", id);
//     return NULL;
// }

// int main()
// {
//     pthread_t philosophers[NUM_PHILOSOPHERS];
//     int ids[NUM_PHILOSOPHERS];

//     // Initialize semaphores and mutex
//     for (int i = 0; i < NUM_PHILOSOPHERS; i++)
//     {
//         sem_init(&forks[i], 0, 1);
//     }
//     pthread_mutex_init(&lock, NULL);

//     // Create philosopher threads
//     for (int i = 0; i < NUM_PHILOSOPHERS; i++)
//     {
//         ids[i] = i;
//         pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
//     }

//     // Wait for all philosophers to finish
//     for (int i = 0; i < NUM_PHILOSOPHERS; i++)
//     {
//         pthread_join(philosophers[i], NULL);
//     }

//     // Cleanup
//     for (int i = 0; i < NUM_PHILOSOPHERS; i++)
//     {
//         sem_destroy(&forks[i]);
//     }
//     pthread_mutex_destroy(&lock);

//     printf("All philosophers have finished eating.\n");
//     return 0;
// }




// //matrix operations

// #include <stdio.h>
// #include <pthread.h>

// #define N 3
// int A[N][N],B[N][N],C[N][N];

// void* add_matrix(void* args) {
// 	int thread_id = *(int*)args;

// 	for(int i=thread_id; i<N; i=i+2) {
// 		for(int j=0; j<N; j++) {
// 			C[i][j] = A[i][j]+B[i][j];
// 		}
// 	}

// 	return NULL;
// }


// void* sub_matrix(void* args) {
// 	int thread_id = *(int*)args;

// 	for(int i=thread_id; i<N; i=i+2) {
// 		for(int j=0; j<N; j++) {
// 			C[i][j] = A[i][j]-B[i][j];
// 		}
// 	}

// 	return NULL;
// }


// void* mul_matrix(void* args) {
// 	int thread_id = *(int*)args;

// 	for(int i=thread_id; i<N; i=i+2) {
// 		for(int j=0; j<N; j++) {
// 			C[i][j] = A[i][j]*B[i][j];
// 		}
// 	}

// 	return NULL;
// }

// void printMatrix(int C[N][N]) {
// 	for(int i=0; i<N; i++) {
// 		for(int j=0; j<N; j++) {
// 			printf("%d ",C[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// }

// int main()
// {
// 	// Setting the values of the array.
// 	for(int i=0; i<N; i++) {
// 		for(int j=0; j<N; j++) {
// 			A[i][j] = i+j;
// 			B[i][j] = i-j;
// 		}
// 	}

// 	// Print array A
// 	for(int i=0; i<N; i++) {
// 		for(int j=0; j<N; j++) {
// 			printf("%d ",A[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	printf("\n");

// 	// Print array B
// 	for(int i=0; i<N; i++) {
// 		for(int j=0; j<N; j++) {
// 			printf("%d ",B[i][j]);
// 		}
// 		printf("\n");
// 	}
	
// 	printf("\n");

// 	pthread_t threads[2]; // We have used the same threads for all the operations.
// 	int thread_id[2] = {0,1};

//     // Addition
// 	for(int i=0; i<N; i++) {
// 		pthread_create(&threads[i],NULL,add_matrix,&thread_id[i]);
// 	}

// 	for(int i=0; i<N; i++) {
// 		pthread_join(threads[i],NULL);
// 	}
	
// 	printf("Matrix Addition: \n");
// 	printMatrix(C);

//     //Subtraction
// 	for(int i=0; i<N; i++) {
// 		pthread_create(&threads[i],NULL,sub_matrix,&thread_id[i]);
// 	}

// 	for(int i=0; i<N; i++) {
// 		pthread_join(threads[i],NULL);
// 	}
// 	printf("Matrix Substraction: \n");
// 	printMatrix(C);

//     // Multiplication
    
// 	for(int i=0; i<N; i++) {
// 		pthread_create(&threads[i],NULL,mul_matrix,&thread_id[i]);
// 	}

// 	for(int i=0; i<N; i++) {
// 		pthread_join(threads[i],NULL);
// 	}
// 	printf("Matrix Multiplication: \n");
// 	printMatrix(C);




// 	return 0;
// }




// //system calls

// // 1
// // 2
// // 3
// // 4
// // 5
// // 6
// // 7

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <sys/wait.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// void fork_exit_wait();
// void file_operations();
// void create_link();
// void create_pipe();
// void create_fifo();
// void get_process_ids();

// int main() {
//     int choice;
    
//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Fork, Exit, Wait\n");
//         printf("2. File Operations (Open, Read, Write, Close)\n");
//         printf("3. Create Link and Unlink\n");
//         printf("4. Pipe\n");
//         printf("5. FIFO\n");
//         printf("6. Get Process IDs (getpid, getppid)\n");
//         printf("7. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
        
//         switch (choice) {
//             case 1:
//                 fork_exit_wait();
//                 break;
//             case 2:
//                 file_operations();
//                 break;
//             case 3:
//                 create_link();
//                 break;
//             case 4:
//                 create_pipe();
//                 break;
//             case 5:
//                 create_fifo();
//                 break;
//             case 6:
//                 get_process_ids();
//                 break;
//             case 7:
//                 printf("Exiting program.\n");
//                 exit(0);
//             default:
//                 printf("Invalid choice, please try again.\n");
//         }
//     }
//     return 0;
// }

// void fork_exit_wait() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("Fork failed");
//         exit(1);
//     } else if (pid == 0) {
//         printf("In Child Process:\n");
//         printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
//         exit(0);
//     } else {
//         wait(NULL);
//         printf("In Parent Process:\n");
//         printf("Parent PID: %d\n", getpid());
//     }
// }

// void file_operations() {
//     int fd;
//     char buffer[100];
//     const char *filename = "/tmp/example.txt";
    
//     // Open, Write, Close
//     fd = open(filename, O_CREAT | O_WRONLY, 0644);
//     if (fd < 0) {
//         perror("Open failed");
//         return;
//     }
//     write(fd, "Sample text written to file.\n", 29);
//     close(fd);
    
//     // Open, Read, Close
//     fd = open(filename, O_RDONLY);
//     if (fd < 0) {
//         perror("Open failed");
//         return;
//     }
//     read(fd, buffer, sizeof(buffer) - 1);
//     printf("Read from file: %s\n", buffer);
//     close(fd);
// }

// void create_link() {
//     const char *filename = "/tmp/example.txt";
//     const char *linkname = "/tmp/example_link.txt";
    
//     if (link(filename, linkname) == 0) {
//         printf("Link created: %s\n", linkname);
//     } else {
//         perror("Link creation failed");
//     }
    
//     if (unlink(linkname) == 0) {
//         printf("Link removed: %s\n", linkname);
//     } else {
//         perror("Unlink failed");
//     }
// }

// void create_pipe() {
//     int pipe_fd[2];
//     pid_t pid;
//     char buffer[100];
//     char message[] = "Message through pipe.\n";
    
//     if (pipe(pipe_fd) == -1) {
//         perror("Pipe creation failed");
//         return;
//     }
    
//     pid = fork();
//     if (pid < 0) {
//         perror("Fork failed");
//         exit(1);
//     } else if (pid == 0) {
//         close(pipe_fd[0]);
//         write(pipe_fd[1], message, strlen(message) + 1);
//         close(pipe_fd[1]);
//         exit(0);
//     } else {
//         close(pipe_fd[1]);
//         read(pipe_fd[0], buffer, sizeof(buffer));
//         printf("Received from pipe: %s\n", buffer);
//         close(pipe_fd[0]);
//         wait(NULL);
//     }
// }

// void create_fifo() {
//     const char *fifo_path = "/tmp/my_fifo";
//     char buffer[100];
//     char message[] = "Message through FIFO.\n";
//     int fd;
    
//     if (mkfifo(fifo_path, 0666) == -1) {
//         perror("FIFO creation failed");
//         return;
//     }
//     printf("FIFO created at %s\n", fifo_path);
    
//     pid_t pid = fork();
//     if (pid < 0) {
//         perror("Fork failed");
//         exit(1);
//     } else if (pid == 0) {
//         fd = open(fifo_path, O_WRONLY);
//         write(fd, message, strlen(message) + 1);
//         close(fd);
//         exit(0);
//     } else {
//         fd = open(fifo_path, O_RDONLY);
//         read(fd, buffer, sizeof(buffer));
//         printf("Received from FIFO: %s\n", buffer);
//         close(fd);
//         wait(NULL);
//         unlink(fifo_path);
//         printf("FIFO removed\n");
//     }
// }

// void get_process_ids() {
//     printf("Current PID: %d\n", getpid());
//     printf("Parent PID: %d\n", getppid());
// }