__Operating System And Network Programming__
________________________________________________________________________________________

OS and Networking Programming: Parent child communication, Producer-Consumer problem, Fork, TCP and UDP client-server communication     
_________________________________________________________________________________________ 

__________________________Operation System__________________________
                           
1. System calls for process management:

        Fork(): Create a child process
        Wait(): Wait for process to change 
        Sleep : Delay for a specified amount of time
        Pipe(): Create pipe
        
2. System calls related to shared memory and semaphores:

        shmget(): Allocates a system V shared memory segment
        shmat(), shmdt(): System V shared memory operations
        shmctl(): System V shared memory control
        semget(): Get a system V semaphore set identifier
        semop(), semtimedop(): System V semaphore operations
        semctl(): System V semaphore control operations
        
__________________________Networking__________________________
                           
Socket Programming

        1. TCP Client and Server 
        
        2. UDP Client and Server
        
__________________________TCP Client__________________________
                     
        Socket()
        Connect()
        Write()
        Read()
        Close()
        
__________________________TCP Server__________________________
                        
         Socket()
         Bind()
         Listen()
         Accept()
         Read()
         Write()
         Read()
         Close()
         
______________________________________________________________________________________________       
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
