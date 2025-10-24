/**
 * COMP 201 - Fall 2025
 * Assignment 1 - BPE Text Tokenizer
 *
 * main.c
 *
 * This file contains the main function for the BPE tokenizer.
 * The main function parses command-line arguments and calls
 * the functions to be implemented by the students.
 *
 * Students: Implement the functions marked with // TODO. You may
 * add helper functions as needed.
 * DO NOT EDIT THE main() FUNCTION.
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <stdbool.h>
 

#define MAX_LINE_NUMBER 64
#define MAX_LINE_LEN 2048
#define MAX_WORD_LEN 32
#define MAX_TOKENS 1024
#define MAX_RULES 4096
#define MAX_VOCAB_SIZE 8192
 

 int normalize_file(const char *in_path, const char *out_path) {
     // TEMP: echo arguments to verify wiring. Delete this block after testing.
     printf("[normalize] input=\"%s\" output=\"%s\"\n", in_path, out_path);
     // TODO: Implement according to description.
     return 0;
 }
 
 int learn_bpe(const char *normalized_corpus_path,
               const char *merges_path,
               const char *vocab_path,
               int vocab_size,
               int min_freq) {
     // TEMP: echo arguments to verify wiring. Delete this block after testing.
     printf("[learn] corpus=\"%s\" merges_out=\"%s\" vocab_out=\"%s\" vocab_size=%d min_freq=%d\n",
            normalized_corpus_path, merges_path, vocab_path, vocab_size, min_freq);
     // TODO: Implement according to description.
     return 0;
 }
 
 int tokenize_file(const char *normalized_input_path,
                   const char *merges_path,
                   const char *tokens_path) {
     // TEMP: echo arguments to verify wiring. Delete this block after testing.
     printf("[tokenize] input=\"%s\" merges=\"%s\" tokens_out=\"%s\"\n",
            normalized_input_path, merges_path, tokens_path);
     // TODO: Implement according to description.
     return 0;
 }
 
 int encode_file(const char *vocab_path,
                 const char *tokens_path,
                 const char *encoded_path) {
     // TEMP: echo arguments to verify wiring. Delete this block after testing.
     printf("[encode] vocab=\"%s\" tokens=\"%s\" encoded_out=\"%s\"\n",
            vocab_path, tokens_path, encoded_path);
     // TODO: Implement according to description.
     return 0;
 }
 
 int decode_file(const char *vocab_path,
                 const char *encoded_path,
                 const char *decoded_path) {
     // TEMP: echo arguments to verify wiring. Delete this block after testing.
     printf("[decode] vocab=\"%s\" encoded=\"%s\" decoded_out=\"%s\"\n",
            vocab_path, encoded_path, decoded_path);
     // TODO: Implement according to description.
     return 0;
 }
 
 void print_usage(const char *prog_name) {
     fprintf(stderr, "Usage:\n");
     fprintf(stderr, "  %s normalize <input_file> <output_file>\n", prog_name);
     fprintf(stderr, "  %s learn <corpus_file> <merges_file> <vocab_file> <vocab_size> <min_freq>\n", prog_name);
     fprintf(stderr, "  %s tokenize <input_file> <merges_file> <tokens_file>\n", prog_name);
     fprintf(stderr, "  %s encode <vocab_file> <tokens_file> <encoded_file>\n", prog_name);
     fprintf(stderr, "  %s decode <vocab_file> <encoded_file> <decoded_file>\n", prog_name);
 }
 
 int main(int argc, char *argv[]) {
     // Check for minimum number of arguments
     if (argc < 2) {
         fprintf(stderr, "Error: No subcommand provided.\n");
         print_usage(argv[0]);
         return EXIT_FAILURE;
     }
 
     const char *command = argv[1];
 
     if (strcmp(command, "normalize") == 0) {
         // Command: ./bpe normalize input_file_name normalized_output_file_name
         if (argc != 4) {
             fprintf(stderr, "Error: Invalid arguments for 'normalize'\n");
             print_usage(argv[0]);
             return EXIT_FAILURE;
         }
         return normalize_file(argv[2], argv[3]);
 
     } else if (strcmp(command, "learn") == 0) {
         // Command: ./bpe learn corpus.txt merges.txt vocab.txt 8000 2
         if (argc != 7) {
             fprintf(stderr, "Error: Invalid arguments for 'learn'\n");
             print_usage(argv[0]);
             return EXIT_FAILURE;
         }
 
         int vocab_size = atoi(argv[5]);
         int min_freq = atoi(argv[6]);
 
         if (vocab_size <= 0 || min_freq < 0) {
             fprintf(stderr, "Error: Invalid vocab_size or min_freq. Values must be non-negative.\n");
             return EXIT_FAILURE;
         }
 
         return learn_bpe(argv[2], argv[3], argv[4], vocab_size, min_freq);
 
     } else if (strcmp(command, "tokenize") == 0) {
         // Command: ./bpe tokenize input.txt merges.txt tokens.txt
         if (argc != 5) {
             fprintf(stderr, "Error: Invalid arguments for 'tokenize'\n");
             print_usage(argv[0]);
             return EXIT_FAILURE;
         }
         return tokenize_file(argv[2], argv[3], argv[4]);
 
     } else if (strcmp(command, "encode") == 0) {
         // Command: ./bpe encode vocab.txt tokens.txt encoded.txt
         if (argc != 5) {
             fprintf(stderr, "Error: Invalid arguments for 'encode'\n");
             print_usage(argv[0]);
             return EXIT_FAILURE;
         }
         return encode_file(argv[2], argv[3], argv[4]);
 
     } else if (strcmp(command, "decode") == 0) {
         // Command: ./bpe decode vocab.txt encoded.txt decoded.txt
         if (argc != 5) {
             fprintf(stderr, "Error: Invalid arguments for 'decode'\n");
             print_usage(argv[0]);
             return EXIT_FAILURE;
         }
         return decode_file(argv[2], argv[3], argv[4]);
 
     } else {
         fprintf(stderr, "Error: Unknown subcommand '%s'\n", command);
         print_usage(argv[0]);
         return EXIT_FAILURE;
     }
 
     return 0;
 }