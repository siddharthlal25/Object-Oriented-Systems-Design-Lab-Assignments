OOSD Lab Problem Sheet 8

Implement the following in C++:

1) Scytale

The Scytale cipher was used in ancient Greece. The scytale consisted of a cylinder and a strip of parchment. The strip of parchment would be wrapped around the cylinder and the message would then be written on it. Suppose the rod allows one to write four letters around in a circle and five letters down the side of it. The plaintext could be: "I am hurt very badly help". To encrypt, one simply writes across the parchment:

_____________________________________________________________
       |   |   |   |   |   |  |
       | I | a | m | h | u |  |
     _| r | t  | v  | e | r  |_|
    |  | y | b | a | d | l  |
    |  | y | h | e | l  | p  |
    |  |   |   |   |   |    |
_____________________________________________________________

so the ciphertext becomes, "Iryyatbhmvaehedlurlp" after unwinding.

Write a program that reads a given text from input.txt, and takes a value d from the terminal. Then it omits the spaces in the text, and treats d like the diameter of the cylinder to encrypt the given message. It should output the encrypted text in a single line in a file named encrypt.txt. Next, modify your program so that it starts considering values of d starting from 1, and tries to decrypt the message. It should write the outcome for each value of d in a file called decrypt.txt. One of these outcomes should contain the real message, without spaces.


2) Caesar Shift


Julius Caesar used the Caesar shift cipher to encode his military messages. It is a method of substitution, where each letter in the message is replaced by a letter fixed number of positions away. For example, if the shift is to 3 positions to the right, then in the message "a" would be replaced by "d", "b" by "e", "t" by "w" and so on. Write a program that reads a given text from input.txt, and takes a value s from the terminal. Then it uses s to shift all letters rightward by a position of s(mod 26). So, if s = 23, then the sentence "The quick brown fox jumps over the lazy dog" should be mapped to "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald". Note that, for a large text, it is easy to guess the shift by looking at small words. For example, single letter words can be only "a" and "I", so that one can get two possible values of the shift, and then decode the text by trying with both. So, have your program omit all punctuation and spaces, and map the above text to "qebnrfzhyoltkclugrjmplsboqebixwvald", and output it in a file encrypt.txt.


With the spaces omitted, the message becomes a little harder to decode. Modify your program, so that it tries all values of s from 0 to 25 and outputs the results serially in a file decrypt.txt.


3) A generalization of the Caesar shift, was to use a general permuation of the alphabet to encode a message. Write a program that reads an input from a file input.txt,  encrypts it using a key from a file key.txt, and writes the output in a file output.txt. The file key.txt will contain the required permutation line by line. For example, key.txt could be as follows:

i m
m q
q  a
a i

This means that the rest of the letters are mapped to themselves. Also note that no two letters are mapped to the same letter. Then if input.txt contains the sentence: "I will ask a question", your program should write "M wmll isk i auestmon." Note that if the encoded message is large enough, then this kind of encryption can easily decoded by looking for small words, as before. For example, "a" and "i" are words with only one letter. "Am", "an", "by", "of", "in", "to" are common words with two letters. "The", "for" and "but" are the most used three letter words. From the sample sentence, one can tell that "m" and "i" stand for "I" and "a". To avoid the ease of decoding, modify your code to remove all punctuation and spaces, and write the output in lowercase only.
Now your program should output "mwmlliskiauestmon" in the file output.txt.

4) Al-Kindi's method

Note that if the permutation cycles are big enough and together span the entire alphabet, then it is considerably difficult to decrypt the message from the final output of the previous program. For such cases a tool called frequency analysis, first described by the medieval Arab mathematician Al Kindi, is used. Frequency analysis means we record the frequency of letters in a normal text, and try to match those with the frequency of the letters in the encrypted message. For example, from any normal large enough piece of English text, it can be seen that "e", "t", "a" and "o" are the most common, while "z", "q" and "x" are rare. Likewise, "th", "er", "on", and "an" are the most common pairs of letters (termed bigrams), and "ss", "ee", "tt", and "ff" are the most common repeats. Your program should read the encrypted message from input.txt, and also read a normal large English text from a file sample.txt. From the two messages it will find out the the frequency of all the letters, and find the five most common pair of letters, and five most common pair of repeats. It will list them in the following format in a file called frequency.txt:

Sample:

Single letters: e > t > a > o > .... > z > q > x

Bigrams:  th > er > on > an > in

Repeats: ss > ee > tt > ff > dd

Encrypted message:

Single letters:

Bigrams:

Repeats:

Using the above information, a small permutation can be obtained which partially decrypts the message and allows us to make good guesses about the rest of the message. Get such a permutation and using the program for the previous question, show your partially decrypted message in a file named decrypt.txt.
