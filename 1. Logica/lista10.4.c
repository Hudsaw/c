{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyM7iKMauMylT4NbcGLUr+SW"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"DkiGl7mzTY1E"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main(){\n","int sum, num, insc, alt, contador=1, mb, ab, ma, aa;\n","float media=0;\n","\n","    printf(\"Escreva a quantidade de atletas:\");\n","    scanf(\"%d\", &num);\n","    printf(\"Escreva a inscrição e altura em centímetros do atleta (00 180): \\n\");\n","    scanf(\"%d %d\", &insc, &alt);\n","    mb=insc;\n","    ab=alt;\n","    ma=insc;\n","    aa=alt;\n","    sum=alt;\n","\n","    while(contador<num){\n","    printf(\"Escreva a inscrição e altura em centímetros do atleta (00 180): \\n\");\n","    scanf(\"%d %d\", &insc, &alt);\n","    sum += alt;\n","    if(ab>alt){\n","        ab=alt;\n","        mb=insc;\n","    }\n","    if(aa<alt){\n","        aa=alt;\n","        ma=insc;\n","    }\n","  contador++;\n","}\n","  media=sum/num;\n","  printf(\"O menor atleta é o %d com %d de altura.\\n\", mb, ab);\n","  printf(\"O maior atleta é o %d com %d de altura.\\n\", ma, aa);\n","  printf(\"A média de altura dos %d atletas é é %.2f.\\n\", num, media);\n","return 0;\n","}\n"]}]}