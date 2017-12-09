                                            
                                            Operating System And Networking Programming
                                            
______________________________________--------------------------------------------------------________________________________________________

OS and Networking Programming: Parent child communication, Producer-Consumer problem, Fork, TCP and UDP client-server communication
     
______________________________________--------------------------------------------------------________________________________________________

___________________________Operation System_______________________
                           ---------------- 
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
        
___________________________Networking__________________________
                           ----------
Socket Programming
        1. TCP Client and Server
        2. UDP Client and Server
        ______________TCP Client__________ 
                      ----------
        Socket()
        Connect()
        Write()
        Read()
        Close()
        
         _______________TCP Server__________ 
                        ----------
         Socket()
         Bind()
         Listen()
         Accept()
         Read()
         Write()
         Read()
         Close()
         
______________________________________--------------------------------------------------------________________________________________________       
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
