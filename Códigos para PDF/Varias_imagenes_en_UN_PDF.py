from PIL import Image
import os

# Pide una carpeta de imágenes para convertirlas en un solo PDF junto

def convertir_imagenes_a_pdf(carpeta_imagenes, archivo_salida):
    # Obtener lista de archivos en la carpeta
    archivos = os.listdir(carpeta_imagenes)
    
    # Filtrar solo los archivos de imagen soportados por PIL
    imagenes = []
    for archivo in archivos:
        if archivo.endswith(('png', 'jpg', 'jpeg', 'tiff', 'bmp', 'gif')):
            ruta_imagen = os.path.join(carpeta_imagenes, archivo)
            imagen = Image.open(ruta_imagen).convert('RGB')
            imagenes.append(imagen)
    
    if imagenes:
        # Guardar todas las imágenes en un solo archivo PDF
        imagenes[0].save(archivo_salida, save_all=True, append_images=imagenes[1:])
        print(f"PDF guardado exitosamente como {archivo_salida}")
    else:
        print("No se encontraron imágenes en la carpeta especificada.")

# Ejemplo de uso
carpeta_imagenes = r'C:\Users\JUAN PABLO\Desktop\Cuaderno'
archivo_salida = r'C:\Users\JUAN PABLO\Desktop\salida.pdf'


convertir_imagenes_a_pdf(carpeta_imagenes, archivo_salida)
