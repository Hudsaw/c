{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyM6UGxa6BORhGtsl3XfxzfT"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"n403P9bANekI"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main(){\n","float s=0, p=0;\n","char sair;\n","\n","   while(sair != 's'){\n","     printf(\"Digite o valor do produto: \\n\");\n","     scanf(\"%f\", &p);\n","     s += p;\n","     printf(\"Quer sair do programa: \\n\");\n","      scanf(\"%c\", &sair);\n","     scanf(\"%c\", &sair);\n","}\n"," if(s > 500){\n","   s = s * 0.8;\n","   printf(\"O valor total de sua compra é: %.2f\", s);\n"," }\n","  else{\n","    s = s * 0.75;\n","     printf(\"O valor total de sua compra é: %.2f\", s);\n","  }\n","return 0;\n","}"]}]}