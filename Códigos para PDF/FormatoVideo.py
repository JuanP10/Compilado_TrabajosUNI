import ffmpeg

# Ruta del archivo de entrada y salida
input_file = r'C:\Users\JUAN PABLO\Desktop\Papa.circ' 
output_file = r'C:\Users\JUAN PABLO\Desktop\Papavideo.avi'  # Cambia la extensión según el formato deseado

# Convertir el archivo de MP4 a otro formato
ffmpeg.input(input_file).output(output_file).run()

print(f"Conversión completada: {output_file}")
