from pydub import AudioSegment

# Función para convertir un archivo m4a a mp3
def convert_m4a_to_mp3(m4a_file, wav_file):
    # Cargar el archivo m4a
    audio = AudioSegment.from_file(m4a_file, format="m4a")
    
    # Exportar el archivo como mp3
    audio.export(wav_file, format="wav")
    print(f"Archivo convertido y guardado como {wav_file}")

# Ruta del archivo m4a y nombre del archivo mp3 resultante
m4a_file = "clase lunes07102024.m4a" 
wav_file = "output.wap"

# Llamar a la función de conversión
convert_m4a_to_mp3(m4a_file, wav_file)
