{"nbformat":4,"nbformat_minor":0,"metadata":{"colab":{"provenance":[],"authorship_tag":"ABX9TyOd/BGikUKn3rjN5T+VoXez"},"kernelspec":{"name":"python3","display_name":"Python 3"},"language_info":{"name":"python"}},"cells":[{"cell_type":"code","execution_count":null,"metadata":{"id":"VhOAWBV8n1GP"},"outputs":[],"source":["#include <stdio.h>\n","\n","int main(){\n","int ingresso=120, ni=120, cont=0;\n","float l=300, p=5, ml=300, pl=5;\n","printf(\"Para %d ingressos a R$%.2f o lucro é de R$%.2f.\\n\", ingresso, p, l);\n","\n","   while(p>1){\n","     ingresso+=26;\n","     p-=.5;\n","     l=ingresso*p-200;\n","     printf(\"Para %d ingressos a R$%.2f o lucro é de R$%.2f.\\n\", ingresso, p, l);\n","    if(l>ml){\n","    ml=l;\n","    pl=p;\n","    ni=ingresso;\n","    }\n","    cont++;\n","\n","}\n","printf(\"O lucro máximo esperado é de R$%.2f para %d ingressos a R$%.2f.\\n\", ml, ni, pl);\n","return 0;\n","}"]}]}