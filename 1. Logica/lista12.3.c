{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyMnLnpGFfhmjXWRfzwWpdJm"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"mzx3zfK-wikk"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","int n, m, num, cont=1, som, sum;\n","\n","printf(\"Escreva o número de valores:\\n\");\n","scanf(\"%d\", &n);\n","\n","  while (cont<=n){\n","    printf(\"\\nEscreva o %dº valor:\\n\", cont);\n","    scanf(\"%d\", &m);\n","    if(m<1){\n","      printf(\"Valor inválido.\\n\");\n","    }\n","    else {\n","      printf(\"A soma dos termos: \");\n","      som=1;\n","      sum=0;\n","      while(som<=m){\n","        printf(\"%d, \", som);\n","        sum+=som;\n","        som++;\n","      }\n","      printf(\"é de %d\\n\", sum);\n","    }\n","    cont++;\n","  }\n","return 0;\n","}"]}]}