{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyMZdbmiklzEdCTE/+P6g9Ft"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"3AviNYPY1cO7"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","int limite, peso;\n","float pt;\n","char mais;\n","printf(\"Escreva o limite diário em Kg:\\n\");\n","scanf(\"%d\", &limite);\n","pt=0;\n","limite*=1000;\n","  while(mais!='n'){\n","    printf(\"Informe o peso do peixe em gramas:\\n\");\n","    scanf(\"%d\", &peso);\n","    if((pt+peso)<=limite){\n","      pt+=peso;\n","    printf(\"Gostaria de informar mais um peixe? (s/n)\\n\");\n","    scanf(\" %c\", &mais);\n","    }\n","    else{\n","      printf(\"Excedeu o limite diário de peso! Não é posível computar seu peixe!\\n\");\n","      mais='n';\n","    }\n","  }\n","printf(\"Peso total: %.3fKg\\n\", pt/1000);\n","return 0;\n","}"]}]}