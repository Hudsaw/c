{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyM9kc48qWitpfYtdb7nDPun"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"uCydPcyddCBd"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main() {\n","\n","  int n, m, cont=1;\n","\n","  printf(\"Digite um número:\\n\");\n","  scanf(\" %d\", &n);\n","  m=0;\n","while (cont <= 10) {\n","  printf(\"%dx%d=%d \\n\", cont, n, m+n);\n","  cont++;\n","  m+=n;\n","}\n","  return 0;\n","}"]}]}