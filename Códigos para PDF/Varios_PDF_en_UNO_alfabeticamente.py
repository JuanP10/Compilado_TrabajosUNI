from PyPDF2 import PdfMerger
import os
import re

# Pide una carpeta de pdf para combinarlos en un solo PDF en orden alfabetico

# Función para extraer números de un nombre de archivo
def extract_number(filename):
    match = re.search(r'\d+', filename)
    return int(match.group()) if match else float('inf')

# Lista los archivos PDF en el directorio especificado
input_dir = r'C:\Users\JUAN PABLO\Desktop\Documentos de Geral'
listaPdfs = os.listdir(input_dir)

# Ordena la lista de archivos por el número extraído de su nombre
listaPdfs.sort(key=extract_number)

print(listaPdfs)  # Imprime la lista de archivos para verificar

merger = PdfMerger()

for file in listaPdfs:
    # Combina la ruta del directorio de entrada con el nombre del archivo
    file_path = os.path.join(input_dir, file)
    merger.append(file_path)

# Ruta completa para el archivo de salida
output_path = r'C:\Users\JUAN PABLO\Desktop\Documentos de Geral\PdfFinal.pdf'
merger.write(output_path)
merger.close()
