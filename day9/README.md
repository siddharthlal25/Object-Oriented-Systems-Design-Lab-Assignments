Object Oriented Systems Design Laboratory: Problem Sheet 9

Implement the following in C++

1) Al-Kindi's method

Note that if the permutation cycles are big enough and together span the entire alphabet, then it is considerably difficult to decrypt the message from the final output of the previous program (Generalized Caesar Cipher). For such cases a tool called frequency analysis, first described by the medieval Arab mathematician Al Kindi, is used. Frequency analysis means we record the frequency of letters in a normal text, and try to match those with the frequency of the letters in the encrypted message. For example, from any normal large enough piece of English text, it can be seen that "e", "t", "a" and "o" are the most common, while "z", "q" and "x" are rare. Likewise, "th", "er", "on", and "an" are the most common pairs of letters (termed bigrams), and "ss", "ee", "tt", and "ff" are the most common repeats. Your program should read the encrypted message from input.txt, and also read a normal large English text from a file sample.txt. From the two messages it will find out the the frequency of all the letters, and find the five most common pair of letters, and five most common pair of repeats. It will list them in the following format in a file called frequency.txt:

Sample:

Single letters: e > t > a > o > .... > z > q > x

Bigrams:  th > er > on > an > in

Repeats: ss > ee > tt > ff > dd

Encrypted message:

Single letters:

Bigrams:

Repeats:

Using the above information, a small permutation can be obtained which partially decrypts the message and allows us to make good guesses about the rest of the message. Get such a permutation and using the program for the previous question, show your partially decrypted message in a file named decrypt.txt.

2) Vigenere Cipher

Frequency Analysis could be made substantially more difficult by replacing consecutive two or more letters by different combinations of lettters. But this made the key-size unpractically large and complicated. For example, for substituting two consecutive letters, there would have to be 26^2 = 676  preset replacements. But even then, given an approrpriately large text, Frequency Analysis could still be used to decode the message.

The Vigenere Cipher is misattributed to Blaise de Vigenere. Actually It was proposed by Giovan Battista Bellaso in 1553. This cipher consists of several interwoven Caesar Ciphers. For example, suppose that the plaintext to be encrypted is

ATTACKATDAWN.
The person sending the message chooses a keyword and repeats it until it matches the length of the plaintext, for example, the keyword "LEMON":

LEMONLEMONLE
Each row starts with a key letter. The rest of the row holds the letters A to Z (in shifted order). Although there are 26 key rows shown, a code will use only as many keys (different alphabets) as there are unique letters in the key string, here just 5 keys: {L, E, M, O, N}. For successive letters of the message, successive letters of the key string will be taken and each message letter enciphered by using its corresponding key row. The next letter of the key is chosen, and that row is gone along to find the column heading that matches the message character. The letter at the intersection of [key-row, msg-col] is the enciphered letter.

For example, the first letter of the plaintext, A, is paired with L, the first letter of the key. Therefore, row L and column A of the VigenÃ¨re square are used, namely L. Similarly, for the second letter of the plaintext, the second letter of the key is used. The letter at row E and column T is X. The rest of the plaintext is enciphered in a similar fashion:

Plaintext: ATTACKATDAWN
Key: LEMONLEMONLE
Ciphertext: LXFOPVEFRNHR

Write a program that reads a given text from input.txt, and takes a key from key.txt. Then it encrypts the message as above and writes the result in output.txt.

3) Kasiski Examination

In 1863, Kasiski published a general method for attacking Vigenere Ciphers, though it is now proved to be known to Charles Babbage and others earlier.

The Kasiski Examination tries to find out the length of the key in a Vigenere Cipher first. Look at the previous example. If the key was CAT instead of LEMON, then the two instances of AT would have been mapped to the same letters. Kasiski's method searches for all repeated groups in the encrypted text and records their distances. Then these distances are factored. The number that occurs the most in the factors is likely to be the length of the key. Once the key is known to be of a certain length n, then the encrypted code is partitioned modulo n and Frequency Analysis is used separately on each part to decrypt the text.

Write a program to use Kasiski's method to decrypt the encrypted message from the previous program. Show your results in an output file called decrypt.txt, and demonstrate a step by step attempt to guess the length of the key, the key itself, and finally display the (partially) decrypted text.
