This code in specific was delivered to broken previously and send as a homework for the "Sistemas Operacionais" subject in UFAM, oriented by professor André Carvalho. Our mission was to fix a multithreading program that had no protection against race conditions: we needed to make the program "thread-safe". 

Here is my result of making it "thread-safe" with semaphores and other mecanisms.

Problem Description:

"Trab2: Produtor-Consumidor-ambidestro

  No código prodconsamb.c, temos uma versão modificada do produtor consumidor com três tipos de threads:
  
  Produtor: Produz um elemento e coloca no buffer 1 se este não estiver cheio.
  
  Consumidor: Consome um elemento do buffer 2 se este não estiver vazio.
  
  Ambos: Consome um elemento do buffer 1 se este não estiver vazio e produz no buffer 2 se este não estiver cheio.
  
  1 - Altere o código para ele se tornar thread-safe.
  
  2 – Altere para que após todas as produções sejam consumidas, o programa acabe."
