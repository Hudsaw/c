{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyPg5u2gpgJblSMZ0VzbO3+D"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"SJI5tYdBTJpt"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","int qnum, num, cont = 1, div, qdiv;\n","\n","  printf(\"Escreva a quantidade de números: \\n\");\n","  scanf(\"%d\", &qnum);\n","\n","    while (cont<=qnum) {\n","      printf(\"Escreva um número inteiro: \\n\");\n","      scanf(\"%d\", &num);\n","      qdiv = 0;\n","      printf(\"Divisores de %d: \", num);\n","      div = 1;\n","\n","      while (div<=num) {\n","        if (num%div==0) {\n","          qdiv++;\n","          printf(\"%d, \", div);\n","        }\n","        div++;\n","      }\n","    printf(\"\\nQuantidade de divisores: %d\\n\", qdiv);\n","      if(qdiv==2){\n","        printf(\"O número %d é primo\\n\", num);\n","      }\n","    cont++;\n","    }\n","\n","return 0;\n","}"]}]}